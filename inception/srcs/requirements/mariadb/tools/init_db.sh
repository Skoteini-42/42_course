#!/bin/sh

# Will make it exit immediately if anything fails (secrets folder missing, command failure etc)
set -e

# Path where MariaDB stores the data
DATADIR="/var/lib/mysql"

# Read secrets from the designated files
DB_ROOT_PASSWORD="$(cat "$MYSQL_ROOT_PASSWORD_FILE")"
DB_PASSWORD="$(cat "$MYSQL_PASSWORD_FILE")"

# MariaDB requires this runtime folder to exist, else it won't start
# /run is a tmp directory which is empty in every container restart
mkdir -p /run/mysqld
# Allow ownership to mysql user (non-root)
chown -R mysql:mysql /run/mysqld "$DATADIR"

# If the mysql system database does not exist, initialize MariaDB
# This will create system tables, prepare metadata etc..
if [ ! -d "$DATADIR/mysql" ]; then
	echo "[MariaDB] Initializing system tables..."
	mariadb-install-db --user=mysql --datadir="$DATADIR"
fi

# Only create the WordPress database if it doesn't exist yet
if [ -d "$DATADIR/$MYSQL_DATABASE" ]; then
	echo "[MariaDB] Database '$MYSQL_DATABASE' already exists."
else
	echo "[MariaDB] Initializing WordPress database..."

	# Create a temporary file (heredoc) with the included SQL commands.
	# This is safer and more reliable than piping to the mysql client.
	tmp_sql="$(mktemp)"
	cat <<-EOF > "$tmp_sql"
		-- This command ensures the grant tables are reloaded.
		FLUSH PRIVILEGES;
		-- Set the password for the root user.
		ALTER USER IF EXISTS 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';
		-- Create the main database for WordPress.
		CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
		-- Create a dedicated user for WordPress to connect with.
		CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
		-- Grant that user full permissions on the WordPress database only.
		GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
		-- Apply all the privilege changes.
		FLUSH PRIVILEGES;
	EOF

	# Run MariaDB in bootstrap mode to execute SQL once (without networking)
	# bootstrap mode will run the server just long enough to execute
	# the SQL from the file, then it will exit immediately.
	mariadbd --user=mysql --bootstrap < "$tmp_sql"

	# Clean up the tmp file
	rm -f "$tmp_sql"

	echo "[MariaDB] Database initialization complete."
fi

# Start MariaDB as PID 1 in the foreground.
echo "[MariaDB] Starting MariaDB server..."
exec mysqld_safe
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

# Check if the data directory is empty and initialize it if it is
if [ ! -d "$DATADIR/$MYSQL_DATABASE" ]; then
	echo "[MariaDB] Initializing database..."
else
	echo "[MariaDB] Database '$MYSQL_DATABASE' already exists."
# Draft - Basic commands
# Base image to build from; using the penultimate stable version of Debian, Bookworm 12
FROM		debian:bookworm-slim

# Information added in the image's metadata
LABEL		owner="fpapadak"

# Install dependencies
# Clean up package lists in order to maintain disk space as small as possible
RUN			apt update && apt install -y \
			mariadb-server \
			mariadb-client \
			&& rm -rf /var/lib/apt/lists/*

# Copy MariaDB configuration (networking, bind-address, etc)
COPY		./conf/60-network.cnf /etc/mysql/mariadb.conf.d/60-network.cnf
# RUN			chmod 644 /etc/mysql/mariadb.conf.d/60-network.cnf

# Copy initialization script and make it executable
COPY		./tools/init_db.sh /usr/local/bin/init_db.sh
RUN			chmod +x /usr/local/bin/init_db.sh

# Port to run from
EXPOSE		3306

# Run the initialization script which wil initialize the database, create users ands set passwords
ENTRYPOINT	["/usr/local/bin/init_db.sh"]

# mysqld is the MariaDB server daemon - in Debian it won't demonize when run directly
# It stays in the foreground so mysqld becomes PID 1
CMD 		["mysqld_safe"]
# Draft - Basic commands
# Base image to build from; using the penultimate stable version of Debian, Bookworm 12
FROM debian:bookworm-slim

# Install dependencies
# Clean up package lists in order to maintain disk space small
RUN apt update && apt install -y \
	mariadb-server \
	mariadb-client \
	&& rm -rf /var/lib/apt/lists/*

# COPY ?
# COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

# Port to run from
EXPOSE 3306

# mysqld is the MariaDB server daemon - in Debian it won't demonize when run directly
# It stays in the foreground so mysqld becomes PID 1
CMD ["mysqld"]
# Draft - Basic commands
# Base image to build from; using the penultimate stable version of Debian, Bookworm 12
FROM debian:bookworm-slim

# Install dependencies: openssl is needed for TSL certificates
# Clean up in order to manage disk space better
RUN apt update && apt install nginx ~y \
	openssl \
	&& rm -rf /var/lib/apt/lists/*

# COPY ?
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

# Port to run from
EXPOSE 3306

# Command docker runs ["executable", "global config override", "prevents daemonization"]
# daemon off to prevent forking and allow nginx to run as PID 1
CMD ["nginx", "-g", "daemon off;"]
# Draft - Basic commands
# Base image to build from; using the penultimate stable version of Debian, Bookworm 12
FROM debian:bookworm-slim

# Probably not needed
WORKDIR /srcs/requirements/nginx/

# Install dependencies: openssl is needed for TSL certificates
# Clean up package lists in order to maintain disk space small
RUN apt update && apt install -y \
	nginx \
	openssl \
	&& rm -rf /var/lib/apt/lists/*

# COPY ?
COPY ./conf/default.conf /etc/nginx/conf.d/default.conf

# Probably not needed
USER fpapadak

# Port to run from
EXPOSE 443

# Command docker runs ["executable", "global config override", "prevents daemonization"]
# daemon off to prevent forking and allow nginx to run as PID 1
CMD ["nginx", "-g", "daemon off;"]
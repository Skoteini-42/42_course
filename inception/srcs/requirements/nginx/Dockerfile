# Draft - Basic commands
# Base image to build from; using the penultimate stable version of Debian, Bookworm 12
FROM --platform linux/amd64 debian:bookworm-slim

# Needed ?
WORKDIR /srcs/requirements/nginx/

# Install dependencies
RUN update && apt install nginx ~Y

# User defined?
USER fpapadak

# Port to run from
EXPOSE 443

# Command to run
CMD
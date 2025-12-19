# Inception

*This project has been created as part of the 42 curriculum by fpapadak.*

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Instructions](#instructions)
- [Resources](#resources)

## Description

![alt text](images/image.png)

### Brief Overview

Inception is a system administration project that challenges you to virtualize a complete web infrastructure using Docker containers. The goal is to set up a functional, isolated environment running multiple interconnected services that together form a WordPress website.

The project's name "inception", implies its required architecture: We are going to use a physical machine with its own OS, run a Virtual machine inside of it, and inside that VM, we are going to use Docker containers. So essentially, we will build a virtual isolated computer system, which will include virtual isolated application environments.

### Docker Usage

Using docker containers, we deploy three interconnected services:

- NGINX as a secure reverse proxy with TLS termination
- WordPress + php-fpm as the content management system
- MariaDB as the persistent database backend

![alt text](images/image-1.png)

```
┌──────────────────────────────────────────────┐
│             DOCKER CONTAINERS                │
├─────────────┬───────────────┬────────────────┤
│   WEB LAYER │   APP LAYER   │   DATA LAYER   │
│   NGINX     │   WordPress   │   MariaDB      │
│   (Reverse  │    (CMS)      │   (Database)   │
│    Proxy &  │               │                │
│    SSL)     │               │                │
└───────┬─────┴───────┬───────┴──────┬─────────┘
        │             │              │
        └─────────────┼──────────────┘
                      │
        Docker Network: inception (bridge)
```
For this project, we are working with Dockers for the following reasons:

- Our services (NGINX, WordPress, MariaDB) don't require complete OS isolation.
- Docker provides sufficient security isolation for web applications.
- Docker Compose simplifies multi-container management.

### Sources Included in the Project

The project repository contains:

- Dockerfiles (srcs/requirements/[service]/Dockerfile):

1. Custom NGINX image with TLS configuration
2. WordPress image with php-fpm optimization
3. MariaDB image with secure initialization

- Configuration Files:

1. NGINX site configuration with SSL/TLS settings
2. MariaDB initialization scripts
3. php-fpm configuration for WordPress

- Orchestration Files:

1. docker-compose.yml: Defines services, networks, volumes
2. .env: Environment variables (credentials, domain names)

- Makefile: Automation for building and managing the stack

- Security Files:

1. Secrets management using Docker secrets
2. SSL certificate generation scripts
3. Environment variable templates

### Main Design Choices

- **Container-per-Service**: Each component in its own container
- **Custom Images**: Built from the penultimate Debian stable version: Debian Bookworm 12
- **Network Isolation**: Custom bridge network with NGINX as sole entry point
- **Data Persistence**: Named volumes with bind mounts for backup
- **Security**: TLSv1.2/1.3, Docker secrets, non-root execution
- **Automation**: Makefile for one-command deployment

### Virtual Machines vs Docker

Virtual machines are designed to emulate a complete OS environment on virtualized hardware. This provides a strong isolation, but comes with significant resource usage, as each VM requires a full OS installation.

A Docker is not a Virtual machine. Unlike VMs, a Docker uses container images which are lightweigt, standalone, executable packages of software which include everything needed in order to run an application. Such packages could involve software dependencies and the application code itself. Multiple copies of the application can be run by allowing the container to run x copies. For better understanding, the container images can be compared to OOP; container images = class, container = instance of that class. Docker container images follow the OCI (Open Container Initiative).

Virtual machines run their own copy of the Linux kernel (OS), while docker containers provide isolated filesystems, networks, and process spaces, but share the host kernel. In other words, they operate in the same OS (in our case they will share the kernal of our VM's OS).

To summarize about the benefits of using docker containers:

- No dependency conflicts.
- Even better utilization efficiency. (containers can be of MB size unlike VMs)
- Containers start quickly, making it more efficient for development and testing.
- The lightweight nature reduces resource usage on the host.

### Secrets vs Environment Variables
### Docker Network vs Host Network
### Docker Volumes vs Bind Mounts

Our applications will often generate data (eg MariaDB data), which we will want to keep in case the respective container is destroyed and recreated from scratch. For that purpose, Docker and containers can handle this case via ```volumes``` and ```mounts```. Volumes and mounts allow us to designate a location where specific data can exist beyond the lifecycle of a single container. The data can live in a location managed by the Docker called Docker Volume, or a location in our host filesystem called Bind Mount. Bind Mounts are dependent on the directory structure and the OS of the host machine, while Docker Volumes are completely managed by the Docker.

![alt text](images/image-2.png)

For this reason, best practice for utilizing either, would be :

- Back up or migrate -> Docker Volumes
- Management of the location where data is stored -> Docker Volumes (via Docker CLI commands)
- OS constraints -> Docker Volumes (work in Linux AND Windows)
- Performance I/O -> Docker Volumes
- Accessing files or directories from the host -> Bind Mount
- Creating or generating files in a container that should persist inside the host -> Bind Mount
- Sharing config files from the host to containers -> Bind Mount

## Features

Feature list


## Instructions

A section containing any relevant information about compilation, installation, and/or execution

## Resources

- https://github.com/sidpalas/devops-directive-docker-course
- https://docs.docker.com/engine/install/debian/
- https://docs.docker.com/engine/storage/volumes/
- https://docs.docker.com/reference/dockerfile/
- https://cloud.theodo.com/en/blog/docker-processes-container
- https://www.docker.com/blog/docker-best-practices-choosing-between-run-cmd-and-entrypoint
- https://hub.docker.com/search?q=bookworm

A section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.

# Developer documentation

This file serves as a guide on how a developer can:

◦ Set up the environment from scratch (prerequisites, configuration files, secrets).
◦ Build and launch the project using the Makefile and Docker Compose.
◦ Use relevant commands to manage the containers and volumes.
◦ Identify where the project data is stored and how it persists.

## Table of contents

- [Setting up the environment from scratch](#setting-up-the-enviroment-from-scratch)
- [Building and launching the project](#building-and-launching-the-project)
- [Containers and volumes management](#containers-and-volumes-management)
- [Project data information](#project-data-information)

## Setting up the environment from scratch

### Virtual Machine set up

The project is required to be executed inside a Virtual Machine.

The specs used for development are the following:

- Virtual Machine: Oracle VM Virtual Box
- Operating System: Debian 12 (Bookworm)
- Desktop environment: XFCE (lightweight GUI for minimal resource usage)
- Architecture: amd64
- Networking: NAT (default VirtualBox networking mode)
- Utilities: Standard system utilities and SSL support
- RAM: Minimum 2GB
- Disk Space: 20GB

### Local domain name configuration

In order to access the WordPress website using the required custom domain `<yourlogin>.42.fr`, local DNS resolution must be configured. Since the project is developed and tested entirely inside a Debian VM with a graphical interface, the domain name is resolved locally within the VM. The NGINX container will expose port 443 on all VM interfaces (0.0.0.0:443).

The `/etc/hosts` file inside the VM needs to be edited to map the custom domain to the loopback address:
```
sudo nano /etc/hosts

# Add the following entry inside the file, save and exit
127.0.0.1   <yourlogin>.42.fr

# Confirm that the local DNS resolution is working
ping yourlogin.42.fr
```
This ensures that requests to `https://yourlogin.42.fr` are correctly routed to the NGINX container listening on port 443.

### System prerequisites

First and foremost, make sure that you add user to sudo group, as Docker commands usually require root privileges :

```
# Log in as root
su -

# Install sudo in case it isn't installed already
apt install sudo

# Add your user to the sudo group (replace with your username)
usermod -aG sudo <your_username>

# Exit and logout from the desktop for the changes to take effect
exit

# Login back and verify the changes
whoami
```

Furthermore, make sure you have installed additional dependencies that are going to be used:

```
sudo apt install -y git make vim
```

### Installing Docker :

We chose for our VM to run Debian OS therefore, the Docker setup instructions were followed from the [Docker's official site](https://docs.docker.com/engine/install/debian).

Notes:
- Follow the *Install using the apt repository* part and set up Docker's apt repository as instructed in the first part.
- For the second part in order to install the Docker packages, follow the *specific version* tab.

```
# Verify that Docker is running
sudo systemctl status docker

# In case you need to start it manually
sudo systemctl start docker

# Run a test command to see if everything works
sudo docker run hello-world
```

For for the sake of conveniency, add ```user``` to the ```docker``` group:
```sudo usermod -aG docker $USER```



## Building and launching the project

One way to build the containers one by one, is by specifying run commands (`docker run`) inside the Makefile for each container along with its relevant arguments, which when ran, everything will be build individually.
For this project's needs though, there is a much better and cleaner way to do that in case we are developing a containerized application with more than one service, and that is by making use of the `docker-compose.yml` file.


## Containers and volumes management

## Project data information
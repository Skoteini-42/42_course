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

(VM included?)

### Prerequisites:

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

$ Login back and verify the changes
whoami
```

Furthermore, make sure you have installed additional dependencies that are going to be used:

```
sudo apt install -y git make
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


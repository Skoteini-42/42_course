# User documentation

This file must explain, in clear and simple terms, how an end user or administrator can:

◦ Understand what services are provided by the stack.
◦ Start and stop the project.
◦ Access the website and the administration panel.
◦ Locate and manage credentials.
◦ Check that the services are running correctly.

### Useful commands
```
# Builds the container image for the relevant application
# -t to allow your image to have a tag (eg version)
docker build -t mariadb:0 .

# Lists all the Docker images available on your local machine
docker iamges

# Runs the container mariadb from the container image mariadb:0
# -d to run the container in detached mode (in the background, won't flood the terminal)
# --name to specific a name for the container, otherwise it will have an auto-generated name
docker run -d --name mariadb mariadb:0

# To check logs
docker logs mariadb

# Shows all the containers that are currently running.
# -a to show all the containers (included the ones that have stopped)
docker ps

# Connect
docker exec -it mariadb mariadb

# For anything else
docker --help
```
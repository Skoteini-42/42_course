NAME = inception

all: init up

init:
	@echo "Creating directories..."
	@mkdir -p ./data/mariadb ./data/wordpress ./secrets
	@if [ ! -f "./secrets/db_root_password.txt" ]; then \
		echo "Generating random root password..."; \
		openssl rand -base64 32 > ./secrets/db_root_password.txt; \
	fi
	@if [ ! -f "./secrets/db_password.txt" ]; then \
		echo "Generating random user password..."; \
		openssl rand -base64 32 > ./secrets/db_password.txt; \
	fi
	@if [ ! -f "srcs/.env" ]; then \
		cp .env.example srcs/.env; \
		echo "Please edit srcs/.env with your configuration"; \
	fi
	@echo "Initialization complete"

up:
	@echo "Starting $(NAME)..."
	docker-compose -f srcs/docker-compose.yml up --build -d

down:
	@echo "Stopping $(NAME)..."
	docker-compose -f srcs/docker-compose.yml down

clean: down
	@echo "Cleaning Docker resources..."
	@docker system prune -af --volumes

fclean: clean
	@echo "Removing data directories..."
	@sudo rm -rf ./data ./secrets

re: fclean all

logs:
	docker-compose -f srcs/docker-compose.yml logs -f

ps:
	docker-compose -f srcs/docker-compose.yml ps

.PHONY: all init up down clean fclean re logs ps
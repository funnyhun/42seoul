# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 20:26:56 by minhulee          #+#    #+#              #
#    Updated: 2025/03/03 08:28:16 by minhulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

build:
	@echo "Building Docker images..."
	@$(DOCKER_COMPOSE) build

up:
	@echo "Starting containers..."
	@$(DOCKER_COMPOSE) up

down:
	@echo "Stopping containers..."
	@$(DOCKER_COMPOSE) down

logs:
	@echo "Displaying logs..."
	@$(DOCKER_COMPOSE) logs

restart:
	@echo "Restarting containers..."
	@$(DOCKER_COMPOSE) down
	@$(DOCKER_COMPOSE) up -d

ps:
	@echo "Checking running containers..."
	@$(DOCKER_COMPOSE) ps

ls:
	@echo "Checking image list..."
	@docker image ls

volumns:
	@echo "Checking volume list..."
	@docker volume ls

clean:
	@echo "Cleaning ALL containers..."
	@make down
	@$(DOCKER_COMPOSE) down -v --rmi all --remove-orphans

fclean : clean
	@echo "Cleaning ALL containers & volumn..."
	@make down
	@sudo rm -rf /home/minhulee/data/db/*
	@sudo rm -rf /home/minhulee/data/wordpress/*
	@docker system prune --volumes --all --force
	@docker network prune --force
	@docker volume prune --force

.PHONY: build up down logs restart ps clean

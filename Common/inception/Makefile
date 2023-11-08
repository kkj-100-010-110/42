all:	up

up:
	mkdir -p /home/gyeokim/data/wp /home/gyeokim/data/db
	docker compose -f ./src/docker-compose.yml up --build -d

down:
	docker compose -f ./src/docker-compose.yml down

clean:
	docker compose -f ./src/docker-compose.yml down -v --rmi all

fclean:	clean
	sudo rm -rf -f /home/gyeokim/data/wp /home/gyeokim/data/db

re:	fclean all

.PHONY:	all up down clean fclean re

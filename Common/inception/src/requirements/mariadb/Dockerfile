FROM debian:buster

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y procps mariadb-server

COPY ./tools/script.sh /tmp/
RUN chmod +x /tmp/script.sh

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

EXPOSE 3306

ENTRYPOINT  [ "bash", "/tmp/script.sh" ]

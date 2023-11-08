FROM debian:buster

RUN apt-get update -y && \
    apt-get upgrade -y && \
    mkdir -p /var/www/html/wordpress /run/php && \
    apt-get install -y wget php7.3-fpm php7.3-mysql mariadb-client && \
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

COPY ./tools/script.sh /tmp
RUN chmod +x /tmp/script.sh

EXPOSE 9000

ENTRYPOINT [ "bash", "/tmp/script.sh" ]

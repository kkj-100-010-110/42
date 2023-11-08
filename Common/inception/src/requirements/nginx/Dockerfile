FROM debian:buster

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y nginx openssl && \
    mkdir -p /var/www/html/wordpress /etc/nginx/ssl

COPY conf/nginx.conf /etc/nginx/conf.d/

COPY tools/script.sh /tmp
RUN chmod +x /tmp/script.sh

RUN openssl req -newkey rsa:2048 -x509 -nodes \
    -subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42seoul/OU=42seoul/CN=gyeokim" \
    -keyout /etc/nginx/ssl/gyeokim.42.fr.key \
    -out /etc/nginx/ssl/gyeokim.42.fr.crt

EXPOSE 443

ENTRYPOINT [ "bash", "/tmp/script.sh" ]

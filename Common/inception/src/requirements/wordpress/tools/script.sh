#!/bin/sh

chown -R www-data:www-data /var/www/
sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g" /etc/php/7.3/fpm/pool.d/www.conf;

if [ ! -f "/var/www/html/wordpress/wp-config.php" ]; then
    wp --allow-root --path=/var/www/html/wordpress \
		core download \
        --locale=en_US && \
    wp --allow-root --path=/var/www/html/wordpress \
		core config \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_PASSWORD \
        --dbhost=$WP_HOST &&\
    wp --allow-root --path=/var/www/html/wordpress \
		core install \
        --url=$DOMAIN_NAME \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
		--skip-email && \
    # sh: 1: /usr/sbin/sendmail: not found (sendmail necessary)
    # function trailingslashit() error (php-mysql necessary)
    # mail error (php-mail necessary)
    wp --allow-root --path=/var/www/html/wordpress \
		user create $WP_USER $WP_EMAIL \
        --role=author \
        --user_pass=$WP_USER_PASSWORD && \
    wp --allow-root --path=/var/www/html/wordpress \
        theme activate twentytwentytwo
fi

exec /usr/sbin/php-fpm7.3 -F

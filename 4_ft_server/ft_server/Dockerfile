# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 18:59:59 by jcarrete          #+#    #+#              #
#    Updated: 2020/10/14 22:59:46 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

ENV AUTOINDEX on

ADD ./srcs/ ./srcs/
ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.3/phpMyAdmin-5.0.3-english.tar.gz /srcs/phpmyadmin/
ADD https://wordpress.org/latest.tar.gz /srcs/wordpress/

RUN apt-get -qq update && apt-get install -y \
	vim wget apt-utils curl \
	nginx \
	openssl \
	mariadb-server \
	php-fpm php-cli php-curl php-mysql php-mbstring && \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/* && \
	\
	mkdir -p /var/www/localhost && \
	mkdir -p etc/nginx/ssl/private/ && \
	mkdir -p etc/nginx/ssl/certs/ && \
	chmod 600 /etc/nginx/ssl/private/ && \
	chmod 600 /etc/nginx/ssl/certs/ && \
	openssl req -config ./srcs/openssl/csr.conf -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/private/localhost.key -out /etc/nginx/ssl/certs/localhost.crt && \
	chmod 644 etc/nginx/ssl/certs/localhost.crt && \
	chmod 600 etc/nginx/ssl/private/localhost.key && \
	\
	rm -rf /etc/nginx/sites-enabled/default && \
	rm -rf /etc/nginx/sites-available/default && \
	mkdir -p /var/www/localhost/html/ && \
	\
	service mysql start && \
	mysql --user=root --password= < /srcs/mysql/init.sql && \
	mysql wordpress --user=root --password= < /srcs/wordpress/wordpress.sql && \
	\
	mkdir -p /var/www/localhost/html/phpmyadmin && \
	chmod 755 /var/www/localhost/html/phpmyadmin/ && \
	chown -R www-data:www-data /var/www/localhost/html/phpmyadmin/ && \
	tar -xf /srcs/phpmyadmin/phpMyAdmin-5.0.3-english.tar.gz -C /var/www/localhost/html/phpmyadmin/ && \
	mv /var/www/localhost/html/phpmyadmin/phpMyAdmin-5.0.3-english  /var/www/localhost/html/phpmyadmin/phpMyAdmin && \
	mv /srcs/phpmyadmin/config.inc.php /var/www/localhost/html/phpmyadmin/phpMyAdmin && \
	\
	tar -xf /srcs/wordpress/latest.tar.gz -C /var/www/localhost/html/ && \
	mv /srcs/wordpress/wp-config.php /var/www/localhost/html/wordpress/ && \
	\
	chown -R www-data:www-data /var/www/* && \
	chmod -R 755 /var/www/*

CMD bash /srcs/start.sh

EXPOSE 80 443

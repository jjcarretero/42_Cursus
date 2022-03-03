#  Autoindex
if [ "$AUTOINDEX" = "on" ] ;
then mv /srcs/nginx/nginx.conf /etc/nginx/sites-available/localhost ;
else mv /srcs/nginx/nginx_off.conf /etc/nginx/sites-available/localhost
		mv /srcs/nginx/index.html /var/www/localhost/html/ ; fi
ln -fs /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/

# Start Services
service nginx start
service mysql start
service php7.3-fpm start

#Start Bash
bash

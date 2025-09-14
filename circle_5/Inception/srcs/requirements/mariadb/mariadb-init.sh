#!/bin/bash

echo "CHECK START!"

service mariadb start

while ! mysqladmin ping -h localhost --silent; do
	sleep 1
done

echo "SETTING START!"

echo "CREATE DATABASE IF NOT EXISTS $DB_NAME ;" > init.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD' ;" >> init.sql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' ;" >> init.sql
echo "FLUSH PRIVILEGES;" >> init.sql

mysql < init.sql

echo "SETTING DONE!"

service mariadb stop

while mysqladmin ping -h localhost --silent; do
	sleep 1
done

mariadbd
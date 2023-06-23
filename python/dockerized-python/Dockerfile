FROM public.ecr.aws/ubuntu/ubuntu:22.04

# Install dependencies
RUN apt-get update && \
    apt-get -y install apache2

# Install apache and write hello world message
RUN echo '<h2>Hello World! This app is stored in Github Packages :)</h2>' >> /var/www/html/index.html
RUN echo '<h3>https://aws.amazon.com/ecr/)</h3>' >> /var/www/html/index.html

# Configure apache
RUN echo '. /etc/apache2/envvars' > /root/run_apache.sh && \
    echo 'mkdir -p /var/run/apache2' >> /root/run_apache.sh && \
    echo 'mkdir -p /var/lock/apache2' >> /root/run_apache.sh && \ 
    echo '/usr/sbin/apache2 -D FOREGROUND' >> /root/run_apache.sh && \ 
    chmod 755 /root/run_apache.sh

EXPOSE 80

CMD /root/run_apache.sh

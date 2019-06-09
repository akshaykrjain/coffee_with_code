 #!/bin/bash
yum update -y
wget https://raw.githubusercontent.com/akshaykrjain/coffee_with_code/master/helloRest/app.py
yum install python-pip -y
pip install flask
python app.py&

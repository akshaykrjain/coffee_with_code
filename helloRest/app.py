#Webservice to return AWS Instance ID
#Author. Akshay.Jain
from flask import Flask
from flask import jsonify
import requests

#Fetch current AWS instance ID
response = requests.get('http://169.254.169.254/latest/meta-data/instance-id')
instance_id = response.text

app = Flask(__name__)

@app.route('/api/aws',methods=['GET'])
def hello_world():
    #return jsonify(message)
	resp = jsonify(
		message="Hello World!",
		sender= "DevOps Team"
    )
	resp.headers.set('aws-instance-id', response.text)

	return resp
	
	
if __name__ == '__main__':
    app.run()

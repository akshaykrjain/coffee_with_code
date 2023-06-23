import boto3
from kubernetes import client, config

# Load Kubernetes configuration
config.load_kube_config()

# Retrieve PVCs from Kubernetes
v1 = client.CoreV1Api()
ret = v1.list_persistent_volume_claim_for_all_namespaces(watch=False)
pvc = [i.spec.volume_name for i in ret.items]

# Retrieve EFS Access Points
efs = boto3.client("efs")
response = efs.describe_access_points(MaxResults=1000)
access_points = response["AccessPoints"]

# Delete unused EFS Access Points
for ap in access_points:
    client_token = ap["ClientToken"]
    access_point_id = ap["AccessPointId"]

    if client_token not in pvc:
        print(
            f"Deleting Access Point {access_point_id} for Client Token {client_token}"
        )
        efs.delete_access_point(AccessPointId=access_point_id)

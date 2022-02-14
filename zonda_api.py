import requests

url = "https://api.zonda.exchange/rest/trading/stats"

headers = {'content-type': 'application/json'}

response = requests.request("GET", url, headers=headers)

print(response.text)

data = response.json()
print(data)

print(f"Status = {(data['status'])}")

for i in data['items']:
    print(i)
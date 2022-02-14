#REST API test - NBP

from requests import get

code = "EUR" #currency code
date = "2022-02-04" #date format YYYY-MM-DD

url = f'http://api.nbp.pl/api/exchangerates/rates/a/{code}/{date}/' #download data from NBP REST API

resp = get(url) #save data
data = resp.json() #convert to .json
#print(data) #leave for testing

print(f"1 {code} = {data['rates'][0]['mid']} PLN w dniu {date}") #print inf
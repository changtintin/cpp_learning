import requests
p = {
    'a':'b'
}

r = requests.get('https://www.google.com/search?q=Adidas', params = p)
with open('./listResult.html','w+') as file:
    file.write(r.text)
    print("Successfully saved")


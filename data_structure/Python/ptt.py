import requests
import pretty_errors
from bs4 import BeautifulSoup
url = "https://www.ptt.cc/bbs/TaichungBun/index.html"
home = "https://www.ptt.cc"

for i in range(1,16):
    print("Page",i)
    link = requests.get(url)
    soup = BeautifulSoup(link.content,'lxml')
    t_tag = soup.select('div.title > a')
    btn = soup.select('div.btn-group > a')

    for j in t_tag:
        if "徵求" in j.text:
            print(j.text)
            print(home + j['href'])
        
    for b in btn:
        if "上頁" in b.text:
            url = home + b['href']
        

        

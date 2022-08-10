import requests
from bs4 import BeautifulSoup
import pretty_errors

result = requests.get('https://www.mercci22.com/zh-tw/tag/HOTTEST')
home = 'https://www.mercci22.com/'    
soup = BeautifulSoup(result.text,"html.parser")
soup.encoding = 'utf-8'

print(soup.find_all('a'))

# # select return a list
# # pdname = class of div
# titles = soup.select('div.pdname a') 
# n = 0
# for idx in titles:
#     n = n + 1
#     print(n)
#     print(idx.text)
#     link = home + idx['href']
#     print(link)

# # p = soup.select('div[class~=price]')
# # for tmp in p:
# #     print(tmp.text)
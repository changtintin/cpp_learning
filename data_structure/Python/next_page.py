from bs4 import BeautifulSoup
import requests
import pretty_errors

home ='https://www.techopedia.com/definition/4501/metropolitan-ethernet-metro-ethernet'
  
# call get method to request the page
page = requests.get(home)
  
# with the help of BeautifulSoup
# method and html parser created soup
soup = BeautifulSoup(page.content, 'html.parser')
t = 0

# With the help of find_all
# method perform searching in parser tree
# for i in soup.find_all('a', href = True):
   
#     if("topic" in i['href']):
#         link = "https://www.techopedia.com" + i['href']
#         next = requests.get(link)
#         newsoup = BeautifulSoup(next.content, 'html.parser')
#         t += 1
#         print(t)
#         print("\nURL Title:\t", newsoup.find('title').string)
#         print(link)
for j in soup.find_all('li'):
    if "list-group-item" in j['class']:    
        print(j.text)

    
        
    
    
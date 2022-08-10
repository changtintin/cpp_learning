from cgitb import html
from bs4 import BeautifulSoup
eg = "<span id = 'abc' ><h1>Practice</h1></span>"
soup = BeautifulSoup(eg, 'lxml')
contents = soup.contents
text = soup.text

#html
print(contents) 
#text inside the tags
print(text) 

soup = BeautifulSoup('<div><b class="boldest" id = "a">Extremely bold</b></div>', 'html.parser')
tag = soup.b
print(tag['id'])
print(tag['class'])


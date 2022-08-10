from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import pretty_errors

options = Options()
options.page_load_strategy = 'normal'
driver = webdriver.Chrome(options = options)
driver.get("https://www.dcard.tw/f")
driver.implicitly_wait(0.6)

search_bar = driver.find_element(by = By.NAME, value ='query')
submit_btn = driver.find_element(by = By.XPATH, value = "//button[@title='搜尋']")
search_bar.send_keys("微西斯")
submit_btn.click()

search_box = driver.find_element(by=By.NAME, value="query")
value = search_box.get_attribute("value")
assert value == "微西斯"

shop = driver.find_element(by = By.XPATH, value = "//a[@href='/goods']")
shop.click()

print("OK!")
input()

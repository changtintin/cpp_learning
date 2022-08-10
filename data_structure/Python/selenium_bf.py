from lib2to3.pgen2 import driver
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.actions.action_builder import ActionBuilder
from selenium.webdriver.common.actions.mouse_button import MouseButton
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

from bs4 import BeautifulSoup
import requests
import pretty_errors

options = Options()
options.page_load_strategy = 'normal'
driver = webdriver.Chrome(options = options)
driver.get("https://atomboyz.beanfun.com/")
wait = WebDriverWait(driver, 30)
try:
    wait.until(EC.element_to_be_clickable((By.XPATH, "//div[@class='btn']"))).click()
    print("Clicked")
except:
    pass

driver.find_element(by = By.ID, value = "mainMenuTrigger").click()

c = driver.find_element(by = By.XPATH, value = "//img[@src = '/assets/img/btn_login.png']")

action = ActionChains(driver)
try:
    action.click(on_element = c)
    action.perform()
except:
    print("Fail!")
    pass

driver.implicitly_wait(3)



from selenium import webdriver
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
import pretty_errors

def test_eight_components():
    # driver = webdriver.Chrome()
    driver = webdriver.Chrome(ChromeDriverManager().install())
    driver.get("https://google.com")

    # title = driver.title
    # assert title == "Google"

    driver.implicitly_wait(0.5)

    search_box = driver.find_element(by=By.NAME, value="q")
    search_button = driver.find_element(by=By.NAME, value="btnK")

    search_box.send_keys("Selenium")
    search_button.click()
    
    # search_box = driver.find_element(by=By.NAME, value="q")
    # value = search_box.get_attribute("value")
    # assert value == "Selenium"



test_eight_components()
print("Search sucessfully")
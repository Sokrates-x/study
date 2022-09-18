#!/bin/python3

import webbrowser
webbrowser.open('https://www.baidu.com');

import requests
res = requests.get('https://www.baidu.com');
print(type(res));
print(res.status_code == requests.codes.ok);
print(len(res.text));
print(res.text);
file = open('baidu.com', 'wb');
for chunk in res.iter_content(1000):
    file.write(chunk);
file.close();
import bs4

bs = bs4.BeautifulSoup(res.text);
print(bs.select('input[type="submit"]'));



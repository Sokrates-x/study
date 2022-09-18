#!/bin/python3

import requests, bs4, os


url = 'https://xkcd.com/1/';

while not url.endswith('#'):
    print('Downloading page %s...' % url);
    res = requests.get(url);
    res.raise_for_status()
    soup = bs4.BeautifulSoup(res.text);
    comicElem = soup.select('#comic img');

    if comicElem == [] :
        print('Can NOT find comic imgames');
    else :
        imgUrl = 'http:' + comicElem[0].get('src');
        print('Downloading image %s...' %(imgUrl));
        res = requests.get(imgUrl);
        res.raise_for_status();
        file = open(os.path.join('images', os.path.basename(imgUrl)), 'wb'); 
        for chunk in res.iter_content(100000):
            file.write(chunk);
        file.close();
    nextLink = soup.select('a[rel="next"]')[0];
    url = 'http://xkcd.com' + nextLink.get('href');

print('Done!');

# coding=utf-8
# ---------------------------------------------
# FileName doubanCrawler.py
# Description 爬取豆瓣电影top250
# Author Forgo7ten
# Version 1.0.0
# Date 2021/1/11

import requests
import re


def movie_crawler():
    my_head = {
        "User-Agent":
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36"
    }
    partten = re.compile(
        r'<a href="([a-zA-Z0-9:/.]*)" class="">\n.*<span class="title">(.*)</span>'
    )
    result = []
    num = 0
    for i in range(10):
        res = requests.get("https://movie.douban.com/top250?start=" +
                           str(num) + "&filter=",
                           headers=my_head)
        result += partten.findall(res.text)
        num += 25
    with open("result.txt", "w", encoding="utf-8") as f:
        i = 1
        for aline in result:
            ast = str(i) + ", " + aline[1] + ", " + aline[0] + "\n"
            f.write(ast)
            i += 1
    print("Down!")


if __name__ == "__main__":
    movie_crawler()

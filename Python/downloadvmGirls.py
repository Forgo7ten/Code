# coding=utf-8
# ---------------------------------------------
# FileName downloadvmGirls.py
# Description 爬取www.vmgirls.com图片
# Author Forgo7ten
# Version 1.0.0
# Date 2021/1/12

import requests
import random
import re
import pickle
import os
import time


def get_user_agent():
    user_agent_list = [
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:84.0) Gecko/20100101 Firefox/84.0",
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36",
        "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.66 Safari/537.36"
        "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Win64; x64; Trident/5.0; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 2.0.50727; Media Center PC 6.0)",
        "Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0; WOW64; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 1.0.3705; .NET CLR 1.1.4322)",
        "Mozilla/4.0 (compatible; MSIE 7.0b; Windows NT 5.2; .NET CLR 1.1.4322; .NET CLR 2.0.50727; InfoPath.2; .NET CLR 3.0.04506.30)",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN) AppleWebKit/523.15 (KHTML, like Gecko, Safari/419.3) Arora/0.3 (Change: 287 c9dfb30)",
        "Mozilla/5.0 (X11; U; Linux; en-US) AppleWebKit/527+ (KHTML, like Gecko, Safari/419.3) Arora/0.6",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.2pre) Gecko/20070215 K-Ninja/2.1.1",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9) Gecko/20080705 Firefox/3.0 Kapiko/3.0",
        "Mozilla/5.0 (X11; Linux i686; U;) Gecko/20070322 Kazehakase/0.4.5"
    ]
    user_agent = random.choice(user_agent_list)
    return user_agent


def download_girls():
    if not os.path.exists("girls"):
        os.mkdir("girls")
    os.chdir("girls")
    girls = set(get_girls_url())
    with open("girls.pkl", "wb") as f:
        pickle.dump(girls, f)
    with open("girls.txt", "w", encoding="utf-8") as f:
        for i in girls:
            f.write(i[1] + ", " + i[0] + '\n')
    my_headers = {
        "User-Agent": get_user_agent(),
    }
    for girl in girls:
        img_rule = re.compile(
            '<a href="//static.vmgirls.com/image/([0-9/]+).jpeg" alt="' +
            girl[1] + '" title="' + girl[1])
        girl_url = "https://www.vmgirls.com/" + girl[0] + ".html"
        girl_html = requests.get(girl_url, headers=my_headers)
        girl_imgs = img_rule.findall(girl_html.text)
        dir_name = girl[1]
        if not os.path.exists(dir_name):
            os.mkdir(dir_name)
            i = 1
            for img in girl_imgs:
                img_url = "https://static.vmgirls.com/image/" + img + ".jpeg"
                img_data = requests.get(img_url, headers=my_headers)
                with open(dir_name + '/' + dir_name + "-" + str(i) + ".jpeg",
                          'wb') as f:
                    f.write(img_data.content)
                    print(dir_name + "-" + str(i) + "  下载完成！")
                i += 1
    print("Down!")


def get_girls_url():
    url = [
        "https://www.vmgirls.com/special/beauty/",
        "https://www.vmgirls.com/special/littlesex/",
        "https://www.vmgirls.com/special/bilitis/",
        "https://www.vmgirls.com/fresh/", "https://www.vmgirls.com/pure/",
        "https://www.vmgirls.com/"
    ]
    my_headers = {
        "User-Agent": get_user_agent(),
    }
    url_tuples = []
    url_tuple_rule = re.compile(
        '<a href="/(\d+).html" title=".+" class="list-title text-md h-2x">(.+)</a>'
    )
    for i in url:
        html = requests.get(i, headers=my_headers)
        time.sleep(1)
        print(html)
        url_tuples += url_tuple_rule.findall(html.text)
    print(url_tuples[0])
    return url_tuples


if __name__ == '__main__':
    download_girls()

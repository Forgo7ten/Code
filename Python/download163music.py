# coding=utf-8
# ---------------------------------------------
# FileName download163music.py
# Description 下载网易云音乐
# Author Forgo7ten
# Version 1.0.0
# Date 2021/1/13

import requests
import json
from Crypto.Cipher import AES
import base64
import codecs
import random
import os


def add_16(par):
    if type(par) == str:
        par = par.encode()
    while len(par) % 16 != 0:
        par += b'\x00'
    return par


def en_aes_cbc(data, key, iv):
    cipher = AES.new(add_16(key), AES.MODE_CBC, add_16(iv))
    bs = AES.block_size
    pad = lambda s: s + (bs - len(s) % bs) * chr(bs - len(s) % bs)
    return str(base64.b64encode(cipher.encrypt(pad(data).encode("utf-8"))),
               encoding="utf-8")


def en_rsa(text, pubKey, modulus):
    text = text[::-1]
    rs = int(codecs.encode(text.encode('utf-8'), 'hex_codec'), 16)**int(
        pubKey, 16) % int(modulus, 16)
    return format(rs, 'x').zfill(256)


def get_enc(music_id, en_text):
    key = ""
    for i in range(16):
        key += random.choice(
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    params = en_aes_cbc(en_text, "0CoJUm6Qyw8W8jud", "0102030405060708")
    params = en_aes_cbc(params, key, "0102030405060708")
    p = "010001"
    pk = "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7"
    encSecKey = en_rsa(key, p, pk)
    return params, encSecKey


def get_user_agent():
    user_agent_list = [
        'Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0; WOW64; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 1.0.3705; .NET CLR 1.1.4322)',
        'Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Win64; x64; Trident/5.0; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 2.0.50727; Media Center PC 6.0)',
        'Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN) AppleWebKit/523.15 (KHTML, like Gecko, Safari/419.3) Arora/0.3 (Change: 287 c9dfb30)',
        'Mozilla/4.0 (compatible; MSIE 7.0b; Windows NT 5.2; .NET CLR 1.1.4322; .NET CLR 2.0.50727; InfoPath.2; .NET CLR 3.0.04506.30)',
        'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.2pre) Gecko/20070215 K-Ninja/2.1.1',
        'Mozilla/5.0 (X11; Linux i686) AppleWebKit/535.7 (KHTML, like Gecko) Ubuntu/11.04 Chromium/16.0.912.77 Chrome/16.0.912.77 Safari/535.7',
        'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36',
        'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:30.0) Gecko/20100101 Firefox/30.0',
        'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36',
        'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14',
        'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.66 Safari/537.36',
        'Mozilla/5.0 (Windows; U; Windows NT 5.1; it; rv:1.8.1.11) Gecko/20071127 Firefox/2.0.0.11',
        'Opera/9.25 (Windows NT 5.1; U; en)',
        'Mozilla/5.0 (X11; U; Linux; en-US) AppleWebKit/527+ (KHTML, like Gecko, Safari/419.3) Arora/0.6',
        'Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:10.0) Gecko/20100101 Firefox/10.0 Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:84.0) Gecko/20100101 Firefox/84.0',
        'Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.2; Win64; x64; Trident/6.0)',
        'Lynx/2.8.5rel.1 libwww-FM/2.14 SSL-MM/1.4.1 GNUTLS/1.2.9',
        'Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9) Gecko/20080705 Firefox/3.0 Kapiko/3.0',
        'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322; .NET CLR 2.0.50727)',
        'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.153 Safari/537.36',
        'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.8.0.12) Gecko/20070731 Ubuntu/dapper-security Firefox/1.5.0.12',
        'Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Kubuntu)',
        'Mozilla/5.0 (X11; Linux i686; U;) Gecko/20070322 Kazehakase/0.4.5'
    ]
    user_agent = random.choice(user_agent_list)
    return user_agent


my_headers = {
    "User-Agent":
    get_user_agent(),
    'Host':
    'music.163.com',
    'Connection':
    'keep-alive',
    'Accept':
    '*/*',
    'Origin':
    'https://music.163.com',
    'Sec-Fetch-Mode':
    'cors',
    'Sec-Fetch-Dest':
    'empty',
    "referer":
    "https://music.163.com/",
    'Cookie':
    '_iuqxldmzr_=32; _ntes_nnid=c95cb6f082d999fd1fc1a4e51055a8f4,1608031566736; _ntes_nuid=c95cb6f082d999fd1fc1a4e51055a8f4; NMTID=00OjNCfF_IZKxcBa06ji6rGifEWAQkAAAF2ZiZ8WQ; WM_TID=9gCiV%2FNWt3JEAUFBEFI%2BOXx4SHxrqIjN; UM_distinctid=176a7e94c7b818-05d60537aea27a-3d133356-1fa400-176a7e94c7c5de; _antanalysis_s_id=1610353627583; NTES_hp_textlink1=old; JSESSIONID-WYYY=lt5%2F8s%2FXsuXCdMGROH3s7HThNf%5CPy6EK%2FsOdI5GUVHVa1BBBdomXrjFf6t4dixM%5CMPxABpG%5CsYojjz%5CIedgq%2Fp8FIq2JdGpofjwRUII%2BFMPrnnYtMrg0uAA%2B6CTs%2BbhtHKJVoDjuEECxwOyx%2FxMeX0MS%5CADw%2B8HFQBsztB%5CkeXaMQ6lW%3A1610454523379; WEVNSM=1.0.0; WNMCID=psrzsp.1610452723990.01.0; WM_NI=HT%2FDFVAV3loO%2BLXB8FNiJ225A2fxUl9KHKG1VhIkE5wKEfIpPB4LKmkm4CniH3RVwRA34uTXD6fHgF91fvNiChzm29cya4KSqe2fqqiF03MHiBgrxV1TVEsjpZ91UC82Nm4%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6eed9d660b5e7fa87f848ab8e8aa6c45e939a9bbbb65c90adf8adec3cfcf18185ec2af0fea7c3b92a8c8ce1a5c55e838afd8dee45e99498a3bb4e8eb786d3b13f83eeaa99d868fb9588acc63b96b8878cc83fb5958b87cc7c949efcadca67a9b3fca4ed638ced9eb7f65a83edfc96d75488eaaaa9e64efbefaa97cd6381b8b68eb133a1a7afd5ca59b3bbfe87f47bab9a00d4d044ab9ea993fb5ef38c9aa6f262b486f7d2d849fcee828eb737e2a3; playerid=16664166'
}


def get_music_detail(music_id):
    my_headers["referer"] = "https://music.163.com/song?id=" + music_id
    en_text = r'{{"id":"{a}","c":"[{{\"id\":\"{b}\"}}]","csrf_token":""}}'.format(
        a=music_id, b=music_id)
    enc = get_enc(music_id, en_text)
    my_data = {"params": enc[0], "encSecKey": enc[1]}
    music_detail = requests.post(
        "https://music.163.com/weapi/v3/song/detail?csrf_token=",
        headers=my_headers,
        data=my_data,
    )
    music_detail_json = json.loads(music_detail.text)
    music_name = music_detail_json['songs'][0]['name']
    music_author = music_detail_json['songs'][0]['ar'][0]['name']
    return music_name + "-" + music_author


def get_music_url(music_id):
    en_text = r'{{"ids":"[{0}]","level":"standard","encodeType":"aac","csrf_token":""}}'.format(
        music_id)
    enc = get_enc(music_id, en_text)
    my_data = {"params": enc[0], "encSecKey": enc[1]}
    my_headers["referer"] = "https://music.163.com/"
    music_data_response = requests.post(
        "https://music.163.com/weapi/song/enhance/player/url/v1?csrf_token=",
        headers=my_headers,
        data=my_data)
    music_data_json_obj = json.loads(music_data_response.text)
    return music_data_json_obj['data'][0]['url']


def download_music(music_data_url, music_id):
    music_data = requests.get(music_data_url)
    file_name = get_music_detail(music_id) + ".m4a"
    if not os.path.exists("music"):
        os.mkdir("music")
    os.chdir("music")
    with open(file_name, "wb") as f:
        f.write(music_data.content)
    print(file_name + " Down!")


def download_163music(music_url):
    music_id = music_url.split("=")[1]
    music_data_url = get_music_url(music_id)
    download_music(music_data_url, music_id)


if __name__ == '__main__':
    url = input("""请输入网易云音乐地址
例如 https://music.163.com/#/song?id=1807537867
如果要退出，请输入 q
""")
    while url != "q":
        download_163music(url)
        url = input("请输入下一个链接或q：")
    else:
        print("程序退出!")
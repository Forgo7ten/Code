# coding=utf-8
# ---------------------------------------------
# FileName music163HotComments.py
# Description 爬取网易云音乐热门评论
# Author Forgo7ten
# Version 1.0.0
# Date 2021/1/11

import requests
import json
from Crypto.Cipher import AES
import base64
import codecs
import random


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


def get_enc(music_id):
    key = ""
    for i in range(16):
        key += random.choice(
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")

    en_text = '{{"rid":"R_SO_4_{a}","threadId":"R_SO_4_{b}","pageNo":"1","pageSize":"20","cursor":"-1","offset":"0","orderType":"1","csrf_token":""}}'.format(
        a=music_id, b=music_id)
    params = en_aes_cbc(en_text, "0CoJUm6Qyw8W8jud", "0102030405060708")
    params = en_aes_cbc(params, key, "0102030405060708")
    p = "010001"
    pk = "00e0b509f6259df8642dbc35662901477df22677ec152b5ff68ace615bb7b725152b3ab17a876aea8a5aa76d2e417629ec4ee341f56135fccf695280104e0312ecbda92557c93870114af6c9d05c4f7f0c3685b7a46bee255932575cce10b424d813cfe4875d3e82047b97ddef52741d546b8e289dc6935b3ece0462db0a22b8e7"
    encSecKey = en_rsa(key, p, pk)
    return params, encSecKey


def get_hot_comments(music_url):
    my_headers = {
        "User-Agent":
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36",
        "referer": music_url
    }
    music_id = music_url.split("=")[1]
    enc = get_enc(music_id)
    my_data = {"params": enc[0], "encSecKey": enc[1]}
    res = requests.post(
        "https://music.163.com/weapi/comment/resource/comments/get?csrf_token=",
        headers=my_headers,
        data=my_data)
    comments_json_obj = json.loads(res.text)
    hotComments = comments_json_obj['data']['hotComments']
    file_name = "music163HotComments_" + music_id + ".txt"
    with open(file_name, "w", encoding="utf-8") as f:
        f.write(music_url + "\n\n")
        for i in range(len(hotComments)):
            f.write(str(i + 1) + ", " + hotComments[i]['content'] + '\n')
    print(file_name + " Down!")


if __name__ == '__main__':
    url = input("""请输入网易云音乐地址
例如 https://music.163.com/#/song?id=1807537867
如果要退出，请输入 q
""")
    while url != "q":
        get_hot_comments(url)
        url = input("请输入下一个链接或q：")
    else:
        print("程序退出!")
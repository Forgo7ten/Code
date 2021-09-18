import execjs
import json
import random
import requests
import time
from lxml import etree


class Login:

    def __init__(self, yhm, password, scokkie):
        self.path = "http://jwgl.hebtu.edu.cn"
        self.modulus = ""
        self.exponent = ""
        self.csrftoken = ""
        # 用户名和密码
        self.yhm = yhm
        self.password = password
        self.mm = ""
        self.s = scokkie
        self.login_url = self.path + "/xtgl/login_slogin.html"

    @staticmethod
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

    def get_csrftoken(self):
        my_header = {
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Host': 'jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Upgrade-Insecure-Requests': '1',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36'
        }
        response = self.s.get(self.login_url, headers=my_header)
        re_html = response.text
        selector = etree.HTML(re_html)
        csrftoken = selector.xpath('//*[@id="csrftoken"]//@value')[0]
        return csrftoken

    def enpwd(self):
        with open("./src/js/login_enpwd.js", 'r') as f:
            js_code = f.read()
        jsexc = execjs.compile(js_code)
        self.mm = jsexc.call('start', self.modulus, self.exponent, self.password)

    def login(self):
        my_headers = {
            'Accept': '*/*',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Host': 'jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Referer': 'http://jwgl.hebtu.edu.cn/xtgl/index_initMenu.html',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
        }
        login_url = self.login_url + "?time=" + str(int(time.time() * 1000))

        my_data = {
            'csrftoken': self.csrftoken,
            'language': 'zh_CN',
            'yhm': self.yhm,
            'mm': self.mm,
            'mm': self.mm
        }
        result = self.s.post(login_url, headers=my_headers, data=my_data)
        return result.status_code

    def start(self):
        print("[{0}] 准备登录....".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
        self.get_csrftoken()
        self.get_me()
        self.enpwd()
        for i in range(1,11):
            result = self.login()
            if result == 200:
                print('[{0}] 登录成功'.format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
                break
            elif i!=10:
                print("登录失败({0})，准备第{1}次登录".format(result,i+1))
        if result != 200:
            print("登录失败")


    def get_me(self):
        my_headers = {
            'Accept': 'application/json, text/javascript, */*; q=0.01',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Host': 'jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Referer': 'http://jwgl.hebtu.edu.cn/xtgl/login_slogin.html',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
            'X-Requested-With': 'XMLHttpRequest',
        }
        get_me_url = self.path + "/xtgl/login_getPublicKey.html?time=" + str(int(time.time() * 1000))
        rep = self.s.get(get_me_url, headers=my_headers)
        json_obj = json.loads(rep.text)
        self.modulus = json_obj['modulus']
        self.exponent = json_obj['exponent']


if __name__ =='__main__':
    scokkie = requests.session()
    a = Login("2019------", "mm123456", scokkie).start()
import re,time

import requests
from lxml import etree

from course import Course
from login import Login


class Jwgl:
    def __init__(self, yhm, password):
        self.yhm = yhm
        self.password = password
        self.host = 'http://jwgl.hebtu.edu.cn'
        self.scokkie = requests.session()
        self.my_headers = {
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Host': 'jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Referer': 'http://jwgl.hebtu.edu.cn/xtgl/login_slogin.html',
            'Upgrade-Insecure-Requests': '1',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
        }
        self.initMenu_text = ""

    def get_user_info(self):
        ui_rule = re.compile(r"clickMenu[(]'(.*)','([/.\w]+)','.*','.*'[)].*")
        seletor = etree.HTML(self.initMenu_text)
        user_info = seletor.xpath('//*[@id="cdNav"]/ul/li[4]/ul/li[1]/a/@onclick')[0]
        re_result = ui_rule.findall(user_info)
        gnmkdm = re_result[0][0]
        url = re_result[0][1]
        my_data = {
            'gnmkdm': gnmkdm,
            'layout': 'default',
            'su': self.yhm
        }
        user_url = self.host + url + "?gnmkdm=" + my_data['gnmkdm'] + '&layout=default&su=' + my_data['su']
        user_info_headers = self.my_headers.copy()
        user_info_headers['Referer'] = 'http://jwgl.hebtu.edu.cn/xtgl/index_initMenu.html'
        user_info_re = self.scokkie.get(user_url, headers=user_info_headers)
        if user_info_re.status_code != 200:
            print("[{0}] 获取信息失败".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
            return -1
        else:
            print("[{0}] 获取信息成功".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
        info_rule = re.compile(r'<p class="form-control-static">(.*)</p>')
        info = info_rule.findall(user_info_re.text)
        yhm = info[0]
        name = info[1]
        print("学号：{0}  姓名：{1}".format(yhm, name))

    def get_initMenu(self):
        initMenu_headers = self.my_headers.copy()
        initMenu = self.scokkie.get('http://jwgl.hebtu.edu.cn/xtgl/index_initMenu.html', headers=initMenu_headers)
        self.initMenu_text = initMenu.text

    def cource(self):
        qnmkdm = 'N253512'
        su = '2019------'
        c = Course(qnmkdm, su, "xs", self.scokkie).start()

    def start(self):
        a = Login(self.yhm, self.password, self.scokkie).start()
        self.get_initMenu()
        self.get_user_info()
        self.cource()


if __name__ == '__main__':
    s = Jwgl("2019------", "mm123456").start()

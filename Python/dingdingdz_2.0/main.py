# coding=utf-8
# ---------------------------------------------
# FileName dingdingdz_2.0.py
# Description 钉钉直播点赞
# Author Forgo7ten
# Version 2.0
# Date 2021/3/4

from PySide2.QtWidgets import QApplication, QLabel
from PySide2.QtUiTools import QUiLoader
import random
import requests
from time import sleep
from threading import Thread, Event
from PySide2.QtCore import Signal, QObject


class Dddz:
    def __init__(self, uuid, count):
        # 忽略报错
        requests.packages.urllib3.disable_warnings()
        self.hostUrl = "https://lv.dingtalk.com/interaction/createLike"
        self.param = {
            'uuid': uuid,
            'count': count
        }
        self.my_headers = {
            'authority': 'lv.dingtalk.com',
            'method': 'GET',
            'scheme': 'https',
            'Host': 'lv.dingtalk.com',
            'accept-encoding': 'gzip, deflate, br',
            'Pragma': 'no-cache',
            'Cache-Control': 'no-cache',
            'Upgrade-Insecure-Requests': '1',
            'User-Agent':
                'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.111 Safari/537.36',
            'Accept':
                'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'Sec-Fetch-Site': 'none',
            'Sec-Fetch-Mode': 'navigate',
            'Sec-Fetch-User': '?1',
            'Sec-Fetch-Dest': 'document',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6'
        }

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

    def start(self):
        self.my_headers['User-Agent'] = self.get_user_agent()
        # 10秒钟超时 关闭证书认证
        html = requests.get(self.hostUrl, params=self.param, headers=self.my_headers, timeout=10, verify=False)
        return html.content.decode()


class MySignals(QObject):
    # 定义一个信号
    textPrint = Signal(QLabel, str)


class DddzWd:
    def __init__(self):
        # 加载UI设置
        self.ui = QUiLoader().load('./ui/dingding.ui')
        # 将【点击刷赞】按钮与 按钮事件绑定
        self.ui.startButton.clicked.connect(self.startDz)
        self.ui.stopButton.clicked.connect(self.stopDz)
        # 设置线程的事件对象，方便控制线程退出
        self.event = Event()
        # 设置标签Qlabel 超链接可点击
        self.ui.labelUrl.setOpenExternalLinks(True)
        # 设置子线程信号
        self.ms = MySignals()
        # 子线程信号与 方法 绑定
        self.ms.textPrint.connect(self.printG)

    # 信号绑定 让子线程可以修改Qlabel
    def printG(self, qlabel, text):
        qlabel.setText(text)

    def stopDz(self):
        self.event.clear()

    # 与【开始刷赞】按钮绑定的方法
    def startDz(self):
        self.event.set()
        # 保存一下作为输出的标签
        printf = self.ui.tipsPrint
        printf.setText("")
        # 获取输入框中的uuid
        uuid = self.ui.inputUuid.text()
        if uuid == "":
            printf.setText("uuid不能为空")
            return -1
        count = self.ui.inputCount.text()
        try:
            tcount = int(count)
            if tcount < 1:
                printf.setText("点赞数范围错误")
        except ValueError:
            printf.setText("点赞数格式错误")
            return -1
        repeatNum = 1
        # 检查单选框repeat是否被选中
        repeatFlag = self.ui.repeat.isChecked()
        if repeatFlag == True:
            try:
                repeatNum = int(self.ui.repeatNum.text())
            except ValueError:
                printf.setText("重复次数错误")
                return -1
        try:
            sleeps = int(self.ui.repeatIntval.text())
        except ValueError:
            printf.setText("重复间隔错误")
            return -1

        # 子线程运行函数
        def childDing():
            # 禁用按钮，防止用户再次点击
            self.ui.startButton.setEnabled(False)
            # 初始化一个Dddz类对象
            dingding = Dddz(uuid, count)
            # 循环重复次数
            for i in range(repeatNum):
                sstr = ""
                if repeatFlag == True:
                    sstr = "第" + str(i + 1) + "次 "
                    sleep(sleeps)
                if not self.event.isSet():
                    # 启用 按钮
                    self.ui.startButton.setEnabled(True)
                    return -1
                tip = dingding.start()
                text = sstr + tip
                if i != repeatNum - 1:
                    self.ms.textPrint.emit(printf, "")
                self.ms.textPrint.emit(printf, text)
            # 启用 按钮
            self.ui.startButton.setEnabled(True)

        # 申请线程对象
        tchild = Thread(target=childDing,
                        daemon=True  # 设置子线程为daemon线程，让子线程随主线程退出而退出
                        )
        # 启动线程
        tchild.start()


if __name__ == '__main__':
    # 开启事件监听对象
    app = QApplication([])
    # 定义窗口
    dz = DddzWd()
    # 展示窗口
    dz.ui.show()
    # 退出
    app.exec_()

import json
import time

import requests
from lxml import etree

from login import Login


class Course:
    def __init__(self, gnmkdm, su, jsdm, scokkie):
        self.host_index = "http://jwgl.hebtu.edu.cn/xsxk/zzxkyzb_cxZzxkYzbIndex.html?gnmkdm={0}&layout=default&su={1}".format(
            gnmkdm, su)
        self.host_PartDispaly = 'http://jwgl.hebtu.edu.cn/xsxk/zzxkyzb_cxZzxkYzbPartDisplay.html?gnmkdm={0}&su={1}'.format(
            gnmkdm, su)
        self.host_course = 'http://jwgl.hebtu.edu.cn/xsxk/zzxkyzbjk_cxJxbWithKchZzxkYzb.html?gnmkdm={0}&su={1}'.format(
            gnmkdm, su)
        self.host_killc = 'http://jwgl.hebtu.edu.cn/xsxk/zzxkyzbjk_xkBcZyZzxkYzb.html?gnmkdm={0}&su={1}'.format(
            gnmkdm, su)
        self.su = su
        self.scokkie = scokkie
        self.jsdm = jsdm
        self.my_headers = {
            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Host': 'jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Referer': 'http://jwgl.hebtu.edu.cn/xtgl/index_initMenu.html?jsdm=xs&_t=1615433086120',
            'Upgrade-Insecure-Requests': '1',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
        }
        self.data = {}
        self.page_res = ""
        self.courses_list = []
        self.xkkz_id = ""
        self.update_flag = False

    def init_data(self):
        selector = etree.HTML(self.page_res)
        self.xkkz_id = selector.xpath('//*[@id="firstXkkzId"]/@value')[0]
        self.data = {
            'njdm_id_list%5B0%5D': self.su[:4],
            'rwlx': '1',  # selector.xpath('//*[@id="rwlx"]/@value'),
            'xkly': '1',  # selector.xpath('//*[@id="rwlx"]/@value'),
            'bklx_id': '0',  # selector.xpath('//*[@id="bklx_id"]/@value'),
            'xqh_id': selector.xpath('//*[@id="xqh_id"]/@value')[0],
            'jg_id': selector.xpath('//*[@id="jg_id_1"]//@value')[0],
            'zyh_id': selector.xpath('//*[@id="zyh_id"]//@value')[0],
            'zyfx_id': selector.xpath('//*[@id="zyfx_id"]/@value')[0],
            'njdm_id': selector.xpath('//*[@id="njdm_id"]/@value')[0],
            'bh_id': selector.xpath('//*[@id="bh_id"]/@value')[0],
            'xbm': selector.xpath('//*[@id="xbm"]/@value')[0],
            'xslbdm': selector.xpath('//*[@id="xslbdm"]/@value')[0],
            'ccdm': selector.xpath('//*[@id="ccdm"]/@value')[0],
            'xsbj': selector.xpath('//*[@id="xsbj"]/@value')[0],
            'sfkknj': '0',  # selector.xpath('//*[@id="sfkknj"]/@value'),
            'sfkkzy': '0',  # selector.xpath('//*[@id="sfkkzy"]/@value'),
            'sfznkx': '0',  # selector.xpath('//*[@id="sfznkx"]/@value'),
            'zdkxms': '0',  # selector.xpath('//*[@id="zdkxms"]/@value'),
            'sfkxq': '0',  # selector.xpath('//*[@id="sfkxq"]/@value'),
            'sfkcfx': '0',  # selector.xpath('//*[@id="sfkcfx"]/@value'),
            'kkbk': '0',  # selector.xpath('//*[@id="kkbk"]/@value'),
            'kkbkdj': '0',  # selector.xpath('//*[@id="kkbkdj"]/@value'),
            'sfkgbcx': '0',  # selector.xpath('//*[@id="sfkgbcx"]/@value'),
            'sfrxtgkcxd': '0',  # selector.xpath('//*[@id="sfrxtgkcxd"]/@value'),
            'tykczgxdcs': '0',  # selector.xpath('//*[@id="tykczgxdcs"]/@value'),
            'xkxnm': selector.xpath('//*[@id="xkxnm"]/@value')[0],
            'xkxqm': selector.xpath('//*[@id="xkxqm"]/@value')[0],
            'kklxdm': '01',  # selector.xpath('//*[@id="kklxdm"]/@value')[0],
            'rlkz': '0',  # selector.xpath('//*[@id="rlkz"]/@value'),
            'xkzgbj': '0',  # selector.xpath('//*[@id="xkzgbj"]/@value'),
            'kspage': '0',
            'jspage': '10',
            'jxbzb': selector.xpath('//*[@id="jxbzb"]/@value')[0],
        }

    def get_course_page(self):
        page_headers = self.my_headers.copy()
        t = int(time.time() * 1000)
        page_headers['Referer'] = "http://jwgl.hebtu.edu.cn/xtgl/index_initMenu.html?jsdm={0}&_t={1}".format(self.jsdm,
                                                                                                             t)
        page_res = self.scokkie.get(self.host_index, headers=page_headers)
        self.page_res = page_res.text

        self.init_data()

    def start(self):
        self.get_course_page()
        if self.get_courses() == -1:
            print("获得课程列表失败")
        print("[{0}] 已获得课程列表".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
        if self.get_course_info() == -1:
            print("获取课程详细信息失败")
        print("[{0}] 获取课程详细信息成功".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
        print("你当前有{0}门课待选".format(len(self.courses_list)))
        self.print_courses_info()
        self.start_kill()

    def get_data(self, dic):
        ss = ""
        for key, value in dic.items():
            ss += key + '=' + value + '&'
        data = ss[:-1]
        return data

    def get_courses(self):
        display_headers = {
            'Accept': 'application/json, text/javascript, */*; q=0.01',
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',
            'Cache-Control': 'no-cache',
            'Content-Length': '363',
            'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8',
            'Host': 'jwgl.hebtu.edu.cn',
            'Origin': 'http://jwgl.hebtu.edu.cn',
            'Pragma': 'no-cache',
            'Proxy-Connection': 'keep-alive',
            'Referer': self.host_index,
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
            'X-Requested-With': 'XMLHttpRequest',
        }
        data = self.get_data(self.data)
        res = self.scokkie.post(self.host_PartDispaly, headers=display_headers, data=data)
        if res.status_code != 200:
            return -1
        json_obj = json.loads(res.text)
        coujs_list = json_obj['tmpList']
        for i in range(len(coujs_list)):
            temp_dic = {
                "教学班": coujs_list[i]['jxbmc'],
                "上课教师": "",
                "已选": coujs_list[i]['yxzrs'],
                "容量": "",
                'kch_id': coujs_list[i]['kch_id'],
                "jxb_id": coujs_list[i]["jxb_id"],
                'kch': coujs_list[i]['kch'],
                'kcmc': coujs_list[i]['kcmc'],
                'xf': coujs_list[i]['xf'],
            }
            self.courses_list.append(temp_dic)
        return 0

    def print_courses_info(self):
        if self.update_flag:
            self.courses_list = []
            if self.get_courses()+self.get_course_info() ==0:
                print("[{0}] 更新课程信息成功".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
            else:
                print("[{0}] 更新课程信息失败".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())))
        else:
            self.update_flag = True
        i = 1
        for dic in self.courses_list:
            k = 0
            stemp = "【" + str(i) + "】 "
            i += 1
            for key, value in dic.items():
                stemp += key + ":" + value + " "
                k += 1
                if k > 3:
                    break
            print(stemp)

    def get_course_info(self):
        ci_headers = {
            'Host': 'jwgl.hebtu.edu.cn',
            'Proxy-Connection': 'keep-alive',
            'Content-Length': '390',
            'Accept': 'application/json,text/javascript,*/*;q=0.01',
            'X-Requested-With': 'XMLHttpRequest',
            'User-Agent': 'Mozilla/5.0(WindowsNT10.0;Win64;x64)AppleWebKit/537.36(KHTML,likeGecko)Chrome/89.0.4389.82Safari/537.36',
            'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8',
            'Origin': 'http://jwgl.hebtu.edu.cn',
            'Referer': self.host_index,
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6'
        }
        selector = etree.HTML(self.page_res)
        tdata = {
            'njdm_id_list%5B0%5D': self.su[:4],
            'rwlx': '1',  # selector.xpath('//*[@id="rwlx"]/@value'),
            'xkly': '1',  # selector.xpath('//*[@id="rwlx"]/@value'),
            'bklx_id': '0',  # selector.xpath('//*[@id="bklx_id"]/@value'),
            'xqh_id': selector.xpath('//*[@id="xqh_id"]/@value')[0],
            'jg_id': selector.xpath('//*[@id="jg_id_1"]//@value')[0],
            'zyh_id': selector.xpath('//*[@id="zyh_id"]//@value')[0],
            'zyfx_id': selector.xpath('//*[@id="zyfx_id"]/@value')[0],
            'njdm_id': selector.xpath('//*[@id="njdm_id"]/@value')[0],
            'bh_id': selector.xpath('//*[@id="bh_id"]/@value')[0],
            'xbm': selector.xpath('//*[@id="xbm"]/@value')[0],
            'xslbdm': selector.xpath('//*[@id="xslbdm"]/@value')[0],
            'ccdm': selector.xpath('//*[@id="ccdm"]/@value')[0],
            'xsbj': selector.xpath('//*[@id="xsbj"]/@value')[0],
            'sfkknj': '0',  # selector.xpath('//*[@id="sfkknj"]/@value'),
            'sfkkzy': '0',  # selector.xpath('//*[@id="sfkkzy"]/@value'),
            'sfznkx': '0',  # selector.xpath('//*[@id="sfznkx"]/@value'),
            'zdkxms': '0',  # selector.xpath('//*[@id="zdkxms"]/@value'),
            'sfkxq': '0',  # selector.xpath('//*[@id="sfkxq"]/@value'),
            'sfkcfx': '0',  # selector.xpath('//*[@id="sfkcfx"]/@value'),
            'kkbk': '0',  # selector.xpath('//*[@id="kkbk"]/@value'),
            'kkbkdj': '0',  # selector.xpath('//*[@id="kkbkdj"]/@value'),
            'xkxnm': selector.xpath('//*[@id="xkxnm"]/@value')[0],
            'xkxqm': selector.xpath('//*[@id="xkxqm"]/@value')[0],
            'rlkz': '0',  # selector.xpath('//*[@id="rlkz"]/@value'),
            'kklxdm': '01',
            'kch_id': '',
            'xkkz_id': self.xkkz_id,
            'cxbj': '0',
            'fxbj': '0'
        }
        for dic in self.courses_list:
            tdata['kch_id'] = dic['kch_id']
            data = self.get_data(tdata)
            res = self.scokkie.post(self.host_course, headers=ci_headers, data=data)
            if res.status_code != 200:
                print("获取课程详细信息失败")
                return -1
            js_obj = json.loads(res.text)
            dic['容量'] = js_obj[0]['jxbrl']
            dic['do_jxb_id'] = js_obj[0]['do_jxb_id']
            dic['上课教师'] = js_obj[0]['jsxx'].split('/')[1]
            self.get_course_page()
        return 0

    def start_kill(self):
        num =2
        #num = int(input("[{0}] 输入你要抢课的编号：".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))))
        selector = etree.HTML(self.page_res)
        header = {
            'Host': 'jwgl.hebtu.edu.cn',
            'Proxy-Connection': 'keep-alive',
            'Content-Length': '544',
            'Pragma': 'no-cache',
            'Cache-Control': 'no-cache',
            'Accept': 'application/json, text/javascript, */*; q=0.01',
            'X-Requested-With': 'XMLHttpRequest',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36',
            'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8',
            'Origin': 'http://jwgl.hebtu.edu.cn',
            'Referer': self.host_index,
            'Accept-Language': 'zh,zh-TW;q=0.9,en-US;q=0.8,en;q=0.7,zh-CN;q=0.6',

        }
        data = {
            'jxb_ids': self.courses_list[num - 1]['do_jxb_id'],  # json
            'kch_id': self.courses_list[num - 1]['kch_id'],  # json
            'kcmc': "({0}){1} - {2} 学分".format(self.courses_list[num - 1]['kch'], self.courses_list[num - 1]['kcmc'],
                                               self.courses_list[num - 1]['xf']),
            'rwlx': '1',  # selector.xpath('//*[@id="rwlx"]/@value'),
            'rlkz': '0',  # selector.xpath('//*[@id="rlkz"]/@value'),
            'rlzlkz': '1',  # selector.xpath('//*[@id="rlzlkz"]/@value'),
            'sxbj': 1,  # rlzlkz为1
            'xxkbj': '0',  # selector.xpath('//*[@id="xxkbj"]/@value'),
            'qz': '0',
            'cxbj': '0',
            'xkkz_id': self.xkkz_id,
            'njdm_id': selector.xpath('//*[@id="njdm_id"]/@value')[0],
            'zyh_id': selector.xpath('//*[@id="zyh_id"]//@value')[0],
            'kklxdm': '01',  # //*[@id="kklxdm"]
            'xklc': '1',  # selector.xpath('//*[@id="xkxnm"]/@value')[0],
            'xkxnm': selector.xpath('//*[@id="xkxnm"]/@value')[0],
            'xkxqm': selector.xpath('//*[@id="xkxqm"]/@value')[0],

        }
        n = 1
        print("[{0}] 正在第{1}次抢课".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), n))
        result = self.kill_course(data, header)
        n += 1
        while result['flag'] != '1':
            print("[{0}] 正在第{1}次抢课".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), n))
            result = self.kill_course(data, header)
            n += 1
        print("[{0}] {1} 抢课成功".format(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), data['kcmc'].split(" ")[0].split(')')[1]))
        self.print_courses_info()

    def kill_course(self, data, header):
        result = self.scokkie.post(self.host_killc, headers=header, data=data)
        res_jsobj = json.loads(result.text)
        return res_jsobj


if __name__ == '__main__':
    scokkie = requests.session()
    su = '2019------'
    a = Login(su, "mm123456", scokkie).start()
    qnmkdm = 'N253512'

    c = Course(qnmkdm, su, "xs", scokkie).start()

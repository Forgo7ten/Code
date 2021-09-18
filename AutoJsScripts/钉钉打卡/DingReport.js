/*
 * @FileName DingReport.js
 * @Description 钉钉自用晨午报
 * @Version 1.0.0
 * @Author Forgo7ten
 * @Date 2021/1/10
 */

main();

function main() {
    try{
        auto();
    }catch(error){
        toast("请手动开启无障碍服务并授权\n请在授权后重新启动程序\n程序即将退出");
        sleep(2000);
        exit();
    }
    //Ding("晨报");
    Ding("午报");
}

function Ding(ha) {
    toast("程序已经开始运行，请不要进行其他操作");
    launchApp("钉钉");
    dingHome();
    toast("已进入搜索界面");
    searchScreen();
    reportWrite();

    function dingHome() {
        var searchArea = desc("搜索").text("搜索");
        myWait(searchArea,14,"没有来到钉钉主界面，程序即将退出");
        toast("已来到钉钉主界面");
        sleep(1000);
        searchArea.findOne().click();
    }

    function searchScreen() {
        var search = text("搜索").id("search_src_text");
        myWait(search, 8, "搜索框没有找到，程序即将退出");
        search.findOne().setText(ha);
        var searchReportStr = "学生" + ha + "(学生处)";
        var searchReport = text(searchReportStr);
        var time_num = 0;
        var times = 0;
        while (!searchReport.exists()) {
            sleep(500);
            time_num += 1;
            if (times > 3) {
                toast("搜索等待时间太长，程序即将退出");
                sleep(1000);
                exit();
            }
            if (time_num > 3) {
                times++;
                time_num = 0;
                search.findOne().setText("未找到，重新搜索");
                search.findOne().setText(ha);
            }
        }
        searchReport.findOne().parent().parent().click();
        var reportTitle = text(searchReportStr);
        myWait(reportTitle, 10, "没有进入日报界面，程序即将退出");
    }

    function reportWrite() {
        sleep(4000);
        toast("已进入日报填写界面");
        var boxList = className("android.webkit.WebView");
        myWait(boxList, 10, "没有找到相应控件，程序即将退出");
        boxList = boxList.findOne().child(1).child(0).child(0).children();
        var aList = [1, 2, 4, 5, 6];
        for (var i = 0; i < aList.length; i++) {
            var j = aList[i];
            var target = boxList[j].child(0);
            target.click();
            sleep(1000);
            fill(j, target);
        }
        sleep(1000);
        var submitBut = text("提交日志").findOne();
        submitBut.click();
        toast("已经提交，程序准备退出");
    }

    function fill(j, target) {
        switch (j) {
            case 1:
                text("是").findOne().click();
                break;
            case 2:
                var aBox = target.child(0).child(1);
                aBox.setText("36." + random(0, 7));
                break;
            case 4:
                text("无").findOne().click();
                break;
            case 5:
            case 6:
                text("否").findOne().click();
                break;
        }
        sleep(1000);
    }

}

function myWait(uiobj, maxNum, tips) {
    var timeNum = 0;
    while (!uiobj.exists()) {
        sleep(500);
        if (timeNum > maxNum) {
            toast(tips);
            sleep(1000);
            exit();
        }
        timeNum += 1;
    }
}
//
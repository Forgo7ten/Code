// 正在写
CdLearn();
function CdLearn() {
    var wechatFind = desc("搜索");
    if (!wechatFind.exists()) {
        
        return -1;
    }
    wechatFind.findOnce().click();
    sleep(2000);
    setText("河北共青团");
}
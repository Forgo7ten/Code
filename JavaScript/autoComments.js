/*
 * @FileName autoComments.js
 * @Description 河北师范大学内网学生师德师风评教自动评价(方正教务系统)
 * @Version 1.0.0
 * @Author Forgo7ten
 * @Date 2020/12/20
 */

function sleep(time) {
    return new Promise((resolve) => setTimeout(resolve, time));
}

async function autoComments() {
    console.log("当前处于第" + currentPage + "页");
    var list = document.getElementsByClassName("ui-widget-content jqgrow ui-row-ltr");
    for (var i = 0; i < list.length; i++) {
        await checkPage();
        async function checkPage() { // 检查当前页，因为如果不是第一页的话，提交后会刷新到第一页
            currentP = nextPage.parentElement.children[3].children[0].value;
            if (currentPage != currentP) {
                nextPage.click();
                await sleep(2000);
            }
        }
        if (list.length == 0) {
            console.log("没有获取到课程列表，退出");
            return -1;
        }
        if (list[i].children[7].innerHTML == "提交") {
            console.log("【" + list[i].children[8].innerHTML + "】评价已经提交，跳过该课程");
            await sleep(100);
            continue; // 如果已经评价过，跳过评价
        }
        // 依次进入每个课程的评价
        list[i].click();
        await sleep(500);
        /*
         * 由于方正系统限制不能全部选择【好】选项，采用先用好覆盖len次，然后用较好1次
         * 以此来达到 len-1 个好，一个较好的目的；
         * 不会改，先这样吧
         */
        await good();

        async function good() {
            var good = document.getElementsByClassName("radio-inline input-xspj input-xspj-1");
            for (var j = 0; j < good.length; j++) {
                var but = good[j].firstElementChild.firstElementChild;
                but.click();
                await sleep(100);
            }
        }
        await sleep(200);
        await better();
        async function better() {
            var better = document.getElementsByClassName("radio-inline input-xspj input-xspj-2");
            betterLen = better.length;
            for (var j = betterLen - 1; j >= betterLen - 1; j--) { // 感觉最后一个选项对老师影响较小，将其改成【较好】
                var but = better[j].firstElementChild.firstElementChild;
                but.click();
                await sleep(100);
            }
        }
        await sleep(200);
        // 填写评语：老师很棒
        var comment = document.getElementById("B5D9189C7D5EAF2BE053D901A8C04891_py");
        await keyboardInput(comment, "老师很棒！！！");

        function keyboardInput(dom, st) {
            var evt = new InputEvent('input', {
                inputType: 'insertText',
                data: st,
                dataTransfer: null,
                isComposing: false
            });
            dom.value = st;
            dom.dispatchEvent(evt);
        };
        await sleep(500);
        // 点击按钮提交评价
        var submit_button = document.getElementById("btn_xspj_tj");
        submit_button.click();
        await sleep(2000);
        // 提示信息：提交成功 点击确定按钮
        var a = document.getElementById("btn_ok");
        a.click();
        await sleep(1000);
        console.log("【" + list[i].children[8].innerHTML + "】评价已经提交");
    }
}

async function start() {
    // 获取下一页按钮控件
    nextPage = document.getElementById("next_pager");
    // 获取总页数
    var pageNum = nextPage.parentElement.children[3].children[1].innerHTML;
    while (true) {
        // 获取当前页码
        currentPage = nextPage.parentElement.children[3].children[0].value;
        await autoComments();
        // 如果最后一页执行完毕，退出程序
        if (currentPage == pageNum) {
            console.log("已执行完最后一页，退出程序。");
            break;
        }
        nextPage.click();
        console.log("当前页已评价完，进入下一页");
        await sleep(2000);
    }
}

start();






/*************************************************************
- js sleep的实现
- 由于直接修改input文本框的value值无法触发相应的输入事件 参考 http://www.fly63.com/article/detial/5935
- 选项直接修改checked值无法触发相应事件

>1.$().prop("checked",true)
使用prop方法并搭配checked属性实现js点击radio
prop方法适用于set和get值为true/false的属性的方法如checked selected readyonly
而且不需要对未点击的radio做处理 很方便
2.$().click()
这个方法就比较干脆，直接出发点击事件，不会出现问题

参考 https://blog.csdn.net/u014267351/article/details/50333425

- 





*************************************************************/
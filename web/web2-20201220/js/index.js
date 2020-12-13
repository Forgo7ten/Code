// 看板娘
L2Dwidget.init({
    "display": {
        "superSample": 2,
        "width": 200,
        "height": 400,
        "position": "left",
        "hOffset": 0,
        "vOffset": 0
    }
});
// 回到顶部
var turnToTop = {};

turnToTop.init = function (e, s) {
    turnToTop.gogogo(e);
    turnToTop.speed = s;
};

turnToTop.gogogo = function (e) {
    window.onscroll = function () {
        if (turnToTop.docEleTop() > 0) {
            e.style.display = "block";
        } else {
            e.style.display = "none";
        }
    };

    e.onclick = function () {
        turnToTop.docEleTop();
        var timer = setInterval(function () {
            if (parseInt(turnToTop.docEleTop()) > 0) {
                document.documentElement.scrollTop = document.body.scrollTop = parseInt(turnToTop.docEleTop()) - turnToTop.speed;
            } else {
                clearInterval(timer);
            }
        }, 20)
    };
};
turnToTop.docEleTop = function () {
    return document.documentElement.scrollTop || document.body.scrollTop;
};


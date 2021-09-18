/*
 * @FileName LikeQQCard.js
 * @Description QQ获赞界面回赞
 * @Version 1.0.0
 * @Author Forgo7ten
 * @Date 2020/12/
 */
LikeQQCard();

function LikeQQCard(){

    // var likeButton = desc("赞").findOnce();
    // log(likeButton.desc());
    // log(likeButton.click());

    var showMore = text("显示更多").id("f0v").findOnce();
    log(showMore.parent().click());

    var endLikeFlag = textStartsWith("暂无更多").exists();
    if(endLikeFlag){
        toast("点赞任务已完成，准备退出");
        sleep(random(2000,3000));
        return 0;
    }
}

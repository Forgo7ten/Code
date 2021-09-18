/*
 * @FileName LikeWechatCampaign.js
 * @Description 微信运动自动点赞
 * @Version 1.0.0
 * @Author Forgo7ten
 * @Date 2020/12/10
 */

LikeWechatCampaign();

function LikeWechatCampaign() {
    HasRankingList();

    function HasRankingList() {
        var rankingList = text("排行榜").id("text1");
        if (!rankingList.exists()) {
            toast("当前不是微信运动排行榜界面\n请打开微信运动排行榜界面");
            sleep(random(1000, 2000));
            var openRankingList = id("dn2"); // 步数排行榜 按钮
            if (openRankingList.exists())
                openRankingList.findOnce().parent().click();
            rankingList.waitFor();
        }
    }

    toast("微信运动排行榜界面，准备开始点赞");
    sleep(2000);
    var screen = className("ListView").findOnce();
    var likeCount = 0;
    while (true) {
        likeButton = id("bo_");
        likeButtonsList = likeButton.find();
        if (likeButtonsList.empty()) {
            log("点赞列表为空");
            return -1;
        }
        // 开始点赞
        
        likeButtonsList.forEach(function LikeClick(aLikeButton) {
            ErrorCheck();

            function ErrorCheck() {
                var myHomePage = text("赞我的朋友");
                var othersHomePage = textEndsWith("的主页");
                if ((othersHomePage.exists() || myHomePage.exists())) {
                    toast("进入运动主页，准备退出");
                    sleep(random(2000, 3000));
                    back();
                }
            }

            if (aLikeButton.parent().parent().click()) {
                likeCount++;
                log("第" + likeCount + "次点赞成功");
                sleep(random(1000, 2000));
            } else {
                log("Error: 执行点赞失败");
            }

        });
        screen.scrollDown();
        toast("下滑页面，进行下一轮点赞");
        sleep(random(2000,3000));
        endFlag = text("邀请朋友").id("cry").exists();
        if(endFlag)
            sleep(random(3000,4000));
            toast("点赞已完成，脚本退出");
    }
}
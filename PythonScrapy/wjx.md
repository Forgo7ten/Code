问卷星自动提交。未写

参数

|     参数     |                    位置                     |
| :----------: | :-----------------------------------------: |
|  `shortid`   |                问卷网址截取                 |
| `starttime`  |     问卷网址html `//*[@id="starttime"]`     |
|   `source`   |      问卷网址html `//*[@id="source"]`       |
| `submittype` |                  `1`，未知                  |
|   `ktimes`   |        次数，定义0每次加一，可以随机        |
|    `hlv`     |              `"1"`，定值 未知               |
|     `rn`     | `/html/body/script[1]/text()` 变量`rndnum`  |
|   `jqpram`   |                                             |
|    `jpm`     |      由 `jpMatchId=jpmarr[0].id` 赋值       |
|  `isMtitle`  |      由 `isMatchTitle` 赋值，定值`1`？      |
|     `t`      |             提交时间毫秒时间戳              |
|  `jqnonce`   | `/html/body/script[1]/text()` 变量`jqnonce` |
|   `jqsign`   |                                             |
|   `u_asec`   |                                             |
|  `u_atype`   |        根据ua决定，（1~7）？ 本机`2`        |
|              |                                             |
|              |                                             |



-  `jqpram` ：wjx_jqparam.js

  

-  `jqsign` 

  ```javascript
  function dataenc(a) {
      var c, d, e, b = ktimes % 10;
      for (0 == b && (b = 1),
      c = [],
      d = 0; d < a.length; d++)
          e = a.charCodeAt(d) ^ b,
          c.push(String.fromCharCode(e));
      return c.join("")
  }
  
  jqsign = encodeURIComponent( dataenc(window.jqnonce) )
  ```

- `u_asec`

  ```javascript
  function getUA(e) {
      var t = window[UA_Opt.LogVal];
      return e ? encodeURIComponent(t) : t
  }
  
  ```

  
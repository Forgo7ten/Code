// 出处 52pojie @frankyxu
function abcd1(_0x17164c) {
  return abcd2(_0x17164c, 3597397);
}

function abcd2(_0x1b1e02, _0x23f273) {
  if (!abcdx()) {
    return;
  }

  var _0x1f9ba1 = 2147483648;
  var _0x3b83ae = 2147483647;

  var _0x4ad458 = ~~(_0x1b1e02 / _0x1f9ba1);

  var _0x470088 = ~~(_0x23f273 / _0x1f9ba1);

  var _0x5bc159 = _0x1b1e02 & _0x3b83ae;

  var _0x35dfa5 = _0x23f273 & _0x3b83ae;

  var _0x353774 = _0x4ad458 ^ _0x470088;

  var _0x4a742c = _0x5bc159 ^ _0x35dfa5;

  return _0x353774 * _0x1f9ba1 + _0x4a742c;
}

function abcd3(_0x420610, _0x1b425f) {
  if (_0x420610 - 62 < 0) {
    var _0xea36a8 = _0x1b425f["substr"](_0x420610, 1);

    return _0xea36a8;
  }

  var _0x45571c = _0x420610 % 62;

  var _0x4e6181 = parseInt(_0x420610 / 62);

  return abcd3(_0x4e6181, _0x1b425f) + _0x1b425f["substr"](_0x45571c, 1);
}

function abcd4(_0x11dbf0, _0x1558df) {
  if (!abcdx()) {
    return;
  }

  var _0x556c7b = _0x1558df["split"]("");

  var _0x27312b = _0x1558df["length"];

  for (var _0x107cfb = 0; _0x107cfb < _0x11dbf0["length"]; _0x107cfb++) {
    var _0x410c33 = parseInt(_0x11dbf0[_0x107cfb]);

    var _0x43a652 = _0x556c7b[_0x410c33];
    var _0x433a77 = _0x556c7b[_0x27312b - 1 - _0x410c33];
    _0x556c7b[_0x410c33] = _0x433a77;
    _0x556c7b[_0x27312b - 1 - _0x410c33] = _0x43a652;
  }

  _0x1558df = _0x556c7b["join"]("");
  return _0x1558df;
}

function abcd5(_0x5565b6) {
  if (!abcdx()) {
    return;
  }

  var _0x546e81 = 0;

  var _0x5ed7b1 = _0x5565b6["split"]("");

  for (var _0x28a6c3 = 0; _0x28a6c3 < _0x5ed7b1["length"]; _0x28a6c3++) {
    _0x546e81 += _0x5ed7b1[_0x28a6c3]["charCodeAt"]();
  }

  var _0x5af006 = _0x5565b6["length"];

  var _0x5258e0 = _0x546e81 % _0x5af006;

  var _0x2b24c5 = [];

  for (var _0x28a6c3 = _0x5258e0; _0x28a6c3 < _0x5af006; _0x28a6c3++) {
    _0x2b24c5["push"](_0x5ed7b1[_0x28a6c3]);
  }

  for (var _0x28a6c3 = 0; _0x28a6c3 < _0x5258e0; _0x28a6c3++) {
    _0x2b24c5["push"](_0x5ed7b1[_0x28a6c3]);
  }

  return _0x2b24c5["join"]("");
}

function abcdu(_0x92722d) {
  var _0x2eb3ad = -480;

  var _0x3a4ef4 = new Date()["getTimezoneOffset"]();

  var _0x58cdae = _0x2eb3ad - _0x3a4ef4;

  return _0x92722d["getTime"]() / 1000 + _0x58cdae * 60;
}

function abcdx() {

  return true;
}

function get_jqParam(rndnum, initstime, activityId) {
  var _0x3098bf = rndnum["split"](".")[0]; // rndnum from html

  var _0x4aaf4a = abcd1(parseInt(_0x3098bf));

  var _0x149db2 = (_0x4aaf4a + "")["split"]("");

  var _0x5b9ae2 = initstime; //"2021/1/28 17:36:28"

  var _0x4eae39 = abcdu(new Date(_0x5b9ae2["replace"](new RegExp("-", "gm"), "/")));

  var _0x5050a2 = _0x4eae39 + "";

  if (_0x4eae39 % 10 > 0) {
    _0x5050a2 = _0x5050a2["split"]("")["reverse"]()["join"]("");
  }

  var _0xd16fcc = parseInt(_0x5050a2 + "89123");

  var _0x149db2 = (_0xd16fcc + "" + (_0x4aaf4a + ""))["split"]("");

  var _0x1b3de6 = abcd4(_0x149db2, "kgESOLJUbB2fCteoQdYmXvF8j9IZs3K0i6w75VcDnG14WAyaxNqPuRlpTHMrhz");

  var _0x3a5cf2 = _0xd16fcc + _0x4aaf4a + parseInt(activityId);

  jqParam = abcd3(_0x3a5cf2, _0x1b3de6);

  var _0x5d90fd = abcd5(jqParam);

  return jqParam

}

var  rndnum = '2008883437.96038739';
var  initstime = "2021/1/28 16:55:06";
var  activityId = '105444284';
var result = get_jqParam(rndnum, initstime, activityId);
console.log(result)
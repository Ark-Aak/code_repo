var SimpleRequest=require('../lib/simple-request');
var toughCookie=require('tough-cookie');
var Step=require('step');
var assert=require('assert');

var CookieJar=new toughCookie.CookieJar();
var returnInfo={};
function test(){
    var url='http://notify.renren.com/wpi/getonlinecount.do';
    //人人网的cookie，重新测试时需要填入新的cookie
    var cookie1='id=2020787973;';
    var cookie2='t=e8e3e2c7ed791f0fc417b098c64ca5433;';
    Step(
        function(){
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie1),url,this.parallel());
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie2),url,this.parallel());
        },
        function(){
            CookieJar.getCookieString(url,function(err,cookies){
                console.log(cookies);
            });
            SimpleRequest.get(url,CookieJar,null,returnInfo,'json',function(){
                console.log(returnInfo);
                assert(2020787973==returnInfo.Content.hostid,'get fail!');
            });
        }
    );

}

test();




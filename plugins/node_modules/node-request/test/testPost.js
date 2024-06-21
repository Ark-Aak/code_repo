var SimpleRequest=require('../lib/simple-request');
var toughCookie=require('tough-cookie');
var Step=require('step');
var assert=require('assert');
var querystring=require('querystring');

var CookieJar=new toughCookie.CookieJar();
var returnInfo={};
function test(){
    //人人网的cookie，重新测试时需要填入新的cookie
    var cookie1='id=2020787973;';
    var cookie2='t=e8e3e2c7ed791f0fc417b098c64ca5433;';
    var token={requestToken:'-1967235412',_rtk:'567f5d06'};

    var uid=601709198;
    var url='http://shell.renren.com/'+uid+'/status';
    var parameter={
        'channel':'renren',
            'content':'test state',
            'hostid':uid,
            '_rtk':token._rtk,
            'requestToken':token.requestToken
    };


    var postData=querystring.stringify(parameter);

    var headers={
        'Referer':'www.renren.com'
        ,'Accept-Language': 'zh-cn'
        ,'Content-Type':'application/x-www-form-urlencoded'
        ,'Content-Length':postData.length
        ,'Connection': 'Keep-Alive'
        ,'Cache-Control': 'no-cache'
    };
    Step(
        function(){
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie1),url,this.parallel());
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie2),url,this.parallel());
        },
        function(){
            CookieJar.getCookieString(url,function(err,cookies){
                console.log(cookies);
            });
            SimpleRequest.post(url,CookieJar,postData,headers,returnInfo,'json',function(){
                console.log(returnInfo);
            });
        }
    );



}

test();




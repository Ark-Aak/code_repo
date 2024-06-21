var SimpleRequest=require('../lib/simple-request');
var toughCookie=require('tough-cookie');
var Step=require('step');
var assert=require('assert');


//人人网的cookie，重新测试时需要填入新的cookie
var cookie1='id=2020787973; domain=.renren.com;';
var cookie2='t=e8e3e2c7ed791f0fc417b098c64ca5433; domain=.renren.com;';
var CookieJar=new toughCookie.CookieJar();
var returnInfo={};


var buildFileField=function(albumId,picturePath){
    var fields=[];
    var field={
        name:'id',
        value:albumId
    };
    fields.push(field);

    field={
        filename:picturePath,
        name:'photo1',
        value:''
    }
    fields.push(field);

    return fields;
}

var picBlock={
    albumId:878929636,             //相册id
    picturePath:__dirname+'\\postfile.jpg'    //图片本地存放绝对路径
};
console.log(picBlock);
function test(){
    var url='http://upload.renren.com/uploadservice.fcgi?pagetype=addPhotoPlain';
    var fields=buildFileField(picBlock.albumId,picBlock.picturePath);
    Step(
        function(){
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie1),url,this.parallel());
            CookieJar.setCookie(toughCookie.Cookie.parse(cookie2),url,this.parallel());
        },
        function(){
            CookieJar.getCookieString(url,function(err,cookies){
                console.log(cookies);
            });
            SimpleRequest.postfile(url,CookieJar,fields,null,returnInfo,'txt',function(){
                console.log(returnInfo);
                console.log(CookieJar);
                var photopage='http://photo.renren.com/editphotolist.do?id=878929636&childAlbumId=0';
                SimpleRequest.get(photopage,CookieJar,null,returnInfo,'txt',function(){
                    //console.log(returnInfo);
                    console.log(CookieJar);
                    assert(returnInfo.Content.indexOf('设为封面')>0);
                });
            });
        }
    );

}

test();
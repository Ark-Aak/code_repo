var BufferHelper=require('bufferhelper');
var url=require('url');
var http=require('http');
var fs=require('fs');
var path=require('path');
var toughCookie=require('tough-cookie');
var userAgent='Mozilla/5.0 (Windows NT 5.1; rv:19.0) Gecko/20100101 Firefox/19.0';


/**
 *
 * @param dstUrl    目标地址
 * @param dstCookie tough-cookie.cookieJar的实例，cookie管理器
 * @param postData  post的数据
 * @param headers   需要自定义的头，可选
 * @param retObj    返回的数据
 * @param retContentType    返回的数据类型
 * @param cb        回调函数
 */
function postRequest(dstUrl,dstCookie,postData,headers,retObj,retContentType,cb){
    var postOption=url.parse(dstUrl);
    postOption.method='POST';
    postOption.headers=headers;
    if(!postOption.headers){
        postOption.headers={};
    }
    postOption.headers['Connection']='Keep-Alive';
    postOption.headers['User-Agent']=userAgent;
    postOption.headers['Host']=postOption.host;
    postOption.headers['Content-Length']=postData.length;//postdata经过url编码所以不存在中文占字节大于1的问题
    //
    if(dstCookie instanceof toughCookie.CookieJar){
        dstCookie.getCookieString(dstUrl, startHttp);
    }else if(typeof dstCookie === 'string'){
        postOption.headers.Cookie=dstCookie;
        startHttp();
    }else{
        startHttp();
    }
    function startHttp(err,httpCookie){
        if(httpCookie){
            postOption.headers.Cookie=httpCookie;
            //console.log('get cookie:'+postOption.headers.Cookie);
        }
        var thisPost=http.request(postOption,function(resin){
            var bufferHelper = new BufferHelper();
            var retHeaders=resin['headers'];
            var retCookie=retHeaders['set-cookie'];
            retObj.Status=resin['statusCode'];
            retObj.ContentType=retHeaders['content-type'];
            cookieMerge(dstCookie,retCookie,dstUrl);

            if(301==retObj.Status || 302==retObj.Status){
                retObj.Location=retHeaders['location'];
            }

            resin.on('data',function(msg){
                //console.log('.');
                bufferHelper.concat(msg);
            });
            resin.on('end',function(){
                //console.log('##post end');
                var resultBuffer=bufferHelper.toBuffer();
                setContent(retObj,resultBuffer,retContentType);
                cb();
            });
        }).on('error',function(err){cb(err);});
        //console.log(postData);
        thisPost.write(postData);
        thisPost.end();
    }
}

/**
 *
 * @param dstUrl    目标地址
 * @param dstCookie cookie管理器 tough-cookie.cookieJar
 * @param headers   自定义头，可选
 * @param retObj    返回内容
 * @param retContentType    返回内容类型
 * @param cb        回调函数
 */
function getRequest(dstUrl,dstCookie,headers,retObj,retContentType,cb){
    ///////////////////////
    var getOption=url.parse(dstUrl);
    getOption.headers=headers;
    if(!getOption.headers){
        getOption.headers={};
    }
    getOption.headers['Connection']='Keep-Alive';
    getOption.headers['User-Agent']=userAgent;
    getOption.headers['Host']=getOption.host;
    if(dstCookie instanceof toughCookie.CookieJar){
        dstCookie.getCookieString(dstUrl, startHttp);
    }else if(typeof dstCookie === 'string'){
        getOption.headers.Cookie=dstCookie;
        startHttp();
    }else{
        startHttp();
    }
    //////////////////////
    function startHttp(err,httpCookie){
        if(httpCookie){
            getOption.headers.Cookie=httpCookie;
            //console.log('get cookie:'+getOption.headers.Cookie);
        }
        var getHttp=http.get(getOption,function(res){
            var bufferHelper = new BufferHelper();
            //////////////////////
            var retHeaders=res['headers'];
            var retCookie=retHeaders['set-cookie'];
            retObj.Status=res['statusCode'];
            retObj.ContentType=retHeaders['content-type'];
            cookieMerge(dstCookie,retCookie,dstUrl);
            if(301==retObj.Status || 302==retObj.Status){
                retObj.Location=retHeaders['location'];
            }

            ///////////////////////
            res.on('data',function(msg){
                //console.log('##DATA');
                bufferHelper.concat(msg);
            });
            res.on('end',function(msg){
                //console.log('##END');
                var resultBuffer=bufferHelper.toBuffer();
                setContent(retObj,resultBuffer,retContentType);
                cb();
            });

        });
        getHttp.on('error',function(err){cb(err);});
    }

}


/**
 *
 * @param retObj
 * @param resultBuffer
 * @param retContentType
 */
function setContent(retObj,resultBuffer,retContentType){
    switch(retContentType){
        case 'txt':
            retObj.Content=resultBuffer.toString();
            break;
        case 'json':
            try{
                retObj.Content=JSON.parse(resultBuffer.toString());
                retObj.parseStatus=true;
            }catch(e){
                retObj.Content=resultBuffer.toString();
                retObj.parseStatus=false;
                retObj.err=e;
            }
            break;
        case 'buf':
            retObj.Content=resultBuffer;
            break;
        default:
            retObj.Content=resultBuffer.toString();
            break;
    }
}

function cookieMerge(MotherCookie,cookieArray,dsturl){
    if(MotherCookie instanceof toughCookie.CookieJar){
        if (cookieArray instanceof Array){
            for(var i=0;i<cookieArray.length;i++){
                var cookie=toughCookie.Cookie.parse(cookieArray[i]);
                MotherCookie.setCookie(cookie, dsturl, function(err,cookie){
                    if(err)
                        console.log('set cookie err:'+err);
                    else
                        console.log(cookie);
                });
            }
        }
    }

}

/**
 * 计算字符串的字节数
 * @param {Object} str
 */
function  getByteLen(str){
    var ll=str.length;
    var n = ll;
    for ( var i=0;i <ll;i++){
        if( str.charCodeAt(i) <0 || str.charCodeAt(i)> 255){
            n++;
        }
    }
    return n;
}

//////////////////////////////////post file part
var mimeTypes = {   //从文件后缀转成contentType,看起来不想后缀的不删掉了，留着吧
    mpeg_audio: "audio/mpeg",
    ogg_audio: "audio/ogg",
    vorbis: "audio/vorbis",
    wma: "audio/wma",
    wav: "audio/vnd.wave",
    gif: "image/gif",
    jpg: "image/jpeg",
    jpeg: "image/jpeg",
    png: "image/png",
    tiff: "image/tiff",
    bmp: "image/bmp",
    cmd: "text/cmd",
    css: "text/css",
    csv: "text/csv",
    html: "text/html",
    js: "text/javascript",
    txt: "text/plain",
    text: "text/plain",
    xml: "text/xml",
    vcard: "text/vcard",
    mpeg_video: "video/mpeg",
    mp4: "video/mp4",
    ogg_video: "video/ogg",
    quicktime: "video/quicktime",
    wmv: "video/x-ms-wmv"
};

/* Private Functions */
function encodeFileField(boundary, fieldName, value, fileName, contentType) {
    var cType;
    if(typeof contentType == 'string'){
        cType = contentType.toLowerCase();
    }else{
        //默认是文本
        cType = 'txt';
    }
    var mimeType = mimeTypes[cType];

    //The content type provided doesn't exist, so our best guess is to just send text
    if(typeof(mimeType) == "undefined") {
        //默认是文本
        mimeType = mimeTypes.txt;
    }

    var ret = "--" + boundary + "\r\n";
    ret += "Content-Disposition: form-data; name=\"" + fieldName + "\"; filename=\"" + fileName + "\"\r\n";
    ret += "Content-Type: " + mimeType + "\r\n\r\n";

    if(value !== "") {
        console.log('File with value!');
        ret += value + "\r\n\r\n";
    }

    return ret;
}

function encodeField(boundary, fieldName, value) {
    var ret = "--" + boundary + "\r\n";
    ret += "Content-Disposition: form-data; name=\"" + fieldName + "\"\r\n\r\n";
    ret += value + "\r\n";

    return ret;
}

function postFileRequest(dstUrl,dstCookie,postFields,headers,retObj,retContentType,cb){
    var multiPost=new Multipost(dstUrl,headers,postFields,cb);
    multiPost.post(retObj,retContentType,dstCookie);
}

var Multipost = function(dstUrl,headers,fields,callback) {

    var _targetUrl;
    var _httpHeader;
    var _fields;
    var _boundary;
    var _nowField;
    var _callbackfn;
    var _postRequest;

    if(typeof dstUrl === 'string'){
        _targetUrl = dstUrl;
    }

    if(typeof headers === 'object'){
        _httpHeader = headers;
    }

    //Check if fields is an array
    if(typeof(fields) === "object" && typeof(fields.length) === "number") {
        _fields = fields;
    }else{
        _fields = [];
    }

    if(typeof callback === 'function'){
        _callbackfn = callback;
    }


    _boundary = "-------------------------" + Math.random();
    _boundary = _boundary.replace(".", "");

    _nowField = 0;

    for(var i=0,max=_fields.length; i<max; i++) {
        var field = _fields[i];
        console.log(field);
        if(typeof(field.filename) != "string") {
            //No filename was set, so assme it's not a file
            field.strData = encodeField(_boundary, field.name || '', field.value || '');
            field.valid=true;
        } else {
            try{
                field.binData = fs.createReadStream(field.filename, {flags : "r", encoding : null});//二进制模式读
                field.binData.pause();//暂停，否则异步之后就变成不可读了，因为被异步读完了。
                field.binLength=fs.statSync(field.filename).size +2;//结尾的\r\n
                field.valid=true;
                console.log('filename ok!'+field.filename);
            }catch(e){
                field.binData = undefined;
                field.valid=false;
                console.log(e);
            }

            if(field.valid){
                var fileName = path.basename(field.filename);
                var fileType = path.extname(field.filename).replace('.','');

                field.strData = encodeFileField(_boundary, field.name || '', field.value || '', fileName, fileType);
            }
        }
        if(field.valid){
            field.dataLength = (field.binLength || 0) + getByteLen(field.strData || '');
        }
    }
    var tailField={
        valid:true,
        strData:'--'+_boundary+'--'+'\r\n'
    };
    tailField.dataLength=tailField.strData.length;
    _fields.push(tailField);

    var ERR_NUM={
        ERR_NONE:0,
        ERR_URL:1,
        ERR_HTTP:2,
        ERR_PIPE:3
    };

    this.post=function(retObj,retContentType,dstCookie){
        var contentLength=0;
        for(var i=0,max=_fields.length; i<max; i++) {
            var field = _fields[i];
            if(field.valid){
                contentLength += field.dataLength;
            }
        }

        if(!_targetUrl){
            console.log('_targetUrl is empty!');
            return callbackExec(ERR_NUM.ERR_URL,'_targetUrl is empty!');
        }

        var postOption=url.parse(_targetUrl);
        postOption.method='POST';
        postOption.headers=_httpHeader;
        if(!postOption.headers){
            postOption.headers={};
        }
        postOption.headers['Connection']='Keep-Alive';
        postOption.headers['User-Agent']=userAgent;
        postOption.headers['Content-Type']='multipart/form-data; boundary=' + _boundary;
        postOption.headers['Content-Length']=contentLength;

        if(dstCookie instanceof toughCookie.CookieJar){
            dstCookie.getCookieString(_targetUrl, startHttp);
        }else if(typeof dstCookie === 'string'){
            postOption.headers.Cookie=dstCookie;
            startHttp();
        }else{
            startHttp();
        }
        //////////////////////
        function startHttp(err,httpCookie){
            if(httpCookie){
                postOption.headers.Cookie=httpCookie;
                console.log('file cookie:'+postOption.headers.Cookie);
            }
            _postRequest=http.request(postOption,function(resin){
                var bufferHelper = new BufferHelper();
                var retHeaders=resin['headers'];
                var retCookie=retHeaders['set-cookie'];
                retObj.Status=resin['statusCode'];
                retObj.ContentType=retHeaders['content-type'];
                cookieMerge(dstCookie,retCookie,_targetUrl);

                resin.on('data',function(msg){
                    bufferHelper.concat(msg);
                });
                resin.on('end',function(){
                    console.log('end http post file!');
                    var resultBuffer=bufferHelper.toBuffer();
                    setContent(retObj,resultBuffer,retContentType);
                    return callbackExec(ERR_NUM.ERR_NONE);

                });
            });
            _postRequest.on('error',function(err){
                console.log(err);
                console.log('httpRequest error!');
                callbackExec(ERR_NUM.ERR_HTTP,err);
            });
            postField();
        }

    }

    var postField=function(){
        if(_nowField < _fields.length){
            var field=_fields[_nowField];
            if(!field.valid){
                _nowField ++;
                return postField();
            }
            if(!field.binData){
                //string
                if(_postRequest){
                    _postRequest.write(field.strData);
                }
                _nowField ++;
                return postField();
            }else{
                //file
                _postRequest.write(field.strData);  //先写文字
                if(typeof field.binData.pipe == 'function'){
                    field.binData.resume();
                    field.binData.pipe(_postRequest,{ end: false });//false表示pipe结束不关闭writeStream

                }

                field.binData.on('error',function(e){
                    console.log('pipe error!');
                    callbackExec(ERR_NUM.ERR_PIPE,'pipe error');
                });

                field.binData.on('end',function(){
                    _postRequest.write('\r\n');
                    _nowField ++;
                    postField();
                });

            }
        }else{
            _postRequest.end();
            console.log('postRequest finish!');
        }
    }

    var callbackExec=function(eNO,eMsg){
        if(typeof _callbackfn == 'function'){
            _callbackfn(eNO,eMsg);
        }
    }

};


exports.get=getRequest;
exports.post=postRequest;
exports.postfile=postFileRequest;



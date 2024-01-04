// ==UserScript==
// @name         Better YCOJ
// @namespace    http://tampermonkey.net/
// @version      2023-12-04
// @description  try to take over the world!
// @author       You
// @icon         https://www.google.com/s2/favicons?sz=64&domain=143.113
// @grant        GM_addStyle
// @grant        unsafeWindow
// @match        http://*/*
// @match        https://*/*
// @grant        GM_xmlhttpRequest
// @grant        GM_setValue
// @grant        GM_getValue
// @noframes
// ==/UserScript==
/* global Swal */
const tz_offset = new Date().getTimezoneOffset() + 480;

const checkNewDay = (ts) => {
    // 检查是否为新的一天，以UTC+8为准
    const t = new Date(ts);
    t.setMinutes(t.getMinutes() + tz_offset);
    t.setHours(0, 0, 0, 0);
    const d = new Date();
    d.setMinutes(t.getMinutes() + tz_offset);
    return (d - t > 86400e3);
};

const sign = () => {
    if (GM_getValue("notified")) {
        sendRequest();
    }
    else {
        Swal.fire(`由于脚本使用了tampermonkey进行跨域请求, 弹出提示请选择"总是允许域名"`).then(() => {
            GM_setValue("notified", true);
            sendRequest();
        })
    }
};

const sendRequest = () => {
    GM_xmlhttpRequest({
        method: "GET",
        url: "https://www.luogu.com.cn/index/ajax_punch",
        timeout: 10e3,
        onload: function (response) {
            response = JSON.parse(response.response);
            console.log(response);
            switch (parseInt(response.code)) {
                case 200: {
                    Swal.fire({
                        icon: 'success',
                        title: '洛谷自动签到',
                        text: '成功!'
                    });
                    GM_setValue("ts", Date.now());
                    break;
                }
                case 201: {
                    Swal.fire({
                        icon: 'error',
                        title: '洛谷自动签到',
                        html: `签到失败, 原因: <strong>${response.message}</strong>`
                    });
                    if (response.message.indexOf("已经打过卡") > -1) {
                        GM_setValue("ts", Date.now());
                    }
                    break;
                }
                default: {
                    Swal.fire({
                        icon: 'error',
                        title: '洛谷自动签到',
                        text: '未知错误, 打开控制台查看详情',
                    });
                    console.log(response);
                }
            }
        },
        onerror: function () {
            Swal.fire({
                icon: 'error',
                title: '洛谷自动签到',
                text: '请求签到时发生错误, 请检查网络或代理, 防火墙等',
            });
        }
    });
};

window.onload = () => {
    if (!GM_getValue("ts") || checkNewDay(GM_getValue("ts"))) {
        sign();
    }
};

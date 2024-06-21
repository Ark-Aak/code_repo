const WebSocketClient = require('websocket').client
const request = require("request");
const clientId = "070fac3c1fa59277759a7ec6c265a0b0e91c98b9";
const uid = "994667";

const headers = { "cookie": "__client_id=" + clientId + "; _uid=" + uid };
function getAlarms(val, later, before) {
  var alarm = val;
  var index = alarm.indexOf(later);
  alarm = alarm.substring(index + later.length, alarm.length);
  index = alarm.indexOf(before);
  alarm = alarm.substring(0, index);
  return alarm
}

function getCSRFToken() {
  var headers = {
    "cookie": `_uid=${uid}; __client_id=${clientId}`
  };
  request({
    url: "https://www.luogu.com.cn",
    method: "GET",
    headers: headers
  }, function (error, response, body) {
    if (!error && response.statusCode === 200) {
      token = getAlarms(body, "<meta name=\"csrf-token\" content=\"", "\">");
    }
    else {
      if (response != undefined) console.log("Error " + response.statusCode);
      else console.log("Error undefined")
    }
  })
}
getCSRFToken();

setInterval(getCSRFToken, 15 * 1000);
const ws = new WebSocketClient();

ws.connect('wss://ws.luogu.com.cn/ws', null, null, headers);
ws.on('connect', function(connection) {
	console.log('WebSocket Client Connected');
	connection.send(JSON.stringify({
        channel: "chat",
        channel_param: `${uid}`,
    	type: "join_channel",
    }));
	async function sendMessage(token, uid, clientId, id, text){
    return await fetch("https://www.luogu.com.cn/api/chat/new", {
        headers: [
            ["cookie", `_uid=${uid}; __client_id=${clientId}`],
            ["content-type", "application/json"],
            ["referer", "https://www.luogu.com.cn/"],
            ["x-csrf-token", token],
        ],
        body: JSON.stringify({
            user: id,
            content: text,
        }),
        method: "POST",
    })
}
	connection.on('message', function(message) {
		if (message.type === 'utf8') {
			console.log("Received: " + message.utf8Data);
			try {
				const data = JSON.parse(message.utf8Data);
				if (data._ws_type !== "server_broadcast") return;
				const Message = data.message;
				const content = JSON.parse(Message.content);
        if (content.type === "transfer") {
          if (!content.transfer_id || !content.sender) return;
          const data = {
            type: "transfer",
            sender: content.sender,
            content: content.content
          };
				  sendTo(content.transfer_id, JSON.stringify(data));
        }
			}
			catch (ignored) {}
		}
		function sendTo(id, content) {
			console.log(`Sending message to ${id}: ${content}`);
			sendMessage(token, uid, clientId, id, content);
		}
	});

  // 每隔 30 秒重新连接
  setTimeout(() => {
    connection.close();
    ws.connect('wss://ws.luogu.com.cn/ws', null, null, headers);
    console.log("Reconnecting...");
  }, 30 * 1000);
});

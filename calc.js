let page = 0;
let success = 0;
let total = 0;

while (true) {
	page += 1;
	console.log("读取第 " + page + " 页...");
	let notifications = JSON.parse(
		await fetch("https://www.luogu.com.cn/user/notification?_contentOnly=1&type=3&page=" + page)
			.then(res => res.text())
	).currentData.notifications.result;
	if (notifications.length == 0) break;
	for (notification of notifications) {
		if (notification.title.includes("团队")) continue;
		if (notification.title.includes("已被移出")) continue;
		if (notification.title.includes("帖子被删除")) continue;
		if (notification.title.includes("举报")) continue;
		if (notification.title.includes("欢迎")) continue;
		total += 1;
		if (notification.content.includes("已经被全站推荐")) success += 1;
		if (notification.content.includes("已经通过审核")) success += 1;
	}
}

console.log("通过率：" + success * 100.0 / total + "%");
console.log("总提交次数：" + total + " 次");
console.log("成功次数：" + success + " 次");

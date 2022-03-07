const fs = require("fs");
let td = require("./tdefines.js");

const express = require('express');
const bodyParser = require('body-parser');
const router = express.Router();
const path = require("path");
const app = express();
const port = 3001;
let flag = fs.readFileSync("flag.txt").toString();
app.set("view engine", "pug");
app.set("views", path.join(__dirname, "views"));
app.use(bodyParser.urlencoded());

let getIndex = () => {
	return Math.floor(Math.random() * (Math.floor(td.length-1) - Math.ceil(1))) + Math.ceil(1);
}

String.prototype.hexEncode = function(){
    let hex, i;
    let result = "";
    for (i=0; i<this.length; i++) {
        hex = this.charCodeAt(i).toString(16);
        result += ("000"+hex).slice(-4);
    }

    return result
}

let main = (flag) => {
	let ff = [];
	let names = "";
	let yourId = 0;
	flag = flag.hexEncode();
	for (let i = 0; i < parseInt(flag.length/4); i++) {
		let t = td[getIndex()];
		ff.push(t);
		names += t.name;
	}
	let encoded = "";
	for (let i = 0; i < flag.length; i+=4) {
		encoded += (td[td.length - 1](eval("0x" + flag.substr(i, 4)), 0xab, ff[yourId%parseInt(flag.length/4)])).toString(16).padStart(2, "0");
		yourId++;
	} 
	resp = `Encoded: ${encoded}\nFunctions I used: ${names}`
	return resp;
}



router.get("/", (req, res) => {
  res.render("index", { flag: main(flag) });
});

app.post("/check", (req, res) => {
	res.send(('user_flag' in req.body) && (flag == req.body.user_flag));
})

app.use("/", router);
app.listen(port, () => {
	console.log(`TLang server listening on ${port}`)
});


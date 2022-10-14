var xhr2 = new XMLHttpRequest();
var url2 = "https://malfind.com/"
var payload = encodeURIComponent("testing3");
xhr2.open("GET", url2+"?"+payload, true);
xhr2.send(payload);
console.log(xhr.responseText);
xhr.send();
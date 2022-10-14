from hashlib import sha256
import requests
from base64 import b64encode
import urllib

url = 'http://rev.chal.csaw.io:10010'

string = "wakuwaku"
sha256_value = sha256(string.encode("utf-8")).digest()

for i in range(999):
    sha256_value = sha256(sha256_value).digest()

b64_value = b64encode(sha256_value)

print(b64_value.decode("UTF-8"))

data = urllib.parse.urlencode({'data': b64_value.decode("UTF-8")})

x = requests.post(url, data=data, headers = {'User-Agent': 'UnityPlayer/2020.3.0f1 (UnityWebRequest/1.0, libcurl/7.52.0-DEV)', 'Content-Type': 'application/x-www-form-urlencoded', 'X-Unity-Version': '2020.3.0f1'})

print('flag{}'.format(x.text))
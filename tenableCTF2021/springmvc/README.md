curl -X POST "http://challenges.ctfd.io:30542/main"
curl -d "please" -X POST "http://challenges.ctfd.io:30542/main"
curl -d "magicWord=please" -X POST "http://challenges.ctfd.io:30542/main"
curl -H "Content-Type: application/json" -X POST "http://challenges.ctfd.io:30542/main"
curl -X OPTIONS "http://challenges.ctfd.io:30542/main"
curl -H "Magic-Word: please" -X GET "http://challenges.ctfd.io:30542/main"


curl "http://challenges.ctfd.io:30542/?name=please"

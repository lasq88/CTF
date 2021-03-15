#!/bin/bash
docker rm -f lovetok
docker build -t lovetok . && \
docker run --name=lovetok --rm -p1337:80 -it lovetok
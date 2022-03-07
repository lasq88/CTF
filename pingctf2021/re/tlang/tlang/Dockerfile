FROM node:17

WORKDIR /usr/src/app

COPY source/package*.json ./
RUN npm install

COPY source .
EXPOSE 3001
CMD [ "node", "server.js" ]
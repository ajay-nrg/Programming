const {createServer} = require("http");

let server = createServer((req,res) => {
  res.writeHead(200,{"Content-Type":"text/html"});
  res.write(`
    <h1>Hello</h1>
    <p>You asked for <code>${req.url}</code></p>
  `);
  res.end();
});

server.listen(8080);
console.log("Listening! (port 8000)");
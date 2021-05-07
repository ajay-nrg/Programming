const http = require('http');
const port = process.env.PORT || 8080;

const server = http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':'text/html'});
    res.end(`<h1>Hello world</h1>`);
});

server.listen(port,()=>console.log(`server started at port ${port}\n`+
'press Ctrl-C to terminate'));
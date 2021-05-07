const http = require("http");
const port = process.env.PORT || 8080;
const url = require('url');

const server = http.createServer((req,res)=>{
    const addr = url.parse(req.url);
    const path = addr.pathname.toLocaleLowerCase();
    switch(path){
        case '/':    
            res.writeHead(200,{'Content-Type':'text/plain'});
            res.end("Home Page");
            break;
        case '/about':    
            res.writeHead(200,{'Content-Type':'text/plain'});
            res.end("about Page");
            break;
        default:    
            res.writeHead(404,{'Content-Type':'text/plain'});
            res.end("Page not found");
            break;
    }
});

server.listen(port, () => console.log(`server started on port ${port}; ` +
'press Ctrl-C to terminate....'))
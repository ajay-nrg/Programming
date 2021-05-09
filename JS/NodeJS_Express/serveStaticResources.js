const http = require('http');
const url = require('url');
const fs = require('fs');
const port = process.env.PORT || 8080;

function serveStaticFiles(res,path,contentType,resposeCode = 200){
    fs.readFile(__dirname + path, (err,data)=>{
        if(err){
            res.writeHead(500,{'Content-Type':'text/plain'});
            res.end('500 - Internal Error');
        }
        res.writeHead(resposeCode,{'Content-Type':contentType});
        res.end(data);
    });
}

const server = http.createServer((req,res)=>{
    const path = (url.parse(req.url)).pathname.toLowerCase();
    switch(path){
        case '/':
            serveStaticFile(res, '/public/home.html', 'text/html');
            break;
        case '/about':
            serveStaticFile(res, '/public/about.html', 'text/html');
            break;
        case '/img/logo.png':
            serveStaticFile(res, '/public/img/logo.png', 'image/png');
            break;
        default:
            serveStaticFiles(res,'/public/404.html', 'text/html', 404);
            break;
    }
});

server(port,()=> console.log(`server started at port ${port}\n`
+'press Ctrl-C to terminate....'));
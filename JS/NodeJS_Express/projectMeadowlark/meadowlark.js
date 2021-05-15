const express = require('express');
const expressHandlebars = require('express-handlebars');

const app = express();
const port = process.env.PORT || 8080;
const handlers = require('./lib/handlers');

// configure Handlebars view engine
app.engine('handlebars',expressHandlebars({
    defaultLayout: 'main',
    helpers: {
        section: function(name,options){
            if(!this._sections) this._sections = {};
            this._sections[name] = options.fn(this);
        },
    },
}));
app.set('view engine','handlebars');

app.use(express.static(__dirname+'/public'));

app.get('/',handlers.home);
app.get('/about',handlers.about);
app.get('/headers',(req,res)=>{
    res.type('test/plain');
    const headers = Object.entries(req.headers)
    .map(([key,val])=>`${key}: ${val}`);
    res.send(headers.join('\n'));
})
app.get('/newsletter-signup', handlers.newsletterSignup)
app.post('/newsletter-signup/process', handlers.newsletterSignupProcess)
app.get('/newsletter-signup/thank-you', handlers.newsletterSignupThankYou)
//custom 404 page
// If we put the 404 handler above
// the routes, the home page and About page would stop working; instead,
// those URLs would result in a 404.
app.use(handlers.notFound);

//custom 500 page
app.use(handlers.serverError);

app.listen(port,()=>console.log(
    `Express started on http://localhost:${port};\n`+
    'press Ctrl-C to terminate.'
));
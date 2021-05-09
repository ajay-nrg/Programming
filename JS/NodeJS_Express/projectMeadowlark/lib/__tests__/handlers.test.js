const handlers = require('../handlers');

test('home page renders', ()=>{
    const req = {}
    const res = { render: jest.fn()}
    handlers.home(req, res)
});
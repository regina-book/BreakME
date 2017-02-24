var express = require('express');
var mongodb = require('mongodb');
var app=express();
app.use(require('body-parser').urlencoded({extended: true}));
app.use(require('body-parser').json());

var MongoClient = require('mongodb').MongoClient;
MongoClient.connect("mongodb://localhost:27017/nosqli", function(err, database) {
  if(err) throw err;

  db = database;
  app.listen(3000);
  console.log("Listening on port 3000");
});

app.get('/', function (req, res) {
  res.sendFile(__dirname + '/index.html')
});

app.post('/login', function (req, reshttp) {
  db.collection('users').findOne(req.body, (err, document) => {
  if (err) throw err;

  console.log("req : " + JSON.stringify(req.body) + " :\n" + "res : " + JSON.stringify(document) + "\n- - - -\n");
  });
  reshttp.redirect('/');
});

app.post('/register', function (req, reshttp) {
  db.collection('users').save(req.body, (err, resdb) => {
    if (err) throw err;

    console.log('saved to database');
  });
  reshttp.redirect('/');
});

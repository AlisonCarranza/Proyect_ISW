var mongoose = require('mongoose');

let bd ='DB';
let port = 27017;
let host = 'localHost'

class Database{
  constructor(){
  	this.conectarBD();
  }

  conectarBD(){
  	mongoose.connect(`mongodb://${host}:${port}/${bd}`)
  	.then(res=>console.log('Se conecto a la DB en Mongo.'))
  	.catch(error=>console.log(error));
  }
}

module.exports = new Database();
const {Schema, model} = require('mongoose');


const commentSchema = new Schema({
    cuerpo: String,
    email: String,
    fecha_creacion: Date
  });

  module.exports=model('comment', commentSchema);

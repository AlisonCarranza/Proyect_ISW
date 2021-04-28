const {Schema, model} = require('mongoose');


const commentSchema = new Schema({
    nombre: String,
    cuerpo: String,
    email: String,
    fecha_creacion: Date,
    id_proyecto: String,
  });

  module.exports=model('comment', commentSchema);

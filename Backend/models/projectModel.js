const {Schema, model} = require('mongoose');


const projectSchema = new Schema({
    email:String,
    titulo: String,
    descripcion: String,
    visibilidad: String,
    presupuesto: Number,
    timeframe: String,
    roles: String,
    herramientas: String,
    fecha_creacion: Date
  });

  module.exports=model('project', projectSchema);
var mongoose = require('mongoose');

var esquema = new mongoose.Schema({
    nombre: String,
    userName: String,
    correo:String,
    telefono:String,
    password:String
});

// requiere de parametros el nombre de la colleccion en mongo y el esquema antes creado.
module.exports = mongoose.model('usuarios',esquema);

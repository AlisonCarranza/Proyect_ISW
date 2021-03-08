//paquetes
var express=require('express');
var cors=require('cors');
var bodyParser=require('body-parser');

//rutas
var database= require('./modules/mongo-db');

//funcionalidades paquetes
var app=express();

//permite peticiones de otros tipos de origenes.
app.use(cors());

//permite el acceso a los parametros enviados mediante post , es decir al cuerpo de la peticion.
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extend:true}));


//middleware.



app.listen(4000,function(){
     console.log('El Servidor esta levantado.');

});


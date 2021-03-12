//paquetes
var express=require('express');
var cors=require('cors');


//rutas
var database= require('./modules/mongo-db');

//funcionalidades paquetes
var app=express();

//permite peticiones de otros tipos de origenes.
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({extend:true}));

//permite el acceso a los parametros enviados mediante post , es decir al cuerpo de la peticion.
app.use(require ('./routes/usuarios-route'));
app.use(require ('./routes/login-route'));

app.listen(4000,function(){
     console.log('El Servidor esta levantado.');

});


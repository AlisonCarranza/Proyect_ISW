//paquetes
var express=require('express');
var cors=require('cors');


//rutas
var database= require('./modules/mongo-db');
var usuariosRouter=require('./routes/usuarios-router');
var loginRouter= require('./routes/login-router');

//funcionalidades paquetes
var app=express();

//permite peticiones de otros tipos de origenes.
app.use(cors());

//permite el acceso a los parametros enviados mediante post , es decir al cuerpo de la peticion.
app.use(express.json());
app.use(express.urlencoded({extend:true}))

//middleware.
app.use('/usuarios',usuariosRouter);
app.use('/login',loginRouter);



app.listen(4000,function(){
     console.log('El Servidor esta levantado.');

});


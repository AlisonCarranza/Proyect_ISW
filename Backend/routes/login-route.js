var express = require('express');
var jwt=require('jsonwebtoken');
var router = express.Router();
var usuario = require('../models/usuario');

//login
router.post('/login',function (req, res) {
    let a = 
       {
        password:req.body.password,
        correo:req.body.correo,
       };
   
    
    usuario.findOne({correo:a.correo}).then(resultado=>{
        if (resultado.password==a.password) {
            let payload = {subject:resultado._id};
            let token= jwt.sign(payload, 'secretKey');

            res.send({token});
        }
        else {
            res.status(401).send('Password Invalido');
        }
        res.end();
        
    }).catch(error=>{
        res.send(error);
        res.end();
    });

});

//exportacion del metodo router para que pueda ser accededido por cualquier usuario
module.exports = router;
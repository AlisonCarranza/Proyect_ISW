var express = require('express');
var router = express.Router();
var jwt=require('jsonwebtoken');
var usuario = require('../models/usuario');

//Crear
router.post('/registro',function (req, res) {
    let a = new usuario(
       {
        nombre:req.body.nombre,
        userName:req.body.userName,
        correo:req.body.correo,
        telefono:req.body.telefono,
        password:req.body.password
       }
    );
    
    a.save().then(resultado=>{
        let payload = {subject:resultado._id};
        let token= jwt.sign(payload, 'secretKey');

        res.send({token});
        res.end();
    }).catch(error=>{
        res.send(error);
        res.end();
    });

});

//Obtener un usuario
router.get('/usuarios/:id',function (req, res) {
    usuario.find({_id:req.params.id}).then(resultado=>{
        res.send(resultado[0]);
        res.end();
    }).catch(error=>{
        res.send(error);
        res.end();
    });
});

//obtener todos los usuarios
router.get('/usuarios',function (req, res) {

    usuario.find().then(resultado=>{
        res.send(resultado);
        res.end();
    }).catch(error=>{
        res.send(error);
        res.end();
    });
    
});

//actualizar
router.put('/usuarios/:id',function (req, res) {
    usuario.updateOne(
        {
          _id:req.params.id
        },
        {
            nombre:req.body.nombre,
            userName:req.body.userName,
            correo:req.body.correo,
            telefono:req.body.telefono,
            password:req.body.password
        }
    ).then(resultado=>{
        res.send(resultado);
        res.end();
    }).catch(error=>{
        res.send(error);
        res.end();
    });
    
});


//eliminar
router.delete('/usuarios/:id',function (req, res) {
    usuario.remove({_id:req.params.id})
    .then(resultado=>{
        res.send(resultado);
        res.end();
    }).catch(error=>{
        res.send(error);
        res.end();
    });
});

//exportacion del metodo router para que pueda ser accededido por cualquier usuario
module.exports = router;
const {Router}=require('express');
const router = Router();
const user = require('../models/usersModel');
const jwt = require('jsonwebtoken');
const bcrypt = require ('bcrypt-nodejs');
const validator = require("email-validator");


//La funcion debe ser async para poder usar await
router.post('/api/signup', async (req, res)=>{
    try {
        //guardar los valores de los datos recibidos en formato json
        const { nombre, username, email, password, vpassword, telefono, genero}= req.body;
        //Creando el objeto usuario usando el modelo en users.js
        const email_l =email.toLowerCase();
        //Validación del correo electronico recibido
        /*if (validator.validate(email_l)==false){
            return res.json({estado:'correo_invalido'})
        }*/
         //Comparacion contraseñas   
        if (password != vpassword){
            return res.json({estado:'password'})
        }
        //Verificación de username no repetido
        if(UserR = await user.findOne({username:username})) {
            return res.json({estado: 'usuario_repetido'});     
        }
    
        /*VERIFICANDO SI EXISTE YA UN CORREO EN LA BASE*/
        if( UserR = await user.findOne({email:email_l})) {
            return res.json({estado: 'correo_repetido'});     
        } else {
            //encriptacion
            const salt = bcrypt.genSaltSync();
            const hash= bcrypt.hashSync(password, salt);
            /*GUARDADO EN LA BASE*/
            const imageName ="Default.png";
            //const imagePath = path.join(__dirname, "../../upload", imageName);
            mesRegistro=new Date().getMonth();
            anioRegistro=new Date().getFullYear();
            const newUser = new user ({nombre, username, email:email_l, password:hash, telefono, genero, picPerfil:imageName, token:"", temporal_pass:"",anioRegistro,mesRegistro});
            await newUser.save();
            //console.log (newUser);
            const token = await jwt.sign({_id: newUser._id}, 'secretkey');
            await user.updateOne({email:email_l},{$set:{token:token}});
            return res.status(200).json({estado:'hecho', token});
            }       
        } catch (error) {
            console.log(error)
            return res.status(401).json({estado:'Error'}) 
        }
            
    });
    
    module.exports = router;

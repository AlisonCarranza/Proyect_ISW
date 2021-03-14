const {Router}=require('express');
const router = Router();
const user = require('../models/usersModel');
const jwt = require('jsonwebtoken');
const bcrypt = require ('bcrypt-nodejs');


router.post('/api/signin', async (req, res) => {
    try {
        const { email, password } = req.body;
        const email_l =email.toLowerCase(); 

        //Verificacion si es usuario pasajero
        if(User = await user.findOne({email:email_l})){
            //if (!User) return res.json({estado:'email'});
            //comparando temporal pass
            if(User.temporal_pass!=""){
                if(bcrypt.compareSync(password, User.temporal_pass)){
                    const token = User.token;
                    return res.status(200).json({estado:'temporal',token:token, type:'usuario'});
                    //comparando pass
                }else if(bcrypt.compareSync(password, User.password)){
                    const token = User.token;
                    await user.updateOne({email:email_l},{$set:{ temporal_pass:""}})
                    return res.status(200).json({estado:'hecho', token:token, type:'usuario'});   
        
                }
                return res.json({estado:'password', type:'usuario'})
    
            }
            if(bcrypt.compareSync(password, User.password)){
                const token = User.token;
                await user.updateOne({email:email_l})
                return res.status(200).json({estado:'hecho',token:token, type:'usuario'});     
            }else{
                return res.json({estado:'password', type:'usuario'});
            }

        }else{
            
            return res.json({estado:'email'});
        }   
    } catch (error) {
        console.log(error)
        res.json({estado:'Error'});       
    }
        
});


module.exports = router;
const {Router}=require('express');
const router = Router();
const jwt = require('jsonwebtoken');
const bcrypt = require ('bcrypt-nodejs');

const professional = require('../models/professionalsModel'); 
const professionalsModel = require('../models/professionalsModel');

router.get('/api/search-prof', async(req, res)=>{
    //console.log('error');
    try{
        
        const profesional = await professional.find({},{_id:0});
        const Professional = await professional.countDocuments();
        console.log(Professional);
        return res.json({profesional, Professional});
    }catch(error){
        res.json({estado:'Error'});  
    }
});

module.exports = router;
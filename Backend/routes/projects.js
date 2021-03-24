const {Router}=require('express');
const router = Router();
const nodemailer = require('nodemailer');
const jwt = require('jsonwebtoken');
const bcrypt = require ('bcrypt-nodejs');

const project = require('../models/projectModel');
const projectModel = require('../models/projectModel');

router.get('/api/projects', async(req, res)=>{
    console.log('error');
    try{
        const proyecto = await project.find({},{_id:0});
        const Project = await project.countDocuments();
        console.log(project);
        return res.json({proyecto, Project});
    }catch(error){
        res.json({estado:'Error'});  
        console.log('fallo')
    }
});

module.exports = router;
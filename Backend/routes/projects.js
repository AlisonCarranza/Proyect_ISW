const {Router}=require('express');
const router = Router();
const jwt = require('jsonwebtoken');

const project = require('../models/projectModel');
const projectModel = require('../models/projectModel');

router.get('/api/projects', async(req, res)=>{
    console.log('peticion del backend');
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
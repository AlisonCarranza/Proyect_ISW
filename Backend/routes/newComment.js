const {Router}=require('express');
const router = Router();
const user = require('../models/usersModel');
const Comment = require('../models/commentModel');

router.post('/api/proyect-comments-editor', async (req, res)=>{
    console.log("backend access");
    let token = req.headers.authorization.split(' ')[1];
    console.log (token);
    try {
      if (User = await user.findOne({token})){
        const comment = new Comment({
            email: User.email,
            cuerpo: req.body.cuerpo,
            fecha_creacion: req.body.fecha_creacion
          });
          console.log(comment);
        await comment.save();

        return res.json({estado:"CommentSuccess"});
      }

    } catch (error) {
        console.log(error)
        return res.status(401).json({estado:'Error'});
    }
    });


module.exports = router;

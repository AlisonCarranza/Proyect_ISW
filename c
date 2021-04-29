[1mdiff --git a/Backend/.gitignore b/Backend/ - Copy.gitignore[m
[1msimilarity index 100%[m
[1mrename from Backend/.gitignore[m
[1mrename to Backend/ - Copy.gitignore[m
[1mdiff --git a/Backend/index.js b/Backend/index.js[m
[1mindex ab1e5c2..7d50334 100644[m
[1m--- a/Backend/index.js[m
[1m+++ b/Backend/index.js[m
[36m@@ -1,28 +1,33 @@[m
 //paquetes[m
 var express=require('express');[m
 var cors=require('cors');[m
[31m-var bodyParser=require('body-parser');[m
[32m+[m
[32m+[m[32m//funcionalidades paquetes[m
[32m+[m[32mvar app=express();[m
 [m
 //rutas[m
 var database= require('./modules/mongo-db');[m
 [m
[31m-//funcionalidades paquetes[m
[31m-var app=express();[m
[32m+[m[32m//middleware.[m
 [m
 //permite peticiones de otros tipos de origenes.[m
[32m+[m[32mapp.use(express.json());[m
 app.use(cors());[m
 [m
 //permite el acceso a los parametros enviados mediante post , es decir al cuerpo de la peticion.[m
[31m-app.use(bodyParser.json());[m
[31m-app.use(bodyParser.urlencoded({extend:true}));[m
[31m-[m
[31m-[m
[31m-//middleware.[m
[31m-[m
[31m-[m
[31m-[m
[32m+[m[32mapp.use (require ('./routes/user'));[m
[32m+[m[32mapp.use (require ('./routes/login'));[m
[32m+[m[32mapp.use (require ('./routes/edit-profile'));[m
[32m+[m[32mapp.use (require ('./routes/upload-profile-pic'));[m
[32m+[m[32mapp.use (require ('./routes/change-password'));[m
[32m+[m[32mapp.use (require ('./routes/rec-password'));[m
[32m+[m[32mapp.use (require ('./routes/recover-password'));[m
[32m+[m[32mapp.use (require ('./routes/newform'));[m
[32m+[m[32mapp.use (require ('./routes/projects'));[m
[32m+[m[32mapp.use (require ('./routes/search-prof'));[m
[32m+[m[32mapp.use (require ('./routes/newComment'));[m
[32m+[m[32mapp.use (require ('./routes/getComments'));[m
 app.listen(4000,function(){[m
      console.log('El Servidor esta levantado.');[m
 [m
 });[m
[31m-[m
[1mdiff --git a/Backend/models/commentModel.js b/Backend/models/commentModel.js[m
[1mnew file mode 100644[m
[1mindex 0000000..3fd6b89[m
[1m--- /dev/null[m
[1m+++ b/Backend/models/commentModel.js[m
[36m@@ -0,0 +1,12 @@[m
[32m+[m[32mconst {Schema, model} = require('mongoose');[m
[32m+[m
[32m+[m
[32m+[m[32mconst commentSchema = new Schema({[m
[32m+[m[32m    nombre: String,[m
[32m+[m[32m    cuerpo: String,[m
[32m+[m[32m    email: String,[m
[32m+[m[32m    fecha_creacion: Date,[m
[32m+[m[32m    id_proyecto: String,[m
[32m+[m[32m  });[m
[32m+[m
[32m+[m[32m  module.exports=model('comment', commentSchema);[m
[1mdiff --git a/Backend/models/professionalsModel.js b/Backend/models/professionalsModel.js[m
[1mnew file mode 100644[m
[1mindex 0000000..b71667b[m
[1m--- /dev/null[m
[1m+++ b/Backend/models/professionalsModel.js[m
[36m@@ -0,0 +1,26 @@[m
[32m+[m[32mconst {Schema, model} = require('mongoose');[m
[32m+[m[32mconst bcrypt = require ('bcrypt-nodejs');[m
[32m+[m
[32m+[m[32mconst professionalSchema = new Schema({[m
[32m+[m[32m    nombre: String,[m
[32m+[m[32m    //apellido:String,[m
[32m+[m[32m    username: String,[m
[32m+[m[32m    email: String,[m
[32m+[m[32m    password: String,[m
[32m+[m[32m    telefono: String,[m
[32m+[m[32m    genero: String,[m
[32m+[m[32m    profesion: String,[m
[32m+[m[32m    tecnologias: String,[m
[32m+[m[32m    experiencia:String,[m
[32m+[m[32m    //intentos:Number,[m
[32m+[m[32m    picPerfil: String,[m
[32m+[m[32m    token: String,[m
[32m+[m[32m    temporal_pass:String,[m
[32m+[m[32m    mesRegistro:Number,[m
[32m+[m[32m    anioRegistro:Number[m
[32m+[m[32m}, {[m
[32m+[m[32m    timestamps: true[m
[32m+[m[32m});[m
[32m+[m[32mprofessionalSchema.index({email:1},{unique:true});[m
[32m+[m
[32m+[m[32mmodule.exports=model('professional', professionalSchema);[m
\ No newline at end of file[m
[1mdiff --git a/Backend/models/projectModel.js b/Backend/models/projectModel.js[m
[1mnew file mode 100644[m
[1mindex 0000000..80b4e40[m
[1m--- /dev/null[m
[1m+++ b/Backend/models/projectModel.js[m
[36m@@ -0,0 +1,16 @@[m
[32m+[m[32mconst {Schema, model} = require('mongoose');[m
[32m+[m
[32m+[m
[32m+[m[32mconst projectSchema = new Schema({[m
[32m+[m[32m    email:String,[m
[32m+[m[32m    titulo: String,[m
[32m+[m[32m    descripcion: String,[m
[32m+[m[32m    visibilidad: String,[m
[32m+[m[32m    presupuesto: Number,[m
[32m+[m[32m    timeframe: String,[m
[32m+[m[32m    roles: String,[m
[32m+[m[32m    herramientas: [],[m
[32m+[m[32m    fecha_creacion: Date[m
[32m+[m[32m  });[m
[32m+[m
[32m+[m[32m  module.exports=model('project', projectSchema);[m
[1mdiff --git a/Backend/models/usersModel.js b/Backend/models/usersModel.js[m
[1mnew file mode 100644[m
[1mindex 0000000..7bee412[m
[1m--- /dev/null[m
[1m+++ b/Backend/models/usersModel.js[m
[36m@@ -0,0 +1,33 @@[m
[32m+[m[32mconst {Schema, model} = require('mongoose');[m
[32m+[m[32mconst bcrypt = require ('bcrypt-nodejs');[m
[32m+[m
[32m+[m[32mconst userSchema = new Schema({[m
[32m+[m[32m    nombre: String,[m
[32m+[m[32m    username: String,[m
[32m+[m[32m    email: String,[m
[32m+[m[32m    password: String,[m
[32m+[m[32m    telefono: String,[m
[32m+[m[32m    genero: String,[m
[32m+[m[32m    //intentos:Number,[m
[32m+[m[32m    picPerfil: String,[m
[32m+[m[32m    token: String,[m
[32m+[m[32m    temporal_pass:String,[m
[32m+[m[32m    mesRegistro:Number,[m
[32m+[m[32m    anioRegistro:Number[m
[32m+[m[32m}, {[m
[32m+[m[32m    timestamps: true[m
[32m+[m[32m});[m
[32m+[m[32muserSchema.index({email:1},{unique:true});[m
[32m+[m
[32m+[m[32m//Lectura de contraseñas encriptadas[m
[32m+[m[32m/*userSchema.methods.compararPass = function (password, cb){ //cb = callback[m
[32m+[m[32m    bcrypt.compare(password, this.password, (err, iguales)=>{[m
[32m+[m[32m        if (err){[m
[32m+[m[32m            return cb(err);[m
[32m+[m[32m        }[m
[32m+[m[32m        cb (null, iguales);[m
[32m+[m[32m    })[m
[32m+[m[32m}*/[m
[32m+[m
[32m+[m
[32m+[m[32mmodule.exports=model('user', userSchema);[m
\ No newline at end of file[m
[1mdiff --git a/Backend/modules/mongo-db.js b/Backend/modules/mongo-db.js[m
[1mindex 58f83e2..aeb53dc 100644[m
[1m--- a/Backend/modules/mongo-db.js[m
[1m+++ b/Backend/modules/mongo-db.js[m
[36m@@ -1,8 +1,8 @@[m
 var mongoose = require('mongoose');[m
 [m
[31m-let bd ='DB';[m
[32m+[m[32mlet bd ='paratus';[m
 let port = 27017;[m
[31m-let host = 'localHost'[m
[32m+[m[32mlet host = 'localhost'[m
 [m
 class Database{[m
   constructor(){[m
[36m@@ -10,7 +10,11 @@[m [mclass Database{[m
   }[m
 [m
   conectarBD(){[m
[31m-  	mongoose.connect(`mongodb://${host}:${port}/${bd}`)[m
[32m+[m[41m  [m	[32mmongoose.connect(`mongodb://${host}:${port}/${bd}`, {[m
[32m+[m[32m      useCreateIndex: true,[m
[32m+[m[32m      useNewUrlParser: true,[m
[32m+[m[32m      useUnifiedTopology: true[m
[32m+[m[32m    })[m
   	.then(res=>console.log('Se conecto a la DB en Mongo.'))[m
   	.catch(error=>console.log(error));[m
   }[m
[1mdiff --git a/Backend/node_modules/.bin/alert b/Backend/node_modules/.bin/alert[m
[1mnew file mode 100644[m
[1mindex 0000000..dd5713e[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/alert[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../alert/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../alert/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/alert.cmd b/Backend/node_modules/.bin/alert.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..06be700[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/alert.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\alert\cli.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/alert.ps1 b/Backend/node_modules/.bin/alert.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..4798d99[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/alert.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../alert/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../alert/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/is-ci b/Backend/node_modules/.bin/is-ci[m
[1mnew file mode 100644[m
[1mindex 0000000..e79342f[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-ci[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../is-ci/bin.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../is-ci/bin.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/is-ci.cmd b/Backend/node_modules/.bin/is-ci.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..e3276c0[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-ci.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\is-ci\bin.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/is-ci.ps1 b/Backend/node_modules/.bin/is-ci.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..3fe2340[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-ci.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../is-ci/bin.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../is-ci/bin.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/is-docker b/Backend/node_modules/.bin/is-docker[m
[1mnew file mode 100644[m
[1mindex 0000000..6211ce4[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-docker[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../is-docker/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../is-docker/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/is-docker.cmd b/Backend/node_modules/.bin/is-docker.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..e259815[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-docker.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\is-docker\cli.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/is-docker.ps1 b/Backend/node_modules/.bin/is-docker.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..7c58800[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/is-docker.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../is-docker/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../is-docker/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/mime b/Backend/node_modules/.bin/mime[m
[1mnew file mode 100644[m
[1mindex 0000000..91e5e16[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mime[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../mime/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../mime/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/mime.cmd b/Backend/node_modules/.bin/mime.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..746a279[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mime.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\mime\cli.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/mime.ps1 b/Backend/node_modules/.bin/mime.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..a6f6f47[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mime.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../mime/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../mime/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/mkdirp b/Backend/node_modules/.bin/mkdirp[m
[1mnew file mode 100644[m
[1mindex 0000000..bcd333f[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mkdirp[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../mkdirp/bin/cmd.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../mkdirp/bin/cmd.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/mkdirp.cmd b/Backend/node_modules/.bin/mkdirp.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..c2c9350[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mkdirp.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\mkdirp\bin\cmd.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/mkdirp.ps1 b/Backend/node_modules/.bin/mkdirp.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..35ce690[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/mkdirp.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../mkdirp/bin/cmd.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../mkdirp/bin/cmd.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/node-which b/Backend/node_modules/.bin/node-which[m
[1mnew file mode 100644[m
[1mindex 0000000..cd9503c[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/node-which[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../which/bin/node-which" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../which/bin/node-which" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/node-which.cmd b/Backend/node_modules/.bin/node-which.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..7060445[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/node-which.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\which\bin\node-which" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/node-which.ps1 b/Backend/node_modules/.bin/node-which.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..60d6560[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/node-which.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../which/bin/node-which" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../which/bin/node-which" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nodemon b/Backend/node_modules/.bin/nodemon[m
[1mnew file mode 100644[m
[1mindex 0000000..439386d[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodemon[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../nodemon/bin/nodemon.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../nodemon/bin/nodemon.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nodemon.cmd b/Backend/node_modules/.bin/nodemon.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..2ef2888[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodemon.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\nodemon\bin\nodemon.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/nodemon.ps1 b/Backend/node_modules/.bin/nodemon.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..413e5cb[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodemon.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../nodemon/bin/nodemon.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../nodemon/bin/nodemon.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nodetouch b/Backend/node_modules/.bin/nodetouch[m
[1mnew file mode 100644[m
[1mindex 0000000..1f7f001[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodetouch[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../touch/bin/nodetouch.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../touch/bin/nodetouch.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nodetouch.cmd b/Backend/node_modules/.bin/nodetouch.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..1f78c68[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodetouch.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\touch\bin\nodetouch.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/nodetouch.ps1 b/Backend/node_modules/.bin/nodetouch.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..236659c[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nodetouch.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../touch/bin/nodetouch.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../touch/bin/nodetouch.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nopt b/Backend/node_modules/.bin/nopt[m
[1mnew file mode 100644[m
[1mindex 0000000..e658aac[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nopt[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../nopt/bin/nopt.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../nopt/bin/nopt.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/nopt.cmd b/Backend/node_modules/.bin/nopt.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..c92ec03[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nopt.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\nopt\bin\nopt.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/nopt.ps1 b/Backend/node_modules/.bin/nopt.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..68c40bf[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/nopt.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../nopt/bin/nopt.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../nopt/bin/nopt.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/rc b/Backend/node_modules/.bin/rc[m
[1mnew file mode 100644[m
[1mindex 0000000..9e01626[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/rc[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../rc/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../rc/cli.js" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/rc.cmd b/Backend/node_modules/.bin/rc.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..aedece9[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/rc.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\rc\cli.js" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/rc.ps1 b/Backend/node_modules/.bin/rc.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..ac2cd2a[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/rc.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../rc/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../rc/cli.js" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/semver b/Backend/node_modules/.bin/semver[m
[1mnew file mode 100644[m
[1mindex 0000000..10497aa[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/semver[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../semver/bin/semver" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../semver/bin/semver" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/semver.cmd b/Backend/node_modules/.bin/semver.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..eb3aaa1[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/semver.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\semver\bin\semver" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/semver.ps1 b/Backend/node_modules/.bin/semver.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..a3315ff[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/semver.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../semver/bin/semver" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../semver/bin/semver" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/uuid b/Backend/node_modules/.bin/uuid[m
[1mnew file mode 100644[m
[1mindex 0000000..316d9ab[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/uuid[m
[36m@@ -0,0 +1,15 @@[m
[32m+[m[32m#!/bin/sh[m
[32m+[m[32mbasedir=$(dirname "$(echo "$0" | sed -e 's,\\,/,g')")[m
[32m+[m
[32m+[m[32mcase `uname` in[m
[32m+[m[32m    *CYGWIN*|*MINGW*|*MSYS*) basedir=`cygpath -w "$basedir"`;;[m
[32m+[m[32mesac[m
[32m+[m
[32m+[m[32mif [ -x "$basedir/node" ]; then[m
[32m+[m[32m  "$basedir/node"  "$basedir/../uuid/dist/bin/uuid" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32melse[m[41m [m
[32m+[m[32m  node  "$basedir/../uuid/dist/bin/uuid" "$@"[m
[32m+[m[32m  ret=$?[m
[32m+[m[32mfi[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.bin/uuid.cmd b/Backend/node_modules/.bin/uuid.cmd[m
[1mnew file mode 100644[m
[1mindex 0000000..37dae17[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/uuid.cmd[m
[36m@@ -0,0 +1,17 @@[m
[32m+[m[32m@ECHO off[m
[32m+[m[32mSETLOCAL[m
[32m+[m[32mCALL :find_dp0[m
[32m+[m
[32m+[m[32mIF EXIST "%dp0%\node.exe" ([m
[32m+[m[32m  SET "_prog=%dp0%\node.exe"[m
[32m+[m[32m) ELSE ([m
[32m+[m[32m  SET "_prog=node"[m
[32m+[m[32m  SET PATHEXT=%PATHEXT:;.JS;=;%[m
[32m+[m[32m)[m
[32m+[m
[32m+[m[32m"%_prog%"  "%dp0%\..\uuid\dist\bin\uuid" %*[m
[32m+[m[32mENDLOCAL[m
[32m+[m[32mEXIT /b %errorlevel%[m
[32m+[m[32m:find_dp0[m
[32m+[m[32mSET dp0=%~dp0[m
[32m+[m[32mEXIT /b[m
[1mdiff --git a/Backend/node_modules/.bin/uuid.ps1 b/Backend/node_modules/.bin/uuid.ps1[m
[1mnew file mode 100644[m
[1mindex 0000000..58e864b[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.bin/uuid.ps1[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m#!/usr/bin/env pwsh[m
[32m+[m[32m$basedir=Split-Path $MyInvocation.MyCommand.Definition -Parent[m
[32m+[m
[32m+[m[32m$exe=""[m
[32m+[m[32mif ($PSVersionTable.PSVersion -lt "6.0" -or $IsWindows) {[m
[32m+[m[32m  # Fix case when both the Windows and Linux builds of Node[m
[32m+[m[32m  # are installed in the same directory[m
[32m+[m[32m  $exe=".exe"[m
[32m+[m[32m}[m
[32m+[m[32m$ret=0[m
[32m+[m[32mif (Test-Path "$basedir/node$exe") {[m
[32m+[m[32m  & "$basedir/node$exe"  "$basedir/../uuid/dist/bin/uuid" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m} else {[m
[32m+[m[32m  & "node$exe"  "$basedir/../uuid/dist/bin/uuid" $args[m
[32m+[m[32m  $ret=$LASTEXITCODE[m
[32m+[m[32m}[m
[32m+[m[32mexit $ret[m
[1mdiff --git a/Backend/node_modules/.package-lock.json b/Backend/node_modules/.package-lock.json[m
[1mnew file mode 100644[m
[1mindex 0000000..0ff1559[m
[1m--- /dev/null[m
[1m+++ b/Backend/node_modules/.package-lock.json[m
[36m@@ -0,0 +1,2273 @@[m
[32m+[m[32m{[m
[32m+[m[32m  "name": "backend",[m
[32m+[m[32m  "version": "1.0.0",[m
[32m+[m[32m  "lockfileVersion": 2,[m
[32m+[m[32m  "requires": true,[m
[32m+[m[32m  "packages": {[m
[32m+[m[32m    "node_modules/@sindresorhus/is": {[m
[32m+[m[32m      "version": "0.14.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/@sindresorhus/is/-/is-0.14.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-9NET910DNaIPngYnLLPeg+Ogzqsi9uM4mSboU5y6p8S5DzMTVEsJZrawi+BoDNUVBa2DhJqQYUFvMDfgU062LQ==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/@szmarczak/http-timer": {[m
[32m+[m[32m      "version": "1.1.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/@szmarczak/http-timer/-/http-timer-1.1.2.tgz",[m
[32m+[m[32m      "integrity": "sha512-XIB2XbzHTN6ieIjfIMV9hlVcfPU26s2vafYWQcZHWXHOxiaRZYEDKEwdl129Zyg50+foYV2jCgtrqSA6qNuNSA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "defer-to-connect": "^1.0.1"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/abbrev": {[m
[32m+[m[32m      "version": "1.1.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/abbrev/-/abbrev-1.1.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-nne9/IiQ/hzIhY6pdDnbBtz7DjPTKrY00P/zvPSm5pOFkl6xuGrGnXn/VtTNNfNtAfZ9/1RtehkszU9qcTii0Q=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/accepts": {[m
[32m+[m[32m      "version": "1.3.7",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/accepts/-/accepts-1.3.7.tgz",[m
[32m+[m[32m      "integrity": "sha512-Il80Qs2WjYlJIBNzNkK6KYqlVMTbZLXgHx2oT0pU/fjRHyEp+PEfEPY0R3WCwAGVOtauxh1hOxNgIf5bv7dQpA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "mime-types": "~2.1.24",[m
[32m+[m[32m        "negotiator": "0.6.2"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/alert": {[m
[32m+[m[32m      "version": "5.0.5",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/alert/-/alert-5.0.5.tgz",[m
[32m+[m[32m      "integrity": "sha512-QoBVHqMNj8rMBc7PY405qkrTzvIWVp7Rzcdkh3KHuCxiCtnZRFUj5lA6Rslc3UYfsr8QKexqPAcGOwMHu2xCUA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "is-program-installed": "2.1.1"[m
[32m+[m[32m      },[m
[32m+[m[32m      "bin": {[m
[32m+[m[32m        "alert": "cli.js"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=10.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ansi-align": {[m
[32m+[m[32m      "version": "3.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ansi-align/-/ansi-align-3.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-ZpClVKqXN3RGBmKibdfWzqCY4lnjEuoNzU5T0oEFpfd/z5qJHVarukridD4juLO2FXMiwUQxr9WqQtaYa8XRYw==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "string-width": "^3.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ansi-align/node_modules/string-width": {[m
[32m+[m[32m      "version": "3.1.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/string-width/-/string-width-3.1.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-vafcv6KjVZKSgz06oM/H6GDBrAtz8vdhQakGjFIvNrHA6y3HCF1CInLy+QLq8dTJPQ1b+KDUqDFctkdRW44e1w==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "emoji-regex": "^7.0.1",[m
[32m+[m[32m        "is-fullwidth-code-point": "^2.0.0",[m
[32m+[m[32m        "strip-ansi": "^5.1.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ansi-regex": {[m
[32m+[m[32m      "version": "4.1.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ansi-regex/-/ansi-regex-4.1.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-1apePfXM1UOSqw0o9IiFAovVz9M5S1Dg+4TrDwfMewQ6p/rmMueb7tWZjQ1rx4Loy1ArBggoqGpfqqdI4rondg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ansi-styles": {[m
[32m+[m[32m      "version": "4.3.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ansi-styles/-/ansi-styles-4.3.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-zbB9rCJAT1rbjiVDb2hqKFHNYLxgtk8NURxZ3IZwD3F6NtxbXZQCnnSi1Lkx+IDohdPlFp222wVALIheZJQSEg==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "color-convert": "^2.0.1"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/anymatch": {[m
[32m+[m[32m      "version": "3.1.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/anymatch/-/anymatch-3.1.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-mM8522psRCqzV+6LhomX5wgp25YVibjh8Wj23I5RPkPppSVSjyKD2A2mBJmWGa+KN7f2D6LNh9jkBCeyLktzjg==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "normalize-path": "^3.0.0",[m
[32m+[m[32m        "picomatch": "^2.0.4"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/append-field": {[m
[32m+[m[32m      "version": "1.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/append-field/-/append-field-1.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha1-HjRA6RXwsSA9I3SOeO3XubW0PlY="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/array-flatten": {[m
[32m+[m[32m      "version": "1.1.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/array-flatten/-/array-flatten-1.1.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-ml9pkFGx5wczKPKgCJaLZOopVdI="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/at-least-node": {[m
[32m+[m[32m      "version": "1.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/at-least-node/-/at-least-node-1.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-+q/t7Ekv1EDY2l6Gda6LLiX14rU9TV20Wa3ofeQmwPFZbOMo9DXrLbOjFaaclkXKWidIaopwAObQDqwWtGUjqg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 4.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/balanced-match": {[m
[32m+[m[32m      "version": "1.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/balanced-match/-/balanced-match-1.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha1-ibTRmasr7kneFk6gK4nORi1xt2c="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/bcrypt-nodejs": {[m
[32m+[m[32m      "version": "0.0.3",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/bcrypt-nodejs/-/bcrypt-nodejs-0.0.3.tgz",[m
[32m+[m[32m      "integrity": "sha1-xgkX8m3CNWYVZsaBBhwwPCsohCs="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/binary-extensions": {[m
[32m+[m[32m      "version": "2.1.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/binary-extensions/-/binary-extensions-2.1.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-1Yj8h9Q+QDF5FzhMs/c9+6UntbD5MkRfRwac8DoEm9ZfUBZ7tZ55YcGVAzEe4bXsdQHEk+s9S5wsOKVdZrw0tQ==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/bl": {[m
[32m+[m[32m      "version": "2.2.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/bl/-/bl-2.2.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-6Pesp1w0DEX1N550i/uGV/TqucVL4AM/pgThFSN/Qq9si1/DF9aIHs1BxD8V/QU0HoeHO6cQRTAuYnLPKq1e4g==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "readable-stream": "^2.3.5",[m
[32m+[m[32m        "safe-buffer": "^5.1.1"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/bluebird": {[m
[32m+[m[32m      "version": "3.5.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/bluebird/-/bluebird-3.5.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-MKiLiV+I1AA596t9w1sQJ8jkiSr5+ZKi0WKrYGUn6d1Fx+Ij4tIj+m2WMQSGczs5jZVxV339chE8iwk6F64wjA=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/body-parser": {[m
[32m+[m[32m      "version": "1.19.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/body-parser/-/body-parser-1.19.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-dhEPs72UPbDnAQJ9ZKMNTP6ptJaionhP5cBb541nXPlW60Jepo9RV/a4fX4XWW9CuFNK22krhrj1+rgzifNCsw==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "bytes": "3.1.0",[m
[32m+[m[32m        "content-type": "~1.0.4",[m
[32m+[m[32m        "debug": "2.6.9",[m
[32m+[m[32m        "depd": "~1.1.2",[m
[32m+[m[32m        "http-errors": "1.7.2",[m
[32m+[m[32m        "iconv-lite": "0.4.24",[m
[32m+[m[32m        "on-finished": "~2.3.0",[m
[32m+[m[32m        "qs": "6.7.0",[m
[32m+[m[32m        "raw-body": "2.4.0",[m
[32m+[m[32m        "type-is": "~1.6.17"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/boxen": {[m
[32m+[m[32m      "version": "4.2.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/boxen/-/boxen-4.2.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-eB4uT9RGzg2odpER62bBwSLvUeGC+WbRjjyyFhGsKnc8wp/m0+hQsMUvUe3H2V0D5vw0nBdO1hCJoZo5mKeuIQ==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "ansi-align": "^3.0.0",[m
[32m+[m[32m        "camelcase": "^5.3.1",[m
[32m+[m[32m        "chalk": "^3.0.0",[m
[32m+[m[32m        "cli-boxes": "^2.2.0",[m
[32m+[m[32m        "string-width": "^4.1.0",[m
[32m+[m[32m        "term-size": "^2.1.0",[m
[32m+[m[32m        "type-fest": "^0.8.1",[m
[32m+[m[32m        "widest-line": "^3.1.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/brace-expansion": {[m
[32m+[m[32m      "version": "1.1.11",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/brace-expansion/-/brace-expansion-1.1.11.tgz",[m
[32m+[m[32m      "integrity": "sha512-iCuPHDFgrHX7H2vEI/5xpz07zSHB00TpugqhmYtVmMO6518mCuRMoOYFldEBl0g187ufozdaHgWKcYFb61qGiA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "balanced-match": "^1.0.0",[m
[32m+[m[32m        "concat-map": "0.0.1"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/braces": {[m
[32m+[m[32m      "version": "3.0.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/braces/-/braces-3.0.2.tgz",[m
[32m+[m[32m      "integrity": "sha512-b8um+L1RzM3WDSzvhm6gIz1yfTbBt6YTlcEKAvsmqCZZFw46z626lVj9j1yEPW33H5H+lBQpZMP1k8l+78Ha0A==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "fill-range": "^7.0.1"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/bson": {[m
[32m+[m[32m      "version": "1.1.5",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/bson/-/bson-1.1.5.tgz",[m
[32m+[m[32m      "integrity": "sha512-kDuEzldR21lHciPQAIulLs1LZlCXdLziXI6Mb/TDkwXhb//UORJNPXgcRs2CuO4H0DcMkpfT3/ySsP3unoZjBg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=0.6.19"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/buffer-equal-constant-time": {[m
[32m+[m[32m      "version": "1.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/buffer-equal-constant-time/-/buffer-equal-constant-time-1.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-+OcRMvf/5uAaXJaXpMbz5I1cyBk="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/buffer-from": {[m
[32m+[m[32m      "version": "1.1.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/buffer-from/-/buffer-from-1.1.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-MQcXEUbCKtEo7bhqEs6560Hyd4XaovZlO/k9V3hjVUF/zwW7KBVdSK4gIt/bzwS9MbR5qob+F5jusZsb0YQK2A=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/busboy": {[m
[32m+[m[32m      "version": "0.2.14",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/busboy/-/busboy-0.2.14.tgz",[m
[32m+[m[32m      "integrity": "sha1-bCpiLvz0fFe7vh4qnDetNseSVFM=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "dicer": "0.2.5",[m
[32m+[m[32m        "readable-stream": "1.1.x"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=0.8.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/busboy/node_modules/isarray": {[m
[32m+[m[32m      "version": "0.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/isarray/-/isarray-0.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-ihis/Kmo9Bd+Cav8YDiTmwXR7t8="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/busboy/node_modules/readable-stream": {[m
[32m+[m[32m      "version": "1.1.14",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/readable-stream/-/readable-stream-1.1.14.tgz",[m
[32m+[m[32m      "integrity": "sha1-fPTFTvZI44EwhMY23SB54WbAgdk=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "core-util-is": "~1.0.0",[m
[32m+[m[32m        "inherits": "~2.0.1",[m
[32m+[m[32m        "isarray": "0.0.1",[m
[32m+[m[32m        "string_decoder": "~0.10.x"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/busboy/node_modules/string_decoder": {[m
[32m+[m[32m      "version": "0.10.31",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/string_decoder/-/string_decoder-0.10.31.tgz",[m
[32m+[m[32m      "integrity": "sha1-YuIDvEF2bGwoyfyEMB2rHFMQ+pQ="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/bytes": {[m
[32m+[m[32m      "version": "3.1.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/bytes/-/bytes-3.1.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-zauLjrfCG+xvoyaqLoV8bLVXXNGC4JqlxFCutSDWA6fJrTo2ZuvLYTqZ7aHBLZSMOopbzwv8f+wZcVzfVTI2Dg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cacheable-request": {[m
[32m+[m[32m      "version": "6.1.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/cacheable-request/-/cacheable-request-6.1.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-Oj3cAGPCqOZX7Rz64Uny2GYAZNliQSqfbePrgAQ1wKAihYmCUnraBtJtKcGR4xz7wF+LoJC+ssFZvv5BgF9Igg==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "clone-response": "^1.0.2",[m
[32m+[m[32m        "get-stream": "^5.1.0",[m
[32m+[m[32m        "http-cache-semantics": "^4.0.0",[m
[32m+[m[32m        "keyv": "^3.0.0",[m
[32m+[m[32m        "lowercase-keys": "^2.0.0",[m
[32m+[m[32m        "normalize-url": "^4.1.0",[m
[32m+[m[32m        "responselike": "^1.0.2"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cacheable-request/node_modules/get-stream": {[m
[32m+[m[32m      "version": "5.2.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/get-stream/-/get-stream-5.2.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-nBF+F1rAZVCu/p7rjzgA+Yb4lfYXrpl7a6VmJrU8wF9I1CKvP/QwPNZHnOlwbTkY6dvtFIzFMSyQXbLoTQPRpA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "pump": "^3.0.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cacheable-request/node_modules/lowercase-keys": {[m
[32m+[m[32m      "version": "2.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/lowercase-keys/-/lowercase-keys-2.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-tqNXrS78oMOE73NMxK4EMLQsQowWf8jKooH9g7xPavRT706R6bkQJ6DY2Te7QukaZsulxa30wQ7bk0pm4XiHmA==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/camelcase": {[m
[32m+[m[32m      "version": "5.3.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/camelcase/-/camelcase-5.3.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-L28STB170nwWS63UjtlEOE3dldQApaJXZkOI1uMFfzf3rRuPegHaHesyee+YxQ+W6SvRDQV6UrdOdRiR153wJg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/chalk": {[m
[32m+[m[32m      "version": "3.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/chalk/-/chalk-3.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-4D3B6Wf41KOYRFdszmDqMCGq5VV/uMAB273JILmO+3jAlh8X4qDtdtgCR3fxtbLEMzSx22QdhnDcJvu2u1fVwg==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "ansi-styles": "^4.1.0",[m
[32m+[m[32m        "supports-color": "^7.1.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/chalk/node_modules/has-flag": {[m
[32m+[m[32m      "version": "4.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/has-flag/-/has-flag-4.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-EykJT/Q1KjTWctppgIAgfSO0tKVuZUjhgMr17kqTumMl6Afv3EISleU7qZUzoXDFTAHTDC4NOoG/ZxU3EvlMPQ==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/chalk/node_modules/supports-color": {[m
[32m+[m[32m      "version": "7.2.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/supports-color/-/supports-color-7.2.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-qpCAvRl9stuOHveKsn7HncJRvv501qIacKzQlO/+Lwxc9+0q2wLyv4Dfvt80/DPn2pqOBsJdDiogXGR9+OvwRw==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "has-flag": "^4.0.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/chokidar": {[m
[32m+[m[32m      "version": "3.4.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/chokidar/-/chokidar-3.4.2.tgz",[m
[32m+[m[32m      "integrity": "sha512-IZHaDeBeI+sZJRX7lGcXsdzgvZqKv6sECqsbErJA4mHWfpRrD8B97kSFN4cQz6nGBGiuFia1MKR4d6c1o8Cv7A==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "anymatch": "~3.1.1",[m
[32m+[m[32m        "braces": "~3.0.2",[m
[32m+[m[32m        "glob-parent": "~5.1.0",[m
[32m+[m[32m        "is-binary-path": "~2.1.0",[m
[32m+[m[32m        "is-glob": "~4.0.1",[m
[32m+[m[32m        "normalize-path": "~3.0.0",[m
[32m+[m[32m        "readdirp": "~3.4.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 8.10.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "optionalDependencies": {[m
[32m+[m[32m        "fsevents": "~2.1.2"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ci-info": {[m
[32m+[m[32m      "version": "2.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ci-info/-/ci-info-2.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-5tK7EtrZ0N+OLFMthtqOj4fI2Jeb88C4CAZPu25LDVUgXJ0A3Js4PMGqrn0JU1W0Mh1/Z8wZzYPxqUrXeBboCQ=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cli-boxes": {[m
[32m+[m[32m      "version": "2.2.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/cli-boxes/-/cli-boxes-2.2.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-y4coMcylgSCdVinjiDBuR8PCC2bLjyGTwEmPb9NHR/QaNU6EUOXcTY/s6VjGMD6ENSEaeQYHCY0GNGS5jfMwPw==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/clone-response": {[m
[32m+[m[32m      "version": "1.0.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/clone-response/-/clone-response-1.0.2.tgz",[m
[32m+[m[32m      "integrity": "sha1-0dyXOSAxTfZ/vrlCI7TuNQI56Ws=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "mimic-response": "^1.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/color-convert": {[m
[32m+[m[32m      "version": "2.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/color-convert/-/color-convert-2.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-RRECPsj7iu/xb5oKYcsFHSppFNnsj/52OVTRKb4zP5onXwVF3zVmmToNcOfGC+CRDpfK/U584fMg38ZHCaElKQ==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "color-name": "~1.1.4"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=7.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/color-name": {[m
[32m+[m[32m      "version": "1.1.4",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/color-name/-/color-name-1.1.4.tgz",[m
[32m+[m[32m      "integrity": "sha512-dOy+3AuW3a2wNbZHIuMZpTcgjGuLU/uBL/ubcZF9OXbDo8ff4O8yVp5Bf0efS8uEoYo5q4Fx7dY9OgQGXgAsQA=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/concat-map": {[m
[32m+[m[32m      "version": "0.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/concat-map/-/concat-map-0.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-2Klr13/Wjfd5OnMDajug1UBdR3s="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/concat-stream": {[m
[32m+[m[32m      "version": "1.6.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/concat-stream/-/concat-stream-1.6.2.tgz",[m
[32m+[m[32m      "integrity": "sha512-27HBghJxjiZtIk3Ycvn/4kbJk/1uZuJFfuPEns6LaEvpvG1f0hTea8lilrouyo9mVc2GWdcEZ8OLoGmSADlrCw==",[m
[32m+[m[32m      "engines": [[m
[32m+[m[32m        "node >= 0.8"[m
[32m+[m[32m      ],[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "buffer-from": "^1.0.0",[m
[32m+[m[32m        "inherits": "^2.0.3",[m
[32m+[m[32m        "readable-stream": "^2.2.2",[m
[32m+[m[32m        "typedarray": "^0.0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/configstore": {[m
[32m+[m[32m      "version": "5.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/configstore/-/configstore-5.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-aMKprgk5YhBNyH25hj8wGt2+D52Sw1DRRIzqBwLp2Ya9mFmY8KPvvtvmna8SxVR9JMZ4kzMD68N22vlaRpkeFA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "dot-prop": "^5.2.0",[m
[32m+[m[32m        "graceful-fs": "^4.1.2",[m
[32m+[m[32m        "make-dir": "^3.0.0",[m
[32m+[m[32m        "unique-string": "^2.0.0",[m
[32m+[m[32m        "write-file-atomic": "^3.0.0",[m
[32m+[m[32m        "xdg-basedir": "^4.0.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/content-disposition": {[m
[32m+[m[32m      "version": "0.5.3",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/content-disposition/-/content-disposition-0.5.3.tgz",[m
[32m+[m[32m      "integrity": "sha512-ExO0774ikEObIAEV9kDo50o+79VCUdEB6n6lzKgGwupcVeRlhrj3qGAfwq8G6uBJjkqLrhT0qEYFcWng8z1z0g==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "safe-buffer": "5.1.2"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/content-type": {[m
[32m+[m[32m      "version": "1.0.4",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/content-type/-/content-type-1.0.4.tgz",[m
[32m+[m[32m      "integrity": "sha512-hIP3EEPs8tB9AT1L+NUqtwOAps4mk2Zob89MWXMHjHWg9milF/j4osnnQLXBCBFBk/tvIG/tUc9mOUJiPBhPXA==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cookie": {[m
[32m+[m[32m      "version": "0.4.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/cookie/-/cookie-0.4.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-+Hp8fLp57wnUSt0tY0tHEXh4voZRDnoIrZPqlo3DPiI4y9lwg/jqx+1Om94/W6ZaPDOUbnjOt/99w66zk+l1Xg==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cookie-signature": {[m
[32m+[m[32m      "version": "1.0.6",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/cookie-signature/-/cookie-signature-1.0.6.tgz",[m
[32m+[m[32m      "integrity": "sha1-4wOogrNCzD7oylE6eZmXNNqzriw="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/core-util-is": {[m
[32m+[m[32m      "version": "1.0.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/core-util-is/-/core-util-is-1.0.2.tgz",[m
[32m+[m[32m      "integrity": "sha1-tf1UIgqivFq1eqtxQMlAdUUDwac="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/cors": {[m
[32m+[m[32m      "version": "2.8.5",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/cors/-/cors-2.8.5.tgz",[m
[32m+[m[32m      "integrity": "sha512-KIHbLJqu73RGr/hnbrO9uBeixNGuvSQjul/jdFvS/KFSIH1hWVd1ng7zOHx+YrEfInLG7q4n6GHQ9cDtxv/P6g==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "object-assign": "^4",[m
[32m+[m[32m        "vary": "^1"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.10"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/crypto-random-string": {[m
[32m+[m[32m      "version": "2.0.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/crypto-random-string/-/crypto-random-string-2.0.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-v1plID3y9r/lPhviJ1wrXpLeyUIGAZ2SHNYTEapm7/8A9nLPoyvVp3RK/EPFqn5kEznyWgYZNsRtYYIWbuG8KA==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/debug": {[m
[32m+[m[32m      "version": "2.6.9",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/debug/-/debug-2.6.9.tgz",[m
[32m+[m[32m      "integrity": "sha512-bC7ElrdJaJnPbAP+1EotYvqZsb3ecl5wi6Bfi6BJTUcNowp6cvspg0jXznRTKDjm/E7AdgFBVeAPVMNcKGsHMA==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "ms": "2.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/decompress-response": {[m
[32m+[m[32m      "version": "3.3.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/decompress-response/-/decompress-response-3.3.0.tgz",[m
[32m+[m[32m      "integrity": "sha1-gKTdMjdIOEv6JICDYirt7Jgq3/M=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "mimic-response": "^1.0.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=4"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/deep-extend": {[m
[32m+[m[32m      "version": "0.6.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/deep-extend/-/deep-extend-0.6.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-LOHxIOaPYdHlJRtCQfDIVZtfw/ufM8+rVj649RIHzcm/vGwQRXFt6OPqIFWsm2XEMrNIEtWR64sY1LEKD2vAOA==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=4.0.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/defer-to-connect": {[m
[32m+[m[32m      "version": "1.1.3",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/defer-to-connect/-/defer-to-connect-1.1.3.tgz",[m
[32m+[m[32m      "integrity": "sha512-0ISdNousHvZT2EiFlZeZAHBUvSxmKswVCEf8hW7KWgG4a8MVEu/3Vb6uWYozkjylyCxe0JBIiRB1jV45S70WVQ=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/denque": {[m
[32m+[m[32m      "version": "1.4.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/denque/-/denque-1.4.1.tgz",[m
[32m+[m[32m      "integrity": "sha512-OfzPuSZKGcgr96rf1oODnfjqBFmr1DVoc/TrItj3Ohe0Ah1C5WX5Baquw/9U9KovnQ88EqmJbD66rKYUQYN1tQ==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=0.10"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/depd": {[m
[32m+[m[32m      "version": "1.1.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/depd/-/depd-1.1.2.tgz",[m
[32m+[m[32m      "integrity": "sha1-m81S4UwJd2PnSbJ0xDRu0uVgtak=",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.6"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/destroy": {[m
[32m+[m[32m      "version": "1.0.4",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/destroy/-/destroy-1.0.4.tgz",[m
[32m+[m[32m      "integrity": "sha1-l4hXRCxEdJ5CBmE+N5RiBYJqvYA="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/dicer": {[m
[32m+[m[32m      "version": "0.2.5",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/dicer/-/dicer-0.2.5.tgz",[m
[32m+[m[32m      "integrity": "sha1-WZbAhrszIYyBLAkL3cCc0S+stw8=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "readable-stream": "1.1.x",[m
[32m+[m[32m        "streamsearch": "0.1.2"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=0.8.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/dicer/node_modules/isarray": {[m
[32m+[m[32m      "version": "0.0.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/isarray/-/isarray-0.0.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-ihis/Kmo9Bd+Cav8YDiTmwXR7t8="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/dicer/node_modules/readable-stream": {[m
[32m+[m[32m      "version": "1.1.14",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/readable-stream/-/readable-stream-1.1.14.tgz",[m
[32m+[m[32m      "integrity": "sha1-fPTFTvZI44EwhMY23SB54WbAgdk=",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "core-util-is": "~1.0.0",[m
[32m+[m[32m        "inherits": "~2.0.1",[m
[32m+[m[32m        "isarray": "0.0.1",[m
[32m+[m[32m        "string_decoder": "~0.10.x"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/dicer/node_modules/string_decoder": {[m
[32m+[m[32m      "version": "0.10.31",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/string_decoder/-/string_decoder-0.10.31.tgz",[m
[32m+[m[32m      "integrity": "sha1-YuIDvEF2bGwoyfyEMB2rHFMQ+pQ="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/dot-prop": {[m
[32m+[m[32m      "version": "5.3.0",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/dot-prop/-/dot-prop-5.3.0.tgz",[m
[32m+[m[32m      "integrity": "sha512-QM8q3zDe58hqUqjraQOmzZ1LIH9SWQJTlEKCH4kJ2oQvLZk7RbQXvtDM2XEq3fwkV9CCvvH4LA0AV+ogFsBM2Q==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "is-obj": "^2.0.0"[m
[32m+[m[32m      },[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">=8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/duplexer3": {[m
[32m+[m[32m      "version": "0.1.4",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/duplexer3/-/duplexer3-0.1.4.tgz",[m
[32m+[m[32m      "integrity": "sha1-7gHdHKwO08vH/b6jfcCo8c4ALOI="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ecdsa-sig-formatter": {[m
[32m+[m[32m      "version": "1.0.11",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ecdsa-sig-formatter/-/ecdsa-sig-formatter-1.0.11.tgz",[m
[32m+[m[32m      "integrity": "sha512-nagl3RYrbNv6kQkeJIpt6NJZy8twLB/2vtz6yN9Z4vRKHN4/QZJIEbqohALSgwKdnksuY3k5Addp5lg8sVoVcQ==",[m
[32m+[m[32m      "dependencies": {[m
[32m+[m[32m        "safe-buffer": "^5.0.1"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/ee-first": {[m
[32m+[m[32m      "version": "1.1.1",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/ee-first/-/ee-first-1.1.1.tgz",[m
[32m+[m[32m      "integrity": "sha1-WQxhFWsK4vTwJVcyoViyZrxWsh0="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/email-validator": {[m
[32m+[m[32m      "version": "2.0.4",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/email-validator/-/email-validator-2.0.4.tgz",[m
[32m+[m[32m      "integrity": "sha512-gYCwo7kh5S3IDyZPLZf6hSS0MnZT8QmJFqYvbqlDZSbwdZlY6QZWxJ4i/6UhITOJ4XzyI647Bm2MXKCLqnJ4nQ==",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">4.0"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/emoji-regex": {[m
[32m+[m[32m      "version": "7.0.3",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/emoji-regex/-/emoji-regex-7.0.3.tgz",[m
[32m+[m[32m      "integrity": "sha512-CwBLREIQ7LvYFB0WyRvwhq5N5qPhc6PMjD6bYggFlI5YyDgl+0vxq5VHbMOFqLg7hfWzmu8T5Z1QofhmTIhItA=="[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/encodeurl": {[m
[32m+[m[32m      "version": "1.0.2",[m
[32m+[m[32m      "resolved": "https://registry.npmjs.org/encodeurl/-/encodeurl-1.0.2.tgz",[m
[32m+[m[32m      "integrity": "sha1-rT/0yG7C0CkyL1oCw6mmBslbP1k=",[m
[32m+[m[32m      "engines": {[m
[32m+[m[32m        "node": ">= 0.8"[m
[32m+[m[32m      }[m
[32m+[m[32m    },[m
[32m+[m[32m    "node_modules/end-of-stream": {[m
[32m+[m[32m      "version"
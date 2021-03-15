import { Component, OnInit } from '@angular/core';
import { HttpErrorResponse } from "@angular/common/http";
import { Router } from "@angular/router";
import { AuthService } from 'src/app/services/auth.service';
//import { ConfigService } from 'src/app/services/config.service';
//import { Model } from './projectModel';
//import {Validation} from './validations';
//import {MatFormFieldModule} from '@angular/material/form-field';
//import {FormControl} from '@angular/forms';

@Component({
  selector: 'abe-new-project-form',
  templateUrl: './new-project-form.component.html',
  styleUrls: ['./new-project-form.component.scss']
})
export class NewProjectFormComponent implements OnInit {
  proyecto={
    titulo: '',
    descripcion: '',
    visibilidad: '',
    presupuesto: 0,
    timeframe: '',
    roles: '',
    herramientas: '',
    fecha_creacion: ''
  }

  constructor(
    private authService: AuthService,
    private router:Router
  ) { }

  ngOnInit(): void {
  }

  roles = [
    'Diseñador',
    'Desarrolador Senior',
    'Desarrollador Junior',
    'Desarrollador fullstack',
    'Desarrollador frontend',
    'Desarrollador Backend',
    'Desarrolador Android',
    'Desarrolador IOS',
    'Soporte Tecnico',
    'Help Desk',
    'Administrador de Base de datos',
    'Product Owner',
    'Servicio al cliente',
    'Ventas',
  ];
  herramientas = [
    'Javascript',
    'HTML',
    'CSS',
    'Mysql',
    'React',
    'PHP',
    'Laravel',
    'Python',
    'Angular',
    'Node',
  ];

  timeframes = [
    'Indefinido',
    'Menos de una semana',
    '1 Semana',
    '1 Mes',
    '3 meses',
    '6 meses',
  ];
  //Variables de control de validaciones
  emptyTitulo=false;
  emptyDescripcion=false;
  camposIncompletos=false;

  current= new Date();
  //month= this.current.getMonth();



  submitNewProjectForm(){
    this.validationPresupuesto();
    if (this.proyecto.titulo==="" || this.proyecto.descripcion===""|| this.proyecto.presupuesto===0 ){
      this.camposIncompletos=true;
    }
    else {
      this.proyecto.fecha_creacion=this.current as unknown as string;
      this.authService.NewProjectForm(this.proyecto)
      .subscribe(
       res =>{
         console.log(res.estado);
         alert("Projecto publicado exitosamente");
       },
       err =>{
         if (err instanceof HttpErrorResponse) {
           if (err.status === 401) {
           }
         }
       }
     )
    }


  };

  validationPresupuesto(){
    if (this.proyecto.titulo===""){
      this.emptyTitulo=true;
    }
    if (this.proyecto.descripcion===""){
      this.emptyDescripcion=true;
    }
    if (this.proyecto.timeframe===""){
      this.emptyDescripcion=true;
    }
  };
  validationTitulo(){

  };

}

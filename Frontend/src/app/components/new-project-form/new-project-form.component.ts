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

  //model=new Model('arthurfleck@unah.hn','','','',20000,'','','','');

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
  };

  validationPresupuesto(){

  };
  validationTitulo(){

  };

}

import { Component, OnInit } from '@angular/core';
import { HttpErrorResponse } from "@angular/common/http";
import { Router } from "@angular/router";
import { AuthService } from 'src/app/services/auth.service';
import * as alertify from 'alertifyjs';
import Swal from "sweetalert2/dist/sweetalert2.js";


@Component({
  selector: 'abe-new-project-form',
  templateUrl: './new-project-form.component.html',
  styleUrls: ['./new-project-form.component.scss']
})
export class NewProjectFormComponent implements OnInit {
  proyecto={
    titulo: '',
    descripcion: '',
    visibilidad: 'no',
    presupuesto: 1000,
    timeframe: '',
    roles: 'indefinido',
    herramientas: [],
    fecha_creacion: null
  }

  constructor(
    private authService: AuthService,
    private router:Router
  ) { }

  ngOnInit(): void {
    this.proyecto.fecha_creacion= this.current;
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
    'HTML',
    'CSS',
    'Javascript',
    'PHP',
    'Python',
    'Java',
    'C',
    'C#',
    'C++',
    'R',
    'Swift',
    'Laravel',
    'React',
    'Angular',
    'Ruby on Rails',
    'Django',
    'ASP.NET',
    'Express',
    'Vue',
    'Node',
    'Mysql',
    'Oracle',
    'PostgreSQL',
    'MongoDB',
    'C#',
    'Amazon Web Services',
    'Ingles',
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
  wrongPresupuesto=false;
  emptyPresupesto=false;
  selectVisible=true;
  deselectVisible=false;

  //obtener tiempo
  current= new Date();
  //indice de herramientas
  indexHerramientas=0;


  submitNewProjectForm(){
    //revisa si se cumplen las funciones
    this.cleanValidations();
    this.validation();
    console.log(this.proyecto);
    //si se cumplen las validaciones se ejecuta el codigo
    if (this.emptyTitulo! || this.emptyDescripcion!|| this.wrongPresupuesto!   ){
      this.camposIncompletos=true;
    }
    else {
      this.proyecto.fecha_creacion=this.current as unknown as string;
      //this.proyecto.herramienta=this.selectedHerramientas;
      this.authService.NewProjectForm(this.proyecto)
      .subscribe(
       res =>{
         console.log(res.estado);
         alert("Projecto publicado exitosamente");
         this.router.navigate(['profile']);

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

  validation(){
    if (this.proyecto.titulo===""){
      this.emptyTitulo=true;
    }
    if (this.proyecto.descripcion===""){
      this.emptyDescripcion=true;
    }
    if (this.proyecto.presupuesto<1000 || this.proyecto.presupuesto>300000 ){
      this.wrongPresupuesto=true;
    }

  };

  cleanValidations(){
    this.emptyTitulo=false;
    this.emptyDescripcion=false;
    this.camposIncompletos=false;
    this.wrongPresupuesto=false;
    this.emptyPresupesto=false;
  }

  addHerramienta(herramienta){
    this.proyecto.herramientas.push(herramienta);
    this.indexHerramientas=this.herramientas.indexOf(herramienta);
    this.herramientas.splice(this.indexHerramientas,1);
  }
  removeHerramienta(herramienta){
    this.herramientas.push(herramienta);
    this.indexHerramientas=this.proyecto.herramientas.indexOf(herramienta);
    this.proyecto.herramientas.splice(this.indexHerramientas,1);
  }




}

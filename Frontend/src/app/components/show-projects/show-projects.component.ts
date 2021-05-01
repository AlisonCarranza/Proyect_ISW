import { DatePipe, formatDate } from '@angular/common';
import { Component, OnInit, ChangeDetectorRef, ViewChild } from '@angular/core';
import {AuthService} from '../../services/auth.service';
import { Router } from "@angular/router";
import { HttpErrorResponse } from '@angular/common/http';
import { ViewContainerRef } from '@angular/core';

@Component({
  selector: 'abe-show-projects',
  templateUrl: './show-projects.component.html',
  styleUrls: ['./show-projects.component.scss']
})
export class ShowProjectsComponent implements OnInit {

  @ViewChild('vc', {read: ViewContainerRef}) vc: ViewContainerRef;

  //elementos a mostrar en la card del html
    elements: any = [];
  /*variable para la cantidad de documentos de la base y asi saber el tamaño 
    que tendra el arreglo elements*/
    docs:number;
  //Arreglo para almacenar los datos recibidos de la consulta a la base
    projects:any=[];
    proyecto={
      _id:''
    }
  //variable para almacenar el email del usuario logueado.
    emailUser:string='';
  
  
  constructor(
    private cdRef: ChangeDetectorRef,
    private authService: AuthService,
    private router: Router) { }
  
  ngOnInit() {
    console.log("Carga el componente");
  if(!this.authService.loggedInDev()){
    this.router.navigate(['/home']);
  }else { 
  
  /*Llamado a la funcion que trae la consulta del backend*/
  this.authService.viewProject()
  .subscribe(
    res=>{
      this.projects=res;
      //console.log(this.projects);
  
      //Guardando el numero de elementos de la consulta hecha
      this.docs= this.projects.Project;
      //console.log(this.docs);
  
      //Guardando todos los elementos de la consulta hecha en projects
      this.projects= this.projects.proyecto;
      
      //console.log('muestra los proyectos',this.projects);
  
      //Llamado a la funcion que llena los elementos a mostrar 
      this.fillItems();
          
    },
    err=>{console.log('error al mostrar proyectos',err)}
  );
  }  
    
  }
  
  /* Permite llenar el arreglo elements para poder mostrar en pantalla determinados campos de los proyectos*/
  fillItems(){
    this.projects.forEach((project,id) => {
      console.log(project.email);
      console.log(this.emailUser);
        this.elements.push({
          ID:id.toString(),
          Titulo: this.projects[id].titulo,
          Descripcion: this.projects[id].descripcion,
          Fecha: this.projects[id].createdAt
        });
        console.log (this.projects[id].fecha_creacion)
        console.log(this.elements[0]);
      
    });
  }

}
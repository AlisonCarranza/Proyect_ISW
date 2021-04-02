import { DatePipe, formatDate } from '@angular/common';
import { Component, OnInit, ChangeDetectorRef, ViewChild } from '@angular/core';
import {AuthService} from '../../services/auth.service';
import { Router } from "@angular/router";
import { HttpErrorResponse } from '@angular/common/http';
import { ViewContainerRef } from '@angular/core';


@Component({
  selector: 'abe-projects',
  templateUrl: './projects.component.html',
  styleUrls: ['./projects.component.scss']
})
export class ProjectsComponent implements OnInit {
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

constructor(
  private cdRef: ChangeDetectorRef,
  private authService: AuthService,
  private router: Router) { }

ngOnInit() {
  console.log("Carga el componente");
if(!this.authService.loggedIn()){
  this.router.navigate(['/search-prof']);
}else { 

/*Llamado a la funcion que trae la consulta del backend*/
this.authService.viewProject()
.subscribe(
  res=>{
    this.projects=res;
    console.log(this.projects);

    //Guardando el numero de elementos de la consulta hecha
    this.docs= this.projects.Project;
    console.log(this.docs);

    //Guardando todos los elementos de la consulta hecha en projects
    this.projects= this.projects.proyecto;
    console.log('muestra los proyectos',this.projects);

    //Llamado a la funcion que llena los elementos a mostrar 
    this.fillItems(this.docs);
    
  },
  err=>{console.log('error al mostrar proyectos',err)}
);
}  
  
}

fillItems(limit: number){
for (let i = 0; i < limit; i++) {
  /*Llenando el arreglo de elementos, para agregar mas datos solo deben incluir una nueva linea
    Con la forma: nombreIndice: this.projects[i].campoDeLaConsulta*/
  this.elements.push({
    ID:i.toString(),
    Titulo: this.projects[i].titulo,
    Descripcion: this.projects[i].descripcion,
    Fecha: this.projects[i].fecha
  });

  console.log(this.elements[0]);
}
}


}


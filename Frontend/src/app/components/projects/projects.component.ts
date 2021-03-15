import { formatDate } from '@angular/common';
import { Component, OnInit, HostListener, ViewChild,AfterViewInit, ChangeDetectorRef } from '@angular/core';
import {MdbTableDirective, MdbTablePaginationComponent} from 'angular-bootstrap-md';
import {AuthService} from '../../services/auth.service';
import { Router } from "@angular/router";

@Component({
  selector: 'abe-projects',
  templateUrl: './projects.component.html',
  styleUrls: ['./projects.component.scss']
})
export class ProjectsComponent implements OnInit {

  el=null;
  //Childs necesarios para usar el ngAfterViewInit (para la paginacion)
  //@ViewChild(MdbTablePaginationComponent, { static: true }) mdbTablePagination: MdbTablePaginationComponent;
  //@ViewChild(MdbTableDirective, {static: true}) mdbTable:MdbTableDirective;

  //elementos a mostrar en la tabla del html
    elements: any = [];
  //variable para el Datasource de la tabla
    previous: string;
  /* variable para la cantidad de documentos de la base y asi saber el tamaño 
    que tendra el arreglo elements*/
    docs:number;
  //Arreglo para almacenar los datos recibidos de la consulta a la base
    projects:any=[];
    proyecto={
      correo:''
    }

  constructor(
    private cdRef: ChangeDetectorRef,
    private authService: AuthService,
    private router: Router) { }

ngOnInit() {
  if(!this.authService.loggedIn()){
    this.router.navigate(['/projects']);
  ///}else { 

  /*Llamado a la funcion que trae la consulta del backend, lleva un parametro (this.elements) 
    porque en el servicio "auth" deje la funcion como si fuese post, en realidad deberia ser
    get y no deberia llevar ningun parametro asi que no se sorprendan por ver eso ahi*/
  /*this.authService.viewProjects()
  .subscribe(
    res=>{
      //Guardando el numero de elementos de la consulta hecha
      this.docs=res.Project;
      console.log(this.docs);
      //Guardando todos los elementos de la consulta hecha en profeessionals
      this.projects=res.proyecto;
      //Llamado a la funcion que llena los elementos a mostrar en la tabla
      this.fillItems(this.docs);
      
    },
    err=>{console.log(err)}
  );*/
  }  
    
}

fillItems(limit){
  for (let i = 0; i < limit; i++) {
    /*Llenando el arreglo de elementos, para agregar mas datos solo deben incluir una nueva linea
      Con la forma: nombreIndice: this.developer[i].campoDeLaConsulta, tambien recuerden agregar un
      valor a headElements para el encabezado de cada columna que agreguen*/
    this.elements.push({
      ID:i.toString(),
      Nombre: this.projects[i].nombres,
      Apellido: this.projects[i].apellidos,
      Correo: this.projects[i].email,
      Genero: this.projects[i].sexo,
      Direccion: this.projects[i].direccion,
      Area: this.projects[i].area,
      Descripcion:this.projects[i].descripcion,
      PicPoroject:this.projects[i].picProject

    });
}
  //this.mdbTable.setDataSource(this.elements);
  //this.previous = this.mdbTable.getDataSource();
}
}

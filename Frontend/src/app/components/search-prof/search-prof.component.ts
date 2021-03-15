import { formatDate } from '@angular/common';
import { Component, OnInit, HostListener, ViewChild,AfterViewInit, ChangeDetectorRef } from '@angular/core';
import {MdbTableDirective, MdbTablePaginationComponent} from 'angular-bootstrap-md';
import {AuthService} from '../../services/auth.service';
import { Router } from "@angular/router";

@Component({
  selector: 'abe-search-prof',
  templateUrl: './search-prof.component.html',
  styleUrls: ['./search-prof.component.scss']
})
export class SearchProfComponent implements OnInit {
//Childs necesarios para usar el ngAfterViewInit (para la paginacion)
@ViewChild(MdbTablePaginationComponent, { static: true }) mdbTablePagination: MdbTablePaginationComponent;
@ViewChild(MdbTableDirective, {static: true}) mdbTable:MdbTableDirective;

//elementos a mostrar en la tabla del html
  elements: any = [];
//Arreglo de cabeceras de la tabla
  headElements = ['Profesión', 'Nombre', 'Apellido', 'Correo', 'Genero','Direccion'];
//variable para la busqueda
  searchText: string = '';
//variable para el Datasource de la tabla
  previous: string;
/* variable para la cantidad de documentos de la base y asi saber el tamaño 
  que tendra el arreglo elements*/
  docs:number;
//Arreglo para almacenar los datos recibidos de la consulta a la base
  professionals:any=[];
  professional={
    correo:''
  }

constructor(
  private cdRef: ChangeDetectorRef,
  private authService: AuthService,
  private router: Router) { }

//Listener para hacer la busqueda dinamica que no requiera un boton
@HostListener('input') oninput() {
  this.searchItems();
}

ngOnInit() {
if(!this.authService.loggedIn()){
  this.router.navigate(['/search-prof']);
//}else { 

/*Llamado a la funcion que trae la consulta del backend, lleva un parametro (this.elements) 
  porque en el servicio "auth" deje la funcion como si fuese post, en realidad deberia ser
  get y no deberia llevar ningun parametro asi que no se sorprendan por ver eso ahi*/
/*this.authService.searchProf()
.subscribe(
  res=>{
    //Guardando el numero de elementos de la consulta hecha
    this.docs=res.Professional;
    console.log(this.docs);
    //Guardando todos los elementos de la consulta hecha en profeessionals
    this.professionals=res.profesional;
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
    Nombre: this.professionals[i].nombre,
    Apellido: this.professionals[i].apellido,
    Correo: this.professionals[i].email,
    Genero: this.professionals[i].sexo,
    Direccion: this.professionals[i].direccion,
    Area: this.professionals[i].profesion
  });
}
this.mdbTable.setDataSource(this.elements);
this.previous = this.mdbTable.getDataSource();
}

searchItems() {
  const prev = this.mdbTable.getDataSource();
  if (!this.searchText) {
      this.mdbTable.setDataSource(this.previous);
      this.elements = this.mdbTable.getDataSource();
  }
  if (this.searchText) {
    /*Busqueda dentro de los datos de la tabla, si se desea agregar un nuevo campo a la busqueda, 
      Solo hay que agregar al arreglo de la funcion el nombre del indice usado en fillItems()
      para el campo que se desea incluir en la busqueda*/
      this.elements = this.mdbTable.searchLocalDataByMultipleFields(this.searchText, ['Nombre', 'Apellido','Correo', 'Estado', 'Lenguajes']);
      this.mdbTable.setDataSource(prev);
  }
}

}

import { Component,Input, OnInit } from '@angular/core';
import { ProyectCommentsEditorComponent } from '../proyect-comments-editor/proyect-comments-editor.component';
import {AuthService} from '../../../services/auth.service';
import { Router } from "@angular/router";
import { HttpErrorResponse } from '@angular/common/http';

@Component({
  selector: 'abe-proyect-comments',
  templateUrl: './proyect-comments.component.html',
  styleUrls: ['./proyect-comments.component.scss']
})

export class ProyectCommentsComponent implements OnInit {

  @Input() idComentario:string; //identificador para comentarios

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }

  comentarioPrevio=[];  //arreglo donde guardamos los comentarios del backend

  fechas=[];  //arreglo donde guardamos los comentarios del backend

  id_proyecto={     //objeto para poder recibir el objeto de comentarios
      id:''
  }


  ngOnInit(): void {
    this.id_proyecto.id=this.idComentario;
    this.authService.getComments(this.id_proyecto)
    .subscribe(
      res=>{

        for(let obj of res.comment.reverse()){
          this.comentarioPrevio.push(obj);
        }
        this.formatoFecha();
      },
        err=>{console.log('error al mostrar proyectos',err)}
    );
  }

  imgUrl="https://comicvine1.cbsistatic.com/uploads/scale_small/1/14487/7767617-db726ed6-c3ba-47ac-ab77-bf29614bce2d.jpeg";


  addComentario(comentario) {
    //console.log(comentario);
    this.comentarioPrevio.unshift( { nombre: comentario.nombre , cuerpo: comentario.cuerpo, fecha_creacion: "Justo Ahora"})
    this.fechas.unshift("Justo Ahora");


  }
  formatoFecha(){
    for(let obj of this.comentarioPrevio){
      console.log(obj.fecha_creacion)

      var year = obj.fecha_creacion.substring(0,4) //months from 1-12
      var month = obj.fecha_creacion.substring(5,7);
      var timeframe = obj.fecha_creacion.substring(11,16);
      //var day = obj.fecha_creacion.getUTCDate();
      //var year = obj.fecha_creacion.getUTCFullYear();
      //this.fechas.push(month+'/'+'/'+year);
      this.fechas.push(month+'/'+year+" "+timeframe)
      //console.log(month+'/'+year+" "+timeframe);
    }


      console.log(this.fechas);
  }


}

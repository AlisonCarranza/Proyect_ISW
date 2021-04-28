import { Component, OnInit } from '@angular/core';
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

  constructor(
    private authService: AuthService,
    private router: Router
  ) { }

  comentarioPrevio=[];

  id_proyecto={
      id:'607643208df26506a0b62a88'
  }


  ngOnInit(): void {
    this.authService.getComments(this.id_proyecto)
    .subscribe(
      res=>{

        for(let obj of res.comment.reverse()){
          this.comentarioPrevio.push(obj);
        }
        console.log(this.comentarioPrevio);
      },
        err=>{console.log('error al mostrar proyectos',err)}
    );
  }

  imgUrl="https://comicvine1.cbsistatic.com/uploads/scale_small/1/14487/7767617-db726ed6-c3ba-47ac-ab77-bf29614bce2d.jpeg";


  addComentario(comentario) {
    console.log(comentario);
    this.comentarioPrevio.unshift( { nombre: comentario.nombre , cuerpo: comentario.cuerpo, fecha_creacion: "Justo Ahora"})


  }



}

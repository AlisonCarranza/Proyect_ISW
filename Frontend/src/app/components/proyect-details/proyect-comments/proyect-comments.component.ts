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

  ngOnInit(): void {
    this.authService.getComments()
    .subscribe(
      res=>{
        console.log(res);
      },
      err=>{console.log('error al mostrar proyectos',err)}
    );

  }
  imgUrl="https://comicvine1.cbsistatic.com/uploads/scale_small/1/14487/7767617-db726ed6-c3ba-47ac-ab77-bf29614bce2d.jpeg"


  comentarioAnterior={
    cuerpo: 'Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industrys standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.',
    fecha_creacion: null
  }


}

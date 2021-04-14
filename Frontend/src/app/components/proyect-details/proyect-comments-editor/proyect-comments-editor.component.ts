import { Component, OnInit } from '@angular/core';
import {  AuthService} from "../../../services/auth.service";
import { HttpErrorResponse } from '@angular/common/http';
import { Observable } from "rxjs";
import { DomSanitizer, SafeResourceUrl, SafeUrl} from '@angular/platform-browser';
import {SidebarComponent} from 'src/app/components/sidebar/sidebar.component';
//para redireccionar
import { Router } from "@angular/router";
import Sawl from "sweetalert2/dist/sweetalert2.js";
import { DatePipe } from '@angular/common';
//alertas
import Swal from "sweetalert2/dist/sweetalert2.js";
import * as alertify from 'alertifyjs';


@Component({
  selector: 'abe-proyect-comments-editor',
  templateUrl: './proyect-comments-editor.component.html',
  styleUrls: ['./proyect-comments-editor.component.scss'],
  providers: [DatePipe]
})
export class ProyectCommentsEditorComponent implements OnInit {

  constructor(
    public authService: AuthService,
    private miDatePipe: DatePipe,
    private router: Router
  ) { }

  imgURL: any;
  profile={
    username: '',

  };
  comentario={
    cuerpo: '',
    fecha_creacion: null
  }

  ngOnInit(): void {
    this.authService.getProfile()
    .subscribe(
      res => {
        this.profile=res.User;
        let currDate = new Date();
       this.getImage().subscribe(x => this.imgURL = x)
      },
      err => {
        if (err instanceof HttpErrorResponse) {
          if (err.status === 401) {
            this.router.navigate(['/signin']);
          }
        }
      }
    )
  }




  enviarComentario(){
      this.authService.newComment(this.comentario)
      .subscribe(
        res =>{
          alert("success");

          if(res.estado=='commentSuccess'){
            Swal.fire("Exitoso", "Comentario Guardado", "success");
            //this.router.navigate(['/profile']);
          }else{
            Swal.fire("Error", "Hubo un error en los datos ingresados, verifique cada uno de ellos!", "warning");
          }

        },
        err =>{
          console.log(err);
          Swal.fire("Error", "Hubo un error en el sistema, favor intente de nuevo!", "error");
          //this.router.navigate(['/signup']);
        }
      )


  }
  getImage(): Observable<SafeResourceUrl> {
    return  this.authService.getProfilePic();
  }
}

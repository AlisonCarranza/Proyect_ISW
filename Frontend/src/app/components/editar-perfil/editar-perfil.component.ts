import { Component, OnInit} from '@angular/core';
import {  AuthService} from "../../services/auth.service";
import { HttpErrorResponse } from '@angular/common/http';
import { Observable } from "rxjs";
import { DomSanitizer, SafeResourceUrl, SafeUrl} from '@angular/platform-browser';
import {SidebarComponent} from 'src/app/components/sidebar/sidebar.component';
//para redireccionar
import { Router } from "@angular/router";
import Sawl from "sweetalert2/dist/sweetalert2.js";
import { DatePipe } from '@angular/common';

@Component({
  selector: 'abe-editar-perfil',
  templateUrl: './editar-perfil.component.html',
  styleUrls: ['./editar-perfil.component.scss'],
  providers: [DatePipe]
})


export class EditarPerfilComponent implements OnInit {


  imgURL: any;
  profile={
    //picPerfil:'',
    nombre:'',
    username: '',
    email:'',
    telefono:''
  }


  constructor(
    public authService: AuthService, private miDatePipe: DatePipe,
    private router: Router
  ) { }


  ngOnInit(){
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

  getImage(): Observable<SafeResourceUrl> {
    return  this.authService.getProfilePic();
  }

  imgURLtest="https://cdn.pixabay.com/photo/2017/06/13/12/53/profile-2398782_1280.png";
  warningMessage='Algunos campos presentan errores';
  newPassword='';
  newPasswordCheck='';
  passwordCheck=false;

    //
  actualizarPerfil(){
    //revisa si son iguales las contrasenas
    this.passwordCheck=false;
    this.checkPasswords();
      //se ejecuta la funcion si se cumplen las validaciones
    if(this.passwordCheck===false){
      //este alert solo es para ver si se validan
      alert("Perfil Editado");
    }



  }
      //funcion del boton para subir imagen
  goSubirImagen(){
      //programacion para subir imagen
  }

  checkPasswords(){
    if(this.newPassword!=this.newPasswordCheck){
      this.warningMessage="Las contraseñas no son iguales"
      this.passwordCheck=true;
    }
    if(this.newPassword===''){
      this.warningMessage='La nueva contraseña no puede estar vacia';
      this.passwordCheck=true;
    }
    if(this.newPassword.length<6){
      this.warningMessage='La nueva contraseña no puede ser menor de 6 caracteres';
      this.passwordCheck=true;
    }
  }


}

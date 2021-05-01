import { Component, OnInit } from '@angular/core';
import {  AuthService} from "../../services/auth.service";
import { HttpErrorResponse } from '@angular/common/http';
import { Observable } from "rxjs";
import { DomSanitizer, SafeResourceUrl, SafeUrl} from '@angular/platform-browser';
//para redireccionar
import { Router , ActivatedRoute} from "@angular/router";
import Swal from "sweetalert2/dist/sweetalert2.js";
import { DatePipe } from '@angular/common';
import * as alertify from 'alertifyjs';

@Component({
  selector: 'abe-profile-prof',
  templateUrl: './profile-prof.component.html',
  styleUrls: ['./profile-prof.component.scss'],
  providers: [DatePipe]
})
export class ProfileProfComponent implements OnInit {

  imgURL: any;
  profile={
    //picPerfil:'',
    nombre:'',
    username: '',
    email:'',
    profesion: '',
    tecnologias: '',
    experiencia: '',
    telefono:''
  }
  email = {
    email:''
  }

  constructor(
    public authService: AuthService, private miDatePipe: DatePipe,
    private router: Router
  ) { }

  ngOnInit(){
    /*if(!this.authService.loggedIn()){
      this.router.navigate(['/signin']);
    }else{
      this.activatedRoute.queryParams.subscribe(params => {
        let userMail = params['user'];
        if(userMail){
          this.email.email=userMail
          this.authService.getProfileProf(this.email)
          .subscribe(
            res => {
              this.profile=res.User;
            },
            err => {
              if (err instanceof HttpErrorResponse) {
                if (err.status === 401) {
                  this.router.navigate(['/signin']);
                }
              }
            }
          )
        }else{
          this.router.navigate(['/admin']);
        }
        
    });
    }
  }*/

/*

    if(this.authService.loggedIn()){
      this.router.navigate(['/profile']);
    }else{
      
    this.authService.userState()
    .subscribe(
      res => {
        if(res.estado=='inactivo'){
          this.router.navigate(['/verification']);
          Swal.fire("Error", "Su cuenta debe estar activa para usar Jalón Universitario", "warning");
        }else{
          this.authService.getProfileDev()
          .subscribe(
            res => {
              this.profile=res.User;
             this.getImage().subscribe(x => {this.imgURL = x})        
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
  }

  getImage(): Observable<SafeResourceUrl> {
    return  this.authService.getProfilePicDev();
  }*/
  

  }

}

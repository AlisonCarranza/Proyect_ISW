import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Router} from '@angular/router';

@Injectable({
  providedIn: 'root'
})

export class UsuariosService{

  constructor(private httpClient:HttpClient, private router:Router) { }

  private URL = 'http://localhost:4000';
  
  guardarUsuario(usuario: any):Observable<any>{
    return this.httpClient.post(this.URL + '/registro',usuario);
  }

  guardarLogin(usuarioLog: any):Observable<any>{
    return this.httpClient.post(this.URL + '/login',usuarioLog);
  }
  
  usuariosLogin(){
  	  return !!localStorage.getItem('token');
  }

  usuarioLogout(){
  	localStorage.removeItem('token');
    this.router.navigate(['/home']);
  }

}
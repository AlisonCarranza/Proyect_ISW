import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Router} from '@angular/router';

@Injectable({
  providedIn: 'root'
})

export class UsuariosService{

  constructor(private httpClient:HttpClient, private router:Router) { }
  
  guardarUsuario(usuario: any):Observable<any>{
    return this.httpClient.post('http://localhost:4000/registro',usuario);
  }

  guardarLogin(usuarioLog: any):Observable<any>{
    return this.httpClient.post('http://localhost:4000/login',usuarioLog);
  }
  
  usuariosLogin(){
  	  return !!localStorage.getItem('token');
  }

  usuariosLogout(){
  	localStorage.removeItem('token');
    this.router.navigate(['/menu']);
  }

}
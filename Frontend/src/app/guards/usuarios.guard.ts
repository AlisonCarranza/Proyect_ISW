import { Injectable } from '@angular/core';
import { CanActivate, ActivatedRouteSnapshot, RouterStateSnapshot, UrlTree, Router} from '@angular/router';
import { UsuariosService } from '../services/usuarios.service';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})

export class UsuariosGuard implements CanActivate {
  constructor(private router:Router, private usuariosService:UsuariosService){

  }	

  canActivate(
    route: ActivatedRouteSnapshot,
    state: RouterStateSnapshot): Observable<boolean | UrlTree> | Promise<boolean | UrlTree> | boolean | UrlTree {
    
      if(this.usuariosService.usuariosLogin()){
        return true
  
      }else{
          this.router.navigate(['/login'])
          return false
      }
  }
  
}


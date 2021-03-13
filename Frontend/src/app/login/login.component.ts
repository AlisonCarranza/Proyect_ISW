import { Component, OnInit } from '@angular/core';
import { FormControl, FormGroup, Validators} from '@angular/forms';
import { Router} from '@angular/router'; 
import { UsuariosService } from '../services/usuarios.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  formLogin= new FormGroup({
    correo: new FormControl('',[Validators.required]),
    password: new FormControl('',[Validators.required,Validators.minLength(8)])
  });

  constructor(private usuariosService:UsuariosService, private router:Router) { }

  ngOnInit(): void {
  }
  get password(){
    return this.formLogin.get('password');
  }

  get correo(){
    return this.formLogin.get('correo');
  }
  
  ingresar(){
    console.log(this.formLogin.value.correo);

    this.usuariosService.guardarLogin(this.formLogin.value).subscribe(
      res=>{
        console.log(this.formLogin.value);
        localStorage.setItem('token', res.token);
        this.router.navigate(['/menu']);
        console.log(res);
      },
      error=>{
        console.log(error);
      });
    
    }
}
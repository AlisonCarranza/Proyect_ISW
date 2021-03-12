import { Component, OnInit } from '@angular/core';
import { FormControl, FormGroup, Validators} from '@angular/forms';
import { Router} from '@angular/router';
import { UsuariosService } from 'src/app/services/usuarios.service';
import { validateLocaleAndSetLanguage } from 'typescript';

@Component({
  selector: 'app-registro-usuarios',
  templateUrl: './registro-usuarios.component.html',
  styleUrls: ['./registro-usuarios.component.css']
})

export class RegistroUsuariosComponent implements OnInit {
  usuarios:any=[];

  formRegistro= new FormGroup({
     nombre: new FormControl('',[Validators.required,Validators.maxLength(30)]),
     userName: new FormControl('',[Validators.required,Validators.maxLength(30)]),
     correo: new FormControl('',[Validators.required]),
     telefono:new FormControl('',[Validators.required]),
     password: new FormControl('',[Validators.required,Validators.minLength(8)]),
     confirmacionPassword: new FormControl('',[Validators.required,Validators.minLength(8)])
  });

  constructor(private usuariosService:UsuariosService, private router:Router) { }

  ngOnInit(): void {
  }

  get nombre(){
    return this.formRegistro.get('nombre');
  }

  get password(){
    return this.formRegistro.get('password');
  }


  guardar(){
  	console.log('formulario',this.formRegistro.valid);

    this.usuariosService.guardarUsuario(this.formRegistro.value).subscribe(
      res=>{
        this.usuarios.push(res);
        localStorage.setItem('token', res.token);
        this.router.navigate(['/menu']);
        console.log(res);
      },
      error=>{
        console.log(error);
      }
    );
  	
  }

}
import { Component, OnInit } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';
import swal from 'sweetalert';

@Component({
  selector: 'app-form-profesional',
  templateUrl: './form-profesional.component.html',
  styleUrls: ['./form-profesional.component.css']
})
export class FormProfesionalComponent implements OnInit {

  formulario = new FormGroup({
    username : new FormControl ('', [Validators.required ]),
    username1 : new FormControl ('', [Validators.required ]),
    useremail : new FormControl ('', [Validators.email, Validators.required]),
    userpassword : new FormControl ('', [Validators.required, Validators.min(3) ]),
    userpassword1 : new FormControl ('', [Validators.required, Validators.min(3) ]),
    usertelefono : new FormControl ('', [Validators.required]),
    usercategory : new FormControl (''),
    usergender : new FormControl ('', [Validators.required]),
    userdescription : new FormControl ('', [Validators.required]),

  });
  /*hide = true;
  hide2 = true;
  get emailInput() { return this.formulario.get('email'); }
  get passwordInput() { return this.formulario.get('password'); }
  get vpasswordInput() { return this.formulario.get('vpassword'); }*/

  template = '';
  validate = true;
  correo = '@unah.hn';

  constructor(){
  }
  ngOnInit(): void {
  }

  ValidPasswor(): void{
    const pass = this.formulario.value.userpassword;
    if (pass !== this.formulario.value.userpassword1 ){
        this.template = '<div class="alert alert-warning" role="alert"><div> Las contraseñas no coinciden verifiquelas.</div></div>';
        swal({title: 'error', text: 'Las contraseñas no coinciden verifiquelas', icon: 'error'});
        this.validate = false;
      }
    }
  validEmail(): void {
    const email = this.formulario.value.useremail;
    if (email.slice(-8) !== this.correo ) {
        swal({title: 'error', text: 'Debe ser correo con terminación @unah.hn ', icon: 'error'});
        this.validate = false;
         }
  }
  verify(): void {
    const pass = this.formulario.value.userpassword;
    if (pass.length < 8){
      this.template = '<div class="alert alert-warning" role="alert"><div> La contraseña debe tener al menos 8 caracteres.</div></div>';
      console.log(this.template);
      swal({title: 'error', text: 'La contraseña debe tener al menos 8 caracteres', icon: 'error'});
      this.validate = false;
    }else if (!pass.match(/[0-9]/)){
      this.template = '<div class="alert alert-warning" role="alert"><div>Debe incluir al menos un número en su contraseña.</div></div>';
      swal({title: 'error', text: 'Debe incluir al menos un número en su contraseña', icon: 'error'});
      this.validate = false;
    }else if (!pass.match(/[A-Z]/)){
      this.template = '<div class="alert alert-warning" role="alert"><div>Debe incluir al menos una mayúscula en contraseña.</div></div>';
      swal({title: 'error', text: 'Debe incluir al menos una mayúscula en contraseña', icon: 'error'});
      this.validate = false;
    }else if (!pass.match(/[a-z]/)){
      this.template = '<div class="alert alert-warning" role="alert"><div>Incluir al menos una minúscula en su contraseña.</div></div>';
      swal({title: 'error', text: 'incluir al menos una minúscula en su contraseña', icon: 'error'});
    }else if (!pass.match(/[_\/\*\$.\\\[\]\(\):;,\?!@#¬'%.$?¡¿+\{\}`^¨]/)){
      this.template = '<div class="alert alert-warning" role="alert"><div>Debe incluir al menos un caracter NO alfa-numérico en su contraseña.</div></div>';
      swal({title: 'error', text: 'Debe incluir al menos un caracter NO alfa-numérico en su contraseña.', icon: 'error'});
      this.validate = false;
    }
    else{
      this.template = '';
      this.validate = true;
    }
  }
  vacio(): void {
    if (this.formulario.value.username === ''){
      swal({title: 'error', text: 'No puede dejar el nombre en blanco', icon: 'error'});
    }else if (this.formulario.value.username1 === ''){
      swal({title: 'error', text: 'No puede dejar el nombre de usuario en blanco', icon: 'error'});
    }else if (this.formulario.value.userdescription === ''){
      swal({title: 'error', text: 'No puede dejar la descripcion de tra bajo en blanco', icon: 'error'});
    }else if (this.formulario.value.useremail === ''){
      swal({title: 'error', text: 'No puede dejar el correo en blanco', icon: 'error'});
    }else if (this.formulario.value.userpassword === ''){
      swal({title: 'error', text: 'No puede dejar la contraseña en blanco', icon: 'error'});
    }else if (this.formulario.value.userpassword1 === ''){
      swal({title: 'error', text: 'Se requiere verificación de su contraseña', icon: 'error'});
    }else if (!this.formulario.value.username.match(/^[a-zA-Z| ]+$/)){
      swal({title: 'error', text: 'El nombre sólo debe incluir letras', icon: 'error'});
    }else if (!this.formulario.value.userdescription.match(/^[a-zA-Z| ]+$/)){
        swal({title: 'error', text: 'La descrpción de trabajoletras', icon: 'error'});
    }else if (!this.formulario.value.usertelefono.match(/^[0-9]+$/)){
      swal({title: 'error', text: 'El número de télefono sólo debe incluir números', icon: 'error'});
  }
}


}

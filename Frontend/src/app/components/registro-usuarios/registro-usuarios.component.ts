import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'abe-registro-usuarios',
  templateUrl: './registro-usuarios.component.html',
  styleUrls: ['./registro-usuarios.component.scss']
})
export class RegistroUsuariosComponent implements OnInit {
  hide = true;
  hide2= true;

  user={
    username: '',
    password: ''
  };

  template='';
  validate=true;

  constructor() { }

  ngOnInit(): void {
  }

  verify(){}

}

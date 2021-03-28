import { Component, OnInit } from '@angular/core';
import {SidebarComponent} from 'src/app/components/sidebar/sidebar.component';

@Component({
  selector: 'abe-editar-perfil',
  templateUrl: './editar-perfil.component.html',
  styleUrls: ['./editar-perfil.component.scss']
})
export class EditarPerfilComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }

  imgURL="https://cdn.pixabay.com/photo/2017/06/13/12/53/profile-2398782_1280.png"

}

import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { LoginComponent } from './login/login.component';
import { RegistroUsuariosComponent } from './registro-usuarios/registro-usuarios.component';
import { LandingPageComponent } from './landing-page/landing-page.component';
import { MenuComponent } from './menu/menu.component';

import { UsuariosGuard } from './guards/usuarios.guard';

const routes: Routes = [
   { path: 'menu', component: MenuComponent,canActivate:[UsuariosGuard]},//autenticacion
   { path: 'registro', component: RegistroUsuariosComponent},
   { path: 'login', component: LoginComponent},
   { path: 'home', component: LandingPageComponent},
   { path: '**', redirectTo: 'home'},
   { path: '', redirectTo: 'home', pathMatch: 'full' }
  
]; // sets up routes constant where you define your routes

// configures NgModule imports and exports
@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { 

}

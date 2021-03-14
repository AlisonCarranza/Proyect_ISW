import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

//Componentes
import { AuthGuard } from "./guards/auth.guard";
import { RecPasswordComponent } from "./components/rec-password/rec-password.component";
import { LandingPageComponent } from "./components/landing-page/landing-page.component";
import { RegistroUsuariosComponent } from "./components/registro-usuarios/registro-usuarios.component";
import { LoginComponent } from "./components/login/login.component";
import { RecoverPasswordComponent } from "./components/recover-password/recover-password.component";


const routes: Routes = [
  
  {
    path: 'home',
    component: LandingPageComponent

  },

  {
    path: 'signup',
    component: RegistroUsuariosComponent

  },

  {
    path: 'signin',
    component: LoginComponent

  },

  {
    path: 'rec-password',
    component: RecPasswordComponent

  },

  {
    path: 'recover-password',
    component: RecoverPasswordComponent

  }

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

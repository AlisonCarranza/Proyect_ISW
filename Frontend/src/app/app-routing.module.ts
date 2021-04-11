import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

//Componentes
import { AuthGuard } from "./guards/auth.guard";
import { RecPasswordComponent } from "./components/rec-password/rec-password.component";
import { LandingPageComponent } from "./components/landing-page/landing-page.component";
import { RegistroUsuariosComponent } from "./components/registro-usuarios/registro-usuarios.component";
import { LoginComponent } from "./components/login/login.component";
import { RecoverPasswordComponent } from "./components/recover-password/recover-password.component";
import { NewProjectFormComponent } from "./components/new-project-form/new-project-form.component";
import { ProfileComponent } from "./components/profile/profile.component"
import { FuncionComponent } from "./components/funcion/funcion.component";
import { ProjectsComponent} from "./components/projects/projects.component";
import { SearchProfComponent } from "./components/search-prof/search-prof.component";
import { EditarPerfilComponent } from "./components/editar-perfil/editar-perfil.component";
import { EnlaceRegistroComponent } from "./components/enlace-registro/enlace-registro.component";
import { ProyectCommentsComponent } from './components/proyect-details/proyect-comments/proyect-comments.component';
import { ProyectCommentsEditorComponent } from './components/proyect-details/proyect-comments-editor/proyect-comments-editor.component';

const routes: Routes = [
  {
    path: '',
      redirectTo: 'home',
      pathMatch: 'full'
    },

  {
    path: 'home',
    component: LandingPageComponent

  },

  {
    path: 'function',
    component: FuncionComponent

  },

  {
    path: 'type-user',
    component: EnlaceRegistroComponent

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
    path: 'profile',
    component: ProfileComponent

  },

  {
    path:'edit-profile',
    component: EditarPerfilComponent

  },

  {
    path: 'rec-password',
    component: RecPasswordComponent

  },

  {
    path: 'recover-password',
    component: RecoverPasswordComponent

  },

  {
    path: 'newProject',
    component: NewProjectFormComponent

  },

  {
    path: 'projects',
    component: ProjectsComponent

  },

  {
    path: 'search-prof',
    component: SearchProfComponent

  },

  {
    path: 'proyect-comments-editor',
    component: ProyectCommentsEditorComponent

  },
  {
    path: 'proyect-comments',
    component: ProyectCommentsComponent
  }


];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

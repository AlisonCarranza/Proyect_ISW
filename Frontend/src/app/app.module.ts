//Import de dependencias
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { NO_ERRORS_SCHEMA } from '@angular/core';
import { MDBBootstrapModule } from 'angular-bootstrap-md';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations'; // If You need animations
import Swal from 'sweetalert2/dist/sweetalert2.js';
import {FormsModule, ReactiveFormsModule} from '@angular/forms';
import {HttpClientModule, HTTP_INTERCEPTORS, HttpClient} from '@angular/common/http';
import { Observable } from "rxjs";
import { ComboBoxModule } from '@syncfusion/ej2-angular-dropdowns';
import { HashLocationStrategy, LocationStrategy } from '@angular/common';

//Imports de componentes y servicios
import { AuthGuard } from "./guards/auth.guard";
import { TokenInterceptorService } from "./services/token-interceptor.service";
import { AuthService } from "./services/auth.service";
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { RecPasswordComponent } from "./components/rec-password/rec-password.component";
import { LandingPageComponent } from './components/landing-page/landing-page.component';
import { RegistroUsuariosComponent } from './components/registro-usuarios/registro-usuarios.component';
import { LoginComponent } from './components/login/login.component';
import { RecoverPasswordComponent } from './components/recover-password/recover-password.component';
import { NewProjectFormComponent } from './components/new-project-form/new-project-form.component';
import { ProfileComponent } from './components/profile/profile.component';
import { FuncionComponent } from './components/funcion/funcion.component';
import { ProjectsComponent } from './components/projects/projects.component';
import { SearchProfComponent } from './components/search-prof/search-prof.component';
import { SidebarComponent } from './components/sidebar/sidebar.component';
import { EditarPerfilComponent } from './components/editar-perfil/editar-perfil.component';

@NgModule({
  declarations: [
    AppComponent,
    RecPasswordComponent,
    LandingPageComponent,
    RegistroUsuariosComponent,
    LoginComponent,
    RecoverPasswordComponent,
    NewProjectFormComponent,
    ProfileComponent,
    FuncionComponent,
    ProjectsComponent,
    SearchProfComponent,
    SidebarComponent,
    EditarPerfilComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    BrowserModule,
    MDBBootstrapModule.forRoot(),
    BrowserAnimationsModule,
    HttpClientModule,
    ReactiveFormsModule,
    ComboBoxModule,
    FormsModule,
    ReactiveFormsModule
  ],
  providers: [
    AuthService, 
    AuthGuard,
  
    {
      provide:HTTP_INTERCEPTORS,
      useClass: TokenInterceptorService,
      multi: true
      
    }
    
  ],
  bootstrap: [AppComponent],
  schemas: [NO_ERRORS_SCHEMA]
})
export class AppModule { }

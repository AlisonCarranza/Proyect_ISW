import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { ReactiveFormsModule } from '@angular/forms';

import { AppComponent } from './app.component';
import { LandingPageComponent } from './landing-page/landing-page.component';
import { FuncionComponent } from './funcion/funcion.component';
import { FormProfesionalComponent } from './form-profesional/form-profesional.component';
import { EnlaceRegistroComponent } from './enlace-registro/enlace-registro.component';

@NgModule({
  declarations: [
    AppComponent,
    LandingPageComponent,
    FuncionComponent,
    FormProfesionalComponent,
    EnlaceRegistroComponent
  ],
  imports: [
    BrowserModule,
    NgbModule,
    ReactiveFormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

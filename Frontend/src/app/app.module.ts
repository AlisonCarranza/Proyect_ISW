import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { NgbModule } from '@ng-bootstrap/ng-bootstrap';

import { AppComponent } from './app.component';
import { LandingPageComponent } from './landing-page/landing-page.component';
import { ComoFuncionaComponent } from './como-funciona/como-funciona.component';
import { FuncionComponent } from './funcion/funcion.component';

@NgModule({
  declarations: [
    AppComponent,
    LandingPageComponent,
    ComoFuncionaComponent,
    FuncionComponent
  ],
  imports: [
    BrowserModule,
    NgbModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

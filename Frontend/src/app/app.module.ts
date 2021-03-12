import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { LandingPageComponent } from './landing-page/landing-page.component';
import { ComoFuncionaComponent } from './como-funciona/como-funciona.component';

@NgModule({
  declarations: [
    AppComponent,
    LandingPageComponent,
    ComoFuncionaComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

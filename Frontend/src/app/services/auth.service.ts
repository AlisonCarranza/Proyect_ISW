import { Injectable } from '@angular/core';
import { HttpClient } from "@angular/common/http";
import { Router } from '@angular/router';
import { Observable } from "rxjs";
import { map } from 'rxjs/operators';
import { DomSanitizer, SafeResourceUrl, SafeUrl} from '@angular/platform-browser';
import { identifierName } from '@angular/compiler';

@Injectable({
  providedIn: 'root'
})
export class AuthService {

  private URL = 'http://localhost:4000/api'
  constructor(
    private http: HttpClient,
    private router: Router,
    private sanitizer: DomSanitizer
    ) {}

  loggedIn() {
    return !!localStorage.getItem('token');
  }

  logout() {
    localStorage.removeItem('token');
    this.router.navigate(['/signin']);
  }  
  
  getToken() {
    return localStorage.getItem('token');
  }

  signUp(user){
    return this.http.post<any>(this.URL + '/signup', user);  
  }

  signIn(user){
    return this.http.post<any>(this.URL + '/signin', user);
  
  }  

  getProfile() {
    return this.http.get<any>(this.URL + '/profile');
  }

  getProfilePic(){
    return this.http.get(this.URL+'/profile-pic', { responseType: 'blob' })
      .pipe(
        map(x => {
          const urlToBlob = window.URL.createObjectURL(x) // get a URL for the blob
          return this.sanitizer.bypassSecurityTrustResourceUrl(urlToBlob); // tell Anuglar to trust this value
        }),
      );
  }

  recPass(user){
    return this.http.post<any>(this.URL + '/rec-password', user);
  }

  changeRecPass(user){
    return this.http.post<any>(this.URL + '/recover-password', user);
  }

  NewProjectForm(titulo){
    return this.http.post<any>(this.URL + '/nuevo-proyecto', titulo);
   }

}

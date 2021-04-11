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
    console.log (this.URL)
    return this.http.post<any>(this.URL + '/signin', user);

  }

  getProfile() {
    return this.http.get<any>(this.URL + '/profile');
  }

  uploadProfile(profile, id){

    return this.http.post<any>(this.URL + '/upload-profile-pic?id='+id, profile);
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

  editProfile(user){
    return this.http.post<any>(this.URL + '/edit-profile', user);
  }

  recPass(user){
    return this.http.post<any>(this.URL + '/rec-password', user);
  }

  changeRecPass(user){
    return this.http.post<any>(this.URL + '/recover-password', user);
  }

  changePassword(user){
    return this.http.post<any>(this.URL + '/change-password', user);
  }

  NewProjectForm(titulo){
    return this.http.post<any>(this.URL + '/nuevo-proyecto', titulo);
   }

  searchProf(){
    return this.http.get<any>(this.URL +'/search-prof');
  }

  viewProject(){
    return this.http.get<any[]>(this.URL +'/projects');
  }

  newComment(comment){
    console.log(comment);
    return this.http.post<any>(this.URL +'/proyect-comments-editor',comment);
  }


}

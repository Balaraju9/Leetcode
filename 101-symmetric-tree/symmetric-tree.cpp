/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        else if(r1->val !=r2->val){
            return false;
        }
        return fun(r1->left,r2->right) && fun(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            return false;
        }
        return fun(root->left,root->right);
        
    }
};


-----------------------------------------------------------------------------------------------------------------------------
welcome user
import { NgModule, Component } from '@angular/core';  
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';  

@Component({  
  selector: 'app-root',  
  standalone: true,  
  imports: [BrowserModule],  
  template: `
    <div *ngIf="!user && !msg">
      <input #u placeholder="Username">
      <input #p type="password" placeholder="Password">
      <button (click)="login(u.value, p.value)">Login</button>
    </div>
    <h4 *ngIf="user">{{ msg }}</h4>
    <h4 *ngIf="msg && !user">{{ msg }}</h4>
    <button *ngIf="msg" (click)="msg=''; user=''">Back</button>
  `  
})  
class AppComponent {  
  user = ''; msg = '';  
  login(name: string, pass: string) {  
    this.user = name === 'admin' && pass === 'admin' ? name : '';  
    this.msg = this.user ? `Welcome ${this.user}` : 'Invalid Login!';  
  }  
}  

bootstrapApplication(AppComponent);


list format
import { NgModule, Component } from '@angular/core';  
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';  

@Component({  
  selector: 'app-root',  
  standalone: true,  
  imports: [BrowserModule],  
  template: `<ul><li *ngFor="let c of courses; let i=index">{{i}} - {{c.name}}</li></ul>`  
})  
class AppComponent {  
  courses = [ {name: "TypeScript"}, {name: "Angular"}, {name: "Node.js"}, {name: "MongoDB"} ];  
}  

bootstrapApplication(AppComponent);




choice
import { Component } from '@angular/core';  
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';  

@Component({  
  selector: 'app-root',  
  standalone: true,  
  imports: [BrowserModule],  
  template: `
    <h4>Current choice is {{choice}}</h4>
    <div [ngSwitch]="choice">
      <p *ngSwitchCase="1">First Choice</p>
      <p *ngSwitchCase="2">Second Choice</p>
      <p *ngSwitchCase="3">Third Choice</p>
      <p *ngSwitchDefault>Default Choice</p>
    </div>
    <button (click)="choice = (choice % 3) + 1">Next Choice</button>
  `  
})  
class AppComponent { choice = 0; }  

bootstrapApplication(AppComponent);



repeat
import { Component, Directive, Input, TemplateRef, ViewContainerRef } from '@angular/core';  
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';  

@Directive({ selector: '[appRepeat]' })  
class RepeatDirective {  
  constructor(private tpl: TemplateRef<any>, private vcr: ViewContainerRef) {}  
  @Input() set appRepeat(count: number) {  
    this.vcr.clear();  
    for (let i = 0; i < count; i++) this.vcr.createEmbeddedView(this.tpl);  
  }  
}  

@Component({  
  selector: 'app-root',  
  standalone: true,  
  imports: [BrowserModule, RepeatDirective],  
  template: `<h1 *appRepeat="10">Angular</h1>`  
})  
class AppComponent {}  

bootstrapApplication(AppComponent);



-------------------------------------------------------------------------------------------
    7
registration form
import { Component } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [BrowserModule, FormsModule],
  template: `
    <h2>Course Registration Form</h2>
    <form #courseForm="ngForm" (ngSubmit)="submitForm(courseForm.value)">
      <label>Name:</label>
      <input type="text" name="name" ngModel required><br><br>

      <label>Email:</label>
      <input type="email" name="email" ngModel required><br><br>

      <label>Course:</label>
      <select name="course" ngModel required>
        <option value="Angular">Angular</option>
        <option value="React">React</option>
        <option value="Vue">Vue</option>
      </select><br><br>

      <button type="submit">Register</button>
    </form>

    <div *ngIf="submitted">
      <h3>Registration Successful!</h3>
      <p><b>Name:</b> {{ formData.name }}</p>
      <p><b>Email:</b> {{ formData.email }}</p>
      <p><b>Course:</b> {{ formData.course }}</p>
    </div>
  `
})
class AppComponent {
  submitted = false;
  formData = { name: '', email: '', course: '' };

  submitForm(data: any) {
    this.formData = data;
    this.submitted = true;
  }
}

bootstrapApplication(AppComponent);
-----------------------------------------------
    7 reative form
import { Component } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { ReactiveFormsModule, FormGroup, FormControl, Validators } from '@angular/forms';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [BrowserModule, ReactiveFormsModule],
  template: `
    <h2>Employee Registration</h2>
    <form [formGroup]="empForm" (ngSubmit)="submitForm()">
      <label>Name:</label>
      <input type="text" formControlName="name"><br><br>

      <label>Email:</label>
      <input type="email" formControlName="email"><br><br>

      <label>Department:</label>
      <select formControlName="department">
        <option value="HR">HR</option>
        <option value="IT">IT</option>
        <option value="Finance">Finance</option>
      </select><br><br>

      <button type="submit" [disabled]="empForm.invalid">Register</button>
    </form>

    <div *ngIf="submitted">
      <h3>Registration Successful!</h3>
      <p><b>Name:</b> {{ empForm.value.name }}</p>
      <p><b>Email:</b> {{ empForm.value.email }}</p>
      <p><b>Department:</b> {{ empForm.value.department }}</p>
    </div>
  `
})
class AppComponent {
  empForm = new FormGroup({
    name: new FormControl('', Validators.required),
    email: new FormControl('', [Validators.required, Validators.email]),
    department: new FormControl('HR', Validators.required)
  });

  submitted = false;

  submitForm() {
    this.submitted = true;
  }
}

bootstrapApplication(AppComponent);

---------------------------------------------------
    email validator for 7c  employee registration and 8 is same course registration form
import { Component } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { ReactiveFormsModule, FormGroup, FormControl, Validators, AbstractControl } from '@angular/forms';

// Custom Validator Function
function emailValidator(control: AbstractControl) {
  const emailPattern = /^[a-zA-Z0-9._%+-]+@example\.com$/; // Only allows emails ending with @example.com
  return emailPattern.test(control.value) ? null : { invalidEmail: true };
}

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [BrowserModule, ReactiveFormsModule],
  template: `
    <h2>Employee Registration</h2>

    <form [formGroup]="empForm" (ngSubmit)="submitted=true">
      <label>Name:</label>
      <input type="text" formControlName="name">
      <span *ngIf="empForm.controls.name.invalid && empForm.controls.name.touched" style="color:red">
        * Required
      </span>
      <br><br>

      <label>Email:</label>
      <input type="email" formControlName="email">
      <span *ngIf="empForm.controls.email.errors?.invalidEmail && empForm.controls.email.touched" style="color:red">
        * Must be a valid example.com email
      </span>
      <br><br>

      <label>Department:</label>
      <select formControlName="department">
        <option value="HR">HR</option>
        <option value="IT">IT</option>
        <option value="Finance">Finance</option>
      </select>
      <br><br>

      <button type="submit" [disabled]="empForm.invalid">Register</button>
    </form>

    <div *ngIf="submitted">
      <h3>Registration Successful!</h3>
      <p><b>Name:</b> {{ empForm.value.name }}</p>
      <p><b>Email:</b> {{ empForm.value.email }}</p>
      <p><b>Department:</b> {{ empForm.value.department }}</p>
    </div>
  `
})
class AppComponent {
  empForm = new FormGroup({
    name: new FormControl('', Validators.required),
    email: new FormControl('', [Validators.required, emailValidator]),
    department: new FormControl('HR', Validators.required)
  });

  submitted = false;
}

bootstrapApplication(AppComponent);

----------------------------------------------

Book Component with Custom Service
import { Component, Injectable, inject } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';

// Book Service to Fetch Data
@Injectable({ providedIn: 'root' })
class BookService {
  getBooks() {
    return [
      { id: 1, name: "The Great Gatsby" },
      { id: 2, name: "1984" },
      { id: 3, name: "To Kill a Mockingbird" },
      { id: 4, name: "The Catcher in the Rye" }
    ];
  }
}

// Book Component
@Component({
  selector: 'book-list',
  standalone: true,
  imports: [BrowserModule],
  template: `
    <h2>Book List</h2>
    <ul>
      <li *ngFor="let book of books">{{ book.id }} - {{ book.name }}</li>
    </ul>
  `
})
class BookComponent {
  books = inject(BookService).getBooks(); // Fetching books using service
}

// Bootstrap Application
bootstrapApplication(BookComponent);



--------------------------------------------------------

main.ts (Using Observables in Angular)

import { Component, Injectable, inject } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { Observable } from 'rxjs';

// Book Service with Observable
@Injectable({ providedIn: 'root' })
class BookService {
  getBooks(): Observable<string> {
    return new Observable(observer => {
      const books = ["The Great Gatsby", "1984", "To Kill a Mockingbird", "The Catcher in the Rye"];
      let index = 0;

      setInterval(() => {
        if (index < books.length) {
          observer.next(books[index]); // Emit book name
          index++;
        } else {
          observer.complete(); // Complete the observable
        }
      }, 2000);
    });
  }
}

// Book Component
@Component({
  selector: 'book-list',
  standalone: true,
  imports: [BrowserModule],
  template: `
    <h2>Book Stream (Using Observables)</h2>
    <ul>
      <li *ngFor="let book of books">{{ book }}</li>
    </ul>
  `
})
class BookComponent {
  books: string[] = [];
  bookService = inject(BookService);

  constructor() {
    this.bookService.getBooks().subscribe({
      next: (book) => this.books.push(book), // Add book to list
      complete: () => console.log("Book list complete") // Log when done
    });
  }
}

// Bootstrap Application
bootstrapApplication(BookComponent);









------------------------------------------------------
http communication
import { Component, Injectable, inject } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { HttpClient, HttpClientModule } from '@angular/common/http';

// Book Service for Server Communication
@Injectable({ providedIn: 'root' })
class BookService {
  constructor(private http: HttpClient) {} 

  getBooks() {
    return this.http.get<any[]>('https://jsonplaceholder.typicode.com/posts'); // Mock API
  }
}

// Book Component
@Component({
  selector: 'book-list',
  standalone: true,
  imports: [BrowserModule, HttpClientModule],
  template: `
    <h2>Book List (Fetched from Server)</h2>
    <ul>
      <li *ngFor="let book of books">{{ book.id }} - {{ book.title }}</li>
    </ul>
  `
})
class BookComponent {
  books: any[] = [];
  bookService = inject(BookService);

  constructor() {
    this.bookService.getBooks().subscribe(data => this.books = data.slice(0, 5)); // Fetch and display first 5 books
  }
}

// Bootstrap Application
bootstrapApplication(BookComponent);

-----------------------------------------------
Multiple Components with Routing
import { Component } from '@angular/core';
import { BrowserModule, bootstrapApplication } from '@angular/platform-browser';
import { RouterModule } from '@angular/router';

// Home Component
@Component({
  selector: 'app-home',
  standalone: true,
  template: `<h2>Home Page</h2><p>Welcome to our website!</p>`
})
class HomeComponent {}

// About Component
@Component({
  selector: 'app-about',
  standalone: true,
  template: `<h2>About Page</h2><p>This is a simple Angular routing example.</p>`
})
class AboutComponent {}

// Main App Component
@Component({
  selector: 'app-root',
  standalone: true,
  imports: [BrowserModule, RouterModule.forRoot([
    { path: '', component: HomeComponent },
    { path: 'about', component: AboutComponent }
  ])],
  template: `
    <h1>Angular Routing Example</h1>
    <nav>
      <a routerLink="/">Home</a> | 
      <a routerLink="/about">About</a>
    </nav>
    <router-outlet></router-outlet>
  `
})
class AppComponent {}

// Bootstrap Application
bootstrapApplication(AppComponent);


#include <iostream>
#include <cstring>
struct book{ 
  int id; 
  char title[20]; 
  char author[20]; 
  double price; 
  char state[20]; 
  int student_id; 
  char student_name[20]; 
  struct book* next; 
}; 
 
struct student{ 
  int id; 
  char name[20]; 
  char sex[10]; 
  char borrow_book[30]; 
  struct student* next; 
}; 
void Print_Book(struct book *head_book); 
void Print_Student(struct student *head_student); 

struct book *Create_New_Book(); 
struct student *Create_New_Student(); 
struct book *Insert_Book(struct book *head_book,struct book *new_book);
struct student *Insert_Student(struct student *head_student,struct student *new_student);
struct book *Search_Book_ById(int id,struct book *head_book);  
struct book *Search_Book_ByTitle(char *title,struct book *head_book);  
struct book *Search_Book_ByPrice(double price_h,double price_l,struct book *head_book); 
struct book* Delete_Book(int id,book* head_book); 
struct student *Search_Student(int id,struct student *head_student); 
struct student* Delete_Student(int id,student* head_student); 
 
void Lent_Book(int id,int student_id,struct book *head_book,struct student *head_student); 
void Back_Book(int id,int student_id,struct book *head_book,struct student *head_student); 
 
int main() 
{ 
  struct book* head_book,*p_book; 
  struct student* head_student, *p_student; 
  int choice, f, id, student_id; 
  int m = 1; 
  char name[20],sex[10]; 
  char title[20]; 
  double price_h,price_l,price; 
  char author[20]; 
  int size_book=sizeof(struct book); 
  int size_student=sizeof(struct student); 
  printf("\n Welcome to the first 1 Second access to the library management system !\n\n");  
  printf("----->[ Group8 ]----->[ New library ]\n\n");  
  printf(" Pay attention to : When entering the book number as 0 when , Through to the next 1 step .\n\n");  
  head_book=Create_New_Book();  
  system("cls"); 
  Print_Book(head_book); 
  printf("\n Welcome to the first 1 Second access to the library management system !\n\n");  
  printf("----->[ Group8 ]----->[ New membership Library ]\n\n");  
  printf(" Pay attention to : When entering the member student number is 0 when , Go to the main menu .\n\n"); 
  head_student=Create_New_Student();  
  system("cls"); 
  do{ 
    printf("\n\t\t\t Library Book management system \n\n");  
    printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
    printf("\n"); 
    printf("\t\t\t[1]: Borrow books for \t");printf(" [6]: Return the book to deal with \n");  
    printf("\t\t\t[2]: Query book \t");printf(" [7]: Query students \n");  
    printf("\t\t\t[3]: Add books \t");printf("         [8]: Add the student \n");  
    printf("\t\t\t[4]: Delete books \t");printf(" [9]: Delete the student \n");  
    printf("\t\t\t[5]: Through books \t");printf("[10]: Traverse the students \n\n");  
    printf("\t\t\t0: exit \n\n");  
    printf(" Please select <0~10>:");  
    scanf("%d",&choice); 
    switch(choice){ 
    case 0: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");  
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");
      printf("\n Thank you for your use !\n\n");  
      break; 
    case 1: 
      system("cls"); 
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n"); 
      printf(" Enter the borrowed book number :\n");  
      scanf("%d",&id); 
      printf(" Input and borrow student id: \n"); 
      scanf("%d",&student_id); 
      Lent_Book(id,student_id,head_book,head_student); 
      break; 
    case 2: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      printf("1. Query by number \n\n");  
      printf("2. Query by name \n\n");  
      printf("3. Query by price range \n\n");  
      printf("0. Back to the main menu \n\n");  
      printf(" Please select a :");  
      scanf("%d",&f);  
      if(f==1){  
        printf(" Please enter the inquiry book number :");  
        scanf("%d",&id);  
        printf(" The relevant information is as follows :\n\n");  
        head_book=Search_Book_ById(id,head_book);  
        break;  
      }  
      else if(f==2){ 
        getchar(); 
        printf(" Please enter the name of the inquiry book :");  
        gets(title); 
        printf(" The relevant information is as follows :\n\n");  
        head_book=Search_Book_ByTitle(title,head_book);  
        break;  
      }  
      else if(f==3){  
        printf(" Please enter the highest price :");  
        scanf("%lf",&price_h);  
        printf(" Please enter the lowest price :");  
        scanf("%lf",&price_l);  
        printf(" The relevant information is as follows :\n\n");  
        head_book=Search_Book_ByPrice(price_h,price_l,head_book);  
        break;  
      }  
      else if(f==0){  
        break;  
      }  
      break; 
    case 3: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      printf(" Please enter the book number :");  
      scanf("%d",&id);  
      printf(" Please enter the name of the book :");  
      scanf("%s",title);  
      printf(" Please enter the author's name :");  
      scanf("%s",author);  
      printf(" Please enter the unit price :");  
      scanf("%lf",&price);  
      printf("\n"); 
      struct book *ptr_b; 
      for(ptr_b=head_book;ptr_b;ptr_b=ptr_b->next)  
      { 
        if(ptr_b->id==id)  
        {  
          printf(" This numbered book already exists \n");  
          m=0;  
          break;  
        }  
      }  
      if(m){  
        p_book=(struct book *)malloc(size_book);  
        strcpy(p_book->title,title);  
        p_book->id=id;  
        p_book->price=price;  
        p_book->student_id=-1;  
        strcpy(p_book->author,author);  
        strcpy(p_book->state," There are ");   
        strcpy(p_book->student_name," To be determined ");  
        Insert_Book(head_book,p_book); 
        printf("\n Add book success !\n\n");  
      }  
      break; 
    case 4: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      printf(" Enter the delete book number :\n");  
      scanf("%d",&id);  
      head_book = Delete_Book(id,head_book); 
      break; 
    case 5:  
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      Print_Book(head_book);  
      break; 
    case 6: 
      system("cls"); 
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n"); 
      printf(" Enter the return book number :\n");  
      scanf("%d",&id); 
      printf(" Input and return student id: \n"); 
      scanf("%d",&student_id); 
      Back_Book(id,student_id,head_book,head_student); 
      break; 
    case 7: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");    
      printf(" Please enter the student id :");  
      scanf("%d",&id);  
      printf(" The relevant information is as follows :\n\n");  
      head_student=Search_Student(id,head_student);  
      break; 
    case 8: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      printf(" Please enter the student number :");  
      scanf("%d",&id);  
      printf(" Please enter the student's name :");  
      scanf("%s",name);  
      printf(" Please enter student gender :");  
      scanf("%s",sex);   
      printf("\n"); 
      struct student *ptr_s; 
      for(ptr_s=head_student;ptr_s;ptr_s=ptr_s->next)  
      { 
        if(ptr_s->id==id)  
        {  
          printf(" This student number already exists \n");  
          m=0;  
          break;  
        }  
      }  
      if(m){  
        p_student=(struct student *)malloc(size_student);   
        p_student->id=id;   
        strcpy(p_student->name,name);  
        strcpy(p_student->sex,sex);   
        strcpy(p_student->borrow_book," There is no ");  
        head_student=Insert_Student(head_student,p_student);  
        printf("\n Add Student success !\n\n");  
      }  
      break; 
    case 9: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      printf(" Enter delete student id :\n");  
      scanf("%d",&id);  
      head_student = Delete_Student(id,head_student); 
      break; 
    case 10: 
      system("cls");  
      printf("\n\t\t\t Library Book management system \n\n");
      printf("\n\t\t\t TyTruong---HungNguyen---QuiTang \n\n");  
      Print_Student(head_student); 
    } 
  }while(choice!=0); 
  return 0; 
} 
 
struct book *Create_New_Book(){ 
  struct book *head_book,*p_book;  
  int id, tag;  
  double price;  
  char title[20],author[20];  
  int size_book=sizeof(struct book);  
    
  head_book=NULL;  
  printf(" Please enter the book number :");  
  scanf("%d",&id);  
  printf(" Please enter the name of the book :");  
  scanf("%s",title);  
  printf(" Please enter the author's name :");  
  scanf("%s",author);  
  printf(" Please enter the unit price :");  
  scanf("%lf",&price);  
  printf("\n");  
  while(true){  
    p_book=(struct book *)malloc(size_book);  
    strcpy(p_book->title,title);  
    p_book->id=id;  
    p_book->price=price;  
    p_book->student_id=-1;  
    strcpy(p_book->author,author);  
    strcpy(p_book->state," There are ");   
    strcpy(p_book->student_name," To be determined ");  
    head_book=Insert_Book(head_book,p_book); 
    printf(" Do you want to continue? Continue to input 1 , press any key to exit \n"); 
    scanf("%d",&tag); 
    if(tag!=1){ 
      break; 
    } 
    printf(" Please enter the book number :");  
    scanf("%d",&id);  
    printf(" Please enter the name of the book :");  
    scanf("%s",title);  
    printf(" Please enter the author's name :");  
    scanf("%s",author);  
    printf(" Please enter the unit price :");  
    scanf("%lf",&price);  
    printf("\n");  
  }  
  return head_book; 
} 
 
struct student *Create_New_Student(){ 
  struct student *head_student,*p_student;  
  int id, tag; 
  char sex[10]; 
  char name[20];  
  int size_student=sizeof(struct student);  
    
  head_student=NULL;  
  printf(" Please enter the student number :");  
  scanf("%d",&id);  
  printf(" Please enter the student's name :");  
  scanf("%s",name);  
  printf(" Please enter student gender :");  
  scanf("%s",sex);   
  printf("\n");  
  while(true){  
    p_student=(struct student *)malloc(size_student);   
    p_student->id=id;   
    strcpy(p_student->name,name);  
    strcpy(p_student->sex,sex);   
    strcpy(p_student->borrow_book," There is no ");  
    head_student=Insert_Student(head_student,p_student);  
    printf(" Do you want to continue? Continue to input 1 , press any key to exit \n"); 
    scanf("%d",&tag); 
    if(tag!=1){ 
      break; 
    } 
    printf(" Please enter the student number :");  
    scanf("%d",&id);  
    printf(" Please enter the student's name :");  
    scanf("%s",name);  
    printf(" Please enter student gender :");  
    scanf("%s",sex);   
    printf("\n");  
  }  
  return head_student; 
} 
 
struct book *Insert_Book(struct book *head_book,struct book *new_book){ 
  struct book *p,*q; 
 
  p=q=head_book; 
   
  if(head_book==NULL){  
    head_book=new_book; 
    new_book->next = NULL; 
  }else{ 
    while((new_book->id>p->id)&&(p->next!=NULL)){ 
      q = p; 
      p = p->next; 
    } 
    if(new_book->id<=p->id){ 
      new_book->next=p; 
      if(head_book==p) 
        head_book=new_book; 
      else 
        q->next = new_book; 
    }else{ 
      p->next=new_book; 
      new_book->next=NULL; 
    } 
  } 
  return head_book; 
}; 
 
struct student *Insert_Student(struct student *head_student,struct student *new_student){ 
  struct student *p,*q; 
 
  p=q=head_student; 
   
  if(head_student==NULL){ 
    head_student=new_student; 
    new_student->next = NULL; 
  }else{ 
    while((new_student->id>p->id)&&(p->next!=NULL)){ 
      q = p; 
      p = p->next; 
    } 
    if(new_student->id<=p->id){ 
      new_student->next=p; 
      if(head_student==p) 
        head_student=new_student; 
      else 
        q->next = new_student; 
    }else{ 
      p->next=new_student; 
      new_student->next=NULL; 
    } 
  } 
  return head_student; 
} 
 
struct book *Search_Book_ById(int id,struct book *head_book){ 
  struct book *ptr_book = head_book;  
  int flag=0;  
  while(ptr_book!=NULL)  
  { 
    if(ptr_book->id==id){ 
      printf(" Book number :%d\n",ptr_book->id); 
      printf(" The name of the book :%s\n",ptr_book->title); 
      printf(" The book cost :%.2lf\n",ptr_book->price); 
      printf(" The book the author :%s\n",ptr_book->author); 
      printf(" Existing state :%s\n",ptr_book->state); 
      printf(" Name of borrower :%s\n",ptr_book->student_name);  
      printf(" Student id :%d\n",ptr_book->student_id); 
      printf("\n"); 
      flag++; 
    } 
    if(flag>0) 
    { 
      break; 
    } 
    ptr_book = ptr_book->next; 
  }  
  if(flag==0){  
      printf(" No information about this book is available !\n\n");  
  }  
  return head_book;  
}; 
 
struct book *Search_Book_ByTitle(char *title,struct book *head_book){ 
  struct book *ptr_book = head_book;  
  int flag=0;  
  while(ptr_book!=NULL)  
  {  
    if(strcmp(ptr_book->title,title)==0){  
      printf(" Book number :%d\n",ptr_book->id);  
      printf(" The name of the book :%s\n",ptr_book->title);  
      printf(" The book cost :%.2lf\n",ptr_book->price);  
      printf(" The book the author :%s\n",ptr_book->author);  
      printf(" Existing state :%s\n",ptr_book->state);  
      printf(" Name of borrower :%s\n",ptr_book->student_name);   
      printf(" Student id :%d\n",ptr_book->student_id);  
      printf("\n");  
      flag++;  
    } 
    if(flag>0) 
    { 
      break; 
    } 
    ptr_book = ptr_book->next; 
  }  
  if(flag==0){  
      printf(" No information about this book is available !\n\n");  
  }  
  return head_book; 
}; 
 
struct book *Search_Book_ByPrice(double price_h,double price_l,struct book *head_book){ 
  struct book *ptr_book = head_book;  
  int flag=0;  
  while(ptr_book!=NULL)  
  {  
    if(ptr_book->price>=price_l&&ptr_book->price<=price_h){  
      printf(" Book number :%d\n",ptr_book->id);  
      printf(" The name of the book :%s\n",ptr_book->title);  
      printf(" The book cost :%.2lf\n",ptr_book->price);  
      printf(" The book the author :%s\n",ptr_book->author);  
      printf(" Existing state :%s\n",ptr_book->state);  
      printf(" Name of borrower :%s\n",ptr_book->student_name);   
      printf(" Student id :%d\n",ptr_book->student_id);  
      printf("\n");  
      flag++;  
    } 
    ptr_book = ptr_book->next; 
  }  
  if(flag==0){  
      printf(" No information about this book is available !\n\n");  
  }  
  return head_book; 
} 
 
 
struct book* Delete_Book(int id,book* head_book){ 
  bool flag=true; 
  struct book *p,*q; 
  p=q=head_book; 
 
  while(p->id!=id&&p->next!=NULL){ 
    q=p; 
    p=p->next; 
  } 
  if(p->id==id){ 
    if(p==head_book){ 
      head_book=p->next; 
    }else{ 
      q->next=p->next; 
    } 
 
    free(p); 
    printf(" Delete successful! \n"); 
  }else{ 
    flag=false; 
    printf(" Can't find the book "); 
  } 
  return head_book; 
}; 
 
struct student* Delete_Student(int id,student* head_student){ 
  bool flag=true; 
  struct student *p,*q; 
  p=q=head_student; 
 
  while(p->id!=id&&p->next!=NULL){ 
    q=p; 
    p=p->next; 
  } 
  if(p->id==id){ 
    if(p==head_student){ 
      head_student=p->next; 
    }else{ 
      q->next=p->next; 
    } 
 
    free(p); 
    printf(" Delete successful! \n"); 
  }else{ 
    flag=false; 
    printf(" The student could not be found "); 
  } 
  return head_student; 
}; 
 
struct student *Search_Student(int id,struct student *head_student){ 
  struct student *ptr_student = head_student;  
  int flag=0;  
  while(ptr_student!=NULL)  
  { 
    if(ptr_student->id==id){ 
      printf(" Student id :%d\n",ptr_student->id); 
      printf(" The name :%s\n",ptr_student->name); 
      printf(" gender :%s\n",ptr_student->sex); 
      printf(" Borrow books :%s\n",ptr_student->borrow_book);  
      printf("\n"); 
      flag++; 
    } 
    if(flag>0) 
    { 
      break; 
    } 
    ptr_student = ptr_student->next; 
  }  
  if(flag==0){  
      printf(" This student information is not available !\n\n");  
  }  
  return head_student;  
}; 
 
void Lent_Book(int id,int student_id,struct book *head_book,struct student *head_student){ 
  struct book* p=head_book; 
  struct student* q=head_student; 
  if(p==NULL||q==NULL){ 
    printf(" Books or students do not exist \n"); 
    return; 
  } 
  while(p!=NULL&&q!=NULL){ 
    if(p->id!=id){ 
      p=p->next; 
    } 
    if(q->id!=student_id){ 
      q=q->next; 
    } 
    if(p->id==id&&q->id==student_id){ 
      break; 
    } 
  } 
  if(p==NULL||q==NULL){ 
    printf(" Books or students do not exist \n"); 
    return; 
  }else{ 
    if(strcmp(p->state," There are ")!=0){ 
      printf(" The book is out !"); 
      return; 
    }else{ 
      p->student_id=student_id; 
      strcpy(p->student_name,q->name); 
      strcpy(q->borrow_book,p->title); 
      strcpy(p->state," Has borrowed "); 
      printf(" Successfully loaned !/n"); 
    } 
  } 
}; 
 
void Back_Book(int id,int student_id,struct book *head_book,struct student *head_student){ 
  struct book* p=head_book; 
  struct student* q=head_student; 
  if(p==NULL||q==NULL){ 
    printf(" Books or students do not exist \n"); 
    return; 
  } 
  while(p!=NULL&&q!=NULL){ 
    if(p->id!=id){ 
      p=p->next; 
    } 
    if(q->id!=student_id){ 
      q=q->next; 
    } 
    if(p->id==id&&q->id==student_id){ 
      break; 
    } 
  } 
  if(p==NULL||q==NULL){ 
    printf(" Books or students do not exist \n"); 
    return; 
  }else{ 
    if(strcmp(p->state," There are ")==0){ 
      printf(" The book did not lend ! I'm sorry !"); 
      return; 
    }else{ 
      p->student_id=-1; 
      strcpy(p->student_name," To be determined "); 
      strcpy(q->borrow_book," There is no "); 
      strcpy(p->state," There are "); 
      printf(" Returned successfully !/n"); 
    } 
  } 
}; 
 
void Print_Book(struct book *head_book){ 
  struct book* p=head_book; 
 
  if(p==NULL){  
    printf("\n No record \n\n");  
    return;  
  }  
  printf("\n Book number \t The name of the book \t The book cost \t The book the author \n\n");  
  while (p!=NULL) 
  { 
    printf("%d\t\t%s\t\t%.2lf\t\t%s\n\n",p->id,p->title,p->price,p->author); 
    p = p->next; 
  } 
} 
 
void Print_Student(struct student *head_student){ 
  struct student* p=head_student; 
 
  if(p==NULL){  
    printf("\n No record \n\n");  
    return;  
  }  
  printf("\n The student's name \t Students' gender \t Student student id \n\n");  
  while (p!=NULL) 
  { 
    printf("%s\t\t%s\t\t%d\n",p->name,p->sex,p->id); 
    p = p->next; 
  } 
} 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

void adminMenu();
void adminlogin();
void finerate();
void borrowmodify();
void LLogin();
void bookadd();
void addborrows();
void search();
void bookdelete();
void bsearch();
void bdelete();
void Librarian();
void allbooks();

int main(){
 
 int admin;
 string username;
 string userpass;
 
 cout << "\n\t\t\t\t\tLibrary Management System\t" << endl << endl;
 cout << "\n\n\n\t\t\t================================================================" << endl;
 cout << "\n\t\t\t\t1. Admin" << endl;
 cout << "\t\t\t\t2. Librarian" << endl;
 cout << "\t\t\t\t3. Exit" << endl;
 cout << "\n\t\t\tEnter your choice : ";
 cin >> admin;
 
 switch(admin){
  case 1:{
   system("cls");
   adminlogin();
   break;
  }
  case 2:{
   system("cls");
   LLogin();
   break;
  }
  case 3:{
   cout << "\n\t\t\tThank you! Have a nice day!!!\n\n";
   break;
  }
  default:
   cout << "\n\t\t\tInvalid choice, Try again--\n";
   main();
 }
 
 return 0;
}

void adminlogin(){
 
 //Login variable
 string adminuser,adminpass,username,password,adminsignup;
 string usern,userp;
 
 //Admin log
 cout << "\n\n\t\t\t\t\t\tAdmin Login\n";
 cout << "\n\t\t\t\t\t****";
 cout << "\n\n\t\t\t\tEnter your username  : ";
 cin >> adminuser;
 cout << "\n\n\t\t\t\tEnter your password  : ";
 cin >> adminpass;
 
 //Admin username and password
 username = "Admin";
 password = "Admin123";

 if(adminuser==username && adminpass==password){
  cout << "\n\t\t\t\tLogin successfully........";
  Sleep(2000);
  adminMenu();
 }else{
  cout << "\n\t\t\t\t--Login fail. Try again--" << endl;
  adminlogin();
 }
}

void adminMenu(){
 
 int adminsignup,adminnumber;
 string adminuser,adminmail,adminid,usern,userp;
 
 system("cls");
 cout << "\n\n\n\t\t\t\t\tAdmin" << endl;
 cout << "\n\t\t\t\t1. Sign up";
 cout << "\n\t\t\t\t2. Fine rate";
 cout << "\n\t\t\t\t3. Barrow modify";
 cout << "\n\t\t\t\t4. Back to menu" << endl;
 cout << "\n\t\t\t\tEnter your choice : ";
 cin >> adminsignup;
 
 switch(adminsignup){
  case 1:{
   system("cls");
   cout << "Enter your ID    : ";
   cin >> adminid;
   cout << "Enter your name  : ";
   cin.ignore();
   getline(cin,adminuser);
   cout << "Enter your Email : ";
   cin >> adminmail;
   cout << "Enter your phone Number : ";
   cin >> adminnumber;
   
   fstream file;
   file.open("librarianPass.dat",ios::in);                                     
   if(file.is_open()){
    string line;
   
    while(getline(file,line)){
     istringstream ss(line);
     string id;
     getline(ss,id,' ');
     
     //check enter id enter to the librarian id
     if(id==adminid){
      for(int i=0;i<0;i++){
       cout << ' ';
      }
      cout << "\n\n\n\t\t\t\tYou Registerd";
      file.close();
      Sleep(2000);
      adminMenu();
     }
    }
      
    fstream file1;
    file1.open("librarianpass.dat",ios::app);                                       
    if(file1.is_open()){
     file << adminid <<" "<< adminuser << " " << adminmail << endl;
     cout << "\n\n\t\tsuccessfully Registerd";
     file1.close();
    } 
      
   }else{
    cout << "\n\n\n\t\t\t\tNot found\n\n\n";
   }
   
   cout << "\n\n\t\t\tCreate username : ";
   cin >> usern;
   cout << "\n\n\t\t\tCreate password : ";
   cin >> userp;
   
   fstream file3;
   file3.open("lpginpassuname.dat",ios::app);
   if(file3.is_open()){
    file3 <<usern <<" "<< userp  << endl;
    cout << "\n\n\t\tsuccessfully Added";
    file3.close();
    system("cls");
    adminMenu();
   }else{
    cout << "Not added";
   }
   break;
  }
  case 2:{
   finerate();
   break;
  }
  case 3:{
   borrowmodify();
   break;
  }
  case 4:{
   system("cls");
   main();
   
   break;
  }default:
   cout << "Wrong option. Try again";
   adminMenu();
 }
}
//librarian login
void LLogin(){
 
 string Lusern,Lpass;
 
 cout << "\n\n\t\t\t\t\tLibrarian Login\n";
 cout << "\n\t\t\t\t---------------------------------\n";
 cout << "\n\t\t\t\tEnter your username : ";
 cin >> Lusern;
 cout << "\n\t\t\t\tEnter your password : ";
 cin >> Lpass;
 
 fstream librylog;
 librylog.open("lpginpassuname.dat",ios::in);
 
 if(librylog.is_open()){
  string line;
  
  while(getline(librylog,line)){
  string usname,pssrd;
  istringstream ss(line);
  
  getline(ss,pssrd,' ');
  getline(ss,usname,' ');
  
  if( usname.compare(Lusern) && pssrd.compare(Lpass) ){
   cout << "\n\t\t\t\t\tSuccessfully Login . ";
   librylog.close();
   Sleep(2000);
   system("cls");
    Librarian();
    
  }
  else {
  	cout << "\n\t\t\t\t\t--Wrong Login, Try again--\n";
  LLogin();
  }
  }
  
 }
 else{
  cout << "\n\t\t\t\t\t--File open failed, Try again--\n";
 }

}

//fine rate
void finerate(){
 system("cls");
   
 string changefiner;
 float newfiner,ufiner;
   
 fstream finerate;
 finerate.open("frfile.dat",ios::in);
 if(!finerate){
  cout << "\n\n\t\tFile not found\n\n\t\t";
 }
 else{
  string line;
  while(getline(finerate,line)){
   istringstream iss(line);
   cout << "\n\n\t\t\t\t\tFine rate\n\n";
   cout <<"\n\t\t\t\t-------------------------------------------";
   cout << "\n\n\t\t\tCurrent fine rate is " << "Rs." << line << endl;
  }
 }
 cout << "\n\n\n\t\t\tAre you changing this fine rate? (yes/no) : ";
 cin >> changefiner;
  
 if(changefiner=="yes"){
  fstream finerate;
  finerate.open("frfile.dat",ios::out);
  if(!finerate){
   cout << "\n\n\n\t\t\tFailed\n\n\n\t\t\t";
  }
  else{
   cout << "\n\n\n\t\t\t\tEnter your new fine rate : ";
   cin >> newfiner;
   finerate << newfiner << endl;
   cout << "\n\n\n\t\t\t\tCurrent fine rate is " << "Rs." << newfiner;
   cout <<"\n\n\n\t\t\t\tSuccesfuly!!!...";
   Sleep(2000);
   adminMenu();
  }
  finerate.close();
 }
 else if(changefiner=="no"){
  cout << "\n\n\n\t\t\t\t\tNext... ";
  Sleep(2000);
  adminMenu();
 }
}
//Modify borrowers
void borrowmodify(){
 string cblimit;
 float newblimit;
   
 system("cls");
   
 fstream barrowmodify;
 barrowmodify.open("bmfile.dat",ios::in);
 if(!barrowmodify){
  cout << "\n\n\n\t\t\tNot found\n\n\n\t\t\t";
 }
 else{
  string line2;
  while(getline(barrowmodify,line2)){
   istringstream iss(line2);
   cout << "\n\n\t\t\t\t\tBarrow Modify\n\n\t\t\t\t";
   cout <<"\n\t\t\t\t-------------------------------------------";
   cout << "\n\n\t\t\t\t\tBarrow limit is " << line2;
  }
 }
 cout << "\n\n\t\t\t\tAre you modify this borrow limit? (yes/no) : ";
 cin >> cblimit;
   
 if(cblimit=="yes"){
  fstream barrowmodify;
  barrowmodify.open("bmfile.dat",ios::out);
  if(!barrowmodify){
   cout << "\n\n\n\t\t\tFaild\n\n\n\t\t\t";
  }
  else{
   cout << "\n\n\n\t\t\tEnter your new barrow limit : ";
   cin >> newblimit;
   barrowmodify<<newblimit<<endl;
   cout << "\n\n\n\t\t\tCurrent Barrow limit is " << newblimit;
   Sleep(2000);
   adminMenu();
  }
  barrowmodify.close();
 }
 else if(cblimit=="no"){
  cout << "\n\n\n\t\t\tNext...\n\n\n\t\t\t";
  Sleep(2000);
  adminMenu();
 }
}

//librarian
void Librarian(){
 int option;
 system("cls");
 
 cout << "\n\n\n\t\t\t\tLibrarian" << endl;
 cout << "\n\t\t1.Book Add" << endl;
 cout << "\n\t\t2.Delete" << endl;
 cout << "\n\t\t3.search" << endl;
 cout << "\n\t\t4.All books" << endl;
 cout << "\n\t\t5.Borrows Add" << endl;
 cout << "\n\t\t6.Borrows delete" << endl;
 cout << "\n\t\t7.Borrow search" << endl;
 cout << "\n\t\t8.Back to menu" << endl;
 
 cout << "\n\n\t\tEnter your option : ";
 cin >> option;
 
 switch(option){
  case 1:{
   system("cls");
   bookadd();
   break;
  }
  case 2:{
   system("cls");
   bookdelete();
   break;
  }
  case 3:{
   system("cls");
   search();
   break;
  }
  case 4:{
   system("cls");
   allbooks();
   break;
  }
  case 5:{
   system("cls");
   addborrows();
   break;
  }
  case 6:{
   system("cls");
   bdelete();
   break;
  }
  case 7:{
   system("cls");
   bsearch();
   break;
  }
  case 8:{
   system("cls");
   main();
   break;
  }
 }
}
//Book add
void bookadd(){
 string bgenre,btitle,bauthor,bpublish,bid;
 float bprice;
 
 system("cls");
 
 //Book details
 cout << "Enter your book ID : ";
 cin >> bid;
 
 fstream bookadd;
 bookadd.open("bookaddfile.dat",ios::in);
 if(bookadd.is_open()){
  string line;
  while(getline(bookadd,line)){
   istringstream ss(line);
   string bookid;
   getline(ss,bookid,',');
   bookadd.close();	
   
   if(bookid==bid){
    cout << "\n\n\n\t\t\t\t\tBook details already added";
    bookadd.close();
    Sleep(2000);
    Librarian();
   }
  }
  
  cout << "Enter your book genre  : ";
  cin.ignore();
  getline(cin,bgenre);
  cout << "Enter your book title  : ";
  getline(cin,btitle);
  cout << "Enter your book author : ";
  getline(cin,bauthor);
  cout << "Enter your book price  : " << "Rs.";
  cin >> bprice;
  cout << "Enter your book publish : ";
  cin >> bpublish;
  
  fstream filecreat;
  filecreat.open("bookaddfile.dat",ios::app);
  if(filecreat.is_open()){
   filecreat << bid << ',' << bgenre << ',' << btitle << ',' << bauthor << ',' << bprice << ',' << bpublish << ',' << endl;
   cout << "\n\n\t\t\tBook added successfully";
   filecreat.close();
   Sleep(2000);
   Librarian();
  }
  else{
   cout << "\n\n\n\n\t\t\t\tBook not added\n\n\n";
  }
 }
 else{
  cout << "\n\n\n\n\t\t\t\tBook not opened\n\n\n";
 }           
 
}

//add borrowers
void addborrows(){
 string borrowid,borrowname,borrowdate;
 int borrownumber;
 
 system("cls");
 
 //Book details
 cout << "Enter your ID : ";
 cin >> borrowid;
 
 fstream borrowadd;
 borrowadd.open("borrowfile.dat",ios::in);   
 if(borrowadd.is_open()){
  string line;
  while(getline(borrowadd,line)){
   istringstream ss(line);
   string borrowsid;
   getline(ss,borrowsid,',');
   
   if(borrowsid==borrowid){
    cout << "\n\n\n\t\t\t\t\tBorrow added";
    borrowadd.close();
    Sleep(2000);
    Librarian();
   }
  }
  
  
  cout << "Enter your name  : ";
  cin.ignore();
  getline(cin,borrowname);
  cout << "Enter your date  : ";
  getline(cin,borrowdate);
  cout << "Enter your phone number : ";
  cin >> borrownumber;
  
   fstream borrowcreat;
   borrowcreat.open("borrowfile.dat",ios::app);
   if(borrowcreat.is_open()){
    borrowcreat << borrowid << ',' << borrowname << ',' << borrowdate << ',' << borrownumber << ',' << endl;
    cout << "\n\n\t\t\tBorrow added successfully";
    borrowcreat.close();
    Sleep(2000);
    Librarian();
   }
   else{
    cout << "\n\n\n\n\t\t\t\tBorrow not added\n\n\n";
   }
 }
 else{ 
  cout << "\n\n\n\n\t\t\t\tBorrow not opened\n\n\n";
 }
 
}

//Search book
void search(){
 system("cls");
 string bid;
 
 cout << "\n\t\t\t\t\t\tPlease enter your book ID : ";
 cin >> bid;
 
 ifstream addbookfile("abook.dat");                
 if(addbookfile.is_open()){                         
  string line;
  while(getline(addbookfile,line)){
   string bookid;
   istringstream iss(line);
   getline(iss,bookid,' ');
  
   //book id
  if(bid==bookid){     	     
    
   cout << line << endl;
   addbookfile.close();
   cout << "\n\n\t\t\t\tNext....";
   getche();
  }
  else{
   cout << "\n\n\t\t\t\tNot available\n\n\n"; 
   Sleep(2000);
   addbookfile.close();
  }
  }
 Librarian();
 }
 else{
  cout << "Not opened"<<endl;
 }
}

//Delete book 
void bookdelete(){
 system("cls");
 
 fstream bookadd;
 fstream filetemp;
 
 bool found = false;
 
 string bgenre,btitle,bauthor,bpublish,bid,bdelete;
 float bprice;
 
 bookadd.open("bookaddfile.dat",ios::in);
 filetemp.open("tempfile.dat",ios::out);
 
 if(!bookadd || !filetemp){
  cout << "Can't open this file" << endl;
 }
 else{
  cout << "Enter your book number to delete : ";
  cin >> bdelete;
  while(bookadd >> bgenre >> btitle >> bauthor >> bpublish >> bid >> bprice){
   if(bid == bdelete){
    found = true;
   }
   else{
    filetemp << bgenre << ' ' << btitle << ' ' << bauthor << ' ' << bpublish << ' ' << bid << ' ' << bprice << ' ' << endl;
   }
  }
 }
 bookadd.close();
 filetemp.close();
 
 if(found == true){
  remove("bookaddfile.dat");
  rename("tempfile.dat","bookaddfile.dat");
  cout << "Book deleted" << endl;
  Sleep(2000);
 }
 else{
  remove("tempfile.dat");
  cout << "Book not found" << endl;
 }
}

//Search borrowers
void bsearch(){
 system("cls");
 
 string borid;
 cout << "Enter your borrow ID : ";
 cin >> borid;
 
 ifstream borrowadd("borrowfile.dat");
 if(borrowadd.is_open()){
  string line;
  while(getline(borrowadd,line)){
   string borrowid;
   istringstream iss(line);
   getline(iss,borrowid);
   
   //Borrow ID check
   if(borrowid == borid){
    cout << "\t\t\t\tBorrow details\n" << endl;
    cout << "ID\tName\tDate\tPhone number";
    cout << line << endl;
    borrowadd.close();
   }
  }
  cout << "\n\n\n\t\t\t\tNext...";
  getche();
  Librarian();
 }
 else{
  cout << "\n\n\n\t\t\t\tNot opened...\n\n\n" << endl;
 }
}

//Borrowers delete
void bdelete(){
 system("cls");
 
 fstream borrowadd;
 fstream filetempd;
 
 bool found = false;
 
 string borrowid,borrowname,borrowdate,deleteborrowid;
 int borrownumber;
 
 borrowadd.open("borrowfile.dat",ios::in);    
 filetempd.open("addtempborrowers.dat",ios::out);
 
 if(!borrowadd ||!filetempd){
  cout << "Can't open this file" << endl;
 }
 else{
  cout << "Enter the borrow ID : ";
  cin >> deleteborrowid;
  while(borrowadd >> borrowname >> borrowid >> borrownumber >> borrowdate){
   if(borrowid == deleteborrowid){
    found = true;
   }
   else{
    filetempd << borrowid << ' ' << borrowname << ' ' << borrowdate << ' ' << borrownumber << endl;
   }  
  }
 }
 borrowadd.close();
 filetempd.close();
 
 if(found == true){
  remove("borrowfile.dat");
  rename("addtempborrowers.dat","borrowfile.dat");
  cout << "Borrower deleted";
  Sleep(2000);
  Librarian();
 }
 else{
  remove("addtempborrowers.dat");
  cout << "Borrower not found" << endl;
 }
}

//Display All books
void allbooks(){
 system("cls");
 fstream bookadd; 
 bookadd.open("bookaddfile.dat",ios::in);
 if(bookadd.is_open()){
  string line;
  while(getline(bookadd,line)){
   cout << line<< endl;
  }
  bookadd.close();
 }else{
  cout <<"\n\t\t\tOpen Faild\n";
 }
 Sleep(4000);
 Librarian();
}

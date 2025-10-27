#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class book{
    public:
    int id;
    string name;
    string author;
    void getdata(){
        cout<<"Enter the book id: "<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter the book name: "<<endl;
        getline(cin,name);
        cout<<"Enter the author name: "<<endl;
        getline(cin,author);
        cout<<endl;
    }
    void showdata(){
        cout<<"Id no. of a book: "<<id<<endl;
        cout<<"Name of the book is : "<<name<<endl;
        cout<<"Name of the author is: "<<author<<endl;
    }
};
void addBook(){
    book b;
    b.getdata();
    ofstream file("library.txt",ios::app);
    file<<b.id<<endl;
    file<<b.name<<endl;
    file<<b.author<<endl;
    file.close();
    cout<<"Book added!\n";
}
void displayBook(){
    book b;
    ifstream file("library.txt");
    while(file>>b.id){
        file.ignore();
        getline(file,b.name);
        getline(file,b.author);
        b.showdata();
    }
    file.close();
}
void searchBook(){
    int searchId;
    book b;
    ifstream file("library.txt");
    cout<<"Enter the book ID to search: ";
    cin>>searchId;
    while(file>>b.id){
        file.ignore();
        getline(file,b.name);
        getline(file,b.author);
        if(b.id==searchId){
            b.showdata();
            return;
        }
    }
    cout<<"Book Not Found! ";
}
void deleteBook(){
    int deleteId;
    book b;
    ifstream file("library.txt");
    ofstream temp("temp.txt",ios::app);
    cout<<"Enter the Book ID to delete: ";
    cin>>deleteId;
    bool found=false;
    while(file>>b.id){
        file.ignore();
        getline(file,b.name);
        getline(file,b.author);
        if(b.id!=deleteId){
            temp<<b.id<<endl;
            temp<<b.name<<endl;
            temp<<b.author<<endl;
        }
        else{
            found=true;
        }
    }
        file.close();
        temp.close();
        remove("library.txt");
        rename("temp.txt","library.txt");
        if(found)cout<<"Book Deleted!";
        else cout<<"Book NOt Found! ";
}
void clearBook(){
    ofstream file("library.txt",ios::trunc);
    file.close();
    cout<<"Library file cleared successfully"<<endl;
}
int main(){
    int choice;
    do{
        cout<<"\n1. Add book \n2.Display \n3. Search \n4. Delete \n5.clear \n6.Exit\n";
        cin>>choice;
        switch(choice){
            case 1: addBook();break;
            case 2: displayBook();break;
            case 3: searchBook();break;
            case 4: deleteBook();break;
            case 5: clearBook();break;
            case 6: cout<<"Exiting";break;
        }
        }while(choice!=6);
    return 0;
}

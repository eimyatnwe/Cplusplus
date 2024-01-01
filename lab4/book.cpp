#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book{
    public: 
        string title, author;
        int quantity;
    void setTitle(string newTitle){
        title = newTitle;
    }
    string getTitle(){
        return title;
    }

    void setAuthor(string newAuthor){
        author = newAuthor;
    }
    string getAuthor() {
        return author;
    }
    void setQuantity(int newQ){
        quantity = newQ;
    }
    int getQuantity() {
        return quantity;
    }
};

class Inventory{
    public:
        vector<Book> books;

        vector<Book> addBook(Book newbook){
            books.push_back(newbook);
            return books;
        }

        vector<Book> removeBook(string rtitle){
            for (int i = 0; i < books.size(); i++){
                if (books[i].getTitle() == rtitle){
                    books.erase(books.begin() + i);
                }else{
                    continue;
                }
            }
            return books;
        }

        string findBook(string ftitle){
            for (int i = 0; i < books.size(); i++){
                if(books[i].getTitle() == ftitle){
                    return "Title: " + books[i].getTitle() + " , Author: " + books[i].getAuthor() 
                            + " , Quantity: " + to_string(books[i].getQuantity());
                }else{
                   continue;
                }
            }
            return "Not found";
        }
       

        void printInventory() {
            if (books.empty()) {
                cout << "There is no book" << endl;
            }
            for (int i = 0; i < books.size(); i++) {
                cout <<   "Title: " + books[i].getTitle() 
                        + "\nAuthor: " + books[i].getAuthor()
                        + "\nQuantity: " + to_string(books[i].getQuantity()) + "\n";
            }
    }

};

int main(){
    char choice;
    string title,author;
    int quantity;
    Book book;
    Inventory bookList;
    while(true){
        cout << "Enter command (a: add, s: search, l: list, r: remove, q: quit): ";
        cin >> choice;

        if (choice == 'a'){
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            
            getline(cin, author);
            cout << "Enter quantity: ";
            cin >> quantity;
            book.setAuthor(author);
            book.setTitle(title);
            book.setQuantity(quantity);
            bookList.addBook(book);

        }
        else if( choice == 's'){
            cout << "Enter title to search: ";
            cin.ignore();
            getline(cin,title);
            string res = bookList.findBook(title);
            cout << res << endl;
        }else if( choice == 'l'){
            bookList.printInventory();
        }else if( choice == 'q'){
            break;
        }else if( choice == 'r'){
            cout << "Enter title to remove: ";
            cin.ignore();
            getline(cin,title);
            bookList.removeBook(title);
        }
        else{
            cout << "Invalid Input" << endl;
        }
       
    }
    return 0;

}
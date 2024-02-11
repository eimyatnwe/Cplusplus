#include<iostream>
#include <vector>
#include "Album.h"

using namespace std;

int main(){
    int choice;
    string name;
    vector<Album> albums;
    albums.emplace_back("Abbey Road","The Beatles",19.99,5);
    albums.emplace_back("The Dark Side of the Moon","Pink Floyd",21.99,3);
    albums.emplace_back("Hotel California","Eagles",15.99,4);
    albums.emplace_back("Back in Black","Ac/DC",20.99,2);
    albums.emplace_back("Rumours","Fleetwood Mac",16.99,3);
    albums.emplace_back("Thriller","Michael Jackson",18.99,5);
    albums.emplace_back("The Wall","Pink Floyd",22.99,2);
    albums.emplace_back("Led Zeppelin IV","Led Zepplin",17.99,3);

    while (true)
    {
        cout << "\nOnline Music Store Menu: \n";
        cout << "1. List all albums\n";
        cout << "2. Purchase an album\n";
        cout << "3. Display sales statistics\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice > 4){
            cout << "Invalid choice. Please Try again\n";
            continue;
        }
       
        if(choice == 1){
            cout << "Available Albums: \n";
            for(int i = 0; i < albums.size(); ++i){
                cout << i + 1 << ". " << albums[i].getTitle() << " by " << albums[i].getArtist()
                << " -  $" << albums[i].getPrice() << " ( " << albums[i].getCopies() << " copies available)\n";
            }
        }
        else if(choice == 2){
            cout << "Enter the name of the album: ";
            cin.ignore();
            getline(cin,name);
            for(int i = 0; i < albums.size(); ++i){
                if(name == albums[i].getTitle()){
                   albums[i].purchaseAlbum();

                }
            }
            
        }
        
        else if(choice == 3){
            cout << "Total albums in inventory: " << Album::getTotalAlbums() << endl;
            cout << "Total sales made: $ " << Album::getTotalSales() << endl;
        }else if(choice == 4){
            cout << "Thank you for using the online Music Store";
            break;
        }
    
    }
    return 0;
    
}
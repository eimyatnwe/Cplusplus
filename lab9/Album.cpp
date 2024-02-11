#include<iostream>
#include "Album.h"
using namespace std;

int Album::totalAlbums = 0;
double Album::totalSales = 0;

Album::Album(const string& title,const string& artist, double prices, int copies){
    Album::title = title;
    Album::artist = artist;
    Album::price = prices;
    copiesAvailable = copies;
    totalAlbums += copiesAvailable;

}

void Album::purchaseAlbum(){
    if(copiesAvailable > 0){
        copiesAvailable--;
        totalAlbums--;
        totalSales += price;
        cout << "Album purchased successfully\n";
    }else{
        cout << "Album out of stock\n";
    }
}

 int Album::getTotalAlbums(){
    return Album::totalAlbums;
}

 double Album::getTotalSales(){
    return Album::totalSales;
}

string Album::getTitle(){
    return title;
}

string Album::getArtist(){
    return artist;
}

double Album::getPrice(){
    return Album::price;
}

int Album::getCopies(){
    return Album::copiesAvailable;
}


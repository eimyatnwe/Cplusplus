#include<string>
using namespace std;
#ifndef ALBUM_H
#define ALBUM_H

class Album{
    private:
        string title,artist;
       double price;
       int copiesAvailable;
       static int totalAlbums;
       static double totalSales;

    public:
       
       Album(const string& title,const string& artist, double price, int copies);

       void purchaseAlbum();
       static int getTotalAlbums();
       static double getTotalSales();
       string getTitle();
       string getArtist();
       double getPrice();
       int getCopies();

};

#endif
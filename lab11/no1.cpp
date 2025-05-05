#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Movie{
    string title;
    vector<string> date;
    vector<vector<bool>> availableSeats;

    Movie(const string& movieTitle,const vector<string>& dates) : title(movieTitle), date(dates){
        availableSeats = vector<vector<bool>>(4,vector<bool>(10,true));
    }
};

struct Reservation{
    string customerName;
    string movieTitle;
    string date;
    int round;
    int seatNumber;
};

void displaySchedule(vector<Movie> movies){
    for(int i = 0; i < movies.size(); i++){
       cout << "\nMovie: " << movies[i].title << endl;
       for(const string& date: movies[i].date){
            cout << "\nDate: " << date;
            for(int j = 0; j < 4; j++){
            cout << (j == 0 ? " 12:00: " : j == 1 ? " 15:00: " : j == 2 ? " 18:00: " : " 21:00: ");
            int availableSeats = 0;
            for(bool seat : movies[i].availableSeats[j]){
                if(seat){
                    ++availableSeats;
                }
            }
            cout << " " << availableSeats << " seats available.";
       }
      
    }
        cout << endl;
    }
}

void makeReservation(vector<Movie>& movies){
    
    int movieChoice;
    int seatNumber,dateNumber,roundNumber,numOfSeats;
    cout << "Select a movie: \n";
    for(int i = 0; i < movies.size(); i++){
        cout << i + 1 << ") " << movies[i].title << endl;
    }

    cout << "Enter movie number: ";
    cin >> movieChoice;
    cout << "Select a date: \n";
    for(int i = 0; i < movies[movieChoice - 1].date.size(); i++){
        cout << i + 1 << ") " << movies[movieChoice - 1].date[i] << endl;
    }
    cout << "Enter date number: ";
    cin >> dateNumber;
    cout << "Select a round: \n";
    for(int j = 0; j < 4; j++){

        cout << j + 1 << ") Round " << j + 1;
        int availableSeats = 0;
        for(bool seat : movies[movieChoice - 1].availableSeats[j]){
            if(seat){
                    ++availableSeats;
                }
            }
        cout << " - " << availableSeats << " seats left." << endl;
    }

    cout << "Enter round number: ";
    cin >> roundNumber;
    cout << "Enter the numbers of seats to reserve: ";
    cin >> numOfSeats;

    bool reserve = true;
   
    for(int i = 0; i < numOfSeats; i++){
        if(!movies[movieChoice - 1].availableSeats[roundNumber - 1][i]){
            reserve = false;
            break;
        }

    }
    if(reserve){
       for(int i = 0; i <  numOfSeats; i++){
            movies[movieChoice - 1].availableSeats[roundNumber - 1][i] = false;
        }
        cout << "Successfully reserved " << numOfSeats << " seats for " << movies[movieChoice - 1].title << " on "
        << movies[movieChoice - 1].date[dateNumber - 1] << " for round " << roundNumber << ".\n"; 
    }else{
        cout << "Not enough seats\n";
    }
};

int main(){
    

    vector<Movie> movies = {
        {"Poor things",{"2024-03-01","2024-03-02","2024-03-03"}},
        {"Co Co",{"2024-03-01","2024-03-02","2024-03-03"}},
        {"Harry Potter",{"2024-03-01","2024-03-02","2024-03-03"}}

    };
    int choice;
    while(true){
        cout << "1.View Schedule\n";
        cout << "2.Make Reservation\n";
        cout << "3.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if(choice < 1 || choice > 3){
            break;
        }
        if(choice == 1){
            displaySchedule(movies);
           
        }
        else if(choice == 2){
            makeReservation(movies);
           
        }
        else if(choice == 3){
            break;
        }
    }
   
    return 0;
}
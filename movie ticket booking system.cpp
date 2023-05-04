// this program is prepared by CODE WARRIORS
#include <iostream>
#include <string>
using namespace std;

class MovieTicketBookingSystem {  //create class
private: //data members
    int seats[10] = {1,1,1,1,1,1,1,1,1,1}; // 1 means available, 0 means booked
    string movie;
    int dd,mm,yyyy;
    int ticketPrice = 130;
public: //methods
    void displayMenu();
    void bookTicket();
    void viewBooking();
};

void MovieTicketBookingSystem::displayMenu() {
    int choice;
     cout << "Enter Movie Title : ";
        fflush(stdin);
        getline(cin, movie);
        fflush(stdin);
        cout << "============ DATE ============" << endl;
        cout << "Enter Date like dd mm yyyy : ";
        cin >> dd >> mm >> yyyy;
    do {
        cout << "============ Movie Ticket Booking System ============" << endl;
        cout << "1. Book a ticket" << endl;
        cout << "2. View booking status" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice; //1, 2 or 3

        switch(choice) {
            case 1:
                bookTicket(); //call method by choice
                break;
            case 2:
                viewBooking();
                break;
            case 3:
                cout << "Thank you for using our system!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(choice != 3);
}

void MovieTicketBookingSystem::bookTicket() {
    int numTickets, seatNum;
    cout << "============ Book a ticket ============" << endl;
    cout << "Movie : " << movie << endl;
    cout << "Date : " << dd << "/" <<mm << "/" <<yyyy << endl;
    cout << "Ticket price : " << ticketPrice << " Rupee" << endl;
    cout << "Number of tickets : ";
    cin >> numTickets;
    if (numTickets > 10) {
        cout << "Sorry, we only have 10 seats available." << endl;
        return;
    }
    cout << "Available seats : ";
    for (int i = 0; i < 10; i++) {
        if (seats[i] == 1) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < numTickets; i++) {
        cout << "Enter seat number for ticket " << i+1 << ": ";
        cin >> seatNum;
        if (seatNum < 1 || seatNum > 10 || seats[seatNum-1] == 0) {
            cout << "Sorry, that seat is not available. Please choose another." << endl;
            i--;
        } else {
            seats[seatNum-1] = 0; // Mark seat as booked
        }
    }
    int totalCost = numTickets * ticketPrice;
    cout << "**Booking successful!**" << endl;
    cout << "Total cost : " << totalCost <<" Rupee"<< endl;
}

void MovieTicketBookingSystem::viewBooking() {
    cout << "============ Booking status ============" << endl;
    cout << "Movie : " << movie << endl;
    cout << "Ticket price : " << ticketPrice << " Rupee" <<endl;
    cout << "Available seats : ";
    for (int i = 0; i < 10; i++) {
        if (seats[i] == 1) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
    cout << "Booked seats : ";
    for(int i = 0; i < 10; i++) {
        if(seats[i] == 0) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main() {
    MovieTicketBookingSystem M1; //Object
    M1.displayMenu(); //call method by Object
    cout<<endl<<"This program is prepared by CODE WARRIORS..";
    return 0;
}

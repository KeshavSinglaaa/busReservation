#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Bus {
public:
    string busNumber;
    string driver;
    string arrival;
    string departure;
    string from;
    string to;
    vector<vector<string> > seats;
    Bus() {
        seats.resize(8, vector<string>(4, "Empty"));
    }
    void install() {
        cout << "Enter Bus Number: ";
        cin >> busNumber;
        cout << "Enter Driver's Name: ";
        cin >> driver;
        cout << "Enter Arrival Time: ";
        cin >> arrival;
        cout << "Enter Departure Time: ";
        cin >> departure;
        cout << "Enter From Location: ";
        cin >> from;
        cout << "Enter To Location: ";
        cin >> to;
    }
    void reserveSeat() {
        int seatNumber;
        cout << "Enter Seat Number (1-32): ";
        cin >> seatNumber;
        if (seatNumber < 1 || seatNumber > 32) {
            cout << "Invalid seat number.\n";
            return;
        }
        int row = (seatNumber - 1) / 4;
        int col = (seatNumber - 1) % 4;
        if (seats[row][col] == "Empty") {
            cout << "Enter Passenger's Name: ";
            cin >> seats[row][col];
            cout << "Seat reserved successfully.\n";
        } else {
            cout << "Seat already reserved.\n";
        }
    }
    void show() const {
        cout << "\nBus Number: " << busNumber
             << "\nDriver: " << driver
             << "\nArrival: " << arrival
             << "\nDeparture: " << departure
             << "\nFrom: " << from
             << "\nTo: " << to << "\n";
        int seatNumber = 1;
        for (const auto& row : seats) {
            for (const auto& seat : row) {
                cout.width(2);
                cout << seatNumber++ << ": " << seat << "\t";
            }
            cout << "\n";
        }
    }
    void availableSeats() const {
        int count = 0;
        for (const auto& row : seats) {
            for (const auto& seat : row) {
                if (seat == "Empty") count++;
            }
        }
        cout << "Available Seats: " << count << "\n";
    }
};
int main() {
    vector<Bus> buses;
    int choice;
    while (true) {
        cout << "\n--- Bus Reservation System ---\n";
        cout << "1. Install New Bus\n";
        cout << "2. Reserve Seat\n";
        cout << "3. Show Bus Info\n";
        cout << "4. List All Buses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Bus newBus;
                newBus.install();
                buses.push_back(newBus);
                break;
            }
            case 2: {
                string busNo;
                cout << "Enter Bus Number: ";
                cin >> busNo;
                bool found = false;
                for (auto& bus : buses) {
                    if (bus.busNumber == busNo) {
                        bus.reserveSeat();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Bus not found.\n";
                break;
            }
            case 3: {
                string busNo;
                cout << "Enter Bus Number: ";
                cin >> busNo;
                bool found = false;
                for (const auto& bus : buses) {
                    if (bus.busNumber == busNo) {
                        bus.show();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Bus not found.\n";
                break;
            }
            case 4: {
                for (const auto& bus : buses) {
                    cout << "Bus Number: " << bus.busNumber << ", From: " << bus.from << ", To: " << bus.to << "\n";
                    bus.availableSeats();
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

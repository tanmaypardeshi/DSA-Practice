#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Car class
class Car {
public:
    string licensePlate;

    Car(const string& plate) {
        licensePlate = plate;
    }
};

// ParkingSpot class
class ParkingSpot {
public:
    int spotNumber;
    bool occupied;
    Car* car; // pointer to car parked in this spot, nullptr if empty

    ParkingSpot(int number) {
        spotNumber = number;
        occupied = false;
        car = nullptr;
    }
};

// ParkingLot class
class ParkingLot {
private:
    vector<ParkingSpot> spots;
    int capacity;

public:
    ParkingLot(int capacity) {
        this->capacity = capacity;
        for (int i = 1; i <= capacity; i++) {
            spots.push_back(ParkingSpot(i));
        }
    }

    // Park a car in the first available spot
    bool parkCar(Car& car) {
        for(ParkingSpot& spot: spots) {
			if(!spot.occupied) {
				spot.occupied = true;
				spot.car = &car;
				return true;
			}
		}
        return false;
    }

    // Remove a car by license plate
    bool removeCar(const string& licensePlate) {
        for(int i = 0; i < spots.size(); i++) {
			if(spots[i].occupied && spots[i].car != nullptr && spots[i].car->licensePlate == licensePlate) {
				spots[i].car = nullptr;
				spots[i].occupied = false;
				return true;
			}
		}
        return false;
    }

    // Display available spots
    void displayAvailableSpots() {
        cout << "Available spots: ";
        for (const auto& spot : spots) {
            if (!spot.occupied) {
                cout << spot.spotNumber << " ";
            }
        }
        cout << endl;
    }

    // Optional: display all cars
    void displayParkedCars() {
        cout << "Parked cars:" << endl;
        for (const auto& spot : spots) {
            if (spot.occupied && spot.car != nullptr) {
                cout << "Spot " << spot.spotNumber << ": " << spot.car->licensePlate << endl;
            }
        }
    }
};

int main() {
    ParkingLot lot(5);

    Car car1("ABC123");
    Car car2("XYZ789");
    Car car3("LMN456");

    lot.parkCar(car1);
    lot.parkCar(car2);
    lot.displayAvailableSpots();
    lot.displayParkedCars();

    lot.removeCar("ABC123");
    lot.displayAvailableSpots();
    lot.displayParkedCars();

    lot.parkCar(car3);
    lot.displayAvailableSpots();
    lot.displayParkedCars();

    return 0;
}

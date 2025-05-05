#include <iostream>
#include <string>

using namespace std;

const int MAX_CARS = 100;

struct Car {
    string make;
    string model;
    int year;
    double price;
};

Car inventory[MAX_CARS];
int car_count = 0;

void addCar(const string& make, const string& model, int year, double price) {
    if (car_count >= MAX_CARS) {
        cout << "Inventory is full. Cannot add more cars.\n";
        return;
    }
    inventory[car_count++] = {make, model, year, price};
    cout << "Car added successfully.\n";
}


void removeCar(const string& make, const string& model, int year) {
    for (int i = 0; i < car_count; ++i) {
        if (inventory[i].make == make && inventory[i].model == model && inventory[i].year == year) {
          
            for (int j = i; j < car_count - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            --car_count;
            cout << "Car removed successfully.\n";
            return;
        }
    }
    cout << "Car not found.\n";
}

void searchByPriceRange(double minPrice, double maxPrice) {
    bool found = false;
    cout << "Cars in the price range $" << minPrice << " - $" << maxPrice << ":\n";
    cout << "Make\tModel\tYear\tPrice\n";
    cout << "----\t-----\t----\t-----\n";
    
    for (int i = 0; i < car_count; ++i) {
        if (inventory[i].price >= minPrice && inventory[i].price <= maxPrice) {
            cout << inventory[i].make << '\t'
                 << inventory[i].model << '\t'
                 << inventory[i].year << '\t'
                 << inventory[i].price << '\n';
            found = true;
        }
    }
    if (!found) {
        cout << "No cars found in the given price range.\n";
    }
}


void displayAllCars() {
    if (car_count == 0) {
        cout << "No cars in inventory.\n";
        return;
    }

    cout << "All cars in inventory:\n";
    cout << "Make\tModel\tYear\tPrice\n";
    cout << "----\t-----\t----\t-----\n";
    
    for (int i = 0; i < car_count; ++i) {
        cout << inventory[i].make << '\t'
             << inventory[i].model << '\t'
             << inventory[i].year << '\t'
             << inventory[i].price << '\n';
    }
}
int main() {
   
    addCar("Toyota", "Camry", 2022, 24999.99);
    addCar("Honda", "Civic", 2021, 21999.99);
    addCar("Ford", "Mustang", 2023, 35999.99);

    displayAllCars();

   
    searchByPriceRange(20000, 30000);

    removeCar("Ford", "Mustang", 2023);

   
    displayAllCars();

    return 0;
}

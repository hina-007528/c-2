
#include <iostream>
#include <string>
   using namespace std;
const int MAX_PRODUCTS = 100; 


struct Product {
  string productName;
   string category;
    double price;
    int stockQuantity;
};

Product inventory[MAX_PRODUCTS];
int numProducts = 0;  


void addProduct(const string& productName, const string& category, double price, int stockQuantity) {
    if (numProducts >= MAX_PRODUCTS) {
        cout << "Error: Cannot add new product. Inventory is full." << endl;
        return;
    }

    
    inventory[numProducts] = {productName, category, price, stockQuantity};
    ++numProducts;
    cout << "Product added successfully." <<endl;
}


void updateStockQuantity(const string& productName, int newStockQuantity) {
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].productName == productName) {
            inventory[i].stockQuantity = newStockQuantity;
           cout << "Stock quantity updated for " << productName << ". New quantity: " << newStockQuantity <<endl;
            return;
        }
    }
    cout << "Error: Product not found." <<endl;
}


void displayProductsByCategory(const string& category) {
    bool found = false;
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].category == category) {
            cout << "Product Name: " << inventory[i].productName <<endl;
            cout << "Category: " << inventory[i].category << endl;
          cout << "Price: $" << inventory[i].price << endl;
           cout << "Stock Quantity: " << inventory[i].stockQuantity << endl;
           cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
       cout << "No products found in category: " << category <<endl;
    }
}

void searchProductsByPriceRange(double minPrice, double maxPrice) {
    bool found = false;
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].price >= minPrice && inventory[i].price <= maxPrice) {
           cout << "Product Name: " << inventory[i].productName << endl;
            cout << "Category: " << inventory[i].category <<endl;
           cout << "Price: $" << inventory[i].price << endl;
            cout << "Stock Quantity: " << inventory[i].stockQuantity <<endl;
            cout << "--------------------------" <<endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No products found in the price range $" << minPrice << " to $" << maxPrice <<endl;
    }
}

int main() {
    
    addProduct("Laptop", "Electronics", 999.99, 10);
    addProduct("Smartphone", "Electronics", 499.99, 25);
    addProduct("Desk Chair", "Furniture", 89.99, 15);
    addProduct("Notebook", "Stationery", 2.99, 100);

    updateStockQuantity("Laptop", 8);

  
   cout << "Electronics:" <<endl;
    displayProductsByCategory("Electronics");

   
    cout << "Products in price range $0 to $500:" <<endl;
    searchProductsByPriceRange(0, 500);

    return 0;
}

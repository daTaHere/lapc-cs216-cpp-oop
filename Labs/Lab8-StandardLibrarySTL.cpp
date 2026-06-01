#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

//====================================================
// GLOBAL DATA STRUCTURES
//====================================================

// ===== STUDENT TASK =====
// Declare inventory using map<string, double>
map<string, double> inventory;

// ===== STUDENT TASK =====
// Declare cart using unordered_map<string, int>
unordered_map<string, int> cart;

// ===== STUDENT TASK =====
// Declare transaction history using vector<string>
vector<string> transactions;

// ===== STUDENT TASK =====
// Declare customer queue using queue<string>
queue<string> customers;

//====================================================
// FUNCTION DECLARATIONS
//====================================================
void addProduct();
void showInventory();
void addToCart();
void removeFromCart();
void viewCart();
void checkout();
void showTopExpensive();
void addCustomer();
void serveCustomer();

//====================================================
// ADD PRODUCT
//====================================================
void addProduct() {
    string name;
    double price;

    cout << "Enter product name: ";
    cin >> name;

    cout << "Enter price: ";
    cin >> price;

    // ===== STUDENT TASK =====
    // Add product to inventory
    // Hint: inventory[name] = price;

    inventory.emplace(name, price);

}

//====================================================
// SHOW INVENTORY
//====================================================
void showInventory() {
    cout << "\nInventory:\n";

    // ===== STUDENT TASK =====
    // Loop through map and print:
    // product_name : price
    for (auto x : inventory) cout << x.first << ": " << "$" << x.second << endl;

}

//====================================================
// ADD TO CART
//====================================================
void addToCart() {
    string name;
    int qty;

    cout << "Enter product: ";
    cin >> name;

    // ===== STUDENT TASK =====
    // Check if product exists in inventory
    // Hint: use inventory.count(name)

    cout << "Enter quantity: ";
    cin >> qty;


    if (!inventory.count(name)) {
        cout << "\n==================\n";
        cout << "This product is not in stock" << endl;
        return;
    }

    // ===== STUDENT TASK =====
    // Add item to cart or update quantity
    cart[name] = (cart.count(name) == 0) ? qty : cart.at(name) + qty;

    cout << "\n==================\n";
    //cout << "Cart updated!\n" << name << endl << "Qty: " << cart.count(name) << endl;
    cout << "Cart updated!\n" << endl;
    viewCart();

}

//====================================================
// REMOVE FROM CART
//====================================================
void removeFromCart() {
    string name;

    cout << "Enter product to remove: ";
    cin >> name;

    // ===== STUDENT TASK =====
    // Remove product from cart
    if (cart.at(name) > 0) {
        cart.at(name)--;
    }

    if (cart.at(name) == 0) {
        cart.erase(name);
    }
    cout << "\n==================\n";
    cout << "Item removed!\n";
    viewCart();

}

//====================================================
// VIEW CART
//====================================================
void viewCart() {
    cout << "\nCart:\n";

    // ===== STUDENT TASK =====
    // Loop and print:
    // product_name x quantity

    if (cart.size() > 0) {  // <--- validate for non empty cart
        cout << "==================\n";
        for (auto item : cart) {
            cout << item.first << " : " << item.second << " quantity." << endl;
        }
        return;
    }

    cout << "==================\n";
    cout << "Your Cart is Empty!!\n";
}

//====================================================
// CHECKOUT
//====================================================
void checkout() {
    double total = 0;

    // ===== STUDENT TASK =====
    // Calculate total using:
    // total += price * quantity
    for (auto item : cart) {
        total += inventory.at(item.first) * item.second;
    }

    cout << "\n==================\n";
    cout << "Total bill: $" << total << endl;

    // ===== STUDENT TASK =====
    // Save transaction to vector

    string transaction = "Items: ";
    for (auto item : cart) {
        transaction += item.first + " " + to_string(item.second) + " $" + to_string(inventory.at(item.first)) + ".00, ";
    }
    transaction += "Total: " + to_string(total) + ".00.";
    transactions.push_back(transaction);

    // ===== STUDENT TASK =====
    // Clear cart after checkout
    cart.clear();
    "Checkout completed\n";
    viewCart();

}

//====================================================
// SHOW TOP EXPENSIVE PRODUCTS
//====================================================
void showTopExpensive() {

    // ===== STUDENT TASK =====
    // Use priority_queue OR sorting
    // Show top 3 most expensive products
    if (inventory.size() >= 3) {
        priority_queue<pair<double, string>> top3; // Order by greats price
        for (auto x : inventory) {
            top3.push({ x.second,x.first });
        }

        for (int i = 0; i < 3; i++) { // output top and then pop off list
            cout << top3.top().second << endl;
            top3.pop();
        }
    }

}

//====================================================
// ADD CUSTOMER
//====================================================
void addCustomer() {
    string name;

    cout << "Enter customer name: ";
    cin >> name;

    // ===== STUDENT TASK =====
    // Add customer to queue
    customers.push(name);
}

//====================================================
// SERVE CUSTOMER
//====================================================
void serveCustomer() {

    // ===== STUDENT TASK =====
    // If queue is empty ? print message
    // Otherwise:
    // 1. Show front customer
    // 2. Remove them from queue

    if (!customers.empty()) {
        cout << "Serving customer: " << customers.front() << endl;
        customers.pop();
        return;
    }

    cout << "No customers waiting" << endl;
}

//====================================================
// MAIN MENU
//====================================================
int main() {

    int choice;

    do {
        cout << "\n===== Grocery Store Menu =====\n";
        cout << "1. Add Product\n";
        cout << "2. Show Inventory\n";
        cout << "3. Add to Cart\n";
        cout << "4. Remove from Cart\n";
        cout << "5. View Cart\n";
        cout << "6. Checkout\n";
        cout << "7. Top Expensive Products\n";
        cout << "8. Add Customer\n";
        cout << "9. Serve Customer\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addProduct(); break;
        case 2: showInventory(); break;
        case 3: addToCart(); break;
        case 4: removeFromCart(); break;
        case 5: viewCart(); break;
        case 6: checkout(); break;
        case 7: showTopExpensive(); break;
        case 8: addCustomer(); break;
        case 9: serveCustomer(); break;
        }

    } while (choice != 0);

    return 0;
}
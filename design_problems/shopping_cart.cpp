#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Item class
class Item {
public:
    string name;
    double price;
    int quantity;

    Item(const string& name, double price, int quantity = 1) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

// ShoppingCart class
class ShoppingCart {
private:
    vector<Item> items;  // store items in the cart

public:
    ShoppingCart() {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void removeItem(const string& itemName) {
        for(int i = 0; i < items.size(); i++) {
			if(items[i].name == itemName) {
				items.erase(items.begin() + i);
			}
		}
    }

    double getTotal() const {
        float total = 0;
		for(const Item& item: items) {
			total += item.price;
		}
        return total;
    }

    void printCart() const {
        cout << "Cart contents:" << endl;
        for (const auto& item : items) {
            cout << item.name << " x" << item.quantity << " @ $" << item.price << endl;
        }
    }
};

int main() {
    ShoppingCart cart;

    // Example usage
    cart.addItem(Item("Apple", 0.99, 3));
    cart.addItem(Item("Banana", 0.59, 2));
    cart.printCart();

    cout << "Total: $" << cart.getTotal() << endl;

    cart.removeItem("Apple");
    cart.printCart();
    cout << "Total: $" << cart.getTotal() << endl;

    return 0;
}

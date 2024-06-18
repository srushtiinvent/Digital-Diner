#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
protected:
    string itemName;
    double itemPrice;

public:
    MenuItem(const string& name, double price) : itemName(name), itemPrice(price) {}
    virtual void displayItemInfo() {
        cout << "Name: " << itemName << " Price: " << itemPrice << endl;
    }
};

class Appetizer : public MenuItem {
private:
    string ingredients;

public:
    Appetizer(const string& name, double price, const string& ingredients)
        : MenuItem(name, price), ingredients(ingredients) {}
    void displayItemInfo() override {
        MenuItem::displayItemInfo();
        cout << "Ingredients: " << ingredients << endl;
    }
};

class MainCourse : public MenuItem {
private:
    string portionSize;

public:
    MainCourse(const string& name, double price, const string& portionsize)
        : MenuItem(name, price), portionSize(portionsize) {}
    void displayItemInfo() override {
        MenuItem::displayItemInfo();
        cout << "Portion size: " << portionSize << endl;
    }
};

int main() {
    vector<MenuItem*> menu;
    
    string appetizerName, appetizerIngredients;
    double appetizerPrice;

    cout << "Enter Appetizer name: ";
    cin >> appetizerName;
    cout << "Enter Appetizer price: ";
    cin >> appetizerPrice;
    cin.ignore();
    cout << "Enter Appetizer ingredients: ";
    getline(cin, appetizerIngredients);

    Appetizer appetizer(appetizerName, appetizerPrice, appetizerIngredients);
    menu.push_back(&appetizer);

    string mainCourseName, mainCoursePortionSize;
    double mainCoursePrice;

    cout << "Enter Main Course Name: ";
    cin >> mainCourseName;
    cout << "Enter Main Course Price: ";
    cin >> mainCoursePrice;
    cin.ignore();
    cout << "Enter Main Course Portion Size: ";
    getline(cin, mainCoursePortionSize);

    MainCourse mainCourse(mainCourseName, mainCoursePrice, mainCoursePortionSize);
    menu.push_back(&mainCourse);

    cout << "Menu Items:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << "Item " << i + 1 << ":\n";
        menu[i]->displayItemInfo();
        cout << "\n";
    }

    int choice;
    cout << "Enter the item number you want to order (1 or 2): ";
    cin >> choice;

    if (choice >= 1 && choice <= menu.size()) {
        cout << "You ordered:\n";
        menu[choice - 1]->displayItemInfo();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}



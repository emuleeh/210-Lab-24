//COMSC 210 | Lab 24 | Emily

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <string>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    
    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    
    //create set of goats
    set<Goat> trip;
    
    //Select menu options
    main_menu();
    
    
    
    return 0;
}

//Main menu function with options
int main_menu() {
    cout << "GOAT MANAGER 3001" << endl;
    int choice = 0;
    while (choice != 4) {
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice -->";
        cin >> choice;
        //input validation
        while (choice < 1 || choice > 4) {
            cout << "\tInvalid input. Please enter a value between 1 and 4." << endl;
            cout << "\tChoice --> ";
        }
    }
    if (choice == 1) {
        add_goat(trip, names, colors);
    }
    else if (choice == 2) {
        delete_goat(trip);
    }
    else if (choice == 3) {
        display_trip(trip);
    }
    else if (choice == 4) {
        cout << " " << endl;
    }
    
}

//select goat to delete
int select_goat(set<Goat> trip) {
    int choose;
    cout << "Select which goat to delete: ";
    //submenu with choices
    display_trip(trip);
    cin >> choose;
    //input validation
    while (choose < 1 || choose > trip.size()) {
        cout << "\tInvalid input. Please enter a value between 1 and " << trip.size() << "." << endl;
        cout << "Select which goat to delete: ";
        cin >> choose;
    }
    return choose;
}


//delete goat
void delete_goat(set<Goat> &trip) {
    int choose = select_goat(trip);
    auto it = trip.begin();
    advance(it, choose - 1);
    trip.erase(it);
}

//add goat
void add_goat(set<Goat> &trip, string names[], string colors[]) {
    string name, color;
    int age;
    cout << "Adding Goat: " << endl;
    //randomly select a name and color from arrays
    srand(time(0));
    name = names[rand() % SZ_NAMES];
    color = colors[rand() % SZ_COLORS];
    
    //randomly select age between 0 and MAX_AGE
    age = rand() % (MAX_AGE + 1);
    
    //new Goat object to add to list
    Goat new_goat(name, age, color);
    trip.insert(new_goat);
}

//display goats
void display_trip(set<Goat> trip) {
    int i = 1;
    for (auto it = trip.begin(); it != trip.end(); it++, i++) {
        cout << "[" << i << "] ";
        cout << *it << " " << endl;
    }
}




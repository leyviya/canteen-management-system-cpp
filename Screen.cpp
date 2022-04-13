//
// Created by Ayşıl Simge Karacan and Leyla Abdullayeva on 2020-05-08.
//

#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include "Canteen.hpp"
#include "Screen.hpp"

using namespace std;

void Screen::clearScreen() {
    //CLEAR THE TERMINAL
    #if _WIN32 || _WIN64 //windows
        system("cls");
    #else //unix based systems
        system("clear");
    #endif
}


void Screen::mainPage() {
    
    Canteen i;
    cout << "--------------------------------------------------------------------------------" << endl;
    std::cout << "\t\t\tCANTEEN MANAGEMENT SYSTEM" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\tOPTIONS\n" << endl;
    cout << "\t\t[1] ADD AN ITEM" << endl;
    cout << "\t\t[2] LIST ALL ITEMS" << endl;
    cout << "\t\t[3] EDIT AN ITEM" << endl;
    cout << "\t\t[4] DELETE AN ITEM" << endl;
    cout << "\t\t[5] EXIT" << endl;
    cout << "\n\tENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            showInv();
            break;
        case 3:
            editItemScreen();
            break;
        case 4:
            deleteItemScreen();
            break;
        case 5:
            exit(0);
            break;

        default:
            cout << "Try Again, Please Give A Correct Number" << endl;
            sleep(1);
            clearScreen();
            mainPage();
            break;
    }
    
}

void Screen::addItem() {
    
    cout << "Enter Item's Name: ";
    cin >> v_name;
    cout << "Enter Item's Price: ";
    cin >> v_price;

    Canteen i;
    i.setItem(v_name, v_price);
    proceedOrStop();

}

//List all items
void Screen::showInv() {
    
    Canteen i;
    i.getAllInfo();
    proceedOrStop();
}

//Edit Item
void Screen::editItemScreen() {
    Canteen i;
    i.getAllInfo();
    string n_name, n_price;
    cout << "Which item you want to change? Type it's item number:";
    cin >> choice;
    
    cout << "New name: ";
    cin >> n_name;
    cout << "New Price: ";
    cin >> n_price;
    
    i.editItem(choice, n_name, n_price);
    proceedOrStop();
    
}

//Delete Item
void Screen::deleteItemScreen() {
    Canteen i;
    i.getAllInfo();
    
    cout <<  "Type Item's number you want to delete: ";
    cin >> choice;
    
    i.deleteItem(choice);
    proceedOrStop();
    
}

void Screen::proceedOrStop() {
    char ch;
    cout << "Go to Main Menu [y][n:Exit]: ";
    cin >> ch;
    
    ch = tolower(ch);
    
    switch (ch) {
        case 'y':
            clearScreen();
            mainPage();
            
            break;
        case 'n':
            exit(0);
            
        default:
            cout << "Wrong Input, Try Again" << endl;
            proceedOrStop();
            break;
    }
    
}

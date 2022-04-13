//
// Created by Aysil Simge Karacan and Leyla Abdullayeva on 2020-05-08.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "Canteen.hpp"
#include <fstream>
using namespace std;


class Screen {
public:
    void mainPage();
    void addItem();
    void clearScreen();
    void showInv();
    void editItemScreen();
    void deleteItemScreen();
    void proceedOrStop();


private:
    int choice;
    string v_name;
    double v_price;
    int count;


};



#endif //OOP_PROJECT_SCREEN_H


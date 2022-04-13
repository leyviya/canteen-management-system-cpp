//
// Created by Aysil Simge Karacan and Leyla Abdullayeva on 2020-04-23.
//

#ifndef CANTEEN_HPP
#define CANTEEN_HPP

#include <string>
#include <vector>
using namespace std;

class Canteen {

public:
    Canteen();
    void setItem(string i_name, double i_price);
    void setItemInfo();
    void getAllInfo();
    void editItem(int id, string name, string price);
    void deleteItem(int id);

private:

    string itemName;
    double itemPrice;

    vector<string> a_Item;
};



#endif //OOP_PROJECT_CANTEEN_HPP


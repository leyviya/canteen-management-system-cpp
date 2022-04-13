//
// Created by Aysil Simge Karacan and Leyla Abdullayeva on 2020-04-23.
//

#include "Canteen.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include<iterator>


ofstream List;

Canteen::Canteen() {
//SET ITEM'S PRICE AND NAME TO VECTORS FROM THE FILE
string name;

    ifstream List("list.txt");
    while (getline (List, name)) {
        a_Item.push_back(name);
    }
    
}

//WRITE ITEM ON A FILE

void Canteen::setItem(string i_name, double i_price) {
    
    //Capitalize the First letter, Lower case the rest [closed]

    if( !i_name.empty() )
    {
        i_name[0] = std::toupper( i_name[0] );

        for( std::size_t i = 1 ; i < i_name.length() ; ++i )
            i_name[i] = std::tolower( i_name[i] );
    }
    
    //IF THE GIVEN ITEM IS  ALREADY IN THE LIST
    bool check = 1;
    string line;
    ifstream ItemList;
    ItemList.open ("list.txt");
    
        if(ItemList.is_open())
        {
            while(!ItemList.eof())
            {
                getline(ItemList,line);
                if ((line.find(i_name, 0)) != string::npos)
                {
                 cout << "found '" << i_name << endl;
                    check = 0;
                    break;
                }
            }
            ItemList.close();
        }
    
    if (check == 1) {
        ofstream List("list.txt", std::ios_base::app);

        List << i_name << " " << i_price << endl;

        List.close();

        Canteen();
    } else {
        cout << "You cannot use the same item name" << endl;
        sleep(1);
    }

}

//PRINT ALL INFO

void Canteen::getAllInfo() {
    int count = 1;
    
    ifstream il("list.txt");
    
    do {
        string line;
        
        if (getline(il, line))
            cout << count << "\t" << line << "TL" << endl;
        count++;
        
    } while (il);
    cout << '\n';
    
}

void Canteen::editItem(int id, string name, string price) { //EDIT AN ITEM
    
    //CHECK IF THE ID IS CORRECT
    
    if ((id > a_Item.size()) || id < 1) {
        cout << "Invalid ID" << endl;
        sleep(1);
    } else {
        
        //Inputs ID, New Name, New Price
        
        List.open("list.txt",ios::out|ios::binary);
        
        //Create temp file
        
        ofstream listTemp("list_temp.txt");
        
        //Delete the items info in the index of ID
        
        a_Item.erase( a_Item.begin() + id - 1 );

        //Change the Item with new name and price in the same ID
        
        a_Item.insert(a_Item.begin() + id - 1, name + " " + price);
        
        //Copy vector items to the temp files
        
        ostream_iterator<std::string> output_iterator1(listTemp, "\n");
        std::copy(a_Item.begin(), a_Item.end(), output_iterator1);
        
        //close and delete old file and rename the temp files
        
        List.close();
        listTemp.close();
        
        remove("list.txt");
        
        rename("list_temp.txt", "list.txt");
    }
}


void Canteen::deleteItem(int id) { //DELETE AN ITEM
    
        //CHECK IF THE ID IS CORRECT
    
    if ((id > a_Item.size()) || id < 1) {
        cout << "Invalid ID" << endl;
        sleep(1);
    } else {
        
        //Inputs ID, New Name, New Price
        
        List.open("list.txt",ios::out|ios::binary);
        
        //Create temp file
        
        ofstream listTemp("list_temp.txt");
        
        //Delete the items info in the index of ID
        
        a_Item.erase( a_Item.begin() + id - 1 );
                
        //Copy vector items to the temp files
        
        ostream_iterator<std::string> output_iterator1(listTemp, "\n");
        std::copy(a_Item.begin(), a_Item.end(), output_iterator1);
        
        //close and delete old file and rename the temp files
        
        List.close();
        listTemp.close();
        
        remove("list.txt");
        
        rename("list_temp.txt", "list.txt");
    }

}







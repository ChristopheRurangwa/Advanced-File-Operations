/*
 *
Name: Christohe Rurangwa
Date: 10/27/2020
CIS 1202-501

Program Name:Inventory Files.

Description of what the program does:

The program creates and updates a binary inventory file named inventory.dat.
This file does not exist anywhere, so the program will create it.
*
*/

#include <iostream>



using namespace std;

//prototype function

int showMenu();
void createFile(fstream&);
void displayFile(fstream&);
void displayRecord(fstream&, int);
void modifyRecord(fstream&);

const int NAME_SIZE = 40;
struct Product
{
    long number;
    char name[NAME_SIZE];
    double price;
    int quantity;
};





int main() {
    showMenu();
    return 0;
}
/**
 * Displays the menu, gets a choice from the keyboard,
 * validates it, and returns a valid menu choice.
 */
int showMenu(){
    cout<<"1.\tDisplay the entire inventory"<<endl;
    cout<<"2.\tDisplay a particular product"<<endl;
    cout<<"3.\tModify a product"<<endl;
    cout<<"4.\tExit the program"<<endl;

    return 0;
}
/**
 * Populate the file with sample data.
 */
void createFile(fstream&){


}

/**
 * Clears the eof flag, seeks to the first record, and
 * uses an eof loop to read the file and display Product
 * records and the record number on the screen.
 */
void displayFile(fstream&){

}

/**
 * Clears the eof flag, then seeks to the record indicated by
 * the in parameter, and displays the Product record.
 */
void displayRecord(fstream&, int){

}

/**
 *Gets input for the record number and new Product values,
 * seeks to that record number, and writes
 * the new values to replace the existing data.
 */
void modifyRecord(fstream&){


}
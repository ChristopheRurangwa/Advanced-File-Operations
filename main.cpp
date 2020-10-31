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
 *
*/

#include <iostream>
#include <fstream>


using namespace std;

const int NAME_SIZE = 40;
struct Product
{
    long number;
    char name[NAME_SIZE];
    double price;
    int quantity;
};



//prototype function

int showMenu();
void createFile(fstream &file);
void displayFile(fstream&);
void displayRecord(fstream&, int);
void modifyRecord(fstream&);


int main() {

    showMenu();
    return 0;
}
/**
 * Displays the menu, gets a choice from the keyboard,
 * validates it, and returns a valid menu choice.
 */
int showMenu(){
    fstream file;


    int choice;
    cout<< "Product Inventory\n";
    cout<<"1.\tDisplay the entire inventory"<<endl;
    cout<<"2.\tDisplay a particular product"<<endl;
    cout<<"3.\tModify a product"<<endl;
    cout<<"4.\tExit the program"<<endl;

    do{
        cin>>choice;
        createFile(file);
        switch (choice) {

            case 1:displayFile(file);
                break;
            case 2: if(true){

                    int record;
                    cout<<"Enter record number to be displayed: ";
                    cin>>record;
                    createFile(file);
                displayRecord(file, record );}
                break;
            case 3:{createFile(file);
                modifyRecord(file);}
                break;
            case 4:exit(0);
            default:{
                cout<<"You have entered an invalid choice, please try again.\n";
                    cin>>choice;
            }


        }


    }while(choice<4);

    return choice;
}
/**
 * Populate the file with sample data.
 */
void createFile(fstream &file){

Product pro,pro1,pro2,pro3,pro4;

pro.number=51992;
strcpy(pro.name,"IPHONE 20 MAX PRO");
pro.price=1999;
pro.quantity=59;
/*product1*/
    pro1.number=9009;
    strcpy(pro1.name,"Motorola LTS20");
    pro1.price=990;
    pro1.quantity=12;
    /*product2*/
    pro2.number=7900;
    strcpy(pro2.name,"Nokia M2500");
    pro2.price=500;
    pro2.quantity=9;
    /*product3*/
    pro3.number=1009;
    strcpy(pro3.name,"BlackBerry L20");
    pro3.price=140;
    pro3.quantity=1;
    /*product4*/
    pro4.number=7801;
    strcpy(pro4.name,"Sony S720");
    pro4.price=143;
    pro4.quantity=51;

file.open("inventory.dat",ios::in);
if(file.fail()){

    file.open("inventory.dat",ios::out|ios::binary);//<-open the file
    file.write(reinterpret_cast<char *>(&pro), sizeof(pro));
    file.write(reinterpret_cast<char *>(&pro1), sizeof(pro1));
    file.write(reinterpret_cast<char *>(&pro2), sizeof(pro2));
    file.write(reinterpret_cast<char *>(&pro3), sizeof(pro3));
    file.write(reinterpret_cast<char *>(&pro4), sizeof(pro4));

}
else {//<-if file already exists.
    file.close();

}


}

/**
 * Clears the eof flag, seeks to the first record, and
 * uses an eof loop to read the file and display Product
 * records and the record number on the screen.
 */
void displayFile(fstream &file) {
    //string str;

    Product pro,pro1,pro2,pro3,pro4;


    while(!file.eof()){


        cout<<"Record #"<<0<<endl;
        cout<<"Product number: "<<pro.number<<endl;
        cout<<"Product name: "<<pro.name<<endl;
        cout<<"Product price: $"<<pro.price<<endl;
        cout<<"Product quantity: "<<pro.quantity<<endl;

        file.read(reinterpret_cast<char *>(&pro), sizeof(pro));
        cout<<"Record #"<<1<<endl;
        cout<<"Product number: "<<pro1.number<<endl;
        cout<<"Product name: "<<pro1.name<<endl;
        cout<<"Product price: $"<<pro1.price<<endl;
        cout<<"Product quantity: "<<pro1.quantity<<endl;
        file.read(reinterpret_cast<char *>(&pro1), sizeof(pro1));
        cout<<"Record #"<<2<<endl;
        cout<<"Product number: "<<pro2.number<<endl;
        cout<<"Product name: "<<pro2.name<<endl;
        cout<<"Product price: $"<<pro2.price<<endl;
        cout<<"Product quantity: "<<pro2.quantity<<endl;
        file.read(reinterpret_cast<char *>(&pro2), sizeof(pro2));
        cout<<"Record #"<<3<<endl;
        cout<<"Product number: "<<pro3.number<<endl;
        cout<<"Product name: "<<pro3.name<<endl;
        cout<<"Product price: $"<<pro3.price<<endl;
        cout<<"Product quantity: "<<pro3.quantity<<endl;
        file.read(reinterpret_cast<char *>(&pro3), sizeof(pro3));
        cout<<"Record #"<<4<<endl;
        cout<<"Product number: "<<pro4.number<<endl;
        cout<<"Product name: "<<pro4.name<<endl;
        cout<<"Product price: $"<<pro4.price<<endl;
        cout<<"Product quantity: "<<pro4.quantity<<endl;
        file.read(reinterpret_cast<char *>(&pro4), sizeof(pro4));

    }
    file.close();

}

/**
 * Clears the eof flag, then seeks to the record indicated by
 * the in parameter, and displays the Product record.
 */
void displayRecord(fstream &file, int record ){

    Product product;

        file.clear();

 file.seekg(record*sizeof(product), ios::end);

file.read(reinterpret_cast<char *>(&product), sizeof(product));

    cout<<"Product number: "<<product.number<<endl;
    cout<<"Product name: "<<product.name<<endl;
    cout<<"Product price: $"<<product.price<<endl;
    cout<<"Product quantity: "<<product.quantity<<endl;


    file.close();


}

/**
 *Gets input for the record number and new Product values,
 * seeks to that record number, and writes
 * the new values to replace the existing data.
 */
void modifyRecord(fstream&file){
    Product product;
    int record;
cout<<"Enter the record number to be modified: ";
cin>>record;cout<<endl;
file.seekg(record*sizeof(product),ios::beg);
file.read(reinterpret_cast<char *>(&product),sizeof(product));


cin.getline(product.name,49);
cout<<"Enter new data.\n";
cout<<"Product number: #";cin>>product.number;
cout<<"Product name: ";cin>>product.name;
cout<<"Price: $";cin>>product.price;
cout<<"Quantity: ";cin>>product.quantity;
cout<<"All data for one product entered.\n";
// move back to start
    file.seekg(record*sizeof(product),ios::beg);
    // write the data collected to file
    file.write(reinterpret_cast<char *>(&product),sizeof(product));
    file.close();






}
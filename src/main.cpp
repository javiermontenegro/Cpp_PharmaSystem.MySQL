#include <iostream>
#include <sstream>
#include <iomanip>
 
#include <string>
#include <termios.h>
#include <unistd.h>

#include <cstdlib>
#include <mysql/mysql.h>
 
#include "PharmaProduct.h"
#include "PharmaTransaction.h"
 
using namespace std;
 
enum Options { PRINT = 1, ADD, UPDATE, REMOVE, FIND, EXIT };
 
void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}//End clear

int mainMenu()
{
   cout << "System options \n"
        << "[1] Print All Products \n" 
        << "[2] Add New \n" 
        << "[3] Update \n" 
        << "[4] Remove \n"  
        << "[5] Find \n" 
        << "[6] Exit \n" << endl;
   int ch;
   cin >> ch;
   return ch;
}//End mainMenu
 
int main(int argc, char** argv)
{
   PharmaTransaction* bt =
      new PharmaTransaction("localhost", "root",
                          "mysql", "pharma");
 
   int choice, option;
   int id;
   string product, presentation, drug, lab;
   double price;
   string username, password;
 
   clear();

   cout << "\nEnter your username: " << endl;
   cin >> username;

   termios oldt;
   tcgetattr(STDIN_FILENO, &oldt);
   termios newt = oldt;
   newt.c_lflag &= ~ECHO;
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);

   cout << "\nEnter password: " << endl;
   cin >> password; 

   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    if( bt->login(username, password) == 0 ) {
       cout << "Fail to login." << endl;
       return 0;
    }//End if  

   clear(); 
   while(1) {
      choice = mainMenu();
      if(choice == EXIT)
         break;
      switch(choice) {
      case PRINT:
         bt->print();
         break;
      case ADD:
         cout << "\nEnter product name: " << endl;
         cin >> product;
         cout << "\nEnter presentation: " << endl;
         cin >> presentation;
         cout << "\nEnter price: " << endl;         
         cin >> price;
         cout << "\nEnter drug: " << endl;         
         cin >> drug;
         cout << "\nEnter lab: " << endl;         
         cin >> lab;

         if(price < 1) {
            cout << "Invalid price." << endl;
            break;
         }//End if
         bt->add(new PharmaProduct(0, product, presentation, price,
                                           drug, lab));
         break;

     case UPDATE:
         clear(); 
         do {
           cout << "Update options \n";
           cout << "[1] Product Name \n";
           cout << "[2] presentation \n";
           cout << "[3] Price \n";
           cout << "[4] Drug \n";
           cout << "[5] Lab \n";
           cout << "[6] Back to main \n";
           cin >> option;

           switch(option){
               case 1:
                   cout << "\nEnter product id: " << endl;
                   cin >> id; 
                   cout << "\nEnter Product Name: " << endl;         
                   cin >> product;
                   bt->update(1, new PharmaProduct(id, product, "", 0, "", ""));
               break;
               case 2:
                   cout << "\nEnter product id: " << endl;
                   cin >> id; 
                   cout << "\nEnter Presentation: " << endl;         
                   cin >> presentation;
                   bt->update(2, new PharmaProduct(id, "", presentation, 0, "", ""));
               break;   
               case 3:
                   cout << "\nEnter product id: " << endl;
                   cin >> id;
                   cout << "\nEnter Price: " << endl;

                   if(price < 1) {
                       cout << "Invalid price." << endl;
                       break;
                   }       
                   cin >> price;
                   bt->update(3, new PharmaProduct(id, "", "", price, "", ""));
               break;           
               case 4:
                   cout << "\nEnter product id: " << endl;
                   cin >> id; 
                   cout << "\nEnter Drug: " << endl;         
                   cin >> drug;
                   bt->update(4, new PharmaProduct(id, "", "", 0, drug, ""));
               break;                                 
               case 5:
                   cout << "\nEnter product id: " << endl;
                   cin >> id; 
                   cout << "\nEnter Lab: " << endl;         
                   cin >> lab;
                   bt->update(5, new PharmaProduct(id, "", "", 0, "", lab));
               break; 
               default: 
                break;
           }//End switch
         }while(option != 6);
         break;  

     case REMOVE:
         cout << "\nEnter product id to remove: " << endl;
         cin >> id;

         bt->remove(id);
         break;
      case FIND:
         cout << "\nEnter product id: " << endl;
         cin >> id;

         if(id < 0) {
            cout << "Invalid product id." << endl;
            break;
         }
         bt->find(id);
         break;         
      default:
         cerr << "Invalid choice!" << endl;
         break;
      }//End switch
   }//End while
   return 0;
}//End main
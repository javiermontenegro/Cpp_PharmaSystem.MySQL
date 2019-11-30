#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <mysql/mysql.h>

#include "PharmaTransaction.h"
#include "PharmaProduct.h"
 
PharmaTransaction::PharmaTransaction(const string HOST,
   const string USER, const string PASSWORD,
   const string DATABASE)
{
   db_conn = mysql_init(NULL);
   if(!db_conn)
      message("MySQL initialization failed! ");
   db_conn = mysql_real_connect(db_conn, HOST.c_str(),
      USER.c_str(), PASSWORD.c_str(), DATABASE.c_str(), 0,
         NULL, 0);
   if(!db_conn)
      message("Connection Error! ");
}//End PharmaTransaction
 
PharmaTransaction::~PharmaTransaction()
{
   mysql_close(db_conn);
}//End ~PharmaTransaction
 
PharmaProduct* PharmaTransaction::get(int id)
{
   PharmaProduct* b = NULL;
   MYSQL_RES* rset;
   MYSQL_ROW row;
   stringstream sql;
   sql << "SELECT * FROM pharma_store WHERE id=" << id;
 
   if(!mysql_query(db_conn, sql.str().c_str())) {
      b = new PharmaProduct();
      rset = mysql_use_result(db_conn);
      row = mysql_fetch_row(rset);
      b->setId(atoi(row[0]));
      b->setProduct(row[1]);
      b->setPresentation(row[2]);
      b->setPrice(atof(row[3]));
      b->setDrug(row[4]);
      b->setLab(row[5]);      
   }//End if
   mysql_free_result(rset);
   return b;
}//End get
  
void PharmaTransaction::add(PharmaProduct* ba)
{
   stringstream ss;   
   ss << "INSERT INTO pharma_store(product, presentation, price, drug, lab) values ('" << ba->getProduct() << "', '" << ba->getPresentation() + "', " << ba->getPrice() << ", '" << ba->getDrug() << "', '" << ba->getLab() << "')";
       
   if(mysql_query(db_conn, ss.str().c_str()))
      message("Failed to create product! ");
   else
      message("Product creation successful.");
}//End add

void PharmaTransaction::update(int option, PharmaProduct* ba)
{
   stringstream ss;
   switch(option){
       case 1:
         ss << "UPDATE pharma_store SET product='" << ba->getProduct() << "' WHERE id=" << ba->getId();
       break;

       case 2:
         ss << "UPDATE pharma_store SET presentation='" << ba->getPresentation() << "' WHERE id=" << ba->getId();
       break;

       case 3:
         ss << "UPDATE pharma_store SET price=" << ba->getPrice() << " WHERE id=" << ba->getId();
       break;

       case 4:
         ss << "UPDATE pharma_store SET drug='" << ba->getDrug() << "' WHERE id=" << ba->getId();
       break;

       case 5:
         ss << "UPDATE pharma_store SET lab='" << ba->getLab() << "' WHERE id=" << ba->getId();
       break;                            
   }//End switch
   
   if(mysql_query(db_conn, ss.str().c_str()))
      message("Failed to create product! ");
   else
      message("Product creation successful.");
}//End update

void PharmaTransaction::remove(int id)
{
   stringstream ss;
   ss << "DELETE FROM pharma_store WHERE id=" << id;
   if(mysql_query(db_conn, ss.str().c_str()))
      message("Failed to remove product! ");
   else
      message("Product removed successful.");
}//End remove
  
void PharmaTransaction::message(string msg)
{
   cout << msg << endl;
}//End message

void PharmaTransaction::print()
{
   MYSQL_RES* rset;
   MYSQL_ROW rows;
   string sql = "SELECT * FROM pharma_store";
   if(mysql_query(db_conn, sql.c_str())) {
      message("Error printing all products! ");
      return;
   }//End if
 
   rset = mysql_use_result(db_conn); 
   
   cout << left << setw(5) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(6) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << '+' << '+' << endl;
   
   cout << setfill(' ') << '|' << left << setw(4) << "id" 
        << setfill(' ') << '|' << setw(20) << "Product Name" 
        << setfill(' ') << '|' << setw(20) << "Presentation" 
        << setfill(' ') << '|' << setw(5) << "Price" 
        << setfill(' ') << '|' << setw(9) << "Drug"        
        << setfill(' ') << '|' << right << setw(9) << "Lab" 
        << '|' << endl;
   
   cout << left << setw(5) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(6) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << left << '+' << setw(10) << setfill('-')         
        << '+' << '+' << endl;

   if(rset) {
      while((rows = mysql_fetch_row(rset))) {
         cout << setfill(' ') << '|' << left << setw(4) << rows[0] 
              << setfill(' ') << '|' << setw(20) << rows[1] 
              << setfill(' ') << '|' << setw(20) << rows[2]   
              << setfill(' ') << '|' << setw(5) << rows[3] 
              << setfill(' ') << '|' << setw(9) << rows[4] 
              << setfill(' ') << '|' << right << setw(9) << rows[5] 
              << '|' << endl;
      }
      cout << left << setw(5) << setfill('-') 
           << left << '+' << setw(21) << setfill('-') 
           << left << '+' << setw(21) << setfill('-') 
           << left << '+' << setw(6) << setfill('-') 
           << left << '+' << setw(10) << setfill('-') 
           << left << '+' << setw(10) << setfill('-')         
           << '+' << '+' << endl;
   }
   mysql_free_result(rset);
}//End print

void PharmaTransaction::find(int id)
{
   MYSQL_RES* rset;
   MYSQL_ROW rows;
   stringstream ss;
   ss << "SELECT * FROM pharma_store WHERE id=" << id;
   if(mysql_query(db_conn, ss.str().c_str())) {
      message("Error printing account! ");
      return;
   }//End if
 
   rset = mysql_use_result(db_conn);
 
   cout << left << setw(5) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(6) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << '+' << '+' << endl;
   
   cout << setfill(' ') << '|' << left << setw(4) << "id" 
        << setfill(' ') << '|' << setw(20) << "Product Name" 
        << setfill(' ') << '|' << setw(20) << "Presentation" 
        << setfill(' ') << '|' << setw(5) << "Price" 
        << setfill(' ') << '|' << setw(9) << "Drug"        
        << setfill(' ') << '|' << right << setw(9) << "Lab" 
        << '|' << endl;
   
   cout << left << setw(5) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(21) << setfill('-') 
        << left << '+' << setw(6) << setfill('-') 
        << left << '+' << setw(10) << setfill('-') 
        << left << '+' << setw(10) << setfill('-')         
        << '+' << '+' << endl;

   if(rset) {
      while((rows = mysql_fetch_row(rset))) {
         cout << setfill(' ') << '|' << left << setw(4) << rows[0] 
              << setfill(' ') << '|' << setw(20) << rows[1] 
              << setfill(' ') << '|' << setw(20) << rows[2]   
              << setfill(' ') << '|' << setw(5) << rows[3] 
              << setfill(' ') << '|' << setw(9) << rows[4] 
              << setfill(' ') << '|' << right << setw(9) << rows[5] 
              << '|' << endl;         
      }//End while
      cout << left << setw(5) << setfill('-') 
           << left << '+' << setw(21) << setfill('-') 
           << left << '+' << setw(21) << setfill('-') 
           << left << '+' << setw(6) << setfill('-') 
           << left << '+' << setw(10) << setfill('-') 
           << left << '+' << setw(10) << setfill('-')         
           << '+' << '+' << endl;
   }//End if
   mysql_free_result(rset);
}//End find


int PharmaTransaction::login(string username, string password)
{
   PharmaProduct* b = NULL;
   MYSQL_RES* rset;
   MYSQL_ROW row;
   stringstream sql;
   sql << "SELECT COUNT(*) FROM users WHERE username='" << username << "' AND password='" << password << "'";
   
   int rvalue = 0;
   if(!mysql_query(db_conn, sql.str().c_str())) {
      rset = mysql_use_result(db_conn);
      row = mysql_fetch_row(rset);
      
      rvalue = atoi(row[0]);
                
   }//End if
   mysql_free_result(rset);
   return rvalue;
}//End login
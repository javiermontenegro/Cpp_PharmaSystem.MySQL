#ifndef PHARMATRANSACTION_H
#define PHARMATRANSACTION_H
 
/*! \file PharmaTransaction.h
 *  \brief Definitions for pharma transaction manipulation.
 *
 *  The PharmaTransaction class is a implementation of public and private methods.
 */

#include <mysql/mysql.h>
#include <string>
 
class PharmaProduct;
 
using namespace std;

class PharmaTransaction
{
public:
   PharmaTransaction(const string = "localhost",
      const string = "",
   const string = "", const string = "");
   ~PharmaTransaction();
   void add(PharmaProduct*);
   void remove(int);
   void update(int, PharmaProduct*);
   PharmaProduct* get(int);
   void print();
   void find(int);
   int login(string, string);
   void message(string);
 
private:
   MYSQL* db_conn;
}; //End PharmaTransaction
 
#endif   // PHARMATRANSACTION_H
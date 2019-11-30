#ifndef PHARMAPRODUCT_H
#define PHARMAPRODUCT_H

/*! \file PharmaProduct.h
 *  \brief Definitions for pharma product manipulation.
 *
 *  The PharmaProduct class is a implementation of public and private methods.
 */
 
#include <string>
using std::string;
 
class PharmaProduct
{
public:
   static const int MAX_SIZE = 30;
 
   PharmaProduct(int = 0, string = "", string = "",
      double = 0.0, string = "", string = "");
   ~PharmaProduct();
 
   void setId(int);
   void setProduct(string);
   void setPresentation(string);
   void setPrice(double);
   void setDrug(string);
   void setLab(string);
 
   int getId() const;
   string getProduct() const;
   string getPresentation() const;
   double getPrice() const;
   string getDrug() const;
   string getLab() const;
 
private:
   int id;
   char product[MAX_SIZE];
   char presentation[MAX_SIZE];
   double price;
   char drug[MAX_SIZE];
   char lab[MAX_SIZE];
}; //End PharmaProduct
 
#endif   // PHARMAPRODUCT_H
#include "PharmaProduct.h"
 
#include <string>
#include <cstring>
 
using std::string;
 
PharmaProduct::PharmaProduct(int id, string product, string presentation,
   double price, string drug, string lab)
{
   setId(id);
   setProduct(product);
   setPresentation(presentation);
   setPrice(price);
   setDrug(drug);
   setLab(lab);
}//End PharmaProduct
 
void PharmaProduct::setId(int _id)
{
   id = _id;
}//End setId

void PharmaProduct::setProduct(string _product)
{
   const char* d = _product.data();
   int len = _product.size();
   len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
   strncpy(product, d, len);
   product[len] = '\0';
}//End setProduct
 
void PharmaProduct::setPresentation(string _presentation)
{
   const char* d = _presentation.data();
   int len = _presentation.size();
   len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
   strncpy(presentation, d, len);
   presentation[len] = '\0';
}//End setPresentation
 
void PharmaProduct::setPrice(double _price)
{
   price = _price;
}

void PharmaProduct::setDrug(string _drug)
{
   const char* d = _drug.data();
   int len = _drug.size();
   len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
   strncpy(drug, d, len);
   drug[len] = '\0';
}//End setDrug
 
void PharmaProduct::setLab(string _lab)
{
   const char* d = _lab.data();
   int len = _lab.size();
   len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
   strncpy(lab, d, len);
   lab[len] = '\0';
}//End setLab

int PharmaProduct::getId() const
{
   return id;
}//End getId

string PharmaProduct::getProduct() const
{
   return product;
}//End getProduct
 
string PharmaProduct::getPresentation() const
{
   return presentation;
}//End getPresentation
 
double PharmaProduct::getPrice() const
{
   return price;
}//End getPrice
 
string PharmaProduct::getDrug() const
{
   return drug;
}//End getDrug

string PharmaProduct::getLab() const
{
   return lab;
}//End getLab
 
PharmaProduct::~PharmaProduct(){} //End ~PharmaProduct
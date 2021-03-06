#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string.h>
#include <cassert>
using namespace std;
class Product
{
private :
    char* name;
    int quantity;
    double price;
public :
    Product();
    ~Product();
    Product(char*,int,double);
    Product(const Product&);
    double getPrice() const;
    int getQuantity() const;
    const char* getName() const;
    void setName(char*);
    void setQuantity(int);
    void setPrice(double);
    Product& operator= (const Product& other);

};
#endif // PRODUCT_H

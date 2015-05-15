#pragma once
#incude <iostream>
#include <string>

class Sales_data {
public:
    Sales_data();
    ~Sales_data();

    Sales_data& operator=(const Sales_data& other);
    Sales_data& operator+=(const Sales_data& other)
    {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
    }
    
    string isbn() const { return bookNO; }




private:
    string bookNO;
    int units_sold;
    double price;
    double revenue;
};


Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

//IO Operators Must Be Nonmember Functions
ostream& operator<<(ostream& os, const Sales_data &item)
{
    os<<item.isbn() << " " << item.units_sold << " "
	<< item.revenue <<" " << item.avg_price();
    return os;
}

istream& operator>>(istream& is, Sales_data& item)
{
    double price;
    is >> item.bookNO >> item.units_sold >> price;
    if (is) //check that the inputs succeeded
	item.revenue = item.units_sold * price;
    else
	item = Sales_data();
    return is;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() &&
	   lhs.units_sold == rhs.units_sold &&
	   lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

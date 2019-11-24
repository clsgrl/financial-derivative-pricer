// ConsoleApplicationTest1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//needed to be imported otherwise cannot cout a variable of type string
//it is important to check the "const" modifier
//check as well the bitwise operations
#include <iostream>
#include <string>

using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle();
	Rectangle(int, int);
	int area(void) { return (width * height); }
};


class Circle {
	double radius;
public:
	Circle() { radius = 2; }
	Circle(int r) { radius = r; }
	double area() { return radius * radius * 3.14159; }
};

class Product {
private:
	
	string prodName;
	float price;
public:
	

	Product(string _prodName, float _price) : prodName(_prodName), price(_price){}
	float operator+ (const Product&);

	string getProdName() const { return prodName; }
	float getPrice() const { return price; }

	void setProdName(string _name) { prodName = _name; }
	void setPrice(float _price) { price = _price; }
};


Rectangle::Rectangle(){
	width = 3;
	height = 3;
}

Rectangle::Rectangle(int a, int b){
	width = a;
	height = b;
}

float Product::operator+(const Product& prod){
	return this->getPrice() + prod.getPrice();
}

int _tmain3(int argc, _TCHAR* argv[])
{
	Rectangle rect(3, 4);
	Rectangle rectb;
	Rectangle rectc = { 5, 5 };
	Rectangle* rec2 = new Rectangle(2, 3);


	std::cout << "rect area: " << rect.area() << std::endl;
	std::cout << "rectb area: " << rectb.area() << std::endl;

	Circle foo;
	Circle foo2 = 20;
	Circle foo3 = { 30 };

	std::cout << "foo area: " << foo.area() << std::endl;
	std::cout << "foo2 area: " << foo2.area() << std::endl;
	std::cout << "foo3 area: " << foo3.area() << std::endl;

	Product* p1 = new Product("phone", 200.00);
	Product* p2 = new Product("laptop", 1500.00);

	float result = (*p1) + (*p2);
	
	std::cout << "Products " << p1->getProdName() << " and " << p2->getProdName() << " cost: " << result << std::endl;

	return 0;
}


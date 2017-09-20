// XMLPS-REST Restaurant System
//Food.cpp

#include "Restaurant.h"

using namespace std;

void Food::importItem(const Item_Raw &item)
{
	setName(item.name);
	setDescription(item.description);
	setPrice(item.price);
}

void Food::setName(std::string _name)
{
	name = _name;
}

void Food::setDescription(std::string _description)
{
	description = _description;
}

void Food::setPrice(double _price)
{
	price = _price;
}

void Food::setItem(std::string _name, std::string _description, double _price)
{
	setName(_name);
	setDescription(_description);
	setPrice(_price);
}

std::string Food::getName() const
{
	return name;
}

std::string Food::getDescription() const
{
	return description;
}

double Food::getPrice() const
{
	return price;
}
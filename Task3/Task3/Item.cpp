#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, int price)
	: name_(name)
	, price_(price)
{

}

const std::string& Item::GetName() const
{
	return name_;
}

int	Item::GetPrice() const
{
	return price_;
}

void Item::Clear()
{
	name_ = "";
	price_ = 0;
}

void Item::PrintAllItems() const
{
	std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
}

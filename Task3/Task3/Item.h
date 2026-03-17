#pragma once
#include <string>


class Item
{
public:
	Item(const std::string& name = "", int price = 0);
	
	
	const std::string& GetName() const;
	int GetPrice() const;
	void Clear();
	void PrintAllItems() const;
	
private:
	std::string name_;
	int price_;
};


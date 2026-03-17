#include "Inventory.h"
#include "Item.h"
#include <string>

int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>(10);

	itemInventory->AddItem(Item("검", 2000));
	itemInventory->AddItem(Item("방패", 800));
	itemInventory->AddItem(Item("표창", 700));
	itemInventory->AddItem(Item("포션", 300));
	itemInventory->AddItem(Item("귀환서", 100));
	itemInventory->AddItem(Item("강화석", 1500));
	itemInventory->AddItem(Item("반지", 500));
	itemInventory->AddItem(Item("목걸이", 500));
	itemInventory->AddItem(Item("장갑", 1000));
	itemInventory->AddItem(Item("갑옷", 1200));


	int choice = -1;
	int itemCount = 0;	
	std::cout << "[1] 아이템 획득 | [0] 아이템 제거 | [-1] 종료" << std::endl;

	while (true)
	{
		std::cout << "입력하세요." << std::endl;
		std::cin >> choice;

		if (choice == 1)
		{
			// 아이템 순차 생성 (예: 아이템1, 아이템2...)
			itemCount++;
			std::string itemName = "아이템" + std::to_string(itemCount);
			int itemPrice = itemCount * 100;

			itemInventory->AddItem(Item(itemName, itemPrice));
			itemInventory->PrintAllItems();
		}
		else if (choice == 0)
		{
			// 마지막 아이템 제거
			std::cout << "마지막 아이템을 제거합니다." << std::endl;
			itemInventory->RemoveLastItem();
			itemInventory->PrintAllItems();
		}
		else if (choice == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		}
		else
		{
			std::cout << "잘못된 입력입니다. (1, 0, -1 중 입력)" << std::endl;
		}
	}
	//for (int i = 0; i < 11; ++i)
	//{
	//	itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	//}

	itemInventory->PrintAllItems();

	std::cout << "마지막 아이템을 제거합니다." << std::endl;
	itemInventory->RemoveLastItem();
	itemInventory->PrintAllItems();


	delete itemInventory;
	itemInventory = nullptr;

	return 0;
}
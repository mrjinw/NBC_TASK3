#pragma once
#include <vector>
#include <iostream>

template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10) // 동적배열 생성. 저장공간 10개 인벤토리. 생성자 
	{
		capacity_ = (capacity <= 0) ? 1 : capacity; //인벤 저장공간이 0보다 작거나 같으면 1로 설정해라.
		size_ = 0;// 아이템 개수
		pItems_ = new T[capacity_];//템플릿 T의 [capacity_]에 동적할당
	}

	~Inventory() // 동적배열 해제 소멸자 
	{
		if (pItems_ != nullptr)
		{
			delete[] pItems_;
			pItems_ = nullptr;
		}
	}
	//size_++을 활용하여 아아템을 배열에 배치
	// -예외처리 : capacity를 초과한다면?


	void AddItem(const T& item) // 멤버 함수
	{
		if (size_ >= capacity_)
		{
			std::cout << "인벤토리가 꽉 찼습니다." << std::endl;
			return;
		}
		pItems_[size_++] = item; //현재 size_ 위치에 저장 후 size_ 1씩 증가
	}

	void RemoveLastItem()        //size_--을 활용하여 마지막 아이템을 clear
	{
		if (size_ <= 0)
		{
			std::cout << "인벤토리가 비어있습니다." << std::endl;
			return;
		}
		pItems_[size_ - 1].Clear();
		size_--;

	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}


	void PrintAllItems() const		 //size_만큼 for을 돌면서 item의 정보를 출력 
	{
		
		
		std::cout << "\n--- 인벤토리 목록 (용량: " << size_ << "/" << capacity_ << ") ---" << std::endl;
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i].PrintAllItems();
		}

		std::cout << "-------------------------------------------\n" << std::endl;
	}

private: //멤버 변수
	T* pItems_;
	int capacity_;
	int size_;
};


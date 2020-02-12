#include "UnsortedType.h"
using namespace std;

UnsortedType::UnsortedType()
{
	length = 0;
	listData = NULL;
}

bool UnsortedType::IsFull() const
{
	NodeType* location:
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int UnsortedType::GetLength() const
{
	return length;
}

void UnsortedType::MakeEmpty()
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPrt;
	}
	length = 0;
}

void UnsortedType::PutItems(ItemType item)
{
	NodeType* location;
	location = new NodeType;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(info[location]))
		{
		case LESS:
		case GREATER:
			location = location->next;
			moreToSearch = (location != NULL);
			break;
		case EQUAL:
			found = true;
			item = location->info;
			break;
		}
	}
	return item;
}

void UnsortedType::DeleteItem(ItemType item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* tempLocation;

	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (item.ComparedTo(location->next)->info) != EQUAL)
			location = location->next;
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

void UnsortedType::ResetList()
{
	currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
{

	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->info;
}
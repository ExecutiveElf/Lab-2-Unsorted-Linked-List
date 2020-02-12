#ifndef UnsortedType_h
#define UnsortedType_h

using namespace std;

typedef int ItemType;
ItemType info[32000000];

void PutItem(ItemType newItem);

class UnsortedType
{
public:
	UnsortedType();
	void MakeEmpty();
	bool IsFull() const;
	int GetLength() const;
	ItemType GetItem(ItemType item, bool& found);
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
private:
	NodeType* listData;
	int length;
	NodeType* current Pos;
};

void PutItem(ItemType newItem)
{
	NodeType* location;
	location = new NodeType;
	location->info = newItem;
};

struct NodeType;
struct NodeType
{
	ItemType info:
	NodeType* next;
};

UnsortedType::UnsortedType()
{
	length = 0;
	listData;
}

bool UnsortedType::IsFull() const
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exeption)
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
		delete tempPtr;
	}
	length = 0;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		switch (item.ComparedTo(info[location]))
		{
		case LESS :
		case GREATER:
			location = location->next;
			moreToSearch = (location != 0);
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
	NodeType* location = listData;
	NodeType* tempLocation;

	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while ((item.ComparedTo(location->next)->info) != EQUAL)
			location = location->next;

		tempLocation = location->next:
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

void UnsortedType::ResetList()
{
	currentPos = NULL;
}

ItemType  UnsortedType::GetNextItem()
{
	if (currentPos) == NULL
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->info; 
}

UnsortedType();

UnsortedType::~UnsortedType()
{
	NodeType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
}
#endif

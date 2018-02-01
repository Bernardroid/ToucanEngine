#pragma once
template <class T> class LinkedList
{
private:
	struct Node
	{
		Node * nextNode;
		T value;
	};

	Node * rootNode;

public:

	void Add(T _value)
	{
		if (rootNode == NULL)
		{
			rootNode = new Node();
			rootNode->value = _value;
			rootNode->nextNode = NULL;
		}
		else
		{
			Node * newNode = new Node();
			newNode->value = _value;

			Node * tempNode = rootNode;
			while (tempNode->nextNode != NULL)
			{
				tempNode = tempNode->nextNode;
			}

			tempNode->nextNode = newNode;
		}
	}

	void Delete(int _targetNode)
	{
		if (_targetNode == 1)
		{
			Node * iLiveToDie = rootNode;
			rootNode = rootNode->nextNode;
			delete iLiveToDie;
		}
		else
		{
			Node* tempNode1 = rootNode;
			Node* tempNode2 = rootNode->nextNode;

			int target = _targetNode - 1;

			if (target <= 0)
			{
				target = 1;
			}

			for (int i = 1; i < target; i++)
			{
				tempNode1 = tempNode2;
				tempNode2 = tempNode2->nextNode;
			}

			tempNode1->nextNode = tempNode2->nextNode;
			delete tempNode2;
		}
	}

	T GetValue(int _targetNode)
	{
		Node* tempNode = rootNode;

		for (int i = 1; i < _targetNode; i++)
		{
			tempNode = tempNode->nextNode;
		}
		return tempNode->value;
	}

	int Count()
	{
		if (rootNode == NULL)
		{
			return 0;
		}
		else
		{
			int size = 1;
			Node * tempNode = rootNode;
			while (tempNode->nextNode != NULL)
			{
				tempNode = tempNode->nextNode;
				size++;
			}
			return size;
		}
	}

	void DeleteList()
	{
		Node * gonnaGetYou = rootNode;
		Node * gonnaGetYoKid = rootNode->nextNode;

		int count = Count();

		for (int i = 0; i < count; i++)
		{
			delete gonnaGetYou;
			gonnaGetYou = gonnaGetYoKid;
			gonnaGetYoKid = gonnaGetYoKid->nextNode;
		}
	}

	Node GetRoot()
	{
		return rootNode;
	}
};
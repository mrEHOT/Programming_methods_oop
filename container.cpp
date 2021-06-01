#include "container.h"
namespace simple_matrix
{
	void container::Input(ifstream& ifst)
	{
		node* tmpNode = new node;

		while (tmpNode->NodeAdd(ifst))
		{
			if (head == NULL)
			{
				head = tmpNode;
				tmpNode->next = tmpNode;
				tmpNode->prev = tmpNode;
			}
			else
			{
				tmpNode->prev = head->prev;
				tmpNode->next = head;
				head->prev->next = tmpNode;
				head->prev = tmpNode;
			}
			size++;
			tmpNode = NULL;
			tmpNode = new node;
		}
		delete tmpNode;
	}

	void container::Output(ofstream& ofst)
	{
		node* currNode;

		ofst << "Container contains " << size << " elements." << endl;
		for (int i = 0; i < size; i++)
		{
			currNode = head;
			for (int j = 0; j < i; j++)
			{
				currNode = currNode->next;
			}
			currNode->NodeOutput(ofst);
		}
	}

	void container::FilteredOutput(ofstream& ofst)
	{
		node* currNode;

		ofst << "Filtered Output - Square matrix:" << endl << endl;
		for (int i = 0; i < size; i++)
		{
			currNode = head;
			for (int j = 0; j < i; j++)
			{
				currNode = currNode->next;
			}
			currNode->FilteredNodeOutput(ofst);
		}
	}

	void container::Clear()
	{
		if (head != NULL)
		{
			node* currNode;
			for (int i = size - 1; i > 0; i--)
			{
				currNode = head;
				for (int j = 0; j < i; j++)
				{
					currNode = currNode->next;
				}
				currNode->NodeRemove();
				free(currNode);
			}
			size = 0;
			head = NULL;
		}
	}

	container::container()
	{
		size = 0;
		head = NULL;
	}
}
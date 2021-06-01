#include "node.h"
namespace simple_matrix
{
	void node::NodeCompare(node* head, int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (matrix::MtxCompare(GetNode(head, i)->mtx, GetNode(head, j)->mtx))
				{
					NodeSwap(head, i, j);
				}
			}
		}
	}

	node* node::GetNode(node* head, int pos)
	{
		node* retNode = head;

		for (int i = 0; i < pos; i++)
		{
			retNode = retNode->next;
		}
		return retNode;
	}

	void node::NodeSwap(node* head, int first, int second)
	{
		node* temp = new node;
		temp->mtx = GetNode(head, first)->mtx;
		GetNode(head, first)->mtx = GetNode(head, second)->mtx;
		GetNode(head, second)->mtx = temp->mtx;
	}

	bool node::NodeAdd(ifstream& ifst)
	{
		mtx = matrix::MtxInput(ifst);

		if (mtx == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void node::NodeOutput(ofstream& ofst)
	{
		mtx->Output(ofst);
	}

	void node::FilteredNodeOutput(ofstream& ofst)
	{
		mtx->FilteredMtxOut(ofst);
	}

	void node::NodeRemove()
	{
		mtx->ClearMtx();
	}
}  // end namespace simple_matrix
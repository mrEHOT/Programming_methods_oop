#include "node.h"
namespace simple_matrix
{
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
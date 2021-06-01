#include "matrix.h"
#include "squareMtx.h"
#include "diagonalMtx.h"
#include "triangularMtx.h"
namespace simple_matrix
{
	matrix* matrix::MtxInput(ifstream& ifst)
	{

		matrix* newMtx;
		int key = -1;
		int style = -1;
		ifst >> key;
		ifst >> style;

		switch (key)
		{
		case 0:
			newMtx = new  squareMtx(style);
			break;
		case 1:
			newMtx = new diagonalMtx(style);
			break;
		case 2:
			newMtx = new triangularMtx(style);
			break;
		default:
			return 0;
		}

		if (newMtx->Input(ifst))
		{
			return newMtx;
		}
		else
		{
			return NULL;
		}

	}

	bool matrix::MtxCompare(matrix* first, matrix* second)
	{
		if (first->MtxSum() > second->MtxSum())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}  // end namespace simple_matrix
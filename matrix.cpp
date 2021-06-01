#include "matrix.h"
#include "squareMtx.h"
#include "diagonalMtx.h"
#include "triangularMtx.h"
namespace simple_matrix
{
	matrix* matrix::MtxInput(ifstream& ifst)
	{

		matrix* newMtx;
		int key;
		ifst >> key;

		switch (key)
		{
		case 0:
			newMtx = new squareMtx;
			break;
		case 1:
			newMtx = new diagonalMtx;
			break;
		case 2:
			newMtx = new triangularMtx;
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
}  // end namespace simple_matrix
#include "matrix.h"
#include "squareMtx.h"
#include "diagonalMtx.h"
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
			newMtx = new  squareMtx;
			break;
		case 1:
			newMtx = new diagonalMtx;
			break;
		default:
			return 0;
		}

		newMtx->Input(ifst);
		return newMtx;
	}
}  // end namespace simple_matrix
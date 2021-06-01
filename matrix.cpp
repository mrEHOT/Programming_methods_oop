#include "matrix.h"
#include "squareMtx.h"
#include "diagonalMtx.h"
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
		default:
			return 0;
		}

		newMtx->Input(ifst);
		return newMtx;
	}
}  // end namespace simple_matrix
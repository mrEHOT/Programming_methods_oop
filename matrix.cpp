#include "matrix.h"
#include "squareMtx.h"
#include "diagonalMtx.h"
#include "triangularMtx.h"
namespace simple_matrix
{
	matrix* matrix::MtxInput(ifstream& ifst)
	{
		matrix* newMtx;
		int key = 0;
		int style = 0;
		string content = "";

		if (ifst.eof())
		{
			return NULL;
		}

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				key++;
			}
		}
		if (key != 0)
		{
			cout << "Input Error! Matrix type must be one digit: 0 - Square, 1 - Diagonal, 3 - Triangular!" << endl;
			return NULL;
		}
		else
		{
			key = atoi(content.c_str());
			content = "";
		}

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				style++;
			}
		}
		if (style != 0)
		{
			cout << "Input Error! Output style must be one digit: 0 - Line by line, 1 - Output by columns, 3 - Output to a one-dimensional array!" << endl;
			return NULL;
		}
		else
		{
			style = atoi(content.c_str());
			content = "";
		}

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
			cout << "The matrix type is undefined!" << endl;
			return NULL;
		}

		if (newMtx->Input(ifst))
		{
			return newMtx;
		}
		else
		{
			cout << "Matrix input error!" << endl;
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
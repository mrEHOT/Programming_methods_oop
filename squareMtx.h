#pragma once
#ifndef squareMtx_definition
#define squareMtx_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

namespace simple_matrix
{
	class squareMtx :public matrix
	{
	public:
		int** currentMtx;

		int MtxSum();
		bool Input(ifstream& ifst);
		void FilteredMtxOut(ofstream& ofst);
		void Output(ofstream& ofst);
		void MMMatrix(matrix* other, ofstream& ofst);
		void MMSquare(ofstream& ofst);
		void MMDiagonal(ofstream& ofst);
		void MMTriangular(ofstream& ofst);
		void ClearMtx();
		squareMtx();
		squareMtx(int style);
		~squareMtx() {};
	};
} // end namespace simple_matrix
#endif // !squareMtx_definition
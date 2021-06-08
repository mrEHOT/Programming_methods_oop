#pragma once
#ifndef triangularMtx_definition
#define triangularMtx_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

namespace simple_matrix
{
	class triangularMtx :public matrix
	{
	public:
		int* currentMtx;
		int numberOfElements;

		int MtxSum();
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void MMMatrix(matrix* other, ofstream& ofst) {};
		void MMSquare(ofstream& ofst) {};
		void MMDiagonal(ofstream& ofst) {};
		void ClearMtx();
		triangularMtx();
		triangularMtx(int style);
		~triangularMtx() {};
	};
} // end namespace simple_matrix
#endif // !triangularMtx_definition
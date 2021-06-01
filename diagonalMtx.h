#pragma once
#ifndef diagonalMtx_definition
#define diagonalMtx_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"
using namespace std;
namespace simple_matrix
{
	class diagonalMtx : public matrix
	{
		int* currentMtx;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void ClearMtx();
		diagonalMtx(int style);
		~diagonalMtx() {};
	};
} // end namespace simple_matrix
#endif // !diagonalMtx_definition
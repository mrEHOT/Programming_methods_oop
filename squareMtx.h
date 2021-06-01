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
		int** currentMtx;
	public:
		int MtxSum();
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void ClearMtx();
		squareMtx(int style);
		~squareMtx() {};
	};
} // end namespace simple_matrix
#endif // !squareMtx_definition
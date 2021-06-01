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

		void Input(ifstream& ifst);
		void FilteredMtxOut(ofstream& ofst);
		void Output(ofstream& ofst);
		void ClearMtx();
		~squareMtx() {};
	};
} // end namespace simple_matrix
#endif // !squareMtx_definition
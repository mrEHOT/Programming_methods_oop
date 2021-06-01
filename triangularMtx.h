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
		int* currentMtx;
		int currentMtxSize;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void ClearMtx();
		triangularMtx(int style);
		~triangularMtx() {};
	};
} // end namespace simple_matrix
#endif // !triangularMtx_definition
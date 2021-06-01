#pragma once
#ifndef matrix_definition
#define matrix_definition
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_matrix
{
	class matrix
	{
	public:
		long sideSize;
		int sum = 0;
		bool sumMarker = false;

		static matrix* MtxInput(ifstream& ifst);
		~matrix() {};

		virtual void ClearMtx() = 0;
		virtual void Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		virtual int MtxSum() = 0;

	};
} // end namespace simple_matrix
#endif // !matrix_definition
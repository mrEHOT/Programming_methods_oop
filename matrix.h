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
		enum outputStyle { LINEBYLINE, BYCOLUMNS, ONEDIMENARR };
		outputStyle style;
		int sum = 0;
		bool sumMarker = false;

		static bool MtxCompare(matrix* first, matrix* second);
		static matrix* MtxInput(ifstream& ifst);
		virtual void ClearMtx() = 0;
		virtual bool Input(ifstream& ifst) = 0;
		virtual void FilteredMtxOut(ofstream& ofst) {};
		virtual void Output(ofstream& ofst) = 0;
		virtual void MMMatrix(matrix* other, ofstream& ofst) = 0;
		virtual void MMSquare(ofstream& ofst) = 0;
		virtual void MMDiagonal(ofstream& ofst) = 0;
		virtual int MtxSum() = 0;
		~matrix() {};
	};
} // end namespace simple_matrix
#endif // !matrix_definition
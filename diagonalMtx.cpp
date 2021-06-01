#include "diagonalMtx.h"
namespace simple_matrix
{
	void diagonalMtx::Input(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;


		ifst >> sideSize >> content;
		currentMtx = new int[sideSize];


		while ((pos = content.find(delimiter)) != string::npos)
		{
			part = content.substr(0, pos);
			currentMtx[col] = atoi(part.c_str());
			col++;
			content.erase(0, pos + delimiter.length());
		}

		currentMtx[col] = atoi(content.c_str());
	}

	void diagonalMtx::Output(ofstream& ofst)
	{
		ofst << "It is Diagonal matrix. Matrix side size: " << sideSize << endl;
		for (int row = 0; row < sideSize; row++)
		{
			for (int col = 0; col < sideSize; col++)
			{
				if (row != col)
				{
					ofst << "0" << "\t";
				}
				else
				{
					ofst << currentMtx[row] << "\t";
				}
			}
			ofst << endl;
		}

		ofst << endl;
	}

	void diagonalMtx::ClearMtx()
	{
		delete[] currentMtx;
	}

	int diagonalMtx::MtxSum()
	{
		if (!sumMarker)
		{
			for (int row = 0; row < sideSize; row++)
			{
				sum += currentMtx[row];
			}
			sumMarker = true; // Устанавливаем маркер в TRUE (сумма элементов посчитана)
			return sum;
		} // Выполняется, если сумма элементов не была вычислена ранее
		else
		{
			return sum;
		} // Если сумма уже была посчитана => просто вернем ее
	}
} // end namespace simple_matrix
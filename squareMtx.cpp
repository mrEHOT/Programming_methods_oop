#include "squareMtx.h"
namespace simple_matrix
{
	bool squareMtx::Input(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		ifst >> sideSize;
		currentMtx = new int* [sideSize];
		for (int row = 0; row < sideSize; row++)
		{
			currentMtx[row] = new int[sideSize];
		}

		for (int row = 0; row < sideSize; row++)
		{
			ifst >> content;

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				currentMtx[row][col] = atoi(part.c_str());
				col++;
				content.erase(0, pos + delimiter.length());
			}

			currentMtx[row][col] = atoi(content.c_str());
			content = "";
			col = 0;
		}

		return true;
	}

	void squareMtx::Output(ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << sideSize << endl;
		for (int row = 0; row < sideSize; row++)
		{
			for (int col = 0; col < sideSize; col++)
			{
				ofst << currentMtx[row][col] << "\t";
			}
			ofst << endl;
		}

		ofst << endl;
	}

	void squareMtx::ClearMtx()
	{
		for (int row = 0; row < sideSize; row++)
		{
			delete currentMtx[row];
		}

		delete[] currentMtx;
	}
} // end namespace simple_matrix
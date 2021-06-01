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

		switch (style)
		{
		case 0:
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
			break;
		case 1:
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
			break;
		case 2:
			ofst << "[ ";
			for (int col = 0; col < sideSize; col++)
			{
				ofst << currentMtx[col] << " ";
			}
			ofst << "]" << endl;
			break;
		default:
			break;
		}
		ofst << endl;
	}

	void diagonalMtx::ClearMtx()
	{
		delete[] currentMtx;
	}

	diagonalMtx::diagonalMtx(int style)
	{
		sideSize = 0;
		currentMtx = NULL;

		switch (style)
		{
		case 0:
			this->style = LINEBYLINE;
			break;
		case 1:
			this->style = BYCOLUMNS;
			break;
		case 2:
			this->style = ONEDIMENARR;
			break;
		default:
			break;
		}
	}
} // end namespace simple_matrix
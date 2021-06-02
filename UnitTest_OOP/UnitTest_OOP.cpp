#include "pch.h"
#include "CppUnitTest.h"

#include "..\container.h"
#include "..\container.cpp"
#include "..\matrix.h"
#include "..\matrix.cpp"
#include "..\node.h"
#include "..\node.cpp"
#include "..\squareMtx.h"
#include "..\squareMtx.cpp"
#include "..\diagonalMtx.h"
#include "..\diagonalMtx.cpp"
#include "..\triangularMtx.h"
#include "..\triangularMtx.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_matrix;

namespace UnitTestOOP
{
	TEST_CLASS(UnitTestOOP)
	{
	public:
		string Read(const char* filename)
		{

			ifstream ifst(filename);
			string content = "";
			if (ifst.is_open())
			{
				while (!ifst.eof())
				{
					string tmp;
					ifst >> tmp;
					content += tmp;
				}
				ifst.close();
			}
			return content;
		}

		TEST_METHOD(TestOut)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\out_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			container cont;
			cont.Input(ifst);
			cont.Output(ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\out_cheсk.txt");

			Assert::AreEqual(s1, s2);

			cont.Clear();
		}
		TEST_METHOD(TestInitContainer)
		{
			container* cont = new container();

			Assert::IsTrue((cont->head == NULL) && (cont->size == 0));
		}
		TEST_METHOD(TestSortContainer)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\sortcontainer_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			container cont;
			cont.Input(ifst);
			cont.Sort();
			cont.Output(ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\sortcontainer_cheсk.txt");

			Assert::AreEqual(s1, s2);

			cont.Clear();
		}
		TEST_METHOD(TestClearContainer)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\clearcontainer_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			container cont;
			cont.Input(ifst);
			cont.Sort();
			cont.Output(ofst);
			cont.Clear();
			cont.Output(ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\clearcontainer_check.txt");

			Assert::AreEqual(s1, s2);
		}
		TEST_METHOD(TestFilteredOutput)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\filteredoutput_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			container cont;
			cont.Input(ifst);
			cont.FilteredOutput(ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\filteredoutput_cheсk.txt");

			Assert::AreEqual(s1, s2);

			cont.Clear();
		}
		TEST_METHOD(TestSumElements)
		{
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\sum_input.txt");

			matrix* mtx = matrix::MtxInput(ifst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\sum_check.txt");

			Assert::IsTrue(mtx->MtxSum() == atoi(s1.c_str()));
		}
		TEST_METHOD(TestMatrixCompare)
		{
			ifstream ifst1("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\matrixcompare_first.txt");
			ifstream ifst2("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\matrixcompare_second.txt");

			matrix* mtx1 = matrix::MtxInput(ifst1);

			matrix* mtx2 = matrix::MtxInput(ifst2);

			Assert::IsTrue(mtx1->MtxSum() > mtx2->MtxSum());
		}
		TEST_METHOD(TestNodeSwap)
		{
			int pos1, pos2;
			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\nodeswap_input.txt");
			ofstream ofst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			ifst >> pos1;
			ifst >> pos2;
			container cont;
			cont.Input(ifst);

			if (pos1 < cont.size && pos2 < cont.size)
			{
				node::NodeSwap(cont.head, pos1, pos2);
			}

			cont.Output(ofst);

			string s1 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\universal_output.txt");

			string s2 = Read("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\nodeswap_cheсk.txt");

			Assert::AreEqual(s1, s2);

			cont.Clear();
		}
		TEST_METHOD(TestInputSquare)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\squareinput_input.txt");

			squareMtx* newMatrix = new squareMtx();

			newMatrix->Input(ifst);

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\squareinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				if (check)
				{
					break;
				}

				for (int col = 0; col < newMatrix->sideSize; col++)
				{
					int currNumber;
					checkst >> currNumber;
					if (newMatrix->currentMtx[row][col] != currNumber)
					{
						check = true;
						break;
					}
				}
			}
			Assert::IsFalse(check);

			newMatrix->ClearMtx();
			delete newMatrix;
		}
		TEST_METHOD(TestInputDiagonal)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\diagonalinput_input.txt");

			diagonalMtx* newMatrix = new diagonalMtx();

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\diagonalinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				int currNumber;
				checkst >> currNumber;
				if (newMatrix->currentMtx[row] != currNumber)
				{
					check = true;
					break;
				}
			}
			Assert::IsFalse(check);

			newMatrix->ClearMtx();
			delete newMatrix;
		}
		TEST_METHOD(TestInputTriangular)
		{
			bool check = false;

			ifstream ifst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\triangularinput_input.txt");

			triangularMtx* newMatrix = new triangularMtx();

			ifstream checkst("D:\\Учеба\\Технология и методы программирования\\Программы\\Programming_methods_oop\\UnitTest_OOP\\Tests\\triangularinput_check.txt");

			for (int row = 0; row < newMatrix->sideSize; row++)
			{
				int currNumber;
				checkst >> currNumber;
				if (newMatrix->currentMtx[row] != currNumber)
				{
					check = true;
					break;
				}
			}
			Assert::IsFalse(check);

			newMatrix->ClearMtx();
			delete newMatrix;
		}
	};
}
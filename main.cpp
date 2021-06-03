#include <iostream>
#include <fstream>
#include "container.h"
#include <regex>

using namespace std;
using namespace simple_matrix;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line!" << endl;
		cout << "Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifstCheck(argv[1]);
	if (!ifstCheck.is_open())
	{
		cout << "Input file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Input
	else
	{
		string content = "";
		regex regular("^-?\\d+(,-?\\d+){0,}$");

		while (!ifstCheck.eof())
		{
			string content = "";
			getline(ifstCheck, content); // Считываем строку из исходного файла
			if (!regex_match(content, regular))
			{
				cout << "Invalid input received! Please re-enter!" << endl;
				return 1;
			}
		} // Если весь входной файл удовлетворяет условию регулярного выражения, то его можно использовать в качестве входного
		ifstCheck.close();
	}

	ifstream ifst(argv[1]);

	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		cout << "Output file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Output
	cout << "Start" << endl;

	container cont;

	if (cont.Input(ifst))
	{
		cont.Sort();
		cout << "Filled container. " << endl;
		cont.Output(ofst); // Вывод заполненного контейнера

		cout << "Output of square matrix." << endl;
		cont.FilteredOutput(ofst); // Процедура, реализующая выборочный вывод информации (только о первом виде объетов - стандартные квадратные матрицы)

		cont.Clear(); //Очистка контейнера
		cout << "Empty container. " << endl;
		cont.Output(ofst); // Вывод пустого контейнера

		cout << "Stop" << endl;

		return 0;
	} // Если заполнение контейнера выполнено корректно, то программа выполняется до конца
	else
	{
		cont.Clear(); //Очистка контейнера
		cout << "Input data error! Container filling stopped!" << endl;
		return 1;
	} // Экстренное завершение программы, ошибка при заполнении контейнера
}
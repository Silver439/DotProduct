#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<ctime>
#include <chrono>
#include<cmath>
#include<cblas.h>
using namespace std;
char ch;
float f;
float f1;
float f2;
string s, ss;
int main()
{
	/*ofstream ofile1("f3.dat",ios::out|ios::binary);
	if (ofile1.is_open())
	{
		default_random_engine e(time(0));
		uniform_real_distribution<float> u(-1000,1000);
		for (int i = 0; i < 200000000; i++)
		{
			f = u(e);
			ofile1.write(reinterpret_cast<char*>(&f), sizeof(f));
		}
		ofile1.close();
	}*/
	/*ofstream ofile2("f4.dat", ios::out | ios::binary);
	if (ofile2.is_open())
	{
		default_random_engine r;
		uniform_real_distribution<float> o(-1000, 1000);
		for (int i = 0; i < 200000000; i++)
		{
			f = o(r);
			ofile2.write(reinterpret_cast<char*>(&f), sizeof(f));
		}
		ofile2.close();
	}*/
	double sum = 0.0;
	ifstream ifile1("f3.dat");
	ifstream ifile2("f4.dat");
	float* v1 = new float[200000000];
	float* v2 = new float[200000000];
	if (ifile1.is_open() && ifile2.is_open())
	{
		for (int i = 0; i < 200000000; i++)
		{
			ifile1.read(reinterpret_cast<char*>(&f1), sizeof(f1));
			ifile2.read(reinterpret_cast<char*>(&f2), sizeof(f2));
			v1[i] = f1;
			v2[i] = f2;
		}
		ifile1.close();
		ifile2.close();
	}
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < 199999980; i+=20)
	{
		sum += v1[i] * v2[i]
			+ v1[i + 1] * v2[i + 1]
			+ v1[i + 2] * v2[i + 2]
			+ v1[i + 3] * v2[i + 3]
			+ v1[i + 4] * v2[i + 4]
			+ v1[i + 5] * v2[i + 5]
			+ v1[i + 6] * v2[i + 6]
			+ v1[i + 7] * v2[i + 7]
			+ v1[i + 8] * v2[i + 8]
			+ v1[i + 9] * v2[i + 9]
			+ v1[i + 10] * v2[i + 10]
			+ v1[i + 11] * v2[i + 11]
			+ v1[i + 12] * v2[i + 12]
			+ v1[i + 13] * v2[i + 13]
			+ v1[i + 14] * v2[i + 14]
			+ v1[i + 15] * v2[i + 15]
			+ v1[i + 16] * v2[i + 16]
			+ v1[i + 17] * v2[i + 17]
			+ v1[i + 18] * v2[i + 18]
			+ v1[i + 19] * v2[i + 19];
	}
	auto end = std::chrono::steady_clock::now();
	cout << sum << endl;
	cout<<"用时 "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms.\n";
}
/*double mul(string s1, string s2)
{
	int m = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == '.')
		{
			m += s1.size() - i - 1;
			s1.erase(i, 1);
			break;
		}
	}
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] == '.')
		{
			m += s2.size() - i - 1;
			s2.erase(i, 1);
			break;
		}
	}
	return stod(s1) * stod(s2) / pow(10, m);
}*/

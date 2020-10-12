#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<ctime>
#include<cblas.h>
using namespace std;
char ch;
float f;
float f1;
float f2;
string s, ss;
clock_t start, eND;
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
	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;
	float sum4 = 0;
	ifstream ifile1("f1.dat");
	ifstream ifile2("f2.dat");
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
	start = clock();
	for (int i = 0; i < 199999990; i+=10)
	{
		sum1 += v1[i] * v2[i]
			+ v1[i + 1] * v2[i + 1]
			+ v1[i + 2] * v2[i + 2]
			+ v1[i + 3] * v2[i + 3]
			+ v1[i + 4] * v2[i + 4]
			+ v1[i + 5] * v2[i + 5]
			+ v1[i + 6] * v2[i + 6]
			+ v1[i + 7] * v2[i + 7]
			+ v1[i + 8] * v2[i + 8]
			+ v1[i + 9] * v2[i + 9];
	}
	eND = clock();
	double endtime1 = double(eND - start) / CLOCKS_PER_SEC;
	cout << sum1 << endl;
	cout << "用时 " << endtime1*1000 << "ms.\n" << endl;
	start = clock();
	for (int i = 0; i < 200000000;i++)
	{
		sum2 += v1[i] * v2[i];
	}
	eND = clock();
	cout << sum2 << endl;
	double endtime2 = double(eND - start) / CLOCKS_PER_SEC;
	cout << "用时 " << endtime2 * 1000 << "ms.\n" << endl;
	start = clock();
	for (int i = 0; i < 199999980; i += 20)
	{
		sum3 += v1[i] * v2[i]
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
	eND = clock();
	cout << sum3 << endl;
	double endtime3 = double(eND - start) / CLOCKS_PER_SEC;
	cout << "用时 " << endtime3 * 1000 << "ms.\n" << endl;
	start = clock();
	sum4 = cblas_sdot(200000000, v1, 1, v2, 1);
	eND = clock();
	double endtime4 = double(eND - start) / CLOCKS_PER_SEC;
	cout << sum4 << endl;
	cout << "用时 " << endtime4 * 1000 << "ms.\n" << endl;
	start = clock();
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

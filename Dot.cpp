#include<iostream>
#include<string>
#include <chrono>
using namespace std;
int len;
int n1 = 0; int n2 = 0;
string s1, s2;
double sum = 0.0;
bool check1(string);
int check2(string);
int main()
{
	cout << "Please input your length of vector:";
	cin >> len;
	cin.get();
	cout << "Please input first vector:";
	getline(cin, s1);
	cout << "Please input second vector:";
	getline(cin, s2);
	if (!check1(s1) || !check1(s2))
	{
		cout << "Error!You can only input numbers and spaces!";
		return 0;
	}
	if (check2(s1)==-1 || check2(s2)==-1)
	{
		cout << "Error!Please input correct numbers!";
		return 0;
	}
	n1 = check2(s1);
	n2 = check2(s2);
	if (n1 != len || n2 != len)
	{
		cout << "Error！Please input two vector that have correct lenth!";
		return 0;
	}
	float * v1 = new float[len];
	float * v2 = new float[len];
	int m1 = 0;
	int m2 = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 48 && s1[i] <= 57)
		{
			if (i == s1.size() - 1) v1[m1++] = stof(s1.substr(i, 1));
			for (int j = i + 1; j < s1.size(); j++)
			{
				if (j == s1.size() - 1)
				{
					++j;
					v1[m1++]= stod(s1.substr(i, j - i));
					i = j;
					break;
				}
				if (s1[j] == ' ')
				{
					v1[m1++] = stod(s1.substr(i, j - i));
					i = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] >= 48 && s2[i] <= 57)
		{
			if (i == s2.size() - 1) v2[m2++] = stod(s2.substr(i, 1));
			for (int j = i + 1; j < s2.size(); j++)
			{
				if (j == s2.size() - 1)
				{
					++j;
					v2[m2++] = stod(s2.substr(i, j - i));
					i = j;
					break;
				}
				if (s2[j] == ' ')
				{
					v2[m2++] = stod(s2.substr(i, j - i));
					i = j;
					break;
				}
			}
		}
	}
	auto start = std::chrono::steady_clock::now();
	int r = len % 10;
	for (int i = 0; i < len - r; i += 10)
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
			+ v1[i + 9] * v2[i + 9];
	}
	if (r != 0)
	{
		for (int i = 0; i < r; i++)
		{
			sum += v1[len - r + i] * v2[len - r + i];
		}
	}
	auto end = std::chrono::steady_clock::now();
	cout << sum << endl;
	cout << "用时 " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms.\n";
}
bool check1(string s)
{
	bool b1= 1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '.' || s[i] == ' ')
		{
			continue;
		}
		else
		{
			b1= 0;
		}
	}
	return b1;
}
int check2(string s)
{
	int n = 0;
	float f;
	for (int i = 0; i < s.size(); i++)
	{
		if (n == -1) break;
		if (s[i] == '.')
		{
			n = -1;
			break;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			if (i == s.size() - 1) n++;
			for (int j = i+1; j < s.size(); j++)
			{
				if (j == s.size() - 1)
				{
					++j;
					try
					{
						f = stod(s.substr(i, j - i));
					}
					catch (const std::exception&)
					{
						n = -1;
						break;
					}
					if (n != -1) n++;
					i = j - 1;
					break;
				}
				if (s[j] == ' ')
				{
					try
					{
						f=stof(s.substr(i, j - i));
					}
					catch (const std::exception&)
					{
						n = -1;
						break;
					}
					if (n != -1) n++;
					i = j;
					break;
				}
			}
		}
	}
	return n;
}
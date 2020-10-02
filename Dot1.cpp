#include<iostream>
#include<string>
using namespace std;
string s1, s2;
bool check(string);
bool examine(string);
int len(string);
int main()
{
    int x1 = 0;
    int x2 = 0;
    cout << "Please input a vector:";
    getline(cin, s1);
    int len1 = len(s1)+1;
    float* v1 = new float[len1];
    cout << "Please input another vector:";
    getline(cin, s2);
    int len2 = len(s2)+1;
    float* v2 = new float[len2];
    if (!check(s1) || !check(s2)) cout << "Please input a vector like 1,2,3,4";
    else if (len1 != len2) cout << "Please input two that have same lenth!";
    else
    {
        if(s1[0]==',') cout << "Error!Please input a vector like 1,2,3,4";
        else
        {
            int k1 = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == ','||i==s1.size()-1)
                {
                    if (i == s1.size() - 1) i++;
                    if(i==k1) cout << "Error!Please input a vector like 1,2,3,4";
                    else
                    {
                        if(!examine(s1.substr(k1,i-k1))) cout << "Error!Please input a vector like 1,2,3,4";
                        else
                        {
                            v1[x1] = stod(s1.substr(k1, i - k1));
                            x1 += 1;
                            k1 = i+1;
                        }
                    }
                }
            }
        }
        if (s2[0] == ',') cout << "Error!Please input a vector like 1,2,3,4";
        else
        {
            int k2 = 0;
            for (int i = 0; i < s2.size(); i++)
            {
                if (s2[i] == ','||i == s2.size() - 1)
                {
                    if (i == s2.size() - 1) i++;
                    if (i == k2) cout << "Error!Please input a vector like 1,2,3,4";
                    else
                    {
                        if (!examine(s2.substr(k2, i - k2))) cout << "Error!Please input a vector like 1,2,3,4";
                        else
                        {
                            v2[x2] = stod(s2.substr(k2, i - k2));
                            x2 += 1;
                            k2 = i+1;
                        }
                    }
                }
            }
        }
        float result=0;
        for (int i = 0; i < len1; i++)
        {
            result += v1[i] * v2[i];
        }
        cout << result;
    }
    return 0;
}
bool check(string s)
{
    bool b=1;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 48 && s[i] <= 57) || s[i] == ','||s[i]=='.') continue;
        else
        {
            b = 0;
            break;
        }
    }
    return b;
}
bool examine(string s)
{
    bool e = 1;
    int ex = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.') ex++;
    }
    if (ex >= 2) e = 0;
    return e;
}
int len(string s)
{
    int le = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',') le++;
    }
    return le;
}
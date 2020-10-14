# DotProduct
## 主要功能：
* 能够在合理的精度范围内较为高效地进行两个向量的点积计算。
* 能够处理用户的各种异常输入，并指出错误类型。
* 可以支持任意长度向量的点积计算。
## 主要思路：
* 对于较大长度的向量，例如200M，正常算法是进行两亿次循环，每次循环两向量的分量相乘再相加。本程序使用分块的思想对其进行优化，使得其运算速度能够在正常基础上提高3到4倍。
## 包含文件：
* 本项目共包含两个源代码文件`Dot1.cpp`和`Dot2.cpp`。其中Dot1.cpp是用于对较长向量乘法进行运算测试。测试数据共4个.dat文件，分为两组，代表两组长度为200M的向量。我用不同的算法对这两组向量的点积进行了计算，测试了它们所需的运算时间，并且引入了openblas中的cblas—sdot（）函数进行对比。
* Dot2.cpp是实际用户可以使用的程序代码。其主要功能见上。
## 程序测试：
####  输入&输出：
* 用户首先需要输入向量的长度。

  ```c++
  cout << "Please input your length of vector:";
  	cin >> len;
  	cin.get();
  ```
  
* 然后以字符串形式输入两个向量。这里用户只能输入数字（支持小数）和空格，其余符号均为非法符号。
  
  ```c++
  cout << "Please input first vector:";
  	getline(cin, s1);
  cout << "Please input second vector:";
  	getline(cin, s2);
  ```
  
 * 通过两个检查函数`check1（）`和`check2（）`来处理输入异常。check1（）检查是否存在非法符号，check2（）检查每个数字小数点个数和位置是否正确。代码如下：
  
   ```c++
   bool check1(string s)
   {
   	bool b1= 1;
   	for (int i = 0; i < s.size(); i++)
   	{
   		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '.' || s[i] == ' ') continue;
   		else b1= 0;
   	}
   	return b1;
   }
   ```
   
   ```c++
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
   ```
   * 这里check2（）在处理异常的同时还记录了该字符串内所含数字的多少。
 * 以下是一些异常输入以及对应的输出结果：
   
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/3.jpg)
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/4.jpg)
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/5.jpg)
   * 用户输入数字间的空格数没有限制，例如1     1 1是可以被允许的：
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/6.jpg)
 * 以上便是对输入异常处理的部分。
#### 计算部分：
* 计算采用分组的方法，先将两个向量的各个分量存入两个动态数组，再每十个为一组进行运算。最后再计算余下的小于十个的部分。代码如下：

   ```c++
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
  ```
   * 结果测试：
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/7.jpg)
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/8.jpg)
   * 对与较长的向量，以长度为200M为例，运行Dot1.cpp得到如下结果：
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/1.jpg)
   * ![Alt text](https://github.com/Silver439/DotProduct/raw/master/picture/2.jpg)
   * 以上两个结果是对于两组文件进行计算得到的。每组文件包含2亿个float数字。两个图中共四个结果，第一个结果是使用分块算法优化，即每个循环处理10个数据；第二个结果是不进行任何优化所得到的结果。第三个结果是同样使用分块优化，但每个循环处理20个数据。第四个结果是通过调用openblas中的cblas—sdot（）函数得到的。
   * 可以看到优化后的有了速度明显的提升，但在精确度方面有所下降。
## 总结：
 *以上便是我在此次作业中完成的功能。本次作业我花费时间较长，有很大一部分时间在处理计算的精度问题。我在测试代码中也同过字符串的处理方式写了小数高精度乘法，但在200M数据情况下运行所花费时间极其长久，完全没有应用价值。的确既想要精度又想要速度是很难实现的。本次优化算法其实比较简单，优化效果也没能达到10倍。我还尝试着使用多线程的方式加快运算速度但没能成功。但在这些失败的尝试中我还是有了很大的收获。

# 感谢阅读！

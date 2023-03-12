//cache优化算法
#include<iostream>
#include<windows.h>
using namespace std;
const long long int n=10;
int main()
{
    cout<<"矩阵的规模是"<<n<<endl;
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	long long int arry[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arry[i][j] = i+j;
		}
	}
	long long int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	long long int res[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
	}
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			res[j] += arry[i][j] * a[i];
		}
	}
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "矩阵的每一列与固定向量的乘积是：";
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << "程序1.2耗费的时间是：" << time*10000;
	return 0;
}
//利用cache的优化算法，改变按列访问的平凡算法，变为按行访问，保证每个元素只被访问一次，减少读取时间

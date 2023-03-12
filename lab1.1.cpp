//逐列访问元素的平凡算法
#include<iostream>
#include<windows.h>
const long long int n=10;
using namespace std;
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
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	for (int j = 0; j < n; j++)
	{
		res[j] = 0;
		for (int i = 0; i <n; i++)
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
	cout << "程序1.1耗费的时间是：" << time*10000;
	return 0;
}
//在这种算法中，对矩阵是按照列来读取的，由于访问数组元素时，CPU不会每次只从内存中读取一个元素，而是读取一个区域的元素。假设二维数组的大小为（10 x 10），访问第一个元素时，CPU也会读取它的相邻元素，因为这个数组比较小，CPU一次就可以把所有元素缓存，因此无论是按行访问数组还是按列访问数组，CPU访问主存的数量都相同。随着数组元素越来越多，CPU缓存一次只能读取数组不到一行的数据，因此按列访问元素时每访问一个元素都要访问内存，因此速度就会慢很多。这种算法无疑不好


//循环展开算法
#include<iostream>
#include<windows.h>
using namespace std;
const long long int n=256;
int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;

	long long int arry[n];
	for (int i = 0; i < n; i++)
	{
		arry[i] =i%10;
	}
	long long int sum1=0;
	long long int sum2=0;
	long long int sum=0;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	int i=0;
	for (i = 0;i <n-6; i+=6)
	{
		sum1 += arry[i]+arry[i+1]+arry[i+2];
		sum2+=arry[i+3]+arry[i+4]+arry[i+5];
	}
	sum=sum1+sum2;
	for(;i<n;i++)
    {
        sum+=arry[i];
    }
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout <<n<<"个数相加结果为：" << sum << endl;
	cout << "程序2.3耗费的时间是：" << time*100;
	return 0;
}


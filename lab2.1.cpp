//����ۼӵ�ƽ���㷨
#include<iostream>
#include<windows.h>
using namespace std;
const long long int n=131072;
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
	long long int total=0;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	for (int i = 0;i <n; i++)
	{
		total += arry[i];
	}
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout <<n<<"������ӽ��Ϊ��" << total << endl;
	cout << "����2.1�ķѵ�ʱ���ǣ�" << time*100;
	return 0;
}
//����ʽ�㷨�ٶ���Խ���

//������Թ�Լ
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
	long long int sum1=0;
	long long int sum2=0;
	long long int sum=0;
    QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	for(int i=0;i<n;i+=2)
    {
        sum1+=arry[i];
        sum2+=arry[i+1];
    }
    sum=sum1+sum2;
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout <<n<<"������ӽ��Ϊ��" << sum<<endl;
	cout << "����2.2�ķѵ�ʱ���ǣ�" << time * 100;
	return 0;
}
//�����������ԭ�����˵������ӣ�һ����ۼ���ͣ��������

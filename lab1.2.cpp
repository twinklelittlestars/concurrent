//cache�Ż��㷨
#include<iostream>
#include<windows.h>
using namespace std;
const long long int n=10;
int main()
{
    cout<<"����Ĺ�ģ��"<<n<<endl;
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
	cout << "�����ÿһ����̶������ĳ˻��ǣ�";
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << "����1.2�ķѵ�ʱ���ǣ�" << time*10000;
	return 0;
}
//����cache���Ż��㷨���ı䰴�з��ʵ�ƽ���㷨����Ϊ���з��ʣ���֤ÿ��Ԫ��ֻ������һ�Σ����ٶ�ȡʱ��

//���з���Ԫ�ص�ƽ���㷨
#include<iostream>
#include<windows.h>
const long long int n=10;
using namespace std;
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
	cout << "�����ÿһ����̶������ĳ˻��ǣ�";
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << "����1.1�ķѵ�ʱ���ǣ�" << time*10000;
	return 0;
}
//�������㷨�У��Ծ����ǰ���������ȡ�ģ����ڷ�������Ԫ��ʱ��CPU����ÿ��ֻ���ڴ��ж�ȡһ��Ԫ�أ����Ƕ�ȡһ�������Ԫ�ء������ά����Ĵ�СΪ��10 x 10�������ʵ�һ��Ԫ��ʱ��CPUҲ���ȡ��������Ԫ�أ���Ϊ�������Ƚ�С��CPUһ�ξͿ��԰�����Ԫ�ػ��棬��������ǰ��з������黹�ǰ��з������飬CPU�����������������ͬ����������Ԫ��Խ��Խ�࣬CPU����һ��ֻ�ܶ�ȡ���鲻��һ�е����ݣ���˰��з���Ԫ��ʱÿ����һ��Ԫ�ض�Ҫ�����ڴ棬����ٶȾͻ����ܶࡣ�����㷨���ɲ���


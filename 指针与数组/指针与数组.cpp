#include<iostream>
using namespace std;

int main()
{
	int arr[5] = {1,2,3,4,5};
	int* p = NULL;
	p = arr;
	cout << "����arr������Ԫ�أ�" << endl;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		cout << arr[i]<<" ";
	cout << endl;
	cout << "����arr�еĵ��ĸ�Ԫ�أ�" << p[3] << endl;
	cout << "p=arr����pָ��arr�еĵ�һ��Ԫ�صĵ�ַ��Ϊ" << p << endl;
	cout << "��Ϊ*p��ֵΪ��" << *p << endl;
}
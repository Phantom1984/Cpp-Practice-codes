#include<iostream>
using namespace std;

int main()
{
	int arr[5] = {1,2,3,4,5};
	int* p = NULL;
	p = arr;
	cout << "数组arr的所有元素：" << endl;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		cout << arr[i]<<" ";
	cout << endl;
	cout << "数组arr中的第四个元素：" << p[3] << endl;
	cout << "p=arr代表p指向arr中的第一个元素的地址，为" << p << endl;
	cout << "因为*p的值为：" << *p << endl;
}
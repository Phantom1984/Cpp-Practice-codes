/*
��������: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

���Զ��������������Լ��Զ����������͵����ݽ��д洢(ʹ��ģ�弼��)
�������е����ݴ洢��������new��
���캯���п��Դ������������
�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ�������⣨��ֵ��������أ�
�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ�����ṩ����������
����ͨ���±�ķ�ʽ���������е�Ԫ�أ�����[]��
���Ի�ȡ�����е�ǰԪ�ظ�����������������ṩ����������
*/
#include"myArray.hpp"
//����
void printIntArray(myArray<int>& arr)
{
	for (int i = 0; i < arr.get_Size(); i++)
		cout << arr[i];
	cout << endl;
}
//�Զ�����������
class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPersonArray(myArray<Person>& arr)//�������Person��ʵ�ֺ��棬���򱨴�
{
	for (int i = 0; i < arr.get_Size(); i++)
		cout << "������" << arr[i].m_Name << " " << "���䣺" << arr[i].m_Age << endl;
}

int main()
{
	myArray<int>arr(5);
	arr.push_Back(1);
	arr.push_Back(3);
	arr.push_Back(5);
	arr.push_Back(7);
	arr.push_Back(9);
	printIntArray(arr);
	arr[2] = 2;
	cout << arr[2];
}

//void test01()
//{
//	myArray<int>arr1(5);
//	for (int i = 0; i < 5; i++)
//	{
//		//����β�巨�������в�������
//		arr1.push_Back(i);
//	}
//	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
//
//	printIntArray(arr1);
//	cout << "array1�Ĵ�С��" << arr1.get_Size() << endl;
//	cout << "array1��������" << arr1.get_Capacity() << endl;
//	cout << "--------------------------" << endl;
//
//	myArray<int>arr2 = arr1;
//	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
//	printIntArray(arr2);
//
//	//βɾ
//	arr2.pop_Back();
//	cout << "arr2βɾ��:" << endl;
//	printIntArray(arr2);
//	cout << "array2�Ĵ�С��" << arr2.get_Size() << endl;
//	cout << "array2��������" << arr2.get_Capacity() << endl;
//}
//
//void test02()
//{
//	myArray<Person>arr(10);
//
//	Person p1("�����", 100);
//	Person p2("����", 20);
//	Person p3("槼�", 18);
//	Person p4("���Ѿ�", 15);
//	Person p5("����", 24);
//
//	//�����ݲ��뵽������
//	arr.push_Back(p1);
//	arr.push_Back(p2);
//	arr.push_Back(p3);
//	arr.push_Back(p4);
//	arr.push_Back(p5);
//	//arr[3] = p2;
//	//cout<<arr[0].m_Name;
//	//��ӡ����
//	printPersonArray(arr);
//}

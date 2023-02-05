#pragma once
#include"startup.h"
/*new�ļ򵥽��ܣ�
1. new() �����������͵�һ����С���ڴ�ռ�,���������е�ֵ����ʼ���������;
2. new[] �����������͵�n����С���ڴ�ռ�,����Ĭ�Ϲ��캯������ʼ����Щ����;
*/
template<class T>
class myArray
{
public:
	myArray(int capacity)//��ʼ������������
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_pAddress =new T[this->m_Capacity];//����֮ǰд����this->m_pAddress=NULL;�൱��û�п��٣��϶�����
	}
	myArray(const myArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr->m_Capacity];//���(�����c++��new[]��new()�Ľ��ܣ��ڱ���Ŀ��)
												   /*�����T��Ϊ�����򿪱���m_Capacity�������С���ڴ�ռ䣬
												   ��������Ϊ�¿��ٿռ��е�Ԫ�أ���m_pAddressָ��*/
		for (int i = 0; i < this->m_Size; i++)    //�����ݴ���
			this->m_pAddress[i] = arr.m_pAddress[i];
	}
	//operator=��ֹǳ�������� a = b = c,
	//������myArray������T����Ϊ���=ֻ��myArray�������أ����������е���������
	myArray& operator=(const myArray &arr)/*1.���������Ǹ�const��Ϊ�˲���ԭ���Ķ����޸ģ��������������ñ����˶�ʵ�εĿ��������Ч��
                                            2.��������const��׺��ʾ�˺������޸����Ա����������ں������޸�������뱨��*/
	{
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;//��ֹҰָ��
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr->m_Capacity];//������T������myArray����ΪmyArray��һ�������������������Ԫ����T�����T������int�ͣ���������
		for (int i = 0; i < this->m_Size; i++)//�����ݴ���
			this->m_pAddress[i] = arr.m_pAddress[i];//��������arr[i]����Ϊarr��myArray��Ķ������ݴ洢��*m_pAddress�У�ͬʱ����������T��������
		return *this;                         //����ʵ�����Ķ�����Ϊreturn this�򷵻ص��ǵ�ַ����Ϊ������ǰ������ ����& ���š�
	}
	//����[]�������±�
	//������T������myArray����Ϊ���Ƕ�����������������κ��������ͣ�������Ҫ�õ�ģ��
	T& operator[](int index)
	{
		return this->m_pAddress[index];
	}
	//β�巨��������ĩβ��������
	void push_Back(const T& val)//const���κ�����������ֹģ���Ӧ�����������е����ݱ��޸ģ������ڸ�ֵ(��������)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����������" << endl;
			return;
		}
		this->m_pAddress[this->m_Size] = val;
		this->m_Size++;//����ȼ�������������
	}
	//βɾ����ɾ������ĩβ������
	void pop_Back()
	{
		if (this->m_Size != 0)
			this->m_Size--;
		else
			return;
	}
	//��ȡ��ǰ���������
	int get_Capacity()
	{
		return this->m_Capacity;
	}
	//��ȡ��ǰ�����Ԫ�ظ���
	int get_Size()
	{
		return this->m_Size;
	}
	~myArray()
	{
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;//��ֹҰָ��
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:            //˽��Ȩ�޵����ݿ���ͨ�������ӿں������и�ֵ�Ȳ���
	T* m_pAddress;  //ָ��ָ��������ٵ���ʵ����
	int m_Size;     //�����С
	int m_Capacity;  //��������
};

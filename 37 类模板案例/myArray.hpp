#pragma once
#include"startup.h"
/*new的简单介绍：
1. new() 分配这种类型的一个大小的内存空间,并以括号中的值来初始化这个变量;
2. new[] 分配这种类型的n个大小的内存空间,并用默认构造函数来初始化这些变量;
*/
template<class T>
class myArray
{
public:
	myArray(int capacity)//初始定义数组容量
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_pAddress =new T[this->m_Capacity];//这里之前写成了this->m_pAddress=NULL;相当于没有开辟，肯定报错！
	}
	myArray(const myArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr->m_Capacity];//深拷贝(详情见c++中new[]和new()的介绍，在本项目中)
												   /*这里的T若为对象，则开辟了m_Capacity个该类大小的内存空间，
												   对象则作为新开辟空间中的元素，被m_pAddress指向*/
		for (int i = 0; i < this->m_Size; i++)    //将数据传递
			this->m_pAddress[i] = arr.m_pAddress[i];
	}
	//operator=防止浅拷贝问题 a = b = c,
	//这里是myArray而不是T是因为这个=只对myArray进行重载，而不是所有的数据类型
	myArray& operator=(const myArray &arr)/*1.参数里面那个const是为了不对原来的对象修改，另外这里用引用避免了对实参的拷贝，提高效率
                                            2.函数加上const后缀表示此函数不修改类成员变量，如果在函数里修改了则编译报错*/
	{
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;//防止野指针
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr->m_Capacity];//这里用T而不是myArray是因为myArray是一个新容器，而容器里的元素是T，这个T可以是int型，甚至对象
		for (int i = 0; i < this->m_Size; i++)//将数据传递
			this->m_pAddress[i] = arr.m_pAddress[i];//不可以是arr[i]，因为arr是myArray类的对象，数据存储在*m_pAddress中，同时该数据属于T数据类型
		return *this;                         //返回实例化的对象，若为return this则返回的是地址，因为我们在前面用了 引用& 符号。
	}
	//重载[]，访问下标
	//这里是T而不是myArray是因为我们定义的这个数组可以是任何数据类型，所以需要用到模板
	T& operator[](int index)
	{
		return this->m_pAddress[index];
	}
	//尾插法，在数组末尾插入数据
	void push_Back(const T& val)//const修饰函数参数，防止模板对应的数据类型中的数据被修改，多用于赋值(保护作用)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "容量已满！" << endl;
			return;
		}
		this->m_pAddress[this->m_Size] = val;
		this->m_Size++;//如果先加容量会怎样？
	}
	//尾删法，删除数组末尾的数据
	void pop_Back()
	{
		if (this->m_Size != 0)
			this->m_Size--;
		else
			return;
	}
	//获取当前数组的容量
	int get_Capacity()
	{
		return this->m_Capacity;
	}
	//获取当前数组的元素个数
	int get_Size()
	{
		return this->m_Size;
	}
	~myArray()
	{
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;//防止野指针
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:            //私有权限的数据可以通过公共接口函数进行赋值等操作
	T* m_pAddress;  //指针指向堆区开辟的真实数组
	int m_Size;     //数组大小
	int m_Capacity;  //数组容量
};

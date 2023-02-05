/*
* ��������
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

* ʵ�ֲ���
1.��������ѡ�֣��ŵ�vector��
2.����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
3.sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
4.deque��������һ�飬�ۼ��ܷ�
5.��ȡƽ����
*/

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>
#include<iomanip>
#include<ctime>
using namespace std;

class Person
{
public:
	Person(string name, float score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	float m_Score;
};

void printPerson(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
		cout << (*it).m_Name << " ";
	cout << endl;
}

void printPersonScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
		cout << (*it).m_Score << " ";
	cout << endl;
}

void createPerson(vector<Person>&v)//����ѡ����
{
	string nameSerial = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Person p("ѡ��", 0);//��ʼ��ѡ��
		p.m_Name += nameSerial[i];
		v.push_back(p);//��ѡ�ִ����vector������
	}
}

void setScore(vector<Person>& v)
{
	//��ÿһ��ѡ�ִ�֣��ȴ�vector��ȡѡ��
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i=0;i<10;i++)//��ʮ������
		{
			(*it).m_Score = rand() % 40 + 60;//60~100��
			d.push_back((*it).m_Score);
		}
		sort(d.begin(),d.end());
		cout << (*it).m_Name << "�ĵ÷֣�";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
			cout << (*dit) << " ";
		cout << endl;
		cout << "ȥ��һ����߷֣�" << d[9] << endl;
		cout << "ȥ��һ����ͷ֣�" << d[0] << endl;
		d.pop_front(); d.pop_back();//ȥ����߷ֺ���ͷ�
		float avg=0, sum=0;
		for (int i = 0; i < 8; i++)
		{
			sum += d[i];
			avg = sum / 8;
		}
		//cout << "���÷֣�" << avg << "�֣�" << endl;
		cout << "���÷֣�" << setiosflags(ios::fixed) << setprecision(1) << avg << "�֣�" << endl;
		cout<<"/*************************************************/" << endl;
		(*it).m_Score = avg;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Person>v; deque<int>d;
	createPerson(v);
	setScore(v);
	//printPersonScore(v);
	//�����ΰ���������
	/*
	����������һ�������У�����
	��forѭ����if�����жϣ����ƥ�䣬����ȡ����ʤѡ�ֵ�����
	*/
	vector<float>v_score;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		v_score.push_back((*it).m_Score);
	}
	//cout << v_score.size();
	/*for (vector<float>::iterator it = v_score.begin(); it != v_score.end(); it++)
		cout << (*it)<< " ";
	cout << endl;*/
	sort(v_score.begin(), v_score.end());
	//cout << v_score.back();//���ֵ
	string winner;//��ʤ������
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
		if ((*it).m_Score == v_score.back())
			winner = (*it).m_Name;
	cout << "���α����Ļ�ʤ���ǣ�" << winner << "  �÷�Ϊ��" << v_score.back() << endl;
}
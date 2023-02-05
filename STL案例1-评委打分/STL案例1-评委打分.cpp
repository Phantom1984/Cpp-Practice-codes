/*
* 案例描述
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

* 实现步骤
1.创建五名选手，放到vector中
2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3.sort算法对deque容器中分数排序，去除最高和最低分
4.deque容器遍历一遍，累加总分
5.获取平均分
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

void createPerson(vector<Person>&v)//创建选手名
{
	string nameSerial = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Person p("选手", 0);//初始化选手
		p.m_Name += nameSerial[i];
		v.push_back(p);//将选手存放至vector容器中
	}
}

void setScore(vector<Person>& v)
{
	//对每一个选手打分，先从vector中取选手
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i=0;i<10;i++)//打十个分数
		{
			(*it).m_Score = rand() % 40 + 60;//60~100分
			d.push_back((*it).m_Score);
		}
		sort(d.begin(),d.end());
		cout << (*it).m_Name << "的得分：";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
			cout << (*dit) << " ";
		cout << endl;
		cout << "去掉一个最高分：" << d[9] << endl;
		cout << "去掉一个最低分：" << d[0] << endl;
		d.pop_front(); d.pop_back();//去掉最高分和最低分
		float avg=0, sum=0;
		for (int i = 0; i < 8; i++)
		{
			sum += d[i];
			avg = sum / 8;
		}
		//cout << "最后得分：" << avg << "分！" << endl;
		cout << "最后得分：" << setiosflags(ios::fixed) << setprecision(1) << avg << "分！" << endl;
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
	//将名次按分数排序
	/*
	将分数存在一个容器中，排序
	用for循环和if条件判断，如果匹配，则提取出获胜选手的名字
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
	//cout << v_score.back();//最大值
	string winner;//获胜者姓名
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
		if ((*it).m_Score == v_score.back())
			winner = (*it).m_Name;
	cout << "本次比赛的获胜者是：" << winner << "  得分为：" << v_score.back() << endl;
}
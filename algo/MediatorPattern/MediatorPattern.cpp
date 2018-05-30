// MediatorPattern.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Mediator;
class Colleague
{
protected:
	Mediator *mediator; //�н�  
public:
	virtual void sendMsg(string message) = 0;   //���н鷢����Ϣ  
	virtual void getMsg(string message) = 0;   //���н��ȡ��Ϣ  
};

class Mediator
{
public:
public:
	virtual void opertion(string msg) = 0;
	void addColleague(Colleague *c) {
		this->colleagues.push_back(c);
	}
protected:
	list<Colleague*> colleagues;
};

//�ⷿ��
class Renter : public Colleague
{
public:
	Renter(Mediator *mediator){
		this->mediator = mediator;
	};
	void sendMsg(string message) { 
		mediator->opertion(message); 
	}
	void getMsg(string message) { 
		cout << "�ⷿ���յ���Ϣ -> " << message; 
	}
};
//����  
class Landlord : public Colleague
{
public:
	Landlord(Mediator *mediator) {
		this->mediator = mediator;
	};
	void sendMsg(string message) { 
		mediator->opertion(message); 
	}
	void getMsg(string message) { 
		cout << "�����յ���Ϣ -> " << message; 
	}
};

//�����н�  
class HouseMediator :public Mediator {
	void opertion(string msg) {
		list<Colleague*>::iterator iter = colleagues.begin();
		for (; iter != colleagues.end(); iter++) {
			(*iter)->getMsg(msg);
		}
	}
};

int main()
{
	Mediator *mediator = new HouseMediator();
	Colleague *person1 = new Renter(mediator);    //�ⷿ��  
	Colleague *person2 = new Landlord(mediator);  //����  
	mediator->addColleague(person1);
	mediator->addColleague(person2);
	person1->sendMsg("�������Ͼ�·�������׷��ӣ��۸�800Ԫһ����\n");
	person2->sendMsg("���ⷿ�ӣ��Ͼ�·100�ţ�70ƽ�ף�1000Ԫһ����\n");
	delete person1; 
	delete person2; 
	delete mediator;

    return 0;
}

// MediatorPattern.cpp : 定义控制台应用程序的入口点。
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
	Mediator *mediator; //中介  
public:
	virtual void sendMsg(string message) = 0;   //向中介发送信息  
	virtual void getMsg(string message) = 0;   //从中介获取信息  
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

//租房者
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
		cout << "租房者收到信息 -> " << message; 
	}
};
//房东  
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
		cout << "房东收到信息 -> " << message; 
	}
};

//房屋中介  
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
	Colleague *person1 = new Renter(mediator);    //租房者  
	Colleague *person2 = new Landlord(mediator);  //房东  
	mediator->addColleague(person1);
	mediator->addColleague(person2);
	person1->sendMsg("我想在南京路附近租套房子，价格800元一个月\n");
	person2->sendMsg("出租房子：南京路100号，70平米，1000元一个月\n");
	delete person1; 
	delete person2; 
	delete mediator;

    return 0;
}

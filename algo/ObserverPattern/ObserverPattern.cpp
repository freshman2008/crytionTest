// ObserverPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<list>

using namespace std;
class Subject;

class Observer {
public:
	virtual void notify(int state) = 0;
public:
	Subject *subject;//也可以在notify()接口定义参数Subject *subject
};

class ObserverA : public Observer {
public:
	ObserverA(Subject *subject) { //也可以无惨构造函数，然后subject对象调用addObserver()接口添加被观察者
		this->subject = subject;
		//this->subject->addObserver(this);
	}
	void notify(int state) {
		cout << "ObserverA is notified, state : " << state << endl;
	}
};

class ObserverB : public Observer {
public:
	ObserverB(Subject *subject) { //也可以无惨构造函数，然后subject对象调用addObserver()接口添加被观察者
		this->subject = subject;
		//this->subject->addObserver(this);
	}
	void notify(int state) {
		cout << "ObserverB is notified, state : " << state << endl;
	}
};

class Subject {
public:
	void addObserver(Observer *observer) {
		obs.push_back(observer);
	}

	void deleteObserver(Observer *observer) {
		obs.remove(observer);
	}

	virtual void notifyObservers() = 0;

	int getState() {
		return state;
	}

	void setState(int state) {
		this->state = state;
		notifyObservers();
	}
protected:
	int state;
	list<Observer*> obs;
};

class SubjectA : public Subject {
public:
	void notifyObservers() {
		list<Observer*>::iterator itor;  //定义迭代器 
		itor = obs.begin();
		while (itor != obs.end()) {
			(*itor++)->notify(this->state);
		}
	}
};

int main()
{
	Subject *sub = new SubjectA();
	sub->setState(1);

	ObserverA *obsa = new ObserverA(sub);
	ObserverB *obsb = new ObserverB(sub);
	sub->addObserver(obsa);
	sub->addObserver(obsb);
	sub->setState(1);
	int state = obsa->subject->getState();
	sub->setState(2);
	state = obsa->subject->getState();
	system("pause");
    return 0;
}


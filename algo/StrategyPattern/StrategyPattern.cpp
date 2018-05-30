// StrategyPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class TravelStrategy {
public:
	virtual void travel() {}
};

class AirplaneStrategy: public TravelStrategy {
public:
	void travel() {
		cout << "Go to travel by airplane" << endl;
	}
};

class TrainStrategy: public TravelStrategy {
public:
	void travel() {
		cout << "Go to travel by train" << endl;
	}
};

class BicycleStrategy: public TravelStrategy {
public:
	void travel() {
		cout << "Go to travel by bicycle" << endl;
	}
};

class TravelAgency {
public:
	TravelAgency(TravelStrategy *st):strategy(st) {
	}

	void setStrategy(TravelStrategy *st) {
		strategy = st;
	}
	void GoTravel() {
		strategy->travel();
	}

private:
	TravelStrategy *strategy;
};

int main()
{
	TravelAgency agency(new AirplaneStrategy());
	agency.GoTravel();
	agency.setStrategy(new TrainStrategy());
	agency.GoTravel();
	agency.setStrategy(new BicycleStrategy());
	agency.GoTravel();

	getchar();
    return 0;
}


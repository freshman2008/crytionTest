// statePattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class State {
public:
	virtual void action() = 0;
};

class State1 : public State {
public:
	void action() {
		cout << "switch on" << endl;
	}

};

class State2 : public State {
public:
	void action() {
		cout << "switch off" << endl;
	}

};

class Context {
public:
	Context(State* state) : mState(state) {

	}
	void action() {
		this->mState->action();
	}

	void setState(State *state) {
		this->mState = state;
	}

	State* getState() {
		return this->mState;
	}
private:
	State *mState;
};

int main()
{
	State *state = new State1();
	Context context(state);
	context.action();

	state = new State2();
	context.setState(state);
	context.action();

	state = new State1();
	context.setState(state);
	context.action();

	getchar();
    return 0;
}


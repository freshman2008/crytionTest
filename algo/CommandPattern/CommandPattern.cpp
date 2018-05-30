// CommandPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

class Receiver {
public:
	void powerOn() {
		cout << "power on" << endl;
	}

	void powerOff() {
		cout << "power off" << endl;
	}
};

class CommandPowerOn : public Command {
public:
	CommandPowerOn(Receiver* recv) {
		this->recv = recv;
	}

	void execute() {
		recv->powerOn();
	}
private:
	Receiver* recv;
};

class CommandPowerOff : public Command {
public:
	CommandPowerOff(Receiver* recv) {
		this->recv = recv;
	}

	void execute() {
		recv->powerOff();
	}
private:
	Receiver* recv;
};

class Invoker {
public:
	void runCommand(Command *cmd) {
		cmd->execute();
	}
};

class Invoker2 {
public:
	void addCommand(Command *cmd) {
		cmds.push_back(cmd);
	}
	/*
	void removeCommand(int id) {
	}
	*/
	void runCommand() {
		vector<Command*>::iterator iter;
		iter = cmds.begin();
		while (iter != cmds.end()) {
			(*iter++)->execute();
		}
	}
private:
	vector<Command*> cmds;
};

int main()
{
	Receiver* receiver = new Receiver();
	Invoker* invoker = new Invoker();

	Command* powerOnCmd = new CommandPowerOn(receiver);
	Command* powerOffCmd = new CommandPowerOff(receiver);

	invoker->runCommand(powerOnCmd);
	invoker->runCommand(powerOffCmd);

	Invoker2* invoker2 = new Invoker2();
	invoker2->addCommand(powerOnCmd);
	invoker2->addCommand(powerOffCmd);

	invoker2->runCommand();

	system("pause");
    return 0;
}


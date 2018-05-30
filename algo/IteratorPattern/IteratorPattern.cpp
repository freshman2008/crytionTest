// IteratorPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Employee {
public:
	Employee() {
	}
	Employee(string name, int age, string address) : mName(name), mAge(age), mAddress(address) {
	}
	void setName(string name) {
		this->mName = name;
	}
	string getName() {
		return this->mName;
	}
	void setAge(int age) {
		this->mAge = age;
	}
	int getAge() {
		return this->mAge;
	}
	void setAddress(string address) {
		this->mAddress = address;
	}
	string getAddress() {
		return this->mAddress;
	}
private:
	string mName;
	int mAge;
	string mAddress;
};

class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual Employee next() = 0;
};

class Container {
public:
	virtual int size() = 0;
	virtual void add(const Employee& obj) = 0;
	virtual Employee get(int idx) = 0;
	virtual Iterator* getIterator() = 0;
};

class MyIterator : public Iterator {
public:
	MyIterator(Container *container):mContainer(container), index(0) {
	}

	bool hasNext() {
		if (index > mContainer->size()-1) {
			return false;
		}
		else {
			return true;
		}
	}

	Employee next() {
		Employee ret = mContainer->get(index);
		index++;
		return ret;
	}
private:
	Container* mContainer;
	int index;
};


class ContainerA : public Container {
public:
	ContainerA() : mIterator(NULL) {
		objs.clear();
	}

	int size() {
		return objs.size();
	}

	Iterator* getIterator() {
		if (mIterator == NULL) {
			mIterator = new MyIterator(this);
		}
		return mIterator;
	}

	void add(const Employee& obj) {
		objs.push_back(obj);
	}

	Employee get(int idx) {
		Employee ret;
		if (idx < size()) {
			ret = objs[idx];
		}
		return ret;
	}
private:
	vector<Employee> objs;
	Iterator* mIterator;
};

int main()
{
	ContainerA *ca = new ContainerA();
	Employee ep1("Liu Bei", 40, "Beiing");
	Employee ep2("Guan Yu", 38, "Shang Hai");
	Employee ep3("Zhang Fei", 36, "Nan jing");
	ca->add(ep1);
	ca->add(ep2);
	ca->add(ep3);
	Iterator *iter = ca->getIterator();
	if (NULL != iter) {
		while (iter->hasNext())	{
			Employee& dp = iter->next();
			cout << dp.getName() << "," << dp.getAge() << "," << dp.getAddress() << "," << endl;
		}
	}

    return 0;
}


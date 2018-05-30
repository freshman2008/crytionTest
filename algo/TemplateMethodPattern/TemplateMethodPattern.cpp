// TemplateMethodPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class FileAnalyzer {
public:
	virtual void readFileData() = 0;
	virtual void decryptData() = 0;
	virtual void analyzeData() = 0;
	/*void tearDown() {
		cout << "clean data" << endl;
    }*/
	void getData() {
		readFileData();
		decryptData();
		analyzeData();
		//tearDown(); 在抽象类的模板方法中也可以调用一些具体操作
	}
};

class txtFileAnalyzer : public FileAnalyzer {
	void readFileData() {
		cout << "Read txt file" << endl;
	}

	void decryptData() {
		cout << "Decrypt txt file data" << endl;
	}

	void analyzeData() {
		cout << "Analyze txt file data" << endl;
	}
};

class jsonFileAnalyzer : public FileAnalyzer {
	void readFileData() {
		cout << "Read json file" << endl;
	}

	void decryptData() {
		cout << "Decrypt json file data" << endl;
	}

	void analyzeData() {
		cout << "Analyze json file data" << endl;
	}
};

int main()
{
	FileAnalyzer *analyzer = new txtFileAnalyzer();
	analyzer->getData();

	analyzer = new jsonFileAnalyzer();
	analyzer->getData();

	system("pause");
    return 0;
}


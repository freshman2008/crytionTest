// TemplateMethodPattern.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//tearDown(); �ڳ������ģ�巽����Ҳ���Ե���һЩ�������
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


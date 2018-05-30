// EncryptDecryptTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Base64Util.h"
#include "CryptoUtil.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
	/* base64 encode decode test */
	string data = "This is just a test string";
	char* encryptedData;
	cout << "data: " << data << endl;
	cout << "data len: " << data.size() << endl;
	encryptedData = Base64Encode((char*)data.c_str(), data.size());
	cout << "encryptedData: " << encryptedData << endl;
	cout << "encryptedDataLen: " << strlen(encryptedData) << endl;
	char *decryptedData;
	decryptedData = Base64Decode((char*)encryptedData, strlen(encryptedData));
	cout << "decryptedData: " << decryptedData << endl;
	cout << "decryptedDataLen: " << strlen(decryptedData) << endl;
	cout << data << endl;
	cout << "--------------------------------------------" << endl;

	cout << "data: " << data << endl;
	cout << "data len: " << data.size() << endl;
	string encryptedStr = Encode(string(data), data.size());
	cout << "encryptedStr: " << encryptedStr << endl;
	cout << "encryptedStrLen: " << encryptedStr.length() << endl;
	string decryptedStr = Decode(encryptedStr, encryptedStr.length());
	cout << "decryptedStr: " << decryptedStr << endl;
	cout << "decryptedStrLen: " << decryptedStr.length() << endl;
	cout << data << endl;
	cout << "--------------------------------------------" << endl;

	cout << "data: " << data << endl;
	cout << "data len: " << data.size() << endl;
	encryptedStr = base64_encode(string(data));
	cout << "encryptedStr: " << encryptedStr << endl;
	cout << "encryptedStrLen: " << encryptedStr.length() << endl;
	decryptedStr = base64_decode(encryptedStr);
	cout << "decryptedStr: " << decryptedStr << endl;
	cout << "decryptedStrLen: " << decryptedStr.length() << endl;
	cout << data << endl;
	cout << "--------------------------------------------" << endl;


	system("pause");
    return 0;
}


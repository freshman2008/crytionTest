#pragma once

#include <string>
using namespace std;

string Encode(const string &in, int DataByte);
string Decode(const string &in, int DataByte);

string base64_encode(const string &bindata);
string base64_decode(const string &ascdata);
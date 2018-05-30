#pragma once

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/bio.h>

char* Base64Encode(const char * input, int length, bool with_new_line = false);
char* Base64Decode(const char * input, int length, bool with_new_line = false);
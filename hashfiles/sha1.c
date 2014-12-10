#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha1.h"

unsigned char *sha1_hash(unsigned char user_input[]) 
{
	static unsigned char output_buf[20];

	SHA1(user_input, strlen((const char*)user_input), output_buf);
	
	return output_buf;
}

char* sha1_make(unsigned char* hash_buffer) {

	unsigned char* sha1_res = sha1_hash(hash_buffer);

	const int MAX = 129;
	char *Buffer = malloc(MAX);
	int length=0, i;
	
	for (i=0;i<20;i++)
	{
		length += snprintf(Buffer+length, MAX-length, "%02x", sha1_res[i]);	
	}

	return Buffer;
}




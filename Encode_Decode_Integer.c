//The goal is to save memory usage by encoding a int32 or int64 integer to char array type.


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
/*
	For every byte, 7bits for storage data , 8th bit is the flag whether the char * has finished 
 */
char * EncodeVarInt32(char *dst, uint32_t v){
	unsigned char* ptr = reinterpret_cast<unsigned char*>(dst);
	static const int B = 128;
	if( v < (1<<7)){ 
		*(ptr++) = v;
	}
	else if(v < (1<<14)){
		*(ptr++) = v | B;
		*(ptr++) = v >> 7;
	}
	else if(v < (1 << 21)){
		*(ptr++) = v | B;
		*(ptr++) = (v >> 7) | B;
		*(ptr++) = v >> 14;
	}
	else if(v < (1 << 28)){
		*(ptr++) = v | B;
		*(ptr++) = (v >> 7) | B;
		*(ptr++) = (v >> 14) | B;
		*(ptr++) = v >> 21;
	}
	else{
		*(ptr++) = v | B;
		*(ptr++) = (v >> 7) | B;
		*(ptr++) = (v >> 14) | B;
		*(ptr++) = (v >> 21) | B;
		*(ptr++) = v >> 28;
	}
  return reinterpret_cast<char*>(ptr);
}
char  * EncodeVarInt64(char *dst, uint32_t v){
	unsigned char* ptr = reinterpret_cast<unsigned char*>(dst);
	static const int B = 128;
	while(v >= B){
		*(ptr++) =(v&(B-1))| B;
		v = v >> 7;
	}	
	*(ptr++) = static_cast<unsigned char>(v);	
    return reinterpret_cast<char*>(ptr);
}



const char * DecodeVarInt32(const char * p, uint32_t * v){
	uint32_t result = 0;
	static const int B =128;
	for(uint32_t shift = 0; shift <=28; shift += 7){
		uint32_t byte = *(reinterpret_cast<const unsigned char*>(p));
		p++;
		if(byte & B){
			result |= (byte & (B-1)) << shift;
		}
		else{
			result |= byte << shift;
			*v = result;
			return p;
		}
	}
	return NULL;
}


const char * DecodeVarInt64(const char * p, uint32_t * v){
	uint32_t result = 0;
	static const int B =128;
	for(uint32_t shift = 0; shift <=63; shift += 7){
		uint32_t byte = *(reinterpret_cast<const unsigned char*>(p));
		p++;
		if(byte & B){
			result |= (byte & (B-1)) << shift;
		}
		else{
			result |= byte << shift;
			*v = result;
			return p;
		}
	}
	return NULL;
}



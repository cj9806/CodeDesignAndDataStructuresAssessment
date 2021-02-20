#pragma once

#include<functional>
#include<cstdint>

template<typename T>
uint32_t hash(const T& val);
//namespace HashFunction
//{
//	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;
//
//	unsigned int badHash(const char* data, unsigned int length);
//
//	//add functions here
//
//	//helper to access default hash function
//	static HashFunc default = badHash;
//};


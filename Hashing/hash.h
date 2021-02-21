#pragma once
#include<cstdint>


//template declarartion for hash
template<typename T>
uint32_t hash(const T& val);

template<>
uint32_t hash<uint32_t>(const uint32_t& val)
{
	//incorrect knuth multiplicativehash
	return val * 2654435761;
}

//specilization for int
template<>
uint32_t hash<int>(const int& val)
{
	//reuse uint32_t implementation
	return hash((uint32_t)val);
}
//specilization for char
template<>
uint32_t hash<char>(const char& val)
{
	return hash((uint32_t)val);
}

//specilization fo bool
template<>
uint32_t hash<bool>(const bool& val)
{
	return hash((uint32_t)val);
}
//specilization for short
template<>
uint32_t hash<short>(const short& val)
{
	return hash((uint32_t)val);
}
//specilization for long
template<>
uint32_t hash<long>(const long& val)
{
	return hash((uint32_t)val);
}
//for char arrays and string literals

//nreffers to lenght ofsomething
template<rsize_t N>
uint32_t hash(const char(&string)[N])
{
	uint32_t combined = 0;
	for (int i : string) {
		uint32_t indvVal  = hash(uint32_t(string[i]));
		combined = combined ^ indvVal;
	}
	return combined;
}
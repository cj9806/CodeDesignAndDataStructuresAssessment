#include "hash.h"

#include <cstdint>
#include<iostream>
using std::cout;
using std::endl;


int main() {
	//variation for uint 32
	uint32_t secondHash = hash<uint32_t>(15612);

	//variation for int
	uint32_t intHash = hash<int>(78879);

	//vatiation for char
	const char myChar = 'a';
	uint32_t charhash = hash<char>(myChar);
	//variation for bool
	bool myBool = true;
	uint32_t boolHash = hash<bool>(myBool);
	//variation for short
	short myShort = 15;
	uint32_t shortHash = hash<short>(myShort);
	//varitation for long
	long myLong = 15621624;
	uint32_t longHash = hash<long>(myLong);
	//overload for strings/char arrays
	char name[] = "John Madden";
	uint32_t nameHash = hash(name);

	cout << "hashing of a uint_32 with a value of 15612 yeilds:"<< secondHash << endl;
	cout << "hashing of an int with a value of 78879 yeilds:" << intHash<< endl;
	cout << "hashing of a character with a value of 'a'(97) yeilds:" <<charhash<< endl;
	cout << "hashing of a boolien  with a value of true yeilds:"<<boolHash << endl;
	cout << "hashing of a shart with a value of 15 yeilds:" << shortHash << endl;
	cout << "hashing of a long  with a value of 15621624 yeilds:" << longHash << endl;
	cout << "hashing of a character array with the value of 'John Madden' yeilds:" << nameHash << endl;


	return 0;
}
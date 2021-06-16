#pragma once
#include <string>
using namespace std;
#define MaxSize 1000

struct Address {
	string name;
	int age;
	string phoneNum;
	string address;
};

struct AddressArray {
	Address address[MaxSize];
	int size = 0;
};
void ShowMenu();
void AddAddress(AddressArray * addressArr, Address addr);
Address GetAddress();
void ShowAllAddress(AddressArray addressArr);
void DeleteAddress(AddressArray * addressArr);
void ModifyAddress(AddressArray* addressArr);
void ClearAddressArr(AddressArray* addressArr);
void SearchAddressArr(AddressArray addressArr);
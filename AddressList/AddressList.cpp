#include <iostream>
using namespace std;
#include "Methods.h"
#include <string>


int main() {
	AddressArray addressArr;
	int input;
	do {
		ShowMenu();
		cout << "ÇëÊäÈëÄúµÄ²Ù×÷£º " << endl;
		cin >> input;
		switch (input) {
		case 1: {
			Address a1 = GetAddress();
			AddAddress(&addressArr, a1);
			break;
		}
		case 2:
			DeleteAddress(&addressArr);
			break;
		case 3:
			ModifyAddress(&addressArr);
			break;
		case 4:
			ClearAddressArr(&addressArr);
			break;
		case 5:
			SearchAddressArr(addressArr);
			break;
		case 6:
			ShowAllAddress(addressArr);
			break;
		}
		system("pause");
	} while (input != 0);
	system("pause");
	return 0;
}
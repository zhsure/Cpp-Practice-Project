#include "Methods.h"
#include <iostream>
#include <string>
using namespace std;



/// <summary>
/// 显示菜单
/// </summary>
void ShowMenu() {
	system("cls");
	cout << "***************************************************" << endl;
	cout << "********************1.添加联系人*******************" << endl;
	cout << "********************2.删除联系人*******************" << endl;
	cout << "********************3.修改联系人*******************" << endl;
	cout << "********************4.清空联系人*******************" << endl;
	cout << "********************5.查找联系人*******************" << endl;
	cout << "********************6.显示联系人*******************" << endl;
	cout << "********************7.退出*************************" << endl;
	cout << "***************************************************" << endl;
}

/// <summary>
/// 添加联系人
/// </summary>
/// <param name="addressArr">旧通讯录数组</param>
/// <param name="addr">要添加的联系人</param>
void AddAddress(AddressArray* addressArr, Address addr) {
	addressArr->address[addressArr->size] = addr;
	addressArr->size++;
}

/// <summary>
/// 从键盘输入获取一个新联系人
/// </summary>
/// <returns></returns>
Address GetAddress() {
	Address addr;
	cout << "请输入联系人姓名：" << endl;
	cin >> addr.name;
	cout << "请输入联系人年龄：" << endl;
	cin >> addr.age;
	cout << "请输入联系人电话号：" << endl;
	cin >> addr.phoneNum;
	cout << "请输入联系人地址：" << endl;
	cin >> addr.address;
	return addr;
}

/// <summary>
/// 显式所有联系人
/// </summary>
void ShowAllAddress(AddressArray addressArr) {
	cout << "共有" << addressArr.size << "个联系人" << endl;
	for (int i = 0; i < addressArr.size; i++)
	{
		cout << "序号：" << i + 1 << "\t姓名：" << addressArr.address[i].name
			<< "\t年龄：" << addressArr.address[i].age
			<< "\t联系方式：" << addressArr.address[i].phoneNum
			<< "\t地址：" << addressArr.address[i].address << endl;
	}
}

/// <summary>
/// 删除联系人
/// </summary>
/// <param name="addressArr"></param>
void DeleteAddress(AddressArray* addressArr) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	for (int i = addressArr->size - 1; i >= 0; i--)
	{
		if (addressArr->address[i].name == name) {
			for (int j = i; j < addressArr->size - 1; j++)
			{
				addressArr->address[j] = addressArr->address[j + 1];
			}
			addressArr->size--;
		}
	}
}

/// <summary>
/// 修改联系人
/// </summary>
/// <param name="addressArr"></param>
void ModifyAddress(AddressArray* addressArr) {
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	bool isin = false;//联系人是否在名单中
	for (int i = 0; i < addressArr->size; i++)
	{
		if (addressArr->address[i].name == name)
			isin = true;
	}
	if (!isin) {
		cout << "未找到联系人";
	}
	Address addr = GetAddress();
	for (int i = 0; i < addressArr->size; i++)
	{
		if (addressArr->address[i].name == name)
			addressArr->address[i] = addr;
	}
}

/// <summary>
/// 清空通讯录
/// </summary>
/// <param name="addressArr"></param>
void ClearAddressArr(AddressArray* addressArr) {
	addressArr->size = 0;
}

/// <summary>
/// 查找联系人
/// </summary>
/// <param name="addressArr"></param>
void SearchAddressArr(AddressArray addressArr) {
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	bool isin = false;//联系人是否在名单中
	for (int i = 0; i < addressArr.size; i++)
	{
		if (addressArr.address[i].name == name) {
			cout << "序号：" << i + 1 << "\t姓名：" << addressArr.address[i].name
				<< "\t年龄：" << addressArr.address[i].age
				<< "\t联系方式：" << addressArr.address[i].phoneNum
				<< "\t地址：" << addressArr.address[i].address << endl;
			isin = true;
		}
	}
	if (!isin) {
		cout << "未找到联系人";
	}
}
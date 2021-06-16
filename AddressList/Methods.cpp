#include "Methods.h"
#include <iostream>
#include <string>
using namespace std;



/// <summary>
/// ��ʾ�˵�
/// </summary>
void ShowMenu() {
	system("cls");
	cout << "***************************************************" << endl;
	cout << "********************1.�����ϵ��*******************" << endl;
	cout << "********************2.ɾ����ϵ��*******************" << endl;
	cout << "********************3.�޸���ϵ��*******************" << endl;
	cout << "********************4.�����ϵ��*******************" << endl;
	cout << "********************5.������ϵ��*******************" << endl;
	cout << "********************6.��ʾ��ϵ��*******************" << endl;
	cout << "********************7.�˳�*************************" << endl;
	cout << "***************************************************" << endl;
}

/// <summary>
/// �����ϵ��
/// </summary>
/// <param name="addressArr">��ͨѶ¼����</param>
/// <param name="addr">Ҫ��ӵ���ϵ��</param>
void AddAddress(AddressArray* addressArr, Address addr) {
	addressArr->address[addressArr->size] = addr;
	addressArr->size++;
}

/// <summary>
/// �Ӽ��������ȡһ������ϵ��
/// </summary>
/// <returns></returns>
Address GetAddress() {
	Address addr;
	cout << "��������ϵ��������" << endl;
	cin >> addr.name;
	cout << "��������ϵ�����䣺" << endl;
	cin >> addr.age;
	cout << "��������ϵ�˵绰�ţ�" << endl;
	cin >> addr.phoneNum;
	cout << "��������ϵ�˵�ַ��" << endl;
	cin >> addr.address;
	return addr;
}

/// <summary>
/// ��ʽ������ϵ��
/// </summary>
void ShowAllAddress(AddressArray addressArr) {
	cout << "����" << addressArr.size << "����ϵ��" << endl;
	for (int i = 0; i < addressArr.size; i++)
	{
		cout << "��ţ�" << i + 1 << "\t������" << addressArr.address[i].name
			<< "\t���䣺" << addressArr.address[i].age
			<< "\t��ϵ��ʽ��" << addressArr.address[i].phoneNum
			<< "\t��ַ��" << addressArr.address[i].address << endl;
	}
}

/// <summary>
/// ɾ����ϵ��
/// </summary>
/// <param name="addressArr"></param>
void DeleteAddress(AddressArray* addressArr) {
	cout << "������Ҫɾ������ϵ��������" << endl;
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
/// �޸���ϵ��
/// </summary>
/// <param name="addressArr"></param>
void ModifyAddress(AddressArray* addressArr) {
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	bool isin = false;//��ϵ���Ƿ���������
	for (int i = 0; i < addressArr->size; i++)
	{
		if (addressArr->address[i].name == name)
			isin = true;
	}
	if (!isin) {
		cout << "δ�ҵ���ϵ��";
	}
	Address addr = GetAddress();
	for (int i = 0; i < addressArr->size; i++)
	{
		if (addressArr->address[i].name == name)
			addressArr->address[i] = addr;
	}
}

/// <summary>
/// ���ͨѶ¼
/// </summary>
/// <param name="addressArr"></param>
void ClearAddressArr(AddressArray* addressArr) {
	addressArr->size = 0;
}

/// <summary>
/// ������ϵ��
/// </summary>
/// <param name="addressArr"></param>
void SearchAddressArr(AddressArray addressArr) {
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	bool isin = false;//��ϵ���Ƿ���������
	for (int i = 0; i < addressArr.size; i++)
	{
		if (addressArr.address[i].name == name) {
			cout << "��ţ�" << i + 1 << "\t������" << addressArr.address[i].name
				<< "\t���䣺" << addressArr.address[i].age
				<< "\t��ϵ��ʽ��" << addressArr.address[i].phoneNum
				<< "\t��ַ��" << addressArr.address[i].address << endl;
			isin = true;
		}
	}
	if (!isin) {
		cout << "δ�ҵ���ϵ��";
	}
}
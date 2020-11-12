#pragma once

#include <iostream>
#include <string>
using namespace std;

class UserType
{
public:
	// =������ �����ε�
	void operator=(UserType& _p) 
	{
		id = _p.id;
		pw = _p.pw;
		name = _p.name;
		birth = _p.birth;
		phonenum = _p.phonenum;
	}

	// ==������ �����ε�
	bool operator==(UserType& _p) 
	{
		if (this->id == _p.id)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(UserType& _p) 
	{
		if (this->id > _p.id)
			return true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(UserType& _p) 
	{
		if (this->id < _p.id)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(UserType& _p) 
	{
		if (this->id >= _p.id)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(UserType& _p)
	{
		if (this->id <= _p.id)
			return true;
		else
			return false;
	}

	// UserType ������
	UserType()
	{
		id = "";
		pw = "";
		name = "";
		birth = "";
		phonenum = "";
	}

	// UserType �Ҹ���
	~UserType() {}

	string GetId()
	{
		return id;
	}

	string GetPw()
	{
		return pw;
	}

	string GetName()
	{
		return name;
	}

	string GetBirth()
	{
		return birth;
	}

	string GetPhoneNum()
	{
		return phonenum;
	}

	void SetId(string inid)
	{
		id = inid;
	}

	void SetPw(string inpw)
	{
		pw = inpw;
	}

	void SetName(string inname)
	{
		name = inname;
	}

	void SetBirth(string inbirth)
	{
		birth = inbirth;
	}

	void SetPhoneNum(string inphonenum)
	{
		phonenum = inphonenum;
	}

	void SetRecord(string inid, string inpw, string inname, string inbirth, string inphonenum)
	{
		id = inid;
		pw = inpw;
		name = inname;
		birth = inbirth;
		phonenum = inphonenum;
	}

	void SetIdFromKB()
	{
		cout << "\t���̵� : ";
		cin >> id;
	}

	void SetPwFromKB()
	{
		cout << "\t��й�ȣ : ";
		cin >> pw;
	}

	void SetNameFromKB()
	{
		cout << "\t�̸� : ";
		cin >> name;
	}

	void SetBirthFromKB()
	{
		cout << "\t������� : ";
		cin >> birth;
	}

	void SetPhoneNumFromKB()
	{
		cout << "\t��ȭ��ȣ : ";
		cin >> phonenum;
	}

	void SetRecordFromKB()
	{
		SetIdFromKB();
		SetPwFromKB();
		SetNameFromKB();
		SetBirthFromKB();
		SetPhoneNumFromKB();
	}

private:
	string id;
	string pw;
	string name;
	string birth;
	string phonenum;
};

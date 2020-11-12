#pragma once

#include <iostream>
#include <string>
using namespace std;

class UserType
{
public:
	// =연산자 오버로딩
	void operator=(UserType& _p) 
	{
		id = _p.id;
		pw = _p.pw;
		name = _p.name;
		birth = _p.birth;
		phonenum = _p.phonenum;
	}

	// ==연산자 오버로딩
	bool operator==(UserType& _p) 
	{
		if (this->id == _p.id)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(UserType& _p) 
	{
		if (this->id > _p.id)
			return true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(UserType& _p) 
	{
		if (this->id < _p.id)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(UserType& _p) 
	{
		if (this->id >= _p.id)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(UserType& _p)
	{
		if (this->id <= _p.id)
			return true;
		else
			return false;
	}

	// UserType 생성자
	UserType()
	{
		id = "";
		pw = "";
		name = "";
		birth = "";
		phonenum = "";
	}

	// UserType 소멸자
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
		cout << "\t아이디 : ";
		cin >> id;
	}

	void SetPwFromKB()
	{
		cout << "\t비밀번호 : ";
		cin >> pw;
	}

	void SetNameFromKB()
	{
		cout << "\t이름 : ";
		cin >> name;
	}

	void SetBirthFromKB()
	{
		cout << "\t생년월일 : ";
		cin >> birth;
	}

	void SetPhoneNumFromKB()
	{
		cout << "\t전화번호 : ";
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

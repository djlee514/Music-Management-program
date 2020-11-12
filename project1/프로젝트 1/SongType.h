#pragma once

#include <iostream>
#include <string>
using namespace std;

class SongType
{
private:
	string s_id;	// 고유번호
	string s_name;	// 곡명 (primary key)

public:
	// =연산자 오버로딩
	void operator=(SongType &_p)
	{
		s_id = _p.s_id;
		s_name = _p.s_name;
	}

	// ==연산자 오버로딩
	bool operator==(SongType &_p)
	{
		if (this->s_name == _p.s_name)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(SongType &_p)
	{
		if (this->s_name > _p.s_name)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(SongType &_p)
	{
		if (this->s_name < _p.s_name)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(SongType &_p)
	{
		if (this->s_name >= _p.s_name)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(SongType &_p)
	{
		if (this->s_name <= _p.s_name)
			return true;
		else
			return false;
	}

	SongType();		// SongType 생성자
	~SongType();	// SongType 소멸자

	string GetId();		// s_id 리턴
	string GetName();	// s_name 리턴

	void SetId(string inid);		// inid로 s_id 설정
	void SetName(string inname);	// inname으로 s_name 설정
	void SetRecord(string inid, string inname);	// data로 record 설정

	void SetIdFromKB();			// keyboard로부터 s_id 설정
	void SetNameFromKB();		// keyboard로부터 s_name 설정
	void SetRecordFromKB();		// keyboard로부터 record 설정

	void DisplayIdOnScreen();		// s_id 화면에 출력
	void DisplayNameOnScreen();		// s_name 화면에 출력
	void DisplayRecordOnScreen();	// record 화면에 출력
};
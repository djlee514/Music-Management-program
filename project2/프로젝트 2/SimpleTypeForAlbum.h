#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SimpleTypeForAlbum
{
private:
	int m_id;		// 곡의 고유번호 (primary key)
	string m_name;		// 곡명
public:
	// ==연산자 오버로딩
	bool operator ==(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id == _p.m_id)
			return 1;
		return 0;
	}

	// >연산자 오버로딩
	bool operator >(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id > _p.m_id)
			return 1;
		return 0;
	}

	// <연산자 오버로딩
	bool operator <(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id < _p.m_id)
			return 1;
		return 0;
	}

	// >=연산자 오버로딩
	bool operator >=(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id >= _p.m_id)
			return 1;
		return 0;
	}

	// <=연산자 오버로딩
	bool operator <=(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id <= _p.m_id)
			return 1;
		return 0;
	}

	// =연산자 오버로딩
	void operator =(const SimpleTypeForAlbum& _p)
	{
		this->m_id = _p.m_id;
		this->m_name = _p.m_name;;
	}

	SimpleTypeForAlbum();		// SimpleTypeForAlbum 생성자
	~SimpleTypeForAlbum();		// SimpleTypeForAlbum 소멸자

	// m_id 리턴
	int GetId();

	// m_name 리턴
	string GetName();

	// m_id를 새로운 값으로 설정
	void SetId(int inid);

	// m_name을 새로운 값으로 설정
	void SetName(string inname);

	// SimpleTypeForAlbum 변수들을 새로운 값으로 설정
	void SetRecord(int inid, string inname);

	// m_id를 화면에 출력
	void DisplayIdOnScreen();

	// m_name을 화면에 출력
	void DisplayNameOnScreen();

	// SimpleTypeForAlbum 변수들을 화면에 출력
	void DisplayRecordOnScreen();

};
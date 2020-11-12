#pragma once

#include <iostream>
#include <string>
#include <string>

#include "SingerType.h"
#include "LinkedList.h"
using namespace std;

class EntType
{
public:
	// =연산자 오버로딩
	void operator=(EntType &_p)
	{
		m_ent = _p.m_ent;
		m_list = _p.m_list;
	}

	// ==연산자 오버로딩
	bool operator==(const EntType &_p)
	{
		if (this->m_ent == _p.m_ent)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(const EntType &_p)
	{
		if (this->m_ent > _p.m_ent)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(const EntType &_p)
	{
		if (this->m_ent < _p.m_ent)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(const EntType &_p)
	{
		if (this->m_ent >= _p.m_ent)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(const EntType &_p)
	{
		if (this->m_ent <= _p.m_ent)
			return true;
		else
			return false;
	}

	EntType();		// EntType 생성자
	~EntType();		// EntType 소멸자

	string GetEnt();	// m_ent 리턴

	void SetEnt(string inent);	// m_ent 설정
	void SetEntFromKB();		// m_ent 입력

	void DisplayEntOnScreen();	// m_ent 화면에 출력
	void DisplayEntListOnScreen();	// EntList에 있는 모든 가수의 정보 출력

	void AddMusicToEnt(SingerType& item);		// EntList에 새로운 가수 추가
	void AddMusicToEnt(SingerType& s_item, AlbumType& a_item);
	int DeleteMusicFromEnt(SingerType& item);	// EntList에서 가수 제거
	
private:
	string m_ent;						// 소속사(primary key)
	LinkedList<SingerType> m_list;		// 소속사 내 가수의 리스트
};
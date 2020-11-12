#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AlbumType.h"
#include "LinkedList.h"
using namespace std;

class SingerType
{
public:
	// =연산자 오버로딩
	void operator=(SingerType &_p)
	{
		m_singer = _p.m_singer;
		m_list = _p.m_list;
	}

	// ==연산자 오버로딩
	bool operator==(const SingerType &_p)
	{
		if (this->m_singer == _p.m_singer)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(const SingerType &_p)
	{
		if (this->m_singer > _p.m_singer)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(const SingerType &_p)
	{
		if (this->m_singer < _p.m_singer)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(const SingerType &_p)
	{
		if (this->m_singer >= _p.m_singer)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(const SingerType &_p)
	{
		if (this->m_singer <= _p.m_singer)
			return true;
		else
			return false;
	}

	SingerType();		// SingerType 생성자
	~SingerType();		// SingerType 소멸자

	string GetSinger();		// m_singer 리턴

	void SetSinger(string insinger);	// m_singer 설정
	void SetSingerFromKB();				// m_singer 입력

	void DisplaySingerOnScreen();		// m_singer 화면에 출력
	void DisplaySingerListOnScreen();		// SingerList에 있는 모든 곡의 정보 화면에 출력
	void DisplayAlbumnameOnScreen();

	void AddMusicToSinger(AlbumType& item);			// SingerList에 새로운 앨범 추가
	void AddMusicToSinger(AlbumType& a_item, SimpleTypeForAlbum& s_item);
	int DeleteMusicFromSinger(AlbumType& a_item, SimpleTypeForAlbum& s_item);		// SingerList에서 앨범 제거

private:
	string m_singer;				// 가수(primary key)
	LinkedList<AlbumType> m_list;	// 가수별로 분류된 리스트
};

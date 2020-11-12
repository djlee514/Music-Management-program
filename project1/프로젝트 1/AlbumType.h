#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "SimpleTypeForAlbum.h"
#include "LinkedList.h"
using namespace std;

class AlbumType
{
public:
	// =연산자 오버로딩
	void operator=(AlbumType &_p)
	{
		m_albumname = _p.m_albumname;
		m_singer = _p.m_singer;
		m_ent = _p.m_ent;
		m_numberofsonginalbum = _p.m_numberofsonginalbum;
		m_list = _p.m_list;
	}

	// ==연산자 오버로딩
	bool operator==(const AlbumType &_p)
	{
		if (this->m_albumname == _p.m_albumname)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(const AlbumType &_p)
	{
		if (this->m_albumname > _p.m_albumname)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(const AlbumType &_p)
	{
		if (this->m_albumname < _p.m_albumname)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(const AlbumType &_p)
	{
		if (this->m_albumname >= _p.m_albumname)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(const AlbumType &_p)
	{
		if (this->m_albumname <= _p.m_albumname)
			return true;
		else
			return false;
	}

	AlbumType();		// AlbumType 생성자
	~AlbumType();		// AlbumType 소멸자

	string GetAlbumname();	// m_albumname 리턴
	string GetSinger();		// m_singer 리턴
	string GetEnt();		// m_ent 리턴
	int GetNumberofsonginalbum();	// m_numberofsonginalbum 리턴

	void SetAlbumname(string inalbumname);		// m_albumname 설정
	void SetSinger(string insinger);			// m_singer 설정
	void SetEnt(string inent);					// m_ent 설정
	void SetNumberofsonginalbum(int innumberofsonginalbum);		//m_numberofsonginalbum 설정
	void SetRecord(string inalbumname, string insinger, string inent);	// AlbumType 변수들을 설정
	void SetNumberofsonginalbumIncrease();		// 앨범에 곡 추가할 경우 수록곡 수 1 증가
	void SetNumberofsonginalbumDecrease();		// 앨범에서 곡 제거할 경우 수록곡 수 1 감소

	void SetAlbumnameFromKB();		// m_albumname 입력
	void SetSingerFromKB();			// m_singer 입력
	void SetEntFromKB();			// m_ent 입력
	void SetRecordFromKB();			// AlbumType 변수들 입력
	
	void DisplayAlbumnameOnScreen();		// m_albumname 화면에 출력
	void DisplaySingerOnScreen();			// m_singer 화면에 출력
	void DisplayEntOnScreen();				// m_ent 화면에 출력
	void DisplayNumberofsonginalbumOnScreen();	// m_numberofsonginalbum 화면에 출력
	void DisplayRecordOnScreen();			// AlbumType 변수들 화면에 출력
	void DisplayAlbumListOnScreen();	// AlbumList에 있는 수록곡 정보 전부 화면에 출력

	void AddMusicToAlbum(SimpleTypeForAlbum& item);			// AlbumList에 새로운 곡 추가
	int DeleteMusicFromAlbum(SimpleTypeForAlbum& item);	// AlbumList에서 곡 제거



private:
	string m_albumname;			// 앨범명(primary key)
	string m_singer;			// 가수
	string m_ent;				// 소속사
	int m_numberofsonginalbum;	// 앨범에 수록된 곡의 수
	LinkedList<SimpleTypeForAlbum> m_list;	// 앨범에 수록된 곡의 리스트
};
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "SongType.h"
#include "LinkedList.h"
using namespace std;

class GenreType
{
public:
	// =연산자 오버로딩
	void operator=(GenreType &_p)
	{
		m_genre = _p.m_genre;
		m_list = _p.m_list;
	}

	// ==연산자 오버로딩
	bool operator==(const GenreType &_p)
	{
		if (this->m_genre == _p.m_genre)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(const GenreType &_p)
	{
		if (this->m_genre > _p.m_genre)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(const GenreType &_p)
	{
		if (this->m_genre < _p.m_genre)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(const GenreType &_p)
	{
		if (this->m_genre >= _p.m_genre)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(const GenreType &_p)
	{
		if (this->m_genre <= _p.m_genre)
			return true;
		else
			return false;
	}

	GenreType();		// GenreType 생성자
	~GenreType();		// GenreType 소멸자

	string GetGenre();							// m_genre 리턴
	void SetGenre(string ingenre);				// im_genre를 새로운 값으로 설정 
	void SetGenreFromKB();						// keyboard로부터 m_genre 설정
	void DisplayGenreOnScreen();				// m_genre 화면에 출력
	void DisplaySongOnScreen();					// m_genre별 List에 있는 곡들 화면에 출력
	void AddMusicInGenre(SongType& item);		// GenreList에 item항목 추가
	int DeleteMusicInGenre(SongType& item);		// GenreList에 item항목 제거

private:
	string m_genre;							// 장르 (primary key)
	LinkedList<SongType> m_list;			// 장르내 곡의 리스트
};
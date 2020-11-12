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
	// =������ �����ε�
	void operator=(GenreType &_p)
	{
		m_genre = _p.m_genre;
		m_list = _p.m_list;
	}

	// ==������ �����ε�
	bool operator==(const GenreType &_p)
	{
		if (this->m_genre == _p.m_genre)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(const GenreType &_p)
	{
		if (this->m_genre > _p.m_genre)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(const GenreType &_p)
	{
		if (this->m_genre < _p.m_genre)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(const GenreType &_p)
	{
		if (this->m_genre >= _p.m_genre)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(const GenreType &_p)
	{
		if (this->m_genre <= _p.m_genre)
			return true;
		else
			return false;
	}

	GenreType();		// GenreType ������
	~GenreType();		// GenreType �Ҹ���

	string GetGenre();							// m_genre ����
	void SetGenre(string ingenre);				// im_genre�� ���ο� ������ ���� 
	void SetGenreFromKB();						// keyboard�κ��� m_genre ����
	void DisplayGenreOnScreen();				// m_genre ȭ�鿡 ���
	void DisplaySongOnScreen();					// m_genre�� List�� �ִ� ��� ȭ�鿡 ���
	void AddMusicInGenre(SongType& item);		// GenreList�� item�׸� �߰�
	int DeleteMusicInGenre(SongType& item);		// GenreList�� item�׸� ����

private:
	string m_genre;							// �帣 (primary key)
	LinkedList<SongType> m_list;			// �帣�� ���� ����Ʈ
};
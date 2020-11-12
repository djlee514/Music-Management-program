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
	// =������ �����ε�
	void operator=(SingerType &_p)
	{
		m_singer = _p.m_singer;
		m_list = _p.m_list;
	}

	// ==������ �����ε�
	bool operator==(const SingerType &_p)
	{
		if (this->m_singer == _p.m_singer)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(const SingerType &_p)
	{
		if (this->m_singer > _p.m_singer)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(const SingerType &_p)
	{
		if (this->m_singer < _p.m_singer)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(const SingerType &_p)
	{
		if (this->m_singer >= _p.m_singer)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(const SingerType &_p)
	{
		if (this->m_singer <= _p.m_singer)
			return true;
		else
			return false;
	}

	SingerType();		// SingerType ������
	~SingerType();		// SingerType �Ҹ���

	string GetSinger();		// m_singer ����

	void SetSinger(string insinger);	// m_singer ����
	void SetSingerFromKB();				// m_singer �Է�

	void DisplaySingerOnScreen();		// m_singer ȭ�鿡 ���
	void DisplaySingerListOnScreen();		// SingerList�� �ִ� ��� ���� ���� ȭ�鿡 ���
	void DisplayAlbumnameOnScreen();

	void AddMusicToSinger(AlbumType& item);			// SingerList�� ���ο� �ٹ� �߰�
	void AddMusicToSinger(AlbumType& a_item, SimpleTypeForAlbum& s_item);
	int DeleteMusicFromSinger(AlbumType& a_item, SimpleTypeForAlbum& s_item);		// SingerList���� �ٹ� ����

private:
	string m_singer;				// ����(primary key)
	LinkedList<AlbumType> m_list;	// �������� �з��� ����Ʈ
};

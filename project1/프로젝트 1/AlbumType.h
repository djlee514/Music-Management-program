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
	// =������ �����ε�
	void operator=(AlbumType &_p)
	{
		m_albumname = _p.m_albumname;
		m_singer = _p.m_singer;
		m_ent = _p.m_ent;
		m_numberofsonginalbum = _p.m_numberofsonginalbum;
		m_list = _p.m_list;
	}

	// ==������ �����ε�
	bool operator==(const AlbumType &_p)
	{
		if (this->m_albumname == _p.m_albumname)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(const AlbumType &_p)
	{
		if (this->m_albumname > _p.m_albumname)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(const AlbumType &_p)
	{
		if (this->m_albumname < _p.m_albumname)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(const AlbumType &_p)
	{
		if (this->m_albumname >= _p.m_albumname)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(const AlbumType &_p)
	{
		if (this->m_albumname <= _p.m_albumname)
			return true;
		else
			return false;
	}

	AlbumType();		// AlbumType ������
	~AlbumType();		// AlbumType �Ҹ���

	string GetAlbumname();	// m_albumname ����
	string GetSinger();		// m_singer ����
	string GetEnt();		// m_ent ����
	int GetNumberofsonginalbum();	// m_numberofsonginalbum ����

	void SetAlbumname(string inalbumname);		// m_albumname ����
	void SetSinger(string insinger);			// m_singer ����
	void SetEnt(string inent);					// m_ent ����
	void SetNumberofsonginalbum(int innumberofsonginalbum);		//m_numberofsonginalbum ����
	void SetRecord(string inalbumname, string insinger, string inent);	// AlbumType �������� ����
	void SetNumberofsonginalbumIncrease();		// �ٹ��� �� �߰��� ��� ���ϰ� �� 1 ����
	void SetNumberofsonginalbumDecrease();		// �ٹ����� �� ������ ��� ���ϰ� �� 1 ����

	void SetAlbumnameFromKB();		// m_albumname �Է�
	void SetSingerFromKB();			// m_singer �Է�
	void SetEntFromKB();			// m_ent �Է�
	void SetRecordFromKB();			// AlbumType ������ �Է�
	
	void DisplayAlbumnameOnScreen();		// m_albumname ȭ�鿡 ���
	void DisplaySingerOnScreen();			// m_singer ȭ�鿡 ���
	void DisplayEntOnScreen();				// m_ent ȭ�鿡 ���
	void DisplayNumberofsonginalbumOnScreen();	// m_numberofsonginalbum ȭ�鿡 ���
	void DisplayRecordOnScreen();			// AlbumType ������ ȭ�鿡 ���
	void DisplayAlbumListOnScreen();	// AlbumList�� �ִ� ���ϰ� ���� ���� ȭ�鿡 ���

	void AddMusicToAlbum(SimpleTypeForAlbum& item);			// AlbumList�� ���ο� �� �߰�
	int DeleteMusicFromAlbum(SimpleTypeForAlbum& item);	// AlbumList���� �� ����



private:
	string m_albumname;			// �ٹ���(primary key)
	string m_singer;			// ����
	string m_ent;				// �Ҽӻ�
	int m_numberofsonginalbum;	// �ٹ��� ���ϵ� ���� ��
	LinkedList<SimpleTypeForAlbum> m_list;	// �ٹ��� ���ϵ� ���� ����Ʈ
};
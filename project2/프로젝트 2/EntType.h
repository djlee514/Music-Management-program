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
	// =������ �����ε�
	void operator=(EntType &_p)
	{
		m_ent = _p.m_ent;
		m_list = _p.m_list;
	}

	// ==������ �����ε�
	bool operator==(const EntType &_p)
	{
		if (this->m_ent == _p.m_ent)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(const EntType &_p)
	{
		if (this->m_ent > _p.m_ent)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(const EntType &_p)
	{
		if (this->m_ent < _p.m_ent)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(const EntType &_p)
	{
		if (this->m_ent >= _p.m_ent)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(const EntType &_p)
	{
		if (this->m_ent <= _p.m_ent)
			return true;
		else
			return false;
	}

	EntType();		// EntType ������
	~EntType();		// EntType �Ҹ���

	string GetEnt();	// m_ent ����

	void SetEnt(string inent);	// m_ent ����
	void SetEntFromKB();		// m_ent �Է�

	void DisplayEntOnScreen();	// m_ent ȭ�鿡 ���
	void DisplayEntListOnScreen();	// EntList�� �ִ� ��� ������ ���� ���

	void AddMusicToEnt(SingerType& item);		// EntList�� ���ο� ���� �߰�
	void AddMusicToEnt(SingerType& s_item, AlbumType& a_item);
	int DeleteMusicFromEnt(SingerType& item);	// EntList���� ���� ����
	
private:
	string m_ent;						// �Ҽӻ�(primary key)
	LinkedList<SingerType> m_list;		// �Ҽӻ� �� ������ ����Ʈ
};
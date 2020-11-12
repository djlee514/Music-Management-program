#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SimpleTypeForAlbum
{
private:
	int m_id;		// ���� ������ȣ (primary key)
	string m_name;		// ���
public:
	// ==������ �����ε�
	bool operator ==(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id == _p.m_id)
			return 1;
		return 0;
	}

	// >������ �����ε�
	bool operator >(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id > _p.m_id)
			return 1;
		return 0;
	}

	// <������ �����ε�
	bool operator <(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id < _p.m_id)
			return 1;
		return 0;
	}

	// >=������ �����ε�
	bool operator >=(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id >= _p.m_id)
			return 1;
		return 0;
	}

	// <=������ �����ε�
	bool operator <=(const SimpleTypeForAlbum& _p)
	{
		if (this->m_id <= _p.m_id)
			return 1;
		return 0;
	}

	// =������ �����ε�
	void operator =(const SimpleTypeForAlbum& _p)
	{
		this->m_id = _p.m_id;
		this->m_name = _p.m_name;;
	}

	SimpleTypeForAlbum();		// SimpleTypeForAlbum ������
	~SimpleTypeForAlbum();		// SimpleTypeForAlbum �Ҹ���

	// m_id ����
	int GetId();

	// m_name ����
	string GetName();

	// m_id�� ���ο� ������ ����
	void SetId(int inid);

	// m_name�� ���ο� ������ ����
	void SetName(string inname);

	// SimpleTypeForAlbum �������� ���ο� ������ ����
	void SetRecord(int inid, string inname);

	// m_id�� ȭ�鿡 ���
	void DisplayIdOnScreen();

	// m_name�� ȭ�鿡 ���
	void DisplayNameOnScreen();

	// SimpleTypeForAlbum �������� ȭ�鿡 ���
	void DisplayRecordOnScreen();

};
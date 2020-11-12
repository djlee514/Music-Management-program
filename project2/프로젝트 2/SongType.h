#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class SongType
{
private:
	int s_id;	// ������ȣ (primary key)
	string s_name;	// ���

public:
	// =������ �����ε�
	void operator=(SongType &_p)
	{
		s_id = _p.s_id;
		s_name = _p.s_name;
	}

	// ==������ �����ε�
	bool operator==(SongType &_p)
	{
		if (this->s_id == _p.s_id)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(SongType &_p)
	{
		if (this->s_id > _p.s_id)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(SongType &_p)
	{
		if (this->s_id < _p.s_id)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(SongType &_p)
	{
		if (this->s_id >= _p.s_id)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(SongType &_p)
	{
		if (this->s_id <= _p.s_id)
			return true;
		else
			return false;
	}

	SongType();		// SongType ������
	~SongType();	// SongType �Ҹ���

	int GetId();		// s_id ����
	string GetName();	// s_name ����

	void SetId(int inid);		// inid�� s_id ����
	void SetName(string inname);	// inname���� s_name ����
	void SetRecord(int inid, string inname);	// data�� record ����

	void SetIdFromKB();			// keyboard�κ��� s_id ����
	void SetNameFromKB();		// keyboard�κ��� s_name ����
	void SetRecordFromKB();		// keyboard�κ��� record ����

	void DisplayIdOnScreen();		// s_id ȭ�鿡 ���
	void DisplayNameOnScreen();		// s_name ȭ�鿡 ���
	void DisplayRecordOnScreen();	// record ȭ�鿡 ���

	// file�� ���� data�� �о��
	int ReadDataFromFile(ifstream& fin);

	// file�� data�� ����
	int WriteDataToFile(ofstream& fout);
};
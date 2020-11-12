#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PlaySongType
{
private:
	int ps_id;		// ������ȣ
	string ps_name;	// ��� (primary key)

public:
	// =������ �����ε�
	void operator=(PlaySongType &_p)
	{
		ps_id = _p.ps_id;
		ps_name = _p.ps_name;
	}

	// ==������ �����ε�
	bool operator==(PlaySongType &_p)
	{
		if (this->ps_name == _p.ps_name)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(PlaySongType &_p)
	{
		if (this->ps_name > _p.ps_name)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(PlaySongType &_p)
	{
		if (this->ps_name < _p.ps_name)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(PlaySongType &_p)
	{
		if (this->ps_name >= _p.ps_name)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(PlaySongType &_p)
	{
		if (this->ps_name <= _p.ps_name)
			return true;
		else
			return false;
	}

	PlaySongType();		// SongType ������
	~PlaySongType();	// SongType �Ҹ���

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
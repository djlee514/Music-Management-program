#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PlaySongType
{
private:
	int ps_id;		// 고유번호
	string ps_name;	// 곡명 (primary key)

public:
	// =연산자 오버로딩
	void operator=(PlaySongType &_p)
	{
		ps_id = _p.ps_id;
		ps_name = _p.ps_name;
	}

	// ==연산자 오버로딩
	bool operator==(PlaySongType &_p)
	{
		if (this->ps_name == _p.ps_name)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(PlaySongType &_p)
	{
		if (this->ps_name > _p.ps_name)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(PlaySongType &_p)
	{
		if (this->ps_name < _p.ps_name)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(PlaySongType &_p)
	{
		if (this->ps_name >= _p.ps_name)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(PlaySongType &_p)
	{
		if (this->ps_name <= _p.ps_name)
			return true;
		else
			return false;
	}

	PlaySongType();		// SongType 생성자
	~PlaySongType();	// SongType 소멸자

	int GetId();		// s_id 리턴
	string GetName();	// s_name 리턴

	void SetId(int inid);		// inid로 s_id 설정
	void SetName(string inname);	// inname으로 s_name 설정
	void SetRecord(int inid, string inname);	// data로 record 설정

	void SetIdFromKB();			// keyboard로부터 s_id 설정
	void SetNameFromKB();		// keyboard로부터 s_name 설정
	void SetRecordFromKB();		// keyboard로부터 record 설정

	void DisplayIdOnScreen();		// s_id 화면에 출력
	void DisplayNameOnScreen();		// s_name 화면에 출력
	void DisplayRecordOnScreen();	// record 화면에 출력

	// file로 부터 data를 읽어옴
	int ReadDataFromFile(ifstream& fin);

	// file에 data를 저장
	int WriteDataToFile(ofstream& fout);
};
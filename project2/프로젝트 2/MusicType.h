#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class MusicType
{
public:
	// ==������ �����ε�
	bool operator ==(const MusicType& _p)
	{
		if (this->m_id == _p.GetId())
			return 1;
		return 0;
	}

	// >������ �����ε�
	bool operator >(const MusicType& _p)
	{
		if (this->m_id > _p.GetId())
			return 1;
		return 0;
	}

	// <������ �����ε�
	bool operator <(const MusicType& _p)
	{
		if (this->m_id < _p.GetId())
			return 1;
		return 0;
	}

	// >=������ �����ε�
	bool operator >=(const MusicType& _p)
	{
		if (this->m_id >= _p.GetId())
			return 1;
		return 0;
	}

	// <=������ �����ε�
	bool operator <=(const MusicType& _p)
	{
		if (this->m_id <= _p.GetId())
			return 1;
		return 0;
	}

	// =������ �����ε�
	void operator =(const MusicType& _p)
	{
		m_id = _p.m_id;
		m_name = _p.m_name;
		m_istitle = _p.m_istitle;
		m_singer = _p.m_singer;
		m_runningtime = _p.m_runningtime;
		m_genre = _p.m_genre;
		m_albumname = _p.m_albumname;
		m_release = _p.m_release;
		m_lyricist = _p.m_lyricist;
		m_songwriter = _p.m_songwriter;
		m_ent = _p.m_ent;
		m_playtime = _p.m_playtime;
		m_highlight = _p.m_highlight;
	}

	// MusicType ������
	MusicType();

	// MusicType �Ҹ���
	~MusicType();

	// m_id ����
	int GetId() const;

	// m_name ����
	string GetName();

	// m_istitle ����
	string GetIstitle();

	// m_singer ����
	string GetSinger();

	// m_runningtime ����
	string GetRunningtime();

	// m_genre ����
	string GetGenre();

	// m_albumname ����
	string GetAlbumname();

	// m_release ����
	string GetRelease();

	// m_lyricist ����
	string GetLyricist();

	// m_songwriter ����
	string GetSongwriter();

	// m_ent ����
	string GetEnt();

	// m_playtime ����
	int GetPlaytime();

	// m_highlight ����
	string GetHighlight();

	// m_id�� ���ο� ������ ����
	void SetId(int inid);

	// m_name�� ���ο� ������ ����
	void SetName(string inname);

	// m_istitle�� ���ο� ������ ����
	void SetIstitle(string inistitle);

	// m_singer�� ���ο� ������ ����
	void SetSinger(string insinger);

	// m_runningtime�� ���ο� ������ ����
	void SetRunningtime(string inrunningtime);

	// m_genre�� ���ο� ������ ����
	void SetGenre(string ingenre);

	// m_albumname�� ���ο� ������ ����
	void SetAlbumname(string inalbumname);

	// m_release�� ���ο� ������ ����
	void SetRelease(string inrelease);

	// m_lyricist�� ���ο� ������ ����
	void SetLyricist(string inlyricist);

	// m_songwriter�� ���ο� ������ ����
	void SetSongwriter(string insongwriter);

	// m_ent�� ���ο� ������ ����
	void SetEnt(string inent);

	// m_playtime�� ���ο� ������ ����
	void SetPlaytime(int inplaytime);

	// m_highlight�� ���ο� ������ ����
	void SetHighlight(string inhighlight);

	// MusicType �������� ���ο� ������ ����
	void SetRecord(int inid, string inname, string inistitle, string insinger, string inrunningtime, string ingenre, string inalbumname,
		string inrelease, string inlyricist, string insongwriter, string inent, int inplaytime, string inhighlight);

	// m_Id ȭ�鿡 ���
	void DisplayIdOnScreen();

	// m_name ȭ�鿡 ���
	void DisplayNameOnScreen();

	// m_istitle ȭ�鿡 ���
	void DisplayIstitleOnScreen();

	// m_singer ȭ�鿡 ���
	void DisplaySingerOnScreen();

	// m_runningtime ȭ�鿡 ���
	void DisplayRunningtimeOnScreen();

	// m_genre ȭ�鿡 ���
	void DisplayGenreOnScreen();

	// m_albumname ȭ�鿡 ���
	void DisplayAlbumnameOnScreen();

	// m_release ȭ�鿡 ���
	void DisplayReleaseOnScreen();

	// m_lyricist ȭ�鿡 ���
	void DisplayLyricistOnScreen();

	// m_songwriter ȭ�鿡 ���
	void DisplaySongwriterOnScreen();

	// m_ent ȭ�鿡 ���
	void DisplayEntOnScreen();

	// m_playtime ȭ�鿡 ���
	void DisplayPlaytimeOnScreen();

	// m_highlight ȭ�鿡 ���
	void DisplayHighlightOnScreen();

	// ��� �������� ȭ�鿡 ���
	void DisplayRecordOnScreen();

	// keyboard�κ��� m_id �Է¹���
	void SetIdFromKB();

	// keyboard�κ��� m_name �Է¹���
	void SetNameFromKB();

	// keyboard�κ��� m_istitle �Է¹���
	void SetIstitleFromKB();

	// keyboard�κ��� m_singer �Է¹���
	void SetSingerFromKB();

	// keyboard�κ��� m_runningtime �Է¹���
	void SetRunningtimeFromKB();

	// keyboard�κ��� m_genre �Է¹���
	void SetGenreFromKB();

	// keyboard�κ��� m_albumname �Է¹���
	void SetAlbumnameFromKB();

	// keyboard�κ��� m_release �Է¹���
	void SetReleaseFromKB();

	// keyboard�κ��� m_lyricist �Է¹���
	void SetLyricistFromKB();

	// keyboard�κ��� m_songwriter �Է¹���
	void SetSongwriterFromKB();

	// keyboard�κ��� m_ent �Է¹���
	void SetEntFromKB();

	// keyboard�κ��� m_playtime �Է¹���
	void SetPlaytimeFromKB();

	// keyboard�κ��� m_highlight �Է¹���
	void SetHighlightFromKB();

	// keyboard�κ��� ��� �������� �Է¹���
	void SetRecordFromKB();

	// file�� ���� data�� �о��
	int ReadDataFromFile(ifstream& fin);

	// file�� data�� ����
	int WriteDataToFile(ofstream& fout);

private:
	int m_id;			// ���� ������ȣ (primary key)
	string m_name;			// ���
	string m_istitle;		// Ÿ��Ʋ������ (Title or Track)
	string m_singer;		// ������
	string m_genre;			// �帣
	string m_albumname;		// �ٹ���
	string m_release;		// �� ��ǥ��
	string m_lyricist;		// �ۻ簡
	string m_songwriter;	// �۰���
	string m_ent;			// �Ҽӻ�
	string m_highlight;		// ���̶���Ʈ ����

	string m_runningtime;	// �� ����
	int m_playtime;			// ��� Ƚ��
};
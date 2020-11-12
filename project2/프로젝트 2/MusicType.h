#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class MusicType
{
public:
	// ==연산자 오버로딩
	bool operator ==(const MusicType& _p)
	{
		if (this->m_id == _p.GetId())
			return 1;
		return 0;
	}

	// >연산자 오버로딩
	bool operator >(const MusicType& _p)
	{
		if (this->m_id > _p.GetId())
			return 1;
		return 0;
	}

	// <연산자 오버로딩
	bool operator <(const MusicType& _p)
	{
		if (this->m_id < _p.GetId())
			return 1;
		return 0;
	}

	// >=연산자 오버로딩
	bool operator >=(const MusicType& _p)
	{
		if (this->m_id >= _p.GetId())
			return 1;
		return 0;
	}

	// <=연산자 오버로딩
	bool operator <=(const MusicType& _p)
	{
		if (this->m_id <= _p.GetId())
			return 1;
		return 0;
	}

	// =연산자 오버로딩
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

	// MusicType 생성자
	MusicType();

	// MusicType 소멸자
	~MusicType();

	// m_id 리턴
	int GetId() const;

	// m_name 리턴
	string GetName();

	// m_istitle 리턴
	string GetIstitle();

	// m_singer 리턴
	string GetSinger();

	// m_runningtime 리턴
	string GetRunningtime();

	// m_genre 리턴
	string GetGenre();

	// m_albumname 리턴
	string GetAlbumname();

	// m_release 리턴
	string GetRelease();

	// m_lyricist 리턴
	string GetLyricist();

	// m_songwriter 리턴
	string GetSongwriter();

	// m_ent 리턴
	string GetEnt();

	// m_playtime 리턴
	int GetPlaytime();

	// m_highlight 리턴
	string GetHighlight();

	// m_id를 새로운 값으로 설정
	void SetId(int inid);

	// m_name을 새로운 값으로 설정
	void SetName(string inname);

	// m_istitle을 새로운 값으로 설정
	void SetIstitle(string inistitle);

	// m_singer를 새로운 값으로 설정
	void SetSinger(string insinger);

	// m_runningtime을 새로운 값으로 설정
	void SetRunningtime(string inrunningtime);

	// m_genre를 새로운 값으로 설정
	void SetGenre(string ingenre);

	// m_albumname을 새로운 값으로 설정
	void SetAlbumname(string inalbumname);

	// m_release를 새로운 값으로 설정
	void SetRelease(string inrelease);

	// m_lyricist를 새로운 값으로 설정
	void SetLyricist(string inlyricist);

	// m_songwriter를 새로운 값으로 설정
	void SetSongwriter(string insongwriter);

	// m_ent를 새로운 값으로 설정
	void SetEnt(string inent);

	// m_playtime을 새로운 값으로 설정
	void SetPlaytime(int inplaytime);

	// m_highlight를 새로운 값으로 설정
	void SetHighlight(string inhighlight);

	// MusicType 변수들을 새로운 값으로 설정
	void SetRecord(int inid, string inname, string inistitle, string insinger, string inrunningtime, string ingenre, string inalbumname,
		string inrelease, string inlyricist, string insongwriter, string inent, int inplaytime, string inhighlight);

	// m_Id 화면에 출력
	void DisplayIdOnScreen();

	// m_name 화면에 출력
	void DisplayNameOnScreen();

	// m_istitle 화면에 출력
	void DisplayIstitleOnScreen();

	// m_singer 화면에 출력
	void DisplaySingerOnScreen();

	// m_runningtime 화면에 출력
	void DisplayRunningtimeOnScreen();

	// m_genre 화면에 출력
	void DisplayGenreOnScreen();

	// m_albumname 화면에 출력
	void DisplayAlbumnameOnScreen();

	// m_release 화면에 출력
	void DisplayReleaseOnScreen();

	// m_lyricist 화면에 출력
	void DisplayLyricistOnScreen();

	// m_songwriter 화면에 출력
	void DisplaySongwriterOnScreen();

	// m_ent 화면에 출력
	void DisplayEntOnScreen();

	// m_playtime 화면에 출력
	void DisplayPlaytimeOnScreen();

	// m_highlight 화면에 출력
	void DisplayHighlightOnScreen();

	// 모든 음악정보 화면에 출력
	void DisplayRecordOnScreen();

	// keyboard로부터 m_id 입력받음
	void SetIdFromKB();

	// keyboard로부터 m_name 입력받음
	void SetNameFromKB();

	// keyboard로부터 m_istitle 입력받음
	void SetIstitleFromKB();

	// keyboard로부터 m_singer 입력받음
	void SetSingerFromKB();

	// keyboard로부터 m_runningtime 입력받음
	void SetRunningtimeFromKB();

	// keyboard로부터 m_genre 입력받음
	void SetGenreFromKB();

	// keyboard로부터 m_albumname 입력받음
	void SetAlbumnameFromKB();

	// keyboard로부터 m_release 입력받음
	void SetReleaseFromKB();

	// keyboard로부터 m_lyricist 입력받음
	void SetLyricistFromKB();

	// keyboard로부터 m_songwriter 입력받음
	void SetSongwriterFromKB();

	// keyboard로부터 m_ent 입력받음
	void SetEntFromKB();

	// keyboard로부터 m_playtime 입력받음
	void SetPlaytimeFromKB();

	// keyboard로부터 m_highlight 입력받음
	void SetHighlightFromKB();

	// keyboard로부터 모든 음악정보 입력받음
	void SetRecordFromKB();

	// file로 부터 data를 읽어옴
	int ReadDataFromFile(ifstream& fin);

	// file에 data를 저장
	int WriteDataToFile(ofstream& fout);

private:
	int m_id;			// 곡의 고유번호 (primary key)
	string m_name;			// 곡명
	string m_istitle;		// 타이틀곡인지 (Title or Track)
	string m_singer;		// 가수명
	string m_genre;			// 장르
	string m_albumname;		// 앨범명
	string m_release;		// 곡 발표일
	string m_lyricist;		// 작사가
	string m_songwriter;	// 작곡자
	string m_ent;			// 소속사
	string m_highlight;		// 하이라이트 가사

	string m_runningtime;	// 곡 길이
	int m_playtime;			// 재생 횟수
};
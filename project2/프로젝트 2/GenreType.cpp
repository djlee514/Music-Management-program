#include "GenreType.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// GenreType 생성자
GenreType::GenreType()
{
	m_genre = "";
}

// GenreType 소멸자
GenreType::~GenreType() {}

// 장르 리턴
string GenreType::GetGenre()
{
	return m_genre;
}

// 장르 설정
void GenreType::SetGenre(string ingenre)
{
	m_genre = ingenre;
}

// 장르 입력
void GenreType::SetGenreFromKB()
{
	cout << "\t장르 : ";
	cin >> m_genre;
}

// 장르 출력
void GenreType::DisplayGenreOnScreen()
{
	cout << "\t장르 : " << m_genre << endl;
}

// 장르리스트의 곡 출력
void GenreType::DisplaySongOnScreen()
{
	SongType temp;
	m_list.ResetList();
	cout << "\n\t♬ 장르별 곡 정보 ♬" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
	}
}

// 장르리스트에 곡 추가
void GenreType::AddMusicInGenre(SongType & item)
{
	m_list.Add(item);
}

// 장르리스트에서 곡 제거
int GenreType::DeleteMusicInGenre(SongType & item)
{
	if (m_list.Delete(item))
		if (m_list.GetLength() == 0)
			return 1;
		else
			return 0;
	else
		return -1;
}

#include "AlbumType.h"

// AlbumType 생성자
AlbumType::AlbumType()
{
	m_albumname == "";
	m_singer == "";
	m_ent == "";
	m_numberofsonginalbum = 0;

}

// AlbumType 소멸자
AlbumType::~AlbumType() {}

// 앨범명 리턴
string AlbumType::GetAlbumname()
{
	return m_albumname;
}

// 가수 리턴
string AlbumType::GetSinger()
{
	return m_singer;
}

// 소속사 리턴
string AlbumType::GetEnt()
{
	return m_ent;
}

// 앨범의 수록곡수 리턴
int AlbumType::GetNumberofsonginalbum()
{
	return m_numberofsonginalbum;
}

// 앨범명 설정
void AlbumType::SetAlbumname(string inalbumname)
{
	m_albumname = inalbumname;
}

// 가수 설정
void AlbumType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// 소속사 설정
void AlbumType::SetEnt(string inent)
{
	m_ent = inent;
}

// 수록곡수 설정
void AlbumType::SetNumberofsonginalbum(int innumberofsonginalbum)
{
	m_numberofsonginalbum = innumberofsonginalbum;
}

// 앨범의 정보 설정
void AlbumType::SetRecord(string inalbumname, string insinger, string inent )
{
	m_albumname = inalbumname;
	m_singer = insinger;
	m_ent = inent;
}

// 수록곡수 1 증가
void AlbumType::SetNumberofsonginalbumIncrease()
{
	m_numberofsonginalbum++;
}

// 수록곡수 1 감소
void AlbumType::SetNumberofsonginalbumDecrease()
{
	if (m_numberofsonginalbum != 0)
		m_numberofsonginalbum--;
	else
		cout << "\t앨범 수록곡의 수가 0입니다." << endl;
}

// 앨범명 입력
void AlbumType::SetAlbumnameFromKB()
{
	cout << "\t앨범명 : ";
	cin >> m_albumname;
}

// 가수 입력
void AlbumType::SetSingerFromKB()
{
	cout << "\t가수 : ";
	cin >> m_singer;
}

// 소속사 입력
void AlbumType::SetEntFromKB()
{
	cout << "\t소속사 : ";
	cin >> m_ent;
}

// 앨범의 정보 입력
void AlbumType::SetRecordFromKB()
{
	SetAlbumnameFromKB();
	SetSingerFromKB();
	SetEntFromKB();
}

// 앨범명 출력
void AlbumType::DisplayAlbumnameOnScreen()
{
	cout << "\t앨범명 : " << m_albumname << endl;
}

// 가수 출력
void AlbumType::DisplaySingerOnScreen()
{
	cout << "\t가수 : " << m_singer << endl;
}

// 소속사 출력
void AlbumType::DisplayEntOnScreen()
{
	cout << "\t소속사 : " << m_ent << endl;
}

// 수록곡수 출력
void AlbumType::DisplayNumberofsonginalbumOnScreen()
{
	cout << "\t수록곡의 수 : " << m_numberofsonginalbum << endl;
}

// 앨범의 정보 출력
void AlbumType::DisplayRecordOnScreen()
{
	DisplayAlbumnameOnScreen();
	DisplaySingerOnScreen();
	DisplayEntOnScreen();
	DisplayNumberofsonginalbumOnScreen();
}

// 앨범의 수록곡 출력
void AlbumType::DisplayAlbumListOnScreen()
{
	int check = 0;
	SimpleTypeForAlbum temp;
	m_list.ResetList();
	cout << "\n\t♬ 앨범 내 수록곡 정보 ♬" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t앨범 내 수록곡이 없습니다." << endl;
}

// 앨범에 곡 추가
void AlbumType::AddMusicToAlbum(SimpleTypeForAlbum & item)
{
	m_list.Add(item);
}

// 앨범에서 곡 삭제
int AlbumType::DeleteMusicFromAlbum(SimpleTypeForAlbum & item)
{
	if (m_list.Delete(item))
	{
		if (m_list.GetLength() == 0)
			return 1;
		else
			return 0;
		m_numberofsonginalbum--;
	}
	else
		return -1;
}


#include "SingerType.h"

// SingerType 생성자
SingerType::SingerType()
{
	m_singer = "";
}

// SingerType 소멸자
SingerType::~SingerType() {}

// 가수 리턴
string SingerType::GetSinger()
{
	return m_singer;
}

// 가수 설정
void SingerType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// 가수 입력
void SingerType::SetSingerFromKB()
{
	cout << "\t가수 : ";
	cin >> m_singer;
}

// 가수 출력
void SingerType::DisplaySingerOnScreen()
{
	cout << "\t가수 : " << m_singer << endl;
}

// 가수리스트에 존재하는 앨범 출력
void SingerType::DisplaySingerListOnScreen()
{
	int check = 0;
	AlbumType temp;
	m_list.ResetList();
	cout << "\n\t♬ 가수리스트 내 앨범 ♬" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t가수리스트에 앨범이 없습니다." << endl;
}

// 가수가 작업한 앨범 출력
void SingerType::DisplayAlbumnameOnScreen()
{
	AlbumType album;
	cout << "\n\t♬ 해당가수가 작업한 앨범 ♬" << endl;
	m_list.ResetList();
	while (m_list.GetNextItem(album) != -1)
	{
		album.DisplayAlbumnameOnScreen();
		cout << endl;
	}
}

// 가수에 앨범추가
void SingerType::AddMusicToSinger(AlbumType & item)
{
	m_list.Add(item);
}

// 가수에 앨범과 간단한 정보 추가
void SingerType::AddMusicToSinger(AlbumType & a_item, SimpleTypeForAlbum & s_item)
{
	if (m_list.Get(a_item)) {
		a_item.SetNumberofsonginalbumIncrease();
		a_item.AddMusicToAlbum(s_item);
		m_list.Replace(a_item);
	}
	else {
		AlbumType temp;
		temp.SetRecord(a_item.GetAlbumname(), a_item.GetSinger(),a_item.GetEnt());
		temp.SetNumberofsonginalbumIncrease();
		temp.AddMusicToAlbum(s_item);
		m_list.Add(temp);
	}
}

// 가수에서 앨범과 간단한 정보 제거
int SingerType::DeleteMusicFromSinger(AlbumType & a_item, SimpleTypeForAlbum & s_item)
{
	if (m_list.Get(a_item))
		if (a_item.DeleteMusicFromAlbum(s_item))
			m_list.Delete(a_item);
	if (m_list.GetLength() == 0)
		return 0;
	return 1;
}
//
//int SingerType::DeleteMusicFromSinger(AlbumType & item)
//{
//	if (m_list.Delete(item))
//	{
//		if (m_list.GetLength() == 0)
//			return 1;
//		else
//			return 0;
//	}
//	else
//		return -1;
//}

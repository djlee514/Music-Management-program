#include "EntType.h"

// EntType 생성자
EntType::EntType()
{
	m_ent = "";
}

// EntType 소멸자
EntType::~EntType() {}

// 소속사 리턴
string EntType::GetEnt()
{
	return m_ent;
}

// 소속사 설정
void EntType::SetEnt(string inent)
{
	m_ent = inent;
}

// 소속사 입력
void EntType::SetEntFromKB()
{
	cout << "\t소속사 : ";
	cin >> m_ent;
}

// 소속사 출력
void EntType::DisplayEntOnScreen()
{
	cout << "\t소속사 : " << m_ent << endl;
}

// 소속사의 가수 출력
void EntType::DisplayEntListOnScreen()
{
	int check = 0;
	SingerType temp;
	m_list.ResetList();
	cout << "\n\t♬ 소속사 내 가수 ♬" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplaySingerOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t 소속사 내 가수가 없습니다." << endl;
}

// 소속사에 가수 추가
void EntType::AddMusicToEnt(SingerType & item)
{
	m_list.Add(item);
}

// 소속사에 가수와 앨범 추가
void EntType::AddMusicToEnt(SingerType & s_item, AlbumType & a_item)
{

	if (m_list.Get(s_item))
	{
		s_item.AddMusicToSinger(a_item);
		m_list.Replace(s_item);
	}
	else
	{
		SingerType temp;
		temp.SetSinger(s_item.GetSinger());
		temp.AddMusicToSinger(a_item);
		m_list.Add(temp);

	}
}

// 소속사에서 가수 제거
int EntType::DeleteMusicFromEnt(SingerType & item)
{
	if (m_list.Delete(item))
		if (m_list.GetLength() == 0)
			return 1;
		else
			return 0;
	else
		return -1;
}

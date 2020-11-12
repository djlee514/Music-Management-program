#include "SingerType.h"

// SingerType ������
SingerType::SingerType()
{
	m_singer = "";
}

// SingerType �Ҹ���
SingerType::~SingerType() {}

// ���� ����
string SingerType::GetSinger()
{
	return m_singer;
}

// ���� ����
void SingerType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// ���� �Է�
void SingerType::SetSingerFromKB()
{
	cout << "\t���� : ";
	cin >> m_singer;
}

// ���� ���
void SingerType::DisplaySingerOnScreen()
{
	cout << "\t���� : " << m_singer << endl;
}

// ��������Ʈ�� �����ϴ� �ٹ� ���
void SingerType::DisplaySingerListOnScreen()
{
	int check = 0;
	AlbumType temp;
	m_list.ResetList();
	cout << "\n\t�� ��������Ʈ �� �ٹ� ��" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t��������Ʈ�� �ٹ��� �����ϴ�." << endl;
}

// ������ �۾��� �ٹ� ���
void SingerType::DisplayAlbumnameOnScreen()
{
	AlbumType album;
	cout << "\n\t�� �ش簡���� �۾��� �ٹ� ��" << endl;
	m_list.ResetList();
	while (m_list.GetNextItem(album) != -1)
	{
		album.DisplayAlbumnameOnScreen();
		cout << endl;
	}
}

// ������ �ٹ��߰�
void SingerType::AddMusicToSinger(AlbumType & item)
{
	m_list.Add(item);
}

// ������ �ٹ��� ������ ���� �߰�
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

// �������� �ٹ��� ������ ���� ����
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

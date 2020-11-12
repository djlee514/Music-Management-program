#include "AlbumType.h"

// AlbumType ������
AlbumType::AlbumType()
{
	m_albumname == "";
	m_singer == "";
	m_ent == "";
	m_numberofsonginalbum = 0;

}

// AlbumType �Ҹ���
AlbumType::~AlbumType() {}

// �ٹ��� ����
string AlbumType::GetAlbumname()
{
	return m_albumname;
}

// ���� ����
string AlbumType::GetSinger()
{
	return m_singer;
}

// �Ҽӻ� ����
string AlbumType::GetEnt()
{
	return m_ent;
}

// �ٹ��� ���ϰ�� ����
int AlbumType::GetNumberofsonginalbum()
{
	return m_numberofsonginalbum;
}

// �ٹ��� ����
void AlbumType::SetAlbumname(string inalbumname)
{
	m_albumname = inalbumname;
}

// ���� ����
void AlbumType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// �Ҽӻ� ����
void AlbumType::SetEnt(string inent)
{
	m_ent = inent;
}

// ���ϰ�� ����
void AlbumType::SetNumberofsonginalbum(int innumberofsonginalbum)
{
	m_numberofsonginalbum = innumberofsonginalbum;
}

// �ٹ��� ���� ����
void AlbumType::SetRecord(string inalbumname, string insinger, string inent )
{
	m_albumname = inalbumname;
	m_singer = insinger;
	m_ent = inent;
}

// ���ϰ�� 1 ����
void AlbumType::SetNumberofsonginalbumIncrease()
{
	m_numberofsonginalbum++;
}

// ���ϰ�� 1 ����
void AlbumType::SetNumberofsonginalbumDecrease()
{
	if (m_numberofsonginalbum != 0)
		m_numberofsonginalbum--;
	else
		cout << "\t�ٹ� ���ϰ��� ���� 0�Դϴ�." << endl;
}

// �ٹ��� �Է�
void AlbumType::SetAlbumnameFromKB()
{
	cout << "\t�ٹ��� : ";
	cin >> m_albumname;
}

// ���� �Է�
void AlbumType::SetSingerFromKB()
{
	cout << "\t���� : ";
	cin >> m_singer;
}

// �Ҽӻ� �Է�
void AlbumType::SetEntFromKB()
{
	cout << "\t�Ҽӻ� : ";
	cin >> m_ent;
}

// �ٹ��� ���� �Է�
void AlbumType::SetRecordFromKB()
{
	SetAlbumnameFromKB();
	SetSingerFromKB();
	SetEntFromKB();
}

// �ٹ��� ���
void AlbumType::DisplayAlbumnameOnScreen()
{
	cout << "\t�ٹ��� : " << m_albumname << endl;
}

// ���� ���
void AlbumType::DisplaySingerOnScreen()
{
	cout << "\t���� : " << m_singer << endl;
}

// �Ҽӻ� ���
void AlbumType::DisplayEntOnScreen()
{
	cout << "\t�Ҽӻ� : " << m_ent << endl;
}

// ���ϰ�� ���
void AlbumType::DisplayNumberofsonginalbumOnScreen()
{
	cout << "\t���ϰ��� �� : " << m_numberofsonginalbum << endl;
}

// �ٹ��� ���� ���
void AlbumType::DisplayRecordOnScreen()
{
	DisplayAlbumnameOnScreen();
	DisplaySingerOnScreen();
	DisplayEntOnScreen();
	DisplayNumberofsonginalbumOnScreen();
}

// �ٹ��� ���ϰ� ���
void AlbumType::DisplayAlbumListOnScreen()
{
	int check = 0;
	SimpleTypeForAlbum temp;
	m_list.ResetList();
	cout << "\n\t�� �ٹ� �� ���ϰ� ���� ��" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t�ٹ� �� ���ϰ��� �����ϴ�." << endl;
}

// �ٹ��� �� �߰�
void AlbumType::AddMusicToAlbum(SimpleTypeForAlbum & item)
{
	m_list.Add(item);
}

// �ٹ����� �� ����
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


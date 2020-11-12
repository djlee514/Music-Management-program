#include "GenreType.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// GenreType ������
GenreType::GenreType()
{
	m_genre = "";
}

// GenreType �Ҹ���
GenreType::~GenreType() {}

// �帣 ����
string GenreType::GetGenre()
{
	return m_genre;
}

// �帣 ����
void GenreType::SetGenre(string ingenre)
{
	m_genre = ingenre;
}

// �帣 �Է�
void GenreType::SetGenreFromKB()
{
	cout << "\t�帣 : ";
	cin >> m_genre;
}

// �帣 ���
void GenreType::DisplayGenreOnScreen()
{
	cout << "\t�帣 : " << m_genre << endl;
}

// �帣����Ʈ�� �� ���
void GenreType::DisplaySongOnScreen()
{
	SongType temp;
	m_list.ResetList();
	cout << "\n\t�� �帣�� �� ���� ��" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplayRecordOnScreen();
		cout << endl;
	}
}

// �帣����Ʈ�� �� �߰�
void GenreType::AddMusicInGenre(SongType & item)
{
	m_list.Add(item);
}

// �帣����Ʈ���� �� ����
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

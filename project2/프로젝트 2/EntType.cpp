#include "EntType.h"

// EntType ������
EntType::EntType()
{
	m_ent = "";
}

// EntType �Ҹ���
EntType::~EntType() {}

// �Ҽӻ� ����
string EntType::GetEnt()
{
	return m_ent;
}

// �Ҽӻ� ����
void EntType::SetEnt(string inent)
{
	m_ent = inent;
}

// �Ҽӻ� �Է�
void EntType::SetEntFromKB()
{
	cout << "\t�Ҽӻ� : ";
	cin >> m_ent;
}

// �Ҽӻ� ���
void EntType::DisplayEntOnScreen()
{
	cout << "\t�Ҽӻ� : " << m_ent << endl;
}

// �Ҽӻ��� ���� ���
void EntType::DisplayEntListOnScreen()
{
	int check = 0;
	SingerType temp;
	m_list.ResetList();
	cout << "\n\t�� �Ҽӻ� �� ���� ��" << endl;
	while (m_list.GetNextItem(temp) != -1)
	{
		temp.DisplaySingerOnScreen();
		cout << endl;
		check++;
	}
	if (check == 0)
		cout << "\t �Ҽӻ� �� ������ �����ϴ�." << endl;
}

// �Ҽӻ翡 ���� �߰�
void EntType::AddMusicToEnt(SingerType & item)
{
	m_list.Add(item);
}

// �Ҽӻ翡 ������ �ٹ� �߰�
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

// �Ҽӻ翡�� ���� ����
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

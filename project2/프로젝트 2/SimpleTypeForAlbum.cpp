#include "SimpleTypeForAlbum.h"

// SimpleTypeForAlbum ������
SimpleTypeForAlbum::SimpleTypeForAlbum()
{
	m_id = 0;
	m_name = "";
}

// SimpleTypeForAlbum �Ҹ���
SimpleTypeForAlbum::~SimpleTypeForAlbum() {}

// ������ȣ ����
int SimpleTypeForAlbum::GetId()
{
	return m_id;
}

// ��� ����
string SimpleTypeForAlbum::GetName()
{
	return m_name;
}

// ������ȣ ����
void SimpleTypeForAlbum::SetId(int inid)
{
	m_id = inid;
}

// ��� ����
void SimpleTypeForAlbum::SetName(string inname)
{
	m_name = inname;
}

// ������ ���� ����
void SimpleTypeForAlbum::SetRecord(int inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// ������ȣ ���
void SimpleTypeForAlbum::DisplayIdOnScreen()
{
	cout << "\t������ȣ : " << m_id << endl;
}

// ��� ���
void SimpleTypeForAlbum::DisplayNameOnScreen()
{
	cout << "\t��� : " << m_name << endl;
}

// ������ ���� ���
void SimpleTypeForAlbum::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
}

#include "SimpleTypeForAlbum.h"

// SimpleTypeForAlbum 생성자
SimpleTypeForAlbum::SimpleTypeForAlbum()
{
	m_id = 0;
	m_name = "";
}

// SimpleTypeForAlbum 소멸자
SimpleTypeForAlbum::~SimpleTypeForAlbum() {}

// 고유번호 리턴
int SimpleTypeForAlbum::GetId()
{
	return m_id;
}

// 곡명 리턴
string SimpleTypeForAlbum::GetName()
{
	return m_name;
}

// 고유번호 설정
void SimpleTypeForAlbum::SetId(int inid)
{
	m_id = inid;
}

// 곡명 설정
void SimpleTypeForAlbum::SetName(string inname)
{
	m_name = inname;
}

// 간단한 정보 설정
void SimpleTypeForAlbum::SetRecord(int inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// 고유번호 출력
void SimpleTypeForAlbum::DisplayIdOnScreen()
{
	cout << "\t고유번호 : " << m_id << endl;
}

// 곡명 출력
void SimpleTypeForAlbum::DisplayNameOnScreen()
{
	cout << "\t곡명 : " << m_name << endl;
}

// 간단한 정보 출력
void SimpleTypeForAlbum::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
}

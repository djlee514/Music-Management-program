#include "SongType.h"

// ������
SongType::SongType()
{
	s_name = "";
	s_id = "";
}

// �Ҹ���
SongType::~SongType() {}


// ������ȣ ���
string SongType::GetId() {
	return s_id;
}

// ��� ���
string SongType::GetName() {
	return s_name;
}

// ������ȣ ����
void SongType::SetId(string inid) {
	s_id = inid;
}

// ��� ����
void SongType::SetName(string inname) {
	s_name = inname;
}

// SongType ���� ����
void SongType::SetRecord(string inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// ������ȣ �Է�
void SongType::SetIdFromKB()
{
	cout << "\t������ȣ : ";
	cin >> s_id;
}

// ��� �Է�
void SongType::SetNameFromKB() {
	cout << "\t��� : ";
	cin >> s_name;
}

// SongType ���� �Է�
void SongType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

// ������ȣ ���
void SongType::DisplayIdOnScreen() {
	cout << "\t������ȣ : " << s_id << endl;
}

// ��� ���
void SongType::DisplayNameOnScreen() {
	cout << "\t��� : " << s_name << endl;
}


// ������ �������� ���
void SongType::DisplayRecordOnScreen() 
{
	DisplayNameOnScreen();
	DisplayIdOnScreen();
}
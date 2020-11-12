#include "PlaySongType.h"

// ������
PlaySongType::PlaySongType()
{
	ps_name = "";
	ps_id = 0;
}

// �Ҹ���
PlaySongType::~PlaySongType() {}


// ������ȣ ���
int PlaySongType::GetId() {
	return ps_id;
}

// ��� ���
string PlaySongType::GetName() {
	return ps_name;
}

// ������ȣ ����
void PlaySongType::SetId(int inid) {
	ps_id = inid;
}

// ��� ����
void PlaySongType::SetName(string inname) {
	ps_name = inname;
}

// SongType ���� ����
void PlaySongType::SetRecord(int inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// ������ȣ �Է�
void PlaySongType::SetIdFromKB()
{
	cout << "\t������ȣ : ";
	cin >> ps_id;
}

// ��� �Է�
void PlaySongType::SetNameFromKB() {
	cout << "\t��� : ";
	cin >> ps_name;
}

// SongType ���� �Է�
void PlaySongType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

// ������ȣ ���
void PlaySongType::DisplayIdOnScreen() {
	cout << "\t������ȣ : " << ps_id << endl;
}

// ��� ���
void PlaySongType::DisplayNameOnScreen() {
	cout << "\t��� : " << ps_name << endl;
}


// ������ �������� ���
void PlaySongType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	DisplayIdOnScreen();
}

int PlaySongType::ReadDataFromFile(ifstream & fin)
{
	fin >> ps_id;
	fin >> ps_name;
	return 1;
}

int PlaySongType::WriteDataToFile(ofstream & fout)
{
	fout << ps_id << " ";
	fout << ps_name << " ";
	fout << endl;
	return 1;
}

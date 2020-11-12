#include "PlaySongType.h"

// 생성자
PlaySongType::PlaySongType()
{
	ps_name = "";
	ps_id = 0;
}

// 소멸자
PlaySongType::~PlaySongType() {}


// 고유번호 얻기
int PlaySongType::GetId() {
	return ps_id;
}

// 곡명 얻기
string PlaySongType::GetName() {
	return ps_name;
}

// 고유번호 설정
void PlaySongType::SetId(int inid) {
	ps_id = inid;
}

// 곡명 설정
void PlaySongType::SetName(string inname) {
	ps_name = inname;
}

// SongType 변수 설정
void PlaySongType::SetRecord(int inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// 고유번호 입력
void PlaySongType::SetIdFromKB()
{
	cout << "\t고유번호 : ";
	cin >> ps_id;
}

// 곡명 입력
void PlaySongType::SetNameFromKB() {
	cout << "\t곡명 : ";
	cin >> ps_name;
}

// SongType 변수 입력
void PlaySongType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

// 고유번호 출력
void PlaySongType::DisplayIdOnScreen() {
	cout << "\t고유번호 : " << ps_id << endl;
}

// 곡명 출력
void PlaySongType::DisplayNameOnScreen() {
	cout << "\t곡명 : " << ps_name << endl;
}


// 간단한 음악정보 출력
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

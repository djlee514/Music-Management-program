#include "SongType.h"

// 생성자
SongType::SongType()
{
	s_name = "";
	s_id = 0;
}

// 소멸자
SongType::~SongType() {}


// 고유번호 얻기
int SongType::GetId() {
	return s_id;
}

// 곡명 얻기
string SongType::GetName() {
	return s_name;
}

// 고유번호 설정
void SongType::SetId(int inid) {
	s_id = inid;
}

// 곡명 설정
void SongType::SetName(string inname) {
	s_name = inname;
}

// SongType 변수 설정
void SongType::SetRecord(int inid, string inname)
{
	SetId(inid);
	SetName(inname);
}

// 고유번호 입력
void SongType::SetIdFromKB()
{
	cout << "\t고유번호 : ";
	cin >> s_id;
}

// 곡명 입력
void SongType::SetNameFromKB() {
	cout << "\t곡명 : ";
	cin >> s_name;
}

// SongType 변수 입력
void SongType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
}

// 고유번호 출력
void SongType::DisplayIdOnScreen() {
	cout << "\t고유번호 : " << s_id << endl;
}

// 곡명 출력
void SongType::DisplayNameOnScreen() {
	cout << "\t곡명 : " << s_name << endl;
}


// 간단한 음악정보 출력
void SongType::DisplayRecordOnScreen() 
{
	DisplayNameOnScreen();
	DisplayIdOnScreen();
}

int SongType::ReadDataFromFile(ifstream & fin)
{
	fin >> s_id;
	fin >> s_name;
	return 1;
}

int SongType::WriteDataToFile(ofstream & fout)
{
	fout << s_id << " ";
	fout << s_name << " ";
	fout << endl;
	return 1;
}

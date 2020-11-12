#include "MusicType.h"

// MusicType 생성자
MusicType::MusicType()
{
	m_id = "";
	m_name = "";
	m_istitle = "";
	m_singer = "";
	m_runningtime = "";
	m_genre = "";
	m_albumname = "";
	m_release = "";
	m_lyricist = "";
	m_songwriter = "";
	m_ent = "";
	m_highlight = "";
	m_playtime = 0;
}

// MusicType 소멸자
MusicType::~MusicType() {}

// 곡의 고유번호 리턴
string MusicType::GetId() const
{
	return m_id;
}

// 곡명 리턴
string MusicType::GetName()
{
	return m_name;
}

// 타이틀여부 리턴
string MusicType::GetIstitle()
{
	return m_istitle;
}

// 가수 리턴
string MusicType::GetSinger()
{
	return m_singer;
}

// 곡의 길이 리턴
string MusicType::GetRunningtime()
{
	return m_runningtime;
}

// 장르 리턴
string MusicType::GetGenre()
{
	return m_genre;
}

// 앨범명 리턴
string MusicType::GetAlbumname()
{
	return m_albumname;
}

// 발매일 리턴
string MusicType::GetRelease()
{
	return m_release;
}

// 작사가 리턴
string MusicType::GetLyricist()
{
	return m_lyricist;
}

// 작곡가 리턴
string MusicType::GetSongwriter()
{
	return m_songwriter;
}

// 소속사 리턴
string MusicType::GetEnt()
{
	return m_ent;
}

// 재생횟수 리턴
int MusicType::GetPlaytime()
{
	return m_playtime;
}

// 하이라이트 리턴
string MusicType::GetHighlight()
{
	return m_highlight;
}

// 고유번호 설정
void MusicType::SetId(string inid)
{
	m_id = inid;
}

// 곡명 설정
void MusicType::SetName(string inname)
{
	m_name = inname;
}

// 타이틀여부 설정
void MusicType::SetIstitle(string inistitle)
{
	m_istitle = inistitle;
}

// 가수 설정
void MusicType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// 곡의 길이 설정
void MusicType::SetRunningtime(string inrunningtime)
{
	m_runningtime = inrunningtime;
}

// 장르 설정
void MusicType::SetGenre(string ingenre)
{
	m_genre = ingenre;
}

// 앨범명 설정
void MusicType::SetAlbumname(string inalbumname)
{
	m_albumname = inalbumname;
}

// 발매일 설정
void MusicType::SetRelease(string inrelease)
{
	m_release = inrelease;
}

// 작사가 설정
void MusicType::SetLyricist(string inlyricist)
{
	m_lyricist = inlyricist;
}

// 작곡가 설정
void MusicType::SetSongwriter(string insongwriter)
{
	m_songwriter = insongwriter;
}

// 소속사 설정
void MusicType::SetEnt(string inent)
{
	m_ent = inent;
}

// 재생횟수 설정
void MusicType::SetPlaytime(int inplaytime)
{
	m_playtime = inplaytime;
}

// 하이라이트 설정
void MusicType::SetHighlight(string inhighlight)
{
	m_highlight = inhighlight;
}

// 입력값으로 해당 곡의 모든 정보 설정
void MusicType::SetRecord(string inid, string inname, string inistitle, string insinger, string inrunningtime, string ingenre, string inalbumname, string inrelease,
	string inlyricist, string insongwriter, string inent, int inplaytime, string inhighlight)
{
	SetId(inid);
	SetName(inname);
	SetIstitle(inistitle);
	SetSinger(insinger);
	SetRunningtime(inrunningtime);
	SetGenre(ingenre);
	SetAlbumname(inalbumname);
	SetRelease(inrelease);
	SetLyricist(inlyricist);
	SetSongwriter(insongwriter);
	SetEnt(inent);
	SetPlaytime(inplaytime);
	SetHighlight(inhighlight);
}

// 고유번호 출력
void MusicType::DisplayIdOnScreen()
{
	cout << "\t고유번호 : " << m_id << endl;
}

// 곡명 출력
void MusicType::DisplayNameOnScreen()
{
	cout << "\t곡명 : " << m_name << endl;
}

// 타이틀여부 출력
void MusicType::DisplayIstitleOnScreen()
{
	cout << "\t타이틀 : " << m_istitle << endl;
}

// 가수 출력
void MusicType::DisplaySingerOnScreen()
{
	cout << "\t가수 : " << m_singer << endl;
}

// 곡의 길이 출력
void MusicType::DisplayRunningtimeOnScreen()
{
	cout << "\t곡의 길이 : " << m_runningtime << endl;
}

// 장르 출력
void MusicType::DisplayGenreOnScreen()
{
	cout << "\t장르 : " << m_genre << endl;
}

// 앨범명 출력
void MusicType::DisplayAlbumnameOnScreen()
{
	cout << "\t앨범명 : " << m_albumname << endl;
}

// 발매일 출력
void MusicType::DisplayReleaseOnScreen()
{
	cout << "\t발매일 : " << m_release << endl;
}

// 작사가 출력
void MusicType::DisplayLyricistOnScreen()
{
	cout << "\t작사가 : " << m_lyricist << endl;
}

// 작곡가 출력
void MusicType::DisplaySongwriterOnScreen()
{
	cout << "\t작곡가 : " << m_songwriter << endl;
}

// 소속사 출력
void MusicType::DisplayEntOnScreen()
{
	cout << "\t소속사 : " << m_ent << endl;
}

// 재생횟수 출력
void MusicType::DisplayPlaytimeOnScreen()
{
	cout << "\t재생 횟수 : " << m_playtime << endl;
}

// 하이라이트 출력
void MusicType::DisplayHighlightOnScreen()
{
	cout << "\t하이라이트 : " << m_highlight << endl;
}

// 곡의 모든 정보 출력
void MusicType::DisplayRecordOnScreen()
{
	cout << "\n\t♬ 곡 정보 ♬ " << endl;
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayIstitleOnScreen();
	DisplaySingerOnScreen();
	DisplayRunningtimeOnScreen();
	DisplayGenreOnScreen();
	DisplayAlbumnameOnScreen();
	DisplayReleaseOnScreen();
	DisplayLyricistOnScreen();
	DisplaySongwriterOnScreen();
	DisplayEntOnScreen();
	DisplayPlaytimeOnScreen();
	DisplayHighlightOnScreen();
}

// 고유번호 입력
void MusicType::SetIdFromKB()
{
	cout << "\t고유번호 : ";
	cin >> m_id;
}

// 곡명 입력
void MusicType::SetNameFromKB()
{
	cout << "\t곡명 : ";
	cin >> m_name;
}

// 타이틀여부 입력
void MusicType::SetIstitleFromKB()
{
	cout << "\t타이틀 : ";
	cin >> m_istitle;
}

// 가수 입력
void MusicType::SetSingerFromKB()
{
	cout << "\t가수 : ";
	cin >> m_singer;
}

// 곡의 길이 입력
void MusicType::SetRunningtimeFromKB()
{
	cout << "\t곡의 길이 : ";
	cin >> m_runningtime;
}

// 장르 입력
void MusicType::SetGenreFromKB()
{
	cout << "\t장르 : ";
	cin >> m_genre;
}

// 앨범명 입력
void MusicType::SetAlbumnameFromKB()
{
	cout << "\t앨범명 : ";
	cin >> m_albumname;
}

// 발매일 입력
void MusicType::SetReleaseFromKB()
{
	cout << "\t발매일 : ";
	cin >> m_release;
}

// 작사가 입력
void MusicType::SetLyricistFromKB()
{
	cout << "\t작사가 : ";
	cin >> m_lyricist;
}

// 작곡가 입력
void MusicType::SetSongwriterFromKB()
{
	cout << "\t작곡가 : ";
	cin >> m_songwriter;
}

// 소속사 입력
void MusicType::SetEntFromKB()
{
	cout << "\t소속사 : ";
	cin >> m_ent;
}

// 재생횟수 입력
void MusicType::SetPlaytimeFromKB()
{
	cout << "\t재생 횟수 : ";
	cin >> m_playtime;
}

// 하이라이트 입력
void MusicType::SetHighlightFromKB()
{
	cout << "\t하이라이트 : ";
	getline(cin, m_highlight);
}

// 곡의 모든 정보 입력
void MusicType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetIstitleFromKB();
	SetSingerFromKB();
	SetRunningtimeFromKB();
	SetGenreFromKB();
	SetAlbumnameFromKB();
	SetReleaseFromKB();
	SetLyricistFromKB();
	SetSongwriterFromKB();
	SetEntFromKB();
	SetPlaytimeFromKB();
	SetHighlightFromKB();
}

// 파일로부터 곡의 정보 읽기
int MusicType::ReadDataFromFile(ifstream & fin)
{
	fin >> m_id;
	fin >> m_name;
	fin >> m_istitle;
	fin >> m_singer;
	fin >> m_runningtime;
	fin >> m_genre;
	fin >> m_albumname;
	fin >> m_release;
	fin >> m_lyricist;
	fin >> m_songwriter;
	fin >> m_ent;
	fin >> m_playtime;
	getline(fin, m_highlight);

	return 1;
}

// 파일에 곡의 정보 쓰기
int MusicType::WriteDataToFile(ofstream & fout)
{
	fout << m_id << " ";
	fout << m_name << " ";
	fout << m_istitle << " ";
	fout << m_singer << " ";
	fout << m_runningtime << " ";
	fout << m_genre << " ";
	fout << m_albumname << " ";
	fout << m_release << " ";
	fout << m_lyricist << " ";
	fout << m_songwriter << " ";
	fout << m_ent << " ";
	fout << m_playtime << " ";
	fout << m_highlight;
	fout << endl;

	return 1;
}
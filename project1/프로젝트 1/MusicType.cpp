#include "MusicType.h"

// MusicType ������
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

// MusicType �Ҹ���
MusicType::~MusicType() {}

// ���� ������ȣ ����
string MusicType::GetId() const
{
	return m_id;
}

// ��� ����
string MusicType::GetName()
{
	return m_name;
}

// Ÿ��Ʋ���� ����
string MusicType::GetIstitle()
{
	return m_istitle;
}

// ���� ����
string MusicType::GetSinger()
{
	return m_singer;
}

// ���� ���� ����
string MusicType::GetRunningtime()
{
	return m_runningtime;
}

// �帣 ����
string MusicType::GetGenre()
{
	return m_genre;
}

// �ٹ��� ����
string MusicType::GetAlbumname()
{
	return m_albumname;
}

// �߸��� ����
string MusicType::GetRelease()
{
	return m_release;
}

// �ۻ簡 ����
string MusicType::GetLyricist()
{
	return m_lyricist;
}

// �۰ ����
string MusicType::GetSongwriter()
{
	return m_songwriter;
}

// �Ҽӻ� ����
string MusicType::GetEnt()
{
	return m_ent;
}

// ���Ƚ�� ����
int MusicType::GetPlaytime()
{
	return m_playtime;
}

// ���̶���Ʈ ����
string MusicType::GetHighlight()
{
	return m_highlight;
}

// ������ȣ ����
void MusicType::SetId(string inid)
{
	m_id = inid;
}

// ��� ����
void MusicType::SetName(string inname)
{
	m_name = inname;
}

// Ÿ��Ʋ���� ����
void MusicType::SetIstitle(string inistitle)
{
	m_istitle = inistitle;
}

// ���� ����
void MusicType::SetSinger(string insinger)
{
	m_singer = insinger;
}

// ���� ���� ����
void MusicType::SetRunningtime(string inrunningtime)
{
	m_runningtime = inrunningtime;
}

// �帣 ����
void MusicType::SetGenre(string ingenre)
{
	m_genre = ingenre;
}

// �ٹ��� ����
void MusicType::SetAlbumname(string inalbumname)
{
	m_albumname = inalbumname;
}

// �߸��� ����
void MusicType::SetRelease(string inrelease)
{
	m_release = inrelease;
}

// �ۻ簡 ����
void MusicType::SetLyricist(string inlyricist)
{
	m_lyricist = inlyricist;
}

// �۰ ����
void MusicType::SetSongwriter(string insongwriter)
{
	m_songwriter = insongwriter;
}

// �Ҽӻ� ����
void MusicType::SetEnt(string inent)
{
	m_ent = inent;
}

// ���Ƚ�� ����
void MusicType::SetPlaytime(int inplaytime)
{
	m_playtime = inplaytime;
}

// ���̶���Ʈ ����
void MusicType::SetHighlight(string inhighlight)
{
	m_highlight = inhighlight;
}

// �Է°����� �ش� ���� ��� ���� ����
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

// ������ȣ ���
void MusicType::DisplayIdOnScreen()
{
	cout << "\t������ȣ : " << m_id << endl;
}

// ��� ���
void MusicType::DisplayNameOnScreen()
{
	cout << "\t��� : " << m_name << endl;
}

// Ÿ��Ʋ���� ���
void MusicType::DisplayIstitleOnScreen()
{
	cout << "\tŸ��Ʋ : " << m_istitle << endl;
}

// ���� ���
void MusicType::DisplaySingerOnScreen()
{
	cout << "\t���� : " << m_singer << endl;
}

// ���� ���� ���
void MusicType::DisplayRunningtimeOnScreen()
{
	cout << "\t���� ���� : " << m_runningtime << endl;
}

// �帣 ���
void MusicType::DisplayGenreOnScreen()
{
	cout << "\t�帣 : " << m_genre << endl;
}

// �ٹ��� ���
void MusicType::DisplayAlbumnameOnScreen()
{
	cout << "\t�ٹ��� : " << m_albumname << endl;
}

// �߸��� ���
void MusicType::DisplayReleaseOnScreen()
{
	cout << "\t�߸��� : " << m_release << endl;
}

// �ۻ簡 ���
void MusicType::DisplayLyricistOnScreen()
{
	cout << "\t�ۻ簡 : " << m_lyricist << endl;
}

// �۰ ���
void MusicType::DisplaySongwriterOnScreen()
{
	cout << "\t�۰ : " << m_songwriter << endl;
}

// �Ҽӻ� ���
void MusicType::DisplayEntOnScreen()
{
	cout << "\t�Ҽӻ� : " << m_ent << endl;
}

// ���Ƚ�� ���
void MusicType::DisplayPlaytimeOnScreen()
{
	cout << "\t��� Ƚ�� : " << m_playtime << endl;
}

// ���̶���Ʈ ���
void MusicType::DisplayHighlightOnScreen()
{
	cout << "\t���̶���Ʈ : " << m_highlight << endl;
}

// ���� ��� ���� ���
void MusicType::DisplayRecordOnScreen()
{
	cout << "\n\t�� �� ���� �� " << endl;
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

// ������ȣ �Է�
void MusicType::SetIdFromKB()
{
	cout << "\t������ȣ : ";
	cin >> m_id;
}

// ��� �Է�
void MusicType::SetNameFromKB()
{
	cout << "\t��� : ";
	cin >> m_name;
}

// Ÿ��Ʋ���� �Է�
void MusicType::SetIstitleFromKB()
{
	cout << "\tŸ��Ʋ : ";
	cin >> m_istitle;
}

// ���� �Է�
void MusicType::SetSingerFromKB()
{
	cout << "\t���� : ";
	cin >> m_singer;
}

// ���� ���� �Է�
void MusicType::SetRunningtimeFromKB()
{
	cout << "\t���� ���� : ";
	cin >> m_runningtime;
}

// �帣 �Է�
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣 : ";
	cin >> m_genre;
}

// �ٹ��� �Է�
void MusicType::SetAlbumnameFromKB()
{
	cout << "\t�ٹ��� : ";
	cin >> m_albumname;
}

// �߸��� �Է�
void MusicType::SetReleaseFromKB()
{
	cout << "\t�߸��� : ";
	cin >> m_release;
}

// �ۻ簡 �Է�
void MusicType::SetLyricistFromKB()
{
	cout << "\t�ۻ簡 : ";
	cin >> m_lyricist;
}

// �۰ �Է�
void MusicType::SetSongwriterFromKB()
{
	cout << "\t�۰ : ";
	cin >> m_songwriter;
}

// �Ҽӻ� �Է�
void MusicType::SetEntFromKB()
{
	cout << "\t�Ҽӻ� : ";
	cin >> m_ent;
}

// ���Ƚ�� �Է�
void MusicType::SetPlaytimeFromKB()
{
	cout << "\t��� Ƚ�� : ";
	cin >> m_playtime;
}

// ���̶���Ʈ �Է�
void MusicType::SetHighlightFromKB()
{
	cout << "\t���̶���Ʈ : ";
	getline(cin, m_highlight);
}

// ���� ��� ���� �Է�
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

// ���Ϸκ��� ���� ���� �б�
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

// ���Ͽ� ���� ���� ����
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
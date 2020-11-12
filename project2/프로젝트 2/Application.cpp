#include "Application.h"

// Application 생성자
Application::Application()
{
	m_Command = 0;
}

// Application 소멸자
Application::~Application() {}

// 기본 프로그램 실행
void Application::RunProgram()
{
	while (true)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{	
		case 0:
			cout << "\t음원관리 프로그램을 닫습니다." << endl;
			return;
		case 1:
			Admin();	// 관리자용 모드 로그인 실행
			break;
		case 2:
			User();				// 일반 사용자용 모드로 실행
			break;
		default:
			cout << "\t잘못된 명령입니다. 다시 입력하세요." << endl;
			break;
		}
	}
}

// 사용가능한 모드를 출력하고 선택하여 해당하는 명령어를 반환
int Application::GetCommand()
{
	int com;
	cout << "\n\t-------- 음원관리 프로그램 ----------" << endl;
	cout << "\t|  0 : 음원관리 프로그램 종료       |" << endl;
	cout << "\t|  1 : 프로그램 관리자 지원용 모드  |" << endl;
	cout << "\t|  2 : 일반 사용자 지원용 모드      |" << endl;
	cout << "\t-------------------------------------" << endl;

	cout << "\t사용할 모드를 입력하세요--> ";
	cin >> com;
	cout << endl;

	return com;
}

// 관리자용 모드로 로그인 조건 확인 후 인증되면 관리자 모드 실행
void Application::Admin()
{
	while (true)
	{
		string id, pw;
		cout << endl << endl;
		cout << "\t------------------ 관리자용 모드 ------------------" << endl;
		cout << "\t로그인 인증을 실행합니다." << endl;
		cout << "\tID : ";
		cin >> id;
		cout << "\tPW : ";
		cin >> pw;
		cout << "\t---------------------------------------------------" << endl;
		if (id == "ehdwn514"&&pw == "2015103278")
		{
			system("cls");
			Run_Admin();
			return;
		}
		else
			cout << "\t관리자로 등록되지 않은 정보입니다." << endl;
	}
}

// 사용자용 모드로 로그인 조건 확인 후 인증되면 사용자 모드 실행
void Application::User()
{
	while (true)
	{
		cout << endl << endl;
		int com;

		cout << "\t------------------ 사용자 인증 모드 ------------------" << endl;
		cout << "\t   0 : 사용자 인증모드 종료" << endl;
		cout << "\t   1 : 로그인" << endl;
		cout << "\t   2 : 회원가입" << endl;
		cout << "\t------------------------------------------------------" << endl;

		cout << "\n\t실행할 명령어를 선택하세요--> ";
		cin >> com;
		cout << endl;

		switch (com)
		{
		case 0:
			system("cls");
			return;
		case 1:
			system("cls");
			Login_User();
			break;
		case 2:
			system("cls");
			SignUp_User();
			break;
		default:
			cout << "\t 실행할 수 없는 명령입니다." << endl;
		}
	}
}

// 사용자용 모드 로그인 인증과정
void Application::Login_User()
{
	while (true)
	{
		UserType user;
		cout << "\n\t----------- 로그인 -----------" << endl;
		user.SetIdFromKB();
		user.SetPwFromKB();
		cout << "\t------------------------------" << endl;

		UserType data;
		data.SetId(user.GetId());
		if (UserList.Get(data))
		{
			if (user.GetId() == data.GetId() && user.GetPw() == data.GetPw())
			{
				system("cls");
				cout << "\n\t로그인에 성공했습니다." << endl;
				char id;
				cout << "\n\t로그인한 ID를 다시 입력해주세요. ";
				cin >> id;
				Read_User(id);
				Run_User();
				return;
			}
			else
			{
				cout << "\n\t로그인에 실패했습니다." << endl;
				cout << "\t아이디 혹은 비밀번호가 일치하지 않습니다." << endl;
				cout << "\t초기화면으로 돌아가려면 y를 입력하세요." << endl;
				string reply;
				cin >> reply;
				if (reply == "y")
				{
					system("cls");
					break;
				}
			}
		}
		else
		{
			cout << "\n\t유저정보에 일치하는 정보가 없습니다." << endl;
			cout << "\t초기화면으로 돌아가려면 y를 입력하세요." << endl;
			string reply;
			cin >> reply;
			if (reply == "y")
			{
				system("cls");
				break;
			}
		}		
	}
}

// 사용자용 모드 회원가입
void Application::SignUp_User()
{
	while (true)
	{
		UserType user;
		cout << "\n\t------------ 유저 회원가입 ------------" << endl; 
		cout << "\t가입할 정보를 입력하세요." << endl;
		user.SetRecordFromKB();
		cout << "\t---------------------------------------" << endl;

		if (UserList.Get(user))
		{
			system("cls");
			cout << "\n\t해당 정보로 이미 회원가입이 되어있습니다." << endl;
			break;
		}
		else
		{
			system("cls");
			UserList.Add(user);
			cout << "\n\t회원가입이 정상적으로 완료되었습니다." << endl;
			break;
		}
	}
}

// 일반 사용자 지원용 모드에서 사용가능한 명령어들을 요청에 따라 실행
void Application::Run_User()
{
	while (true)
	{
		cout << endl << endl;
		int com;

		cout << "\t------------------ 유저 모드 ------------------" << endl;
		cout << "\t   0 : 유저 모드 종료" << endl;
		cout << "\t   1 : 사용자 음원목록에 음악 추가" << endl;
		cout << "\t   2 : 사용자 음원목록에서 음악 제거" << endl;
		cout << "\t   3 : 사용자 음원목록에 있는 음악 정보 출력" << endl;
		cout << "\t   4 : 사용자 음원목록에 최근 추가된 곡으로 검색" << endl;
		cout << "\t   5 : 사용자 음원목록에서 곡의 고유번호를 통해 검색" << endl;
		cout << "\t   6 : 사용자 음원목록에서 곡명을 통해 검색" << endl;
		cout << "\t   7 : 사용자 음원목록에서 가수명을 통해 검색" << endl;
		cout << "\t   8 : 사용자 음원목록에서 장르를 통해 검색" << endl;
		cout << "\t   9 : 사용자 음원목록에서 앨범명을 통해 검색" << endl;
		cout << "\t   10 : 사용자 음원목록에서 소속사를 통해 검색" << endl;;
		cout << "\t---------------------------------------------" << endl;

		cout << "\n\t실행할 명령어를 선택하세요--> ";
		cin >> com;
		cout << endl;

		
		switch (com)
		{
		case 0:			// 0을 입력하면 Release 모드 종료
			system("cls");
			cout << "\n\t로그아웃하고 유저모드를 종료합니다." << endl;
			Save_User();
			return;
		case 1:			// 1일 때 Release program AddMusic 실행
			system("cls");
			AddMusic_User();		
			break;
		case 2:			// 2일 때 Release program DeleteMusic 실행
			system("cls");
			DeleteMusic_User();
			break;
		case 3:			// 3일 때 Release program DisplayAllMusic 실행
			system("cls");
			DisplayAllMusic_User();
			break;
		case 4:
			system("cls");
			SearchByRecentlyMusic_User();
			break;
		case 5:			// 4일 때 Release program SearchById 실행
			system("cls");
			SearchById_User();
			break;
		case 6:			// 5일 때 Release program SearchByName 실행
			system("cls");
			SearchByName_User();
			break;
		case 7:			// 6일 때 Release program SearchBySinger 실행
			system("cls");
			SearchBySinger_User();
			break;
		case 8:			// 7일 때 Release program SearchByGenre 실행
			system("cls");
			SearchByGenre_User();
			break;
		case 9:			// 8일 때 Release program SearchByAlbumName 실행
			system("cls");
			SearchByAlbumName_User();
			break;
		case 10:		// 9일 때 Release program SearchByEnt 실행
			system("cls");
			SearchByEnt_User();
			break;
		/*case 11:
			system("cls");
			PlayMusic_User();*/
		default:		// 그 외의 값 입력하면 default로 설정한 문구 출력
			cout << "\t실행할 수 없는 명령입니다." << endl;
			break;
		}
	}
}

// 관리자 지원용 모드에서 사용가능한 명령어들을 요청에 따라 실행
void Application::Run_Admin()
{
	while (true)
	{
		cout << endl << endl;
		int com;
		cout << "\t-------------------- 관리자용 모드 -------------------" << endl;
		cout << "\t   0 : 관리자용 모드 종료" << endl;
		cout << "\t   1 : 음원 추가" << endl;
		cout << "\t   2 : 음원 삭제" << endl;
		cout << "\t   3 : 음원 갱신" << endl;
		cout << "\t   4 : 마스터리스트 가져오기" << endl;
		cout << "\t   5 : 모든 음악 출력" << endl;
		cout << "\t------------------------------------------------------" << endl;

		cout << "\n\t실행할 명령어를 선택하세요--> ";
		cin >> com;
		cout << endl;


		switch (com)
		{
		case 0:
			system("cls");
			cout << "\n\t로그아웃하고 관리자모드를 종료합니다." << endl;
			/*Save_Admin();*/
			return;
		case 1:
			AddMusic_Admin();
			break;
		case 2:
			DeleteMusic_Admin();
			break;
		case 3:
			ReplaceMusic_Admin();
			break;
		case 4:
			LoadMasterList_Admin();
			break;
		case 5:
			DisplayAllMusic_Admin();
			break;
		default:
			cout << "\t실행할 수 없는 명령입니다." << endl;
			break;
		}
	}
}

// 마스터리스트에 음악 추가
void Application::AddMusic_Admin()
{
	MusicType music;
	cout << "\n\t추가할 음원의 정보를 입력하세요\n";
	music.SetRecordFromKB();
	MasterList.Add(music);

	
	//

	// AlbumList에 추가할 때 이미 존재하는 앨범에 추가가 안 들어감.

	//

	// AlbumList에 추가
	if (AlbumList.GetLength() == 0)					// AlbumList가 비어있을 때 
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
		album.SetNumberofsonginalbumIncrease();										// 앨범 수록곡 수 1 증가
		simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum 설정
		album.AddMusicToAlbum(simple);												// album에 추가
		AlbumList.Add(album);														// album을 AlbumList에 추가
	}
	else											// AlbumList에 원소가 존재할 때	
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
		simple.SetRecord(music.GetId(), music.GetName());

		AlbumType temp;																// AlbumType 임시변수
		int test = 0;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(temp) != -1)									// AlbumList 끝까지 검색
		{
			if (temp.GetAlbumname() == album.GetAlbumname())	// 추가할 앨범명이 AlbumList에 존재할 경우
			{
				temp.AddMusicToAlbum(simple);										// 해당 앨범에 추가
				temp.SetNumberofsonginalbumIncrease();
				AlbumList.Replace(temp);											// AlbumList를 갱신
				test++;
				break;
			}
		}
		if (test == 0)								// 추가할 앨범명이 AlbumList에 없을 경우
		{
			album.AddMusicToAlbum(simple);											// 새로운 album에 추가
			album.SetNumberofsonginalbumIncrease();									// 해당 앨범 수록곡수 1 증가
			AlbumList.Add(album);													// AlbumList에 해당 앨범 추가
			/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
			temp.SetNumberofsonginalbumIncrease();
			temp.AddMusicToAlbum(simple);
			AlbumList.Add(temp);*/
		}
	}


	// GenreList에 추가
	if (GenreList.GetLength() == 0)					// GenreList가 비어있을 때
	{
		GenreType genre;
		SongType song;
		genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
		song.SetId(music.GetId());													// 추가할 곡의 Id를 설정
		song.SetName(music.GetName());												// 추가할 곡의 곡명을 설정
		genre.AddMusicInGenre(song);												// genre에 곡의 정보 추가
		GenreList.Add(genre);														// GenreList에 해당 genre를 추가
	}
	else											// GenreList에 원소가 있을 때
	{
		GenreType genre;
		SongType song;

		genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
		song.SetId(music.GetId());													// 추가할 곡의 id 설정
		song.SetName(music.GetName());												// 추가할 곡의 곡명 설정

		GenreType temp;
		int test = 0;
		while (GenreList.GetNextItem(temp) != -1)									// GenreList 끝까지 검색
		{
			if (temp.GetGenre() == music.GetGenre())	// GenreList에 검색할 곡의 장르가 존재할 경우
			{
				temp.AddMusicInGenre(song);											// 해당 장르에 곡 추가
				GenreList.Replace(temp);											// GenreList를 갱신
				test++;
				break;
			}
		}
		if (test == 0)								// GenreList에 검색할 곡의 장르가 없을 경우
		{
			genre.AddMusicInGenre(song);											// 새로운 장르에 추가
			GenreList.Add(genre);													// GenreList에 추가
		}
	}


	// SingerList에 추가
	if (SingerList.GetLength() == 0)				// SingerList에 원소가 없을 경우
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
		album.SetNumberofsonginalbumIncrease();										// album 수록곡수 1 증가
		simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
		album.AddMusicToAlbum(simple);												// album에 정보 추가
		singer.AddMusicToSinger(album);												// singer에 album 추가
		SingerList.Add(singer);														// SingerList에 singer 추가
	}
	else											// SingerList에 원소가 있을 경우
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;
		singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
		if (SingerList.Get(singer))					// SingerList에 추가할 가수가 존재할 경우
		{
			singer.AddMusicToSinger(album, simple);									// 가수에 album과 간단한 정보를 추가
			SingerList.Delete(singer);												// SingerList에서 해당 가수를 삭제
			SingerList.Add(singer);													// SingerList에 갱신된 정보의 가수를 추가
		}
		else										// SingerList에 추가할 가수가 없을 경우
		{
			album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
			album.AddMusicToAlbum(simple);											// album에 정보 추가
			singer.AddMusicToSinger(album);											// singer에 album 추가
			SingerList.Add(singer);													// SingerList에 singer 추가
		}
	}



	// EntList에 추가
	if (EntList.GetLength() == 0)					// EntList에 원소가 없을 경우
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
		singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
		album.AddMusicToAlbum(simple);												// album에 간단한 정보 추가
		singer.AddMusicToSinger(album);												// singer에 album 추가
		ent.AddMusicToEnt(singer);													// ent에 singer 추가
		EntList.Add(ent);															// EntList에 ent 추가
	}
	else											// EntList에 원소가 있을 경우
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
		singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
		if (EntList.Get(ent))						// EntList에 추가할 소속사가 있을 경우
		{
			ent.AddMusicToEnt(singer, album);										// ent에 singer와 album의 정보 추가
			EntList.Delete(ent);													// EntList에서 ent 제거
			EntList.Add(ent);														// EntList에 갱신된 ent 추가
		}
		else										// EntList에 추가할 소속사가 없을 경우
		{
			album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
			album.AddMusicToAlbum(simple);											// album에 간단한 정보 추가
			singer.AddMusicToSinger(album);											// singer에 album 추가
			ent.AddMusicToEnt(singer);												// ent에 singer 추가
			EntList.Add(ent);														// EntList에 ent 추가
		}
	}
}


// 마스터리스트에서 음악 삭제
void Application::DeleteMusic_Admin()
{
	cout << "\t삭제를 할 곡의 고유번호를 입력하세요." << endl;
	MusicType music;
	music.SetIdFromKB();
	if (MasterList.Get(music))
	{
		// 마스터리스트에서 제거
		MasterList.Delete(music);

		// AlbumList에서 제거
		AlbumType album1;
		album1.SetAlbumname(music.GetAlbumname());
		SimpleTypeForAlbum simple1;
		simple1.SetRecord(music.GetId(), music.GetName());

		if (AlbumList.Get(album1))
		{
			if (album1.DeleteMusicFromAlbum(simple1))
			{
				AlbumList.Delete(album1);
			}
		}

		// SingerList에서 제거
		SingerType singer;
		singer.SetSinger(music.GetSinger());
		AlbumType album2;
		SimpleTypeForAlbum simple2;
		album2.SetAlbumname(music.GetAlbumname());
		simple2.SetRecord(music.GetId(), music.GetName());

		if (SingerList.Get(singer))
		{
			if (singer.DeleteMusicFromSinger(album2, simple2) == 1)
			{
				SingerList.Delete(singer);
			}
		}

		// GenreList에서 제거
		GenreType genre;
		genre.SetGenre(music.GetName());
		SongType song;
		song.SetRecord(music.GetId(), music.GetName());

		if (GenreList.Get(genre))
		{
			if (genre.DeleteMusicInGenre(song) == 1)
			{
				GenreList.Delete(genre);
			}
		}

		// EntList에서 제거
		EntType ent;
		ent.SetEnt(music.GetEnt());
		SingerType singer2;
		singer2.SetSinger(music.GetSinger());

		if (EntList.Get(ent))
		{
			if (ent.DeleteMusicFromEnt(singer2) == 1)
			{
				EntList.Delete(ent);
			}
		}

		cout << "\n\t삭제를 완료했습니다." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\t삭제에 실패했습니다. 일치하는 음악이 마스터리스트에 존재하지 않습니다." << endl;
	}
}

// 마스터리스트 갱신
void Application::ReplaceMusic_Admin()
{
	cout << "\n\t갱신할 곡의 고유번호를 입력하세요" << endl;
	MusicType music;
	music.SetIdFromKB();
	if (MasterList.Get(music))
	{
		// 마스터리스트에서 제거
		MasterList.Delete(music);

		// AlbumList에서 제거
		AlbumType album1;
		album1.SetAlbumname(music.GetAlbumname());
		SimpleTypeForAlbum simple1;
		simple1.SetRecord(music.GetId(), music.GetName());

		if (AlbumList.Get(album1))
		{
			if (album1.DeleteMusicFromAlbum(simple1))
			{
				AlbumList.Delete(album1);
			}
		}

		// SingerList에서 제거
		SingerType singer;
		singer.SetSinger(music.GetSinger());
		AlbumType album2;
		SimpleTypeForAlbum simple2;
		album2.SetAlbumname(music.GetAlbumname());
		simple2.SetRecord(music.GetId(), music.GetName());

		if (SingerList.Get(singer))
		{
			if (singer.DeleteMusicFromSinger(album2, simple2) == 1)
			{
				SingerList.Delete(singer);
			}
		}

		// GenreList에서 제거
		GenreType genre;
		genre.SetGenre(music.GetName());
		SongType song;
		song.SetRecord(music.GetId(), music.GetName());

		if (GenreList.Get(genre))
		{
			if (genre.DeleteMusicInGenre(song) == 1)
			{
				GenreList.Delete(genre);
			}
		}

		// EntList에서 제거
		EntType ent;
		ent.SetEnt(music.GetEnt());
		SingerType singer2;
		singer2.SetSinger(music.GetSinger());

		if (EntList.Get(ent))
		{
			if (ent.DeleteMusicFromEnt(singer2) == 1)
			{
				EntList.Delete(ent);
			}
		}

		music.SetIdFromKB();
		music.SetNameFromKB();
		music.SetIstitleFromKB();
		music.SetSingerFromKB();
		music.SetRunningtimeFromKB();
		music.SetGenreFromKB();
		music.SetAlbumnameFromKB();
		music.SetReleaseFromKB();
		music.SetLyricistFromKB();
		music.SetSongwriterFromKB();
		music.SetEntFromKB();
		music.SetPlaytimeFromKB();
		music.SetHighlightFromKB();


		// 새로 입력받은 항목 추가
		MasterList.Add(music);

		// AlbumList에 추가
		if (AlbumList.GetLength() == 0)					// AlbumList가 비어있을 때 
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
			album.SetNumberofsonginalbumIncrease();										// 앨범 수록곡 수 1 증가
			simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum 설정
			album.AddMusicToAlbum(simple);												// album에 추가
			AlbumList.Add(album);														// album을 AlbumList에 추가
		}
		else											// AlbumList에 원소가 존재할 때	
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
			simple.SetRecord(music.GetId(), music.GetName());

			AlbumType temp;																// AlbumType 임시변수
			int test = 0;
			while (AlbumList.GetNextItem(temp) != -1)									// AlbumList 끝까지 검색
			{
				if (temp.GetAlbumname() == album.GetAlbumname())	// 추가할 앨범명이 AlbumList에 존재할 경우
				{
					temp.AddMusicToAlbum(simple);										// 해당 앨범에 추가
					temp.SetNumberofsonginalbumIncrease();
					AlbumList.Replace(temp);											// AlbumList를 갱신
					test++;
					break;
				}
			}
			if (test == 0)								// 추가할 앨범명이 AlbumList에 없을 경우
			{
				album.AddMusicToAlbum(simple);											// 새로운 album에 추가
				album.SetNumberofsonginalbumIncrease();									// 해당 앨범 수록곡수 1 증가
				AlbumList.Add(album);													// AlbumList에 해당 앨범 추가
				/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
				temp.SetNumberofsonginalbumIncrease();
				temp.AddMusicToAlbum(simple);
				AlbumList.Add(temp);*/
			}
		}


		// GenreList에 추가
		if (GenreList.GetLength() == 0)					// GenreList가 비어있을 때
		{
			GenreType genre;
			SongType song;
			genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
			song.SetId(music.GetId());													// 추가할 곡의 Id를 설정
			song.SetName(music.GetName());												// 추가할 곡의 곡명을 설정
			genre.AddMusicInGenre(song);												// genre에 곡의 정보 추가
			GenreList.Add(genre);														// GenreList에 해당 genre를 추가
		}
		else											// GenreList에 원소가 있을 때
		{
			GenreType genre;
			SongType song;

			genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
			song.SetId(music.GetId());													// 추가할 곡의 id 설정
			song.SetName(music.GetName());												// 추가할 곡의 곡명 설정

			GenreType temp;
			int test = 0;
			while (GenreList.GetNextItem(temp) != -1)									// GenreList 끝까지 검색
			{
				if (temp.GetGenre() == music.GetGenre())	// GenreList에 검색할 곡의 장르가 존재할 경우
				{
					temp.AddMusicInGenre(song);											// 해당 장르에 곡 추가
					GenreList.Replace(temp);											// GenreList를 갱신
					test++;
					break;
				}
			}
			if (test == 0)								// GenreList에 검색할 곡의 장르가 없을 경우
			{
				genre.AddMusicInGenre(song);											// 새로운 장르에 추가
				GenreList.Add(genre);													// GenreList에 추가
			}
		}


		// SingerList에 추가
		if (SingerList.GetLength() == 0)				// SingerList에 원소가 없을 경우
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
			album.SetNumberofsonginalbumIncrease();										// album 수록곡수 1 증가
			simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
			album.AddMusicToAlbum(simple);												// album에 정보 추가
			singer.AddMusicToSinger(album);												// singer에 album 추가
			SingerList.Add(singer);														// SingerList에 singer 추가
		}
		else											// SingerList에 원소가 있을 경우
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;
			singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
			if (SingerList.Get(singer))					// SingerList에 추가할 가수가 존재할 경우
			{
				singer.AddMusicToSinger(album, simple);									// 가수에 album과 간단한 정보를 추가
				SingerList.Delete(singer);												// SingerList에서 해당 가수를 삭제
				SingerList.Add(singer);													// SingerList에 갱신된 정보의 가수를 추가
			}
			else										// SingerList에 추가할 가수가 없을 경우
			{
				album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
				album.AddMusicToAlbum(simple);											// album에 정보 추가
				singer.AddMusicToSinger(album);											// singer에 album 추가
				SingerList.Add(singer);													// SingerList에 singer 추가
			}
		}



		// EntList에 추가
		if (EntList.GetLength() == 0)					// EntList에 원소가 없을 경우
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
			singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
			album.AddMusicToAlbum(simple);												// album에 간단한 정보 추가
			singer.AddMusicToSinger(album);												// singer에 album 추가
			ent.AddMusicToEnt(singer);													// ent에 singer 추가
			EntList.Add(ent);															// EntList에 ent 추가
		}
		else											// EntList에 원소가 있을 경우
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
			singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
			if (EntList.Get(ent))						// EntList에 추가할 소속사가 있을 경우
			{
				ent.AddMusicToEnt(singer, album);										// ent에 singer와 album의 정보 추가
				EntList.Delete(ent);													// EntList에서 ent 제거
				EntList.Add(ent);														// EntList에 갱신된 ent 추가
			}
			else										// EntList에 추가할 소속사가 없을 경우
			{
				album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
				album.AddMusicToAlbum(simple);											// album에 간단한 정보 추가
				singer.AddMusicToSinger(album);											// singer에 album 추가
				ent.AddMusicToEnt(singer);												// ent에 singer 추가
				EntList.Add(ent);														// EntList에 ent 추가
			}
		}
		system("cls");
		cout << "\n\t새로 입력한 항목으로 마스터리스트가 갱신되었습니다." << endl;
	}
}

// 마스터리스트 가져오기
int Application::LoadMasterList_Admin()
{
	int index = 0;
	MusicType music;

	char filename[FILENAMESIZE];
	cout << "\n\t불러올 파일명을 입력하세요 : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof())
	{
		music.ReadDataFromFile(m_InFile);
		MasterList.Add(music);
	

		// AlbumList에 추가
		if (AlbumList.GetLength() == 0)					// AlbumList가 비어있을 때 
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
			album.SetNumberofsonginalbumIncrease();										// 앨범 수록곡 수 1 증가
			simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum 설정
			album.AddMusicToAlbum(simple);												// album에 추가
			AlbumList.Add(album);														// album을 AlbumList에 추가
		}
		else											// AlbumList에 원소가 존재할 때	
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
			simple.SetRecord(music.GetId(), music.GetName());

			AlbumType temp;																// AlbumType 임시변수
			int test = 0;
			while (AlbumList.GetNextItem(temp) != -1)									// AlbumList 끝까지 검색
			{
				if (temp.GetAlbumname() == album.GetAlbumname())	// 추가할 앨범명이 AlbumList에 존재할 경우
				{
					temp.AddMusicToAlbum(simple);										// 해당 앨범에 추가
					temp.SetNumberofsonginalbumIncrease();
					AlbumList.Replace(temp);											// AlbumList를 갱신
					test++;
					break;
				}
			}
			if (test == 0)								// 추가할 앨범명이 AlbumList에 없을 경우
			{
				album.AddMusicToAlbum(simple);											// 새로운 album에 추가
				album.SetNumberofsonginalbumIncrease();									// 해당 앨범 수록곡수 1 증가
				AlbumList.Add(album);													// AlbumList에 해당 앨범 추가
				/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
				temp.SetNumberofsonginalbumIncrease();
				temp.AddMusicToAlbum(simple);
				AlbumList.Add(temp);*/
			}
		}


		// GenreList에 추가
		if (GenreList.GetLength() == 0)					// GenreList가 비어있을 때
		{
			GenreType genre;
			SongType song;
			genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
			song.SetId(music.GetId());													// 추가할 곡의 Id를 설정
			song.SetName(music.GetName());												// 추가할 곡의 곡명을 설정
			genre.AddMusicInGenre(song);												// genre에 곡의 정보 추가
			GenreList.Add(genre);														// GenreList에 해당 genre를 추가
		}
		else											// GenreList에 원소가 있을 때
		{
			GenreType genre;
			SongType song;

			genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
			song.SetId(music.GetId());													// 추가할 곡의 id 설정
			song.SetName(music.GetName());												// 추가할 곡의 곡명 설정

			GenreType temp;
			int test = 0;
			while (GenreList.GetNextItem(temp) != -1)									// GenreList 끝까지 검색
			{
				if (temp.GetGenre() == music.GetGenre())	// GenreList에 검색할 곡의 장르가 존재할 경우
				{
					temp.AddMusicInGenre(song);											// 해당 장르에 곡 추가
					GenreList.Replace(temp);											// GenreList를 갱신
					test++;
					break;
				}
			}
			if (test == 0)								// GenreList에 검색할 곡의 장르가 없을 경우
			{
				genre.AddMusicInGenre(song);											// 새로운 장르에 추가
				GenreList.Add(genre);													// GenreList에 추가
			}
		}


		// SingerList에 추가
		if (SingerList.GetLength() == 0)				// SingerList에 원소가 없을 경우
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
			album.SetNumberofsonginalbumIncrease();										// album 수록곡수 1 증가
			simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
			album.AddMusicToAlbum(simple);												// album에 정보 추가
			singer.AddMusicToSinger(album);												// singer에 album 추가
			SingerList.Add(singer);														// SingerList에 singer 추가
		}
		else											// SingerList에 원소가 있을 경우
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;
			singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
			if (SingerList.Get(singer))					// SingerList에 추가할 가수가 존재할 경우
			{
				singer.AddMusicToSinger(album, simple);									// 가수에 album과 간단한 정보를 추가
				SingerList.Delete(singer);												// SingerList에서 해당 가수를 삭제
				SingerList.Add(singer);													// SingerList에 갱신된 정보의 가수를 추가
			}
			else										// SingerList에 추가할 가수가 없을 경우
			{
				album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
				album.AddMusicToAlbum(simple);											// album에 정보 추가
				singer.AddMusicToSinger(album);											// singer에 album 추가
				SingerList.Add(singer);													// SingerList에 singer 추가
			}
		}



		// EntList에 추가
		if (EntList.GetLength() == 0)					// EntList에 원소가 없을 경우
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
			singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
			album.AddMusicToAlbum(simple);												// album에 간단한 정보 추가
			singer.AddMusicToSinger(album);												// singer에 album 추가
			ent.AddMusicToEnt(singer);													// ent에 singer 추가
			EntList.Add(ent);															// EntList에 ent 추가
		}
		else											// EntList에 원소가 있을 경우
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
			singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
			simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
			if (EntList.Get(ent))						// EntList에 추가할 소속사가 있을 경우
			{
				ent.AddMusicToEnt(singer, album);										// ent에 singer와 album의 정보 추가
				EntList.Delete(ent);													// EntList에서 ent 제거
				EntList.Add(ent);														// EntList에 갱신된 ent 추가
			}
			else										// EntList에 추가할 소속사가 없을 경우
			{
				album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
				album.AddMusicToAlbum(simple);											// album에 간단한 정보 추가
				singer.AddMusicToSinger(album);											// singer에 album 추가
				ent.AddMusicToEnt(singer);												// ent에 singer 추가
				EntList.Add(ent);														// EntList에 ent 추가
			}
		}
	}

	m_InFile.close();

	cout << "\n\t" << filename << "파일의 모든 음악 정보" << endl;
	DisplayAllMusic_Admin();

	return 1;	
}

// 마스터리스트의 모든 음악정보 출력
void Application::DisplayAllMusic_Admin()
{
	MusicType data;
	cout << "\n\t ♬ 전체 곡 정보 ♬ " << endl;
	MasterList.ResetList();
	if (MasterList.GetLength() == 0)
	{
		system("cls");
		cout << "\n\t마스터리스트에 음악정보가 존재하지 않습니다." << endl;
	}
	else
	{
		system("cls");
		int num = 1;
		while (MasterList.GetNextItem(data) != -1)
		{
			data.DisplayRecordOnScreen();
			cout << endl;
		}
	}
}

//int Application::Save_Admin()
//{
//	MusicType music;
//	char filename[] = "MasterList.txt";
//
//	cout << "\n\t마스터리스트를 저장합니다." << endl;
//
//	if (!OpenOutFile(filename))
//		return 0;
//
//	MasterList.ResetList();
//	fstream fout;
//	int length = MasterList.GetLength();
//	int curindex = MasterList.GetNextItem(music);
//	while (curindex < length&&curindex != -1)
//	{
//		if (curindex != length - 1)
//		{
//			music.WriteDataToFile(m_OutFile);
//			fout << endl;
//		}
//		else if (curindex == length - 1)
//			music.WriteDataToFile(m_OutFile);
//		curindex = MasterList.GetNextItem(music);
//	}
//
//	m_OutFile.close();
//	return 1;
//}







//


// 곡명이 같은 경우 처음 추가한 곡만 들어가는거 수정해야됨


//
// 사용자리스트에 항목 추가
int Application::AddMusic_User()
{
	cout << "\n\t사용자 음악목록에 추가할 곡명을 입력하세요." << endl;
	SongType song;
	song.SetNameFromKB();
	MusicType music;
	cout << endl;
	int check = 0;

	MasterList.ResetList();
	cout << "\n\t" << song.GetName() << "을(를) 곡명으로 갖는 음원들" << endl << endl;
	while (MasterList.GetNextItem(music) != -1)			// MasterList에서 끝까지 검색
	{
		if (music.GetName() == song.GetName())			// 입력할 곡명이 MasterList에 존재할 때
		{
			music.DisplayIdOnScreen();
			music.DisplayNameOnScreen();
			cout << endl;
			check++;									// check 1 증가
		}
	}


	if (check == 1)
	{
		MusicType item;
		item.SetName(song.GetName());				// item의 곡명에 song의 곡명을 대입

		MasterList.ResetList();
		while (MasterList.GetNextItem(music) != -1) // MasterList에서 끝까지 검색
		{
			if (music.GetName() == song.GetName())	// MasterList에서 추가할 곡명과 일치하는 곡이 있을 때
			{
				SongType song2;
				song2.SetName(music.GetName());
				song2.SetId(music.GetId());
				SongList.Add(song2);				// 해당 곡을 사용자리스트에 추가
				RecentlyList.EnQueue(song2);
				break;
			}
		}
	}
	else if (check > 1)								// 입력할 곡명과 같은 곡이 여러 개 존재할 때
	{
		cout << "\n\t같은 곡명을 가지는 곡이 있습니다. 추가할 곡의 고유번호를 입력하세요" << endl;
		MusicType music2;
		music2.SetIdFromKB();						// 고유번호 비교를 통해 원하는 곡을 입력
		MasterList.RetrieveMusic_Binary(music2);
		SongType song2;
		song2.SetId(music2.GetId());
		song2.SetName(music2.GetName());
		SongList.Add(song2);
		RecentlyList.EnQueue(song2);
	}
	else
	{
		system("cls");
		cout << "\n\t추가할 곡이 MasterList에 존재하지 않습니다." << endl;
	}
	DisplayAllMusic_User();

	return 1;
}


// 사용자리스트에서 항목 제거
void Application::DeleteMusic_User()
{
	cout << "\n\t사용자 음악목록에서 삭제할 곡명을 입력하세요." << endl;
	SongType song;
	song.SetNameFromKB();
	
	SongList.ResetList();
	SongType temp;

	bool test = false;
	while (SongList.GetNextItem(temp) != -1)
	{
		if (temp.GetName() == song.GetName())
		{
			test = true;
		}
	}

	if (test)
	{
		cout << "\n\t"<<song.GetName()<<"을 곡명으로 갖는 음원들" << endl;
		while (SongList.GetNextItem(temp) != -1)
		{
			if (temp.GetName() == song.GetName())
			{
				temp.DisplayRecordOnScreen();
			}
		}
		cout << "\n\t삭제할 음원의 고유번호를 입력하세요." << endl;
		song.SetIdFromKB();
		if (SongList.Delete(song))
		{
			system("cls");
			cout << "\n\t" << song.GetName() << " 음원의 삭제가 완료되었습니다." << endl;
		}
		else
		{
			system("cls");
			cout << "\n\t삭제할 음원의 정보가 존재하지 않습니다." << endl;
		}
	}
	else
	{
		system("cls");
		cout << "\n\t삭제할 음원의 정보가 존재하지 않습니다." << endl;
	}

	DisplayAllMusic_User();
}


// 사용자리스트의 모든 곡 정보 출력
void Application::DisplayAllMusic_User()
{
	cout << "\n\t ♬ 사용자리스트 음악목록 ♬ " << endl << endl;
	SongType song;
	SongList.ResetList();
	if (SongList.GetLength() == 0)
	{
		cout << "\n\t 사용자 음원목록에 음원이 없습니다." << endl;
	}
	while (SongList.GetNextItem(song) != -1)
	{
		song.DisplayRecordOnScreen();
		cout << endl;
	}
}

// 최근 추가된 사용자 음원목록에서 검색
void Application::SearchByRecentlyMusic_User()
{
	SongType song;
	RecentlyList.ResetCurPointer();
	cout << "\n\t♬ 사용자리스트 음악목록 ♬" << endl;
	while (RecentlyList.GetNextItem(song) != -1)
	{
		song.DisplayRecordOnScreen();
		cout << endl;
	}
	if (!RecentlyList.IsEmpty())
	{
		cout << "\n\t검색할 음원의 고유번호를 입력하세요 : ";
		int num;
		cin >> num;
		int check = 0;
		RecentlyList.ResetCurPointer();
		while (RecentlyList.GetNextItem(song) != -1&&check==0)
		{
			if (song.GetId() == num)
			{
				check++;
				MusicType music;
				music.SetId(song.GetId());
				MasterList.Get(music);
				music.DisplayRecordOnScreen();
				break;
			}
		}
	}
}

// 사용자리스트에서 고유번호로 검색
void Application::SearchById_User()
{
	SongType song;
	cout << "\n\t검색할 음원의 고유번호를 입력하세요." << endl;
	song.SetIdFromKB();

	SongType songitem;
	SongList.ResetList();
	bool check = false;

	while (SongList.GetNextItem(songitem) != -1)
	{
		if (song.GetId() == songitem.GetId())
		{
			songitem.DisplayRecordOnScreen();
			check = true;
		}
	}

	MusicType music;

	MasterList.ResetList();
	if (check)
	{
		while (MasterList.GetNextItem(music) != -1)
		{
			if (music.GetId() == song.GetId())
				music.DisplayRecordOnScreen();
		}
	}
	else
	{
		cout << "\n\t고유번호 " << song.GetId() << "에 해당하는 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	}
}

// 사용자리스트에서 곡명으로 검색
void Application::SearchByName_User()
{
	cout << "\n\t검색할 음원의 제목을 입력하세요." << endl;
	SongType song;
	song.SetNameFromKB();
	int check = 0;
	int check1 = 0;

	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList가 끝이 아니고 검색할 name이 SongList에서 못 찾았을 때
	{
		if (song.GetName() == item.GetName())										// 검색할 name을 SontList에서 찾았을 때
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList가 끝이 아니고 검색할 name이 MasterList에서 못 찾았을 때
			{
				if (song.GetName() == music.GetName())								// 검색할 name을 MasterList에서 찾았을 때
				{
					check1++;
					music.DisplayRecordOnScreen();									// 해당 곡의 모든 정보를 출력
				}
			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// 검색할 name이 SongList에 존재하지 않을 경우
		cout << "\n\t" << song.GetName() << " 을(를) 제목으로 가지는 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	/*SongType song;
	cout << "\n\t검색할 음원의 제목을 입력하세요." << endl;
	song.SetNameFromKB();
	cout << endl;

	SongList.ResetList();
	SongType temp;

	bool test = false;
	while (SongList.GetNextItem(temp) != -1)
	{
		if (temp.GetName() == song.GetName())
		{
			test = true;
		}
	}

	if (SongList.Get(song))
	{
		if (test)
		{
			cout << "\t곡명이 같은 곡들입니다." << endl;
			SongList.ResetList();
			while (SongList.GetNextItem(temp) != -1)
			{
				if (temp.GetName() == song.GetName())
				{
					temp.DisplayRecordOnScreen();
				}
			}
		}
		cout << "\n\t검색할 음원의 고유번호를 입력하세요." << endl;
		MusicType musicitem;
		MusicType search;
		search.SetIdFromKB();
		MasterList.ResetList();
		if (MasterList.GetNextItem(musicitem)!=-1)
		{
			system("cls");
			if (search.GetId() == musicitem.GetId())
			{
				musicitem.DisplayRecordOnScreen();
			}
			else
			{
				cout << "\n\t" << song.GetName() << "을(를) 제목으로 가지는 음원 중 " << search.GetId() << "를 고유번호로 갖는 음원이 존재하지 않습니다." << endl;
			}
		}
	
	}
	if (!test)
		cout << "\n\t" << song.GetName() << "을(를) 제목으로 가지는 음원이 사용자 음원목록에 존재하지 않습니다." << endl;*/
}

// 사용자리스트에서 가수명으로 검색
void Application::SearchBySinger_User()
{
	SingerType singer;
	cout << "\n\t검색할 가수명을 입력하세요." << endl;
	singer.SetSingerFromKB();
	cout << endl;
	AlbumType album;
	SongType song;

	SingerType singeritem;
	SingerList.ResetList();
	AlbumType albumitem;
	AlbumList.ResetList();
	SongType songitem;
	SongList.ResetList();
	MusicType musicitem;
	MasterList.ResetList();
	int check = 0;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;


	while (SingerList.GetNextItem(singeritem) != -1 && (check == 0))						// SingerList가 끝이 아니고 SingerList에서 찾지 못했을 때
	{
		if (singer.GetSinger() == singeritem.GetSinger())									// SingerList에서 해당 가수를 찾으면
		{
			cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
			singeritem.DisplayAlbumnameOnScreen();											// 해당 가수의 모든 앨범 출력
			cout << "\n\t" << singer.GetSinger() << "의 앨범목록에서 검색할 앨범을 선택하세요." << endl;
			album.SetAlbumnameFromKB();														// 검색할 앨범명 입력
			while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))					// AlbumList가 끝이 아니고 AlbumList에서 찾지 못했을 때
			{
				cout << endl;
				if (album.GetAlbumname() == albumitem.GetAlbumname())						// AlbumList에서 해당 앨범을 찾으면
				{
					albumitem.DisplayRecordOnScreen();										// 해당 앨범의 정보를 출력
					albumitem.DisplayAlbumListOnScreen();									// 해당 앨범의 수록곡을 출력
					cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
					song.SetNameFromKB();													// 검색할 곡명 입력
					while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))			// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
					{
						if (song.GetName() == songitem.GetName())							// SongList에서 해당 곡을 찾으면
						{
							while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
							{
								if (song.GetName() == musicitem.GetName())					// MasterList에서 해당 곡을 찾으면 
								{
									check3++;
									musicitem.DisplayRecordOnScreen();						// 해당 곡의 모든 정보 출력
								}
							}
							check2++;
						}
					}
					check1++;
				}
			}
			check++;
		}
	}

	if (check == 0)
		cout << "\n\t" << singer.GetSinger() << "의 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	else if (check!=0&&check1 == 0)
		cout << "\n\t" << album.GetAlbumname() << "앨범이 사용자 음원목록에 존재하지 않습니다." << endl;
	if (check != 0 && check1 != 0 && check2 == 0)
		cout << "\n\t" << song.GetName() << " 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	else if (check != 0 && check1 != 0 && check2 != 0 && check3 == 0)
		cout << "\n\t" << song.GetName() << " 은(는)" << album.GetAlbumname() << " 앨범의 수록곡이 아닙니다." << endl;
}

// 사용자리스트에서 장르로 검색
void Application::SearchByGenre_User()
{
	cout << "\n\t검색할 곡의 장르를 입력하세요." << endl;
	GenreType genre;
	genre.SetGenreFromKB();
	cout << endl;
	MusicType music;

	SongType song;
	SongType songitem;
	GenreType genreitem;
	GenreList.ResetList();
	MusicType musicitem;
	MasterList.ResetList();
	int check = 0;
	int check1 = 0;
	int check2 = 0;

	while (GenreList.GetNextItem(genreitem) != -1 && (check == 0))							// GenreList가 끝이 아니고 GenreList에서 찾지 못했을 때
	{
		if (genre.GetGenre() == genreitem.GetGenre())										// GenreList에서 해당 장르를 찾으면
		{
			cout << "\n\t" << genre.GetGenre() << "장르에는 다음 곡들이 있습니다." << endl;
			genreitem.DisplaySongOnScreen();												// 해당 장르의 모든 곡 출력
			cout << "\n\t" << genre.GetGenre() << "의 장르중에서 검색할 곡의 고유번호를 선택하세요." << endl;
			song.SetIdFromKB();																// 검색할 고유번호 입력
			cout << endl;
			SongList.ResetList();
			while (SongList.GetNextItem(songitem) != -1&&(check1==0))
			{
				if (song.GetId() == songitem.GetId())
				{
					check1++;
					song.SetName(songitem.GetName());
					while (MasterList.GetNextItem(musicitem) != -1 && (check2 == 0))				// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
					{
						if (song.GetId() == musicitem.GetId())										// MasterList에서 해당 고유번호를 찾으면
						{
							check2++;
							musicitem.DisplayRecordOnScreen();										// 해당 곡의 모든 정보 출력
						}
					}
				}
			}
			check++;
		}
	}
	
	if (check == 0)
		cout << "\n\t" << genre.GetGenre() << "장르의 음원이 존재하지 않습니다." << endl;
	else if (check != 0 && check1 == 0)																			// 검색할 장르가 GenreList에 존재하지 않을 때
		cout << "\n\t" << genre.GetGenre() << "장르 중 " << song.GetId() << "을(를) 고유번호로 갖는 음원이 사용자 음원목록에 존재하지 않습니다. " << endl;
}

// 사용자리스트에서 앨범명으로 검색
void Application::SearchByAlbumName_User()
{
	AlbumType albumitem;
	AlbumType album;
	cout << "\n\t검색할 앨범명을 입력하세요." << endl;
	album.SetAlbumnameFromKB();
	MusicType musicitem;
	MusicType music;
	SongType songitem;
	SongType song;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;

	if (AlbumList.Get(album))											// AlbumList에서 해당 앨범명이 존재할 때
	{
		check1++;
		cout << "\n\t" << album.GetAlbumname() << "앨범의 정보는 다음과 같습니다." << endl;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(albumitem) != -1)					// AlbumList가 끝이 아닐 때
		{
			if (album.GetAlbumname() == albumitem.GetAlbumname())		// AlbumList에서 해당 앨범명을 찾으면
			{
				albumitem.DisplayRecordOnScreen();						// 해당 앨범의 정보 출력
				albumitem.DisplayAlbumListOnScreen();					// 해당 앨범의 수록곡 출력
				cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 음원의 고유번호를 입력하세요." << endl;
				song.SetIdFromKB();									// 검색할 음원 고유번호 입력

				SongList.ResetList();
				while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))		// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
				{
					if (SongList.Get(song))											// SongList에 해당 음원이 존재하면
					{
						MasterList.ResetList();
						while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
						{

							if (song.GetId() == musicitem.GetId())				// MasterList에서 검색할 곡명을 찾으면
							{
								check3++;
								musicitem.DisplayRecordOnScreen();					// 해당 곡의 모든 정보 출력
							}
						}
						check2++;
					}

				}
			}
		}
	}

	if (check1 == 0)
	{
		cout << "\n\t" << album.GetAlbumname() << " 앨범이 사용자 음원목록에 존재하지 않습니다." << endl;
	}
	else if (check1 != 0 && check2 == 0)
	{
		cout << "\n\t" << album.GetAlbumname() << " 앨범에서 검색한 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	}
	/*else if (check1 != 0 && check2 != 0 && check3 == 0)
		cout << "\n\t" << song.GetName() << " 은(는)" << album.GetAlbumname() << " 앨범의 수록곡이 아닙니다." << endl;*/
}

// 사용자리스트에서 소속사명으로 검색
void Application::SearchByEnt_User()
{
	{
		// 사용자리스트에서 소속사명으로 검색
		EntType ent;
		EntType entitem;
		cout << "\n\t검색할 소속사를 입력하세요." << endl;
		ent.SetEntFromKB();
		SingerType singer;
		SingerType singeritem;
		AlbumType album;
		AlbumType albumitem;
		SongType song;
		SongType songitem;
		MusicType music;
		MusicType musicitem;
		int check = 0;
		int check1 = 0;
		int check2 = 0;
		int check3 = 0;
		int check4 = 0;



		EntList.ResetList();
		while (EntList.GetNextItem(entitem) != -1)									// EntList가 끝이 아닐 때
		{
			if (ent.GetEnt() == entitem.GetEnt())									// EntList에서 검색할 소속사를 찾으면
			{
				cout << "\n\t" << ent.GetEnt() << "의 소속 가수는 다음과 같습니다." << endl;
				entitem.DisplayEntListOnScreen();									// 해당 소속사의 모든 가수 출력
				cout << "\n\t" << ent.GetEnt() << "의 소속 가수중 검색할 가수를 선택하세요." << endl;
				singer.SetSingerFromKB();											// 검색할 가수입력
				SingerList.ResetList();
				while (SingerList.GetNextItem(singeritem) != -1 && (check1 == 0))		// SingerList가 끝이 아니고 SingerList에서 찾지 못했을 때
				{
					if (singer.GetSinger() == singeritem.GetSinger())				// SingerList에서 검색할 가수를 찾으면
					{
						cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
						singeritem.DisplayAlbumnameOnScreen();						// 해당 가수의 모든 앨범 출력
						cout << "\n\t" << singer.GetSinger() << "의 앨범목록에서 검색할 앨범을 선택하세요." << endl;
						album.SetAlbumnameFromKB();									// 검색할 앨범명 입력
						AlbumList.ResetList();
						while (AlbumList.GetNextItem(albumitem) != -1 && (check2 == 0))	// AlbumList가 끝이 아니고 AlbumList에서 찾지 못했을 때
						{
							cout << endl;
							if (album.GetAlbumname() == albumitem.GetAlbumname())	// AlbumList에서 검색할 앨범을 찾으면
							{
								albumitem.DisplayRecordOnScreen();					// 해당 앨범의 정보 출력
								albumitem.DisplayAlbumListOnScreen();				// 해당 앨범의 수록곡 출력
								cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
								song.SetNameFromKB();								// 검색할 곡명 입력
								while (SongList.GetNextItem(songitem) != -1 && (check3 == 0))	// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
								{
									if (song.GetName() == songitem.GetName())		// SongList에서 검색할 곡을 찾으면
									{
										MasterList.ResetList();
										while (MasterList.GetNextItem(musicitem) != -1 && (check4 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
										{
											if (song.GetName() == musicitem.GetName())	// MasterList에서 검색할 곡을 찾으면
											{
												check4++;
												musicitem.DisplayRecordOnScreen();		// 해당 곡의 모든 정보 출력
											}
										}
										check3++;
									}
								}
								check2++;
							}
						}
						check1++;
					}
				}check++;
			}
			
		}

		if (check == 0)
			cout << "\n\t" << ent.GetEnt() << " 소속사의 정보가 없습니다." << endl;
		/*else if (check != 0 && check1 == 0)
			cout << "\n\t" << singer.GetSinger() << " 은(는) "<<ent.GetEnt()<<"소속사의 가수가 아닙니다." << endl;
		else if (check != 0 && check1 != 0 && check2 == 0)
			cout << "\n\t" << album.GetAlbumname() << " 앨범이 " << singer.GetSinger() << " 이(가) 작업한 앨범이 아닙니다." << endl;*/
		else if (check != 0 && check1 != 0 && check2 != 0 && check3 == 0)
			cout << "\n\t" << song.GetName() << " 음원이 사용자 음원목록에 존재하지 않습니다." << endl;
	}
}

//// 사용자 음원목록에서 재생
//void Application::PlayMusic_User()
//{
//	cout << "\n\t♬ 사용자 음원목록 ♬" << endl;
//	PlaySongType playsong;
//	PlayList.ResetList();
//	while (PlayList.GetNextItem(playsong) != -1)
//	{
//		playsong.DisplayRecordOnScreen();
//		cout << endl;
//	}
//
//	cout << "\n\t사용자 음원목록에서 재생할 곡명을 입력하세요." << endl;
//	string name;
//	cout << "\t곡명 : ";
//	cin >> name;
//	string data = name;
//	name += ".mp3";
//	const char* songname = name.c_str();
//
//	bool test = false;
//	PlayList.ResetList();
//	while (PlayList.GetNextItem(playsong) != -1)
//	{
//		if (playsong.GetName() == data)
//		{
//			// 파일 열기
//			  // MCI_OPEN_PARAMS 구조체 변수 mc
//
//			mciOpen.lpstrDeviceType = TEXT("mpegvideo");  // mpegvideo : mp3, waveaudio : wav, avivideo : avi
//			mciOpen.lpstrElementName = TEXT(songname); // 파일이름
//
//			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);
//			//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);
//
//			// 재생
//			dwID = mciOpen.wDeviceID;
//			MCI_PLAY_PARMS m_mciPlayParms;
//
//			mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
//
//			// int 값 입력시 정지 후 초기화면 실행
//			int a;
//			cin >> a;
//			mciSendCommand(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);
//			cin >> a;
//
//			test = true;
//			system("cls");
//			break;
//
//		}
//	}
//	if (!test) {
//		system("cls");
//		cout << "\n\n\t해당음악이 없습니다" << endl;
//	}
//}

// 사용자 음원목록을 사용자 ID의 파일명으로 저장
int Application::Save_User()
{
	SongType song;
	char filename[FILENAMESIZE];

	cout << "\n\t사용자 음원목록을 저장합니다." << endl;
	cout << "\n\t로그인한 ID를 입력하세요 : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	SongList.ResetList();

	int length = SongList.GetLength();
	int curindex = SongList.GetNextItem(song);
	while (curindex < length&&curindex != -1)
	{
		song.WriteDataToFile(m_OutFile);
		curindex = SongList.GetNextItem(song);
	}

	m_OutFile.close();
	SongList.MakeEmpty();
	return 1;
}

// 사용자 ID의 파일명을 사용자 음원목록으로 가져옴
int Application::Read_User(char id)
{
	SongType song;

	cout << "\n\t사용자 음원목록을 불러옵니다." << endl;

	if (!OpenInFile(&id))
		return 0;


	while (!m_InFile.eof())
	{
		song.ReadDataFromFile(m_InFile);
		SongList.Add(song);
	}
	//char erase[30];
	//string add = ".txt";
	//strcpy_s(erase, add.c_str());
	//
	//int check = -1;
	//bool test = true;

	//ifstream fin;
	//string data;
	//while (!m_InFile.eof())
	//{
	//	fin >> data;
	//}

	//m_InFile.close();

	//m_InFile.open(&id);

	//// 파일 빈 파일일때 불러오는 경우 파일 제거하는거 구현해야됨
	//while (!m_InFile.eof())
	//{
	//	if (data!=" ")
	//	{
	//		cout << "\n\t불러온 정보를 사용자 음원목록에 저장합니다." << endl;
	//		song.ReadDataFromFile(m_InFile);
	//		SongList.Add(song);
	//	}
	//	else if (data==" ")
	//	{
	//		cout << "\n\t불러올 파일이 비어있습니다. 해당 파일을 삭제합니다.";
	//		remove(erase);
	//		break;
	//	}
	//}

	m_InFile.close();
	DisplayAllMusic_User();
}


// 불러올 filename이 존재하면 열고 1 리턴, 아니면 0 리턴
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	//불러올 fileName에 해당하는 file을 연다
	if (m_InFile)	//여는데 성공하면
		return 1;
	else
		return 0;
}

int Application::OpenOutFile(char * fileName)
{
	m_OutFile.open(fileName);	//저장할 fileName에 해당하는 file을 연다.
	if (m_OutFile)	//여는데 성공하면
		return 1;
	else
		return 0;
}

/*
// 사용자 리스트에 항목 추가
int Application::AddMusic_User()
{
	cout << "\n\t사용자 설정 음악목록에 추가할 곡의 제목을 입력하세요\n";
	SongType song;
	song.SetNameFromKB();			// 추가할 곡의 제목
	MusicType music;
	MasterList.ResetList();
	GenreType genre;
	GenreList.ResetList();
	AlbumType album;
	AlbumList.ResetList();
	SingerType singer;
	SingerList.ResetList();
	EntType ent;
	EntList.ResetList();
	int check = 0;									// 추가할 곡명과 같은 곡이 MasterList에 몇 개나 존재하는지 확인

	while (MasterList.GetNextItem(music) != -1)		// MasterList에서 끝까지 검색
		if (song.GetName() == music.GetName())		// 입력할 곡명이 MasterList에 존재할 때
			check++;								// check 1 증가

	// SongList에 추가
	if (check == 1)
	{
		MusicType item;
		item.SetName(song.GetName());				// item의 곡명에 song의 곡명을 대입
		MasterList.ResetList();
		while (MasterList.GetNextItem(music) != -1) // MasterList에서 끝까지 검색
		{
			if (music.GetName() == song.GetName())	// MasterList에서 추가할 곡명과 일치하는 곡이 있을 때
			{
				SongType song2;
				song2.SetName(music.GetName());
				song2.SetId(music.GetId());
				SongList.Add(song2);				// 해당 곡을 사용자리스트에 추가
				break;
			}
		}
	}
	else if (check > 1)								// 입력할 곡명과 같은 곡이 여러 개 존재할 때
	{
		cout << "\n\t같은 곡명을 가지는 곡이 있습니다. 추가할 곡의 고유번호를 입력하세요" << endl;
		MusicType music;
		music.SetIdFromKB();						// 고유번호 비교를 통해 원하는 곡을 입력
		MasterList.RetrieveMusic_Binary(music);
		SongType song2;
		song2.SetId(music.GetId());
		song2.SetName(music.GetName());
		SongList.Add(song2);
	}
	else 
	{
		cout << "\n\t추가할 곡이 MasterList에 존재하지 않습니다." << endl;
	}


	// AlbumList에 추가
	if (AlbumList.GetLength() == 0)					// AlbumList가 비어있을 때 
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
		album.SetNumberofsonginalbumIncrease();										// 앨범 수록곡 수 1 증가
		simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum 설정
		album.AddMusicToAlbum(simple);												// album에 추가
		AlbumList.Add(album);														// album을 AlbumList에 추가
	}
	else											// AlbumList에 원소가 존재할 때	
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 AlbumType 설정
		simple.SetRecord(music.GetId(), music.GetName());

		AlbumType temp;																// AlbumType 임시변수
		int test = 0;
		while (AlbumList.GetNextItem(temp) != -1)									// AlbumList 끝까지 검색
		{
			if (temp.GetAlbumname() == album.GetAlbumname())	// 추가할 앨범명이 AlbumList에 존재할 경우
			{
				temp.AddMusicToAlbum(simple);										// 해당 앨범에 추가
				temp.SetNumberofsonginalbumIncrease();
				AlbumList.Replace(temp);											// AlbumList를 갱신
				test++;
				break;
			}
		}
		if (test == 0)								// 추가할 앨범명이 AlbumList에 없을 경우
		{
			album.AddMusicToAlbum(simple);											// 새로운 album에 추가
			album.SetNumberofsonginalbumIncrease();									// 해당 앨범 수록곡수 1 증가
			AlbumList.Add(album);													// AlbumList에 해당 앨범 추가
			//temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
			//temp.SetNumberofsonginalbumIncrease();
			//temp.AddMusicToAlbum(simple);
			//AlbumList.Add(temp);
		}
	}
	

	// GenreList에 추가
	if (GenreList.GetLength() == 0)					// GenreList가 비어있을 때
	{
		GenreType genre;
		SongType song;
		genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
		song.SetId(music.GetId());													// 추가할 곡의 Id를 설정
		song.SetName(music.GetName());												// 추가할 곡의 곡명을 설정
		genre.AddMusicInGenre(song);												// genre에 곡의 정보 추가
		GenreList.Add(genre);														// GenreList에 해당 genre를 추가
	}
	else											// GenreList에 원소가 있을 때
	{
		GenreType genre;
		SongType song;

		genre.SetGenre(music.GetGenre());											// 추가할 genre 설정
		song.SetId(music.GetId());													// 추가할 곡의 id 설정
		song.SetName(music.GetName());												// 추가할 곡의 곡명 설정

		GenreType temp;
		int test = 0;
		while (GenreList.GetNextItem(temp) != -1)									// GenreList 끝까지 검색
		{
			if (temp.GetGenre() == music.GetGenre())	// GenreList에 검색할 곡의 장르가 존재할 경우
			{
				temp.AddMusicInGenre(song);											// 해당 장르에 곡 추가
				GenreList.Replace(temp);											// GenreList를 갱신
				test++;
				break;
			}
		}
		if (test == 0)								// GenreList에 검색할 곡의 장르가 없을 경우
		{
			genre.AddMusicInGenre(song);											// 새로운 장르에 추가
			GenreList.Add(genre);													// GenreList에 추가
		}
	}
	

	// SingerList에 추가
	if (SingerList.GetLength() == 0)				// SingerList에 원소가 없을 경우
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
		album.SetNumberofsonginalbumIncrease();										// album 수록곡수 1 증가
		simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
		album.AddMusicToAlbum(simple);												// album에 정보 추가
		singer.AddMusicToSinger(album);												// singer에 album 추가
		SingerList.Add(singer);														// SingerList에 singer 추가
	}
	else											// SingerList에 원소가 있을 경우
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;
		singer.SetSinger(music.GetSinger());										// 추가할 가수이름 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 저장될 간단한 정보 설정
		if (SingerList.Get(singer))					// SingerList에 추가할 가수가 존재할 경우
		{
			singer.AddMusicToSinger(album, simple);									// 가수에 album과 간단한 정보를 추가
			SingerList.Delete(singer);												// SingerList에서 해당 가수를 삭제
			SingerList.Add(singer);													// SingerList에 갱신된 정보의 가수를 추가
		}
		else										// SingerList에 추가할 가수가 없을 경우
		{
			album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
			album.AddMusicToAlbum(simple);											// album에 정보 추가
			singer.AddMusicToSinger(album);											// singer에 album 추가
			SingerList.Add(singer);													// SingerList에 singer 추가
		}
	}

	

	// EntList에 추가
	if (EntList.GetLength() == 0)					// EntList에 원소가 없을 경우
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
		singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
		album.AddMusicToAlbum(simple);												// album에 간단한 정보 추가
		singer.AddMusicToSinger(album);												// singer에 album 추가
		ent.AddMusicToEnt(singer);													// ent에 singer 추가
		EntList.Add(ent);															// EntList에 ent 추가
	}
	else											// EntList에 원소가 있을 경우
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// 추가할 ent 설정
		singer.SetSinger(music.GetSinger());										// 추가할 singer 설정
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// 추가할 album 설정
		simple.SetRecord(music.GetId(), music.GetName());							// album에 추가할 간단한 정보 추가
		if (EntList.Get(ent))						// EntList에 추가할 소속사가 있을 경우
		{
			ent.AddMusicToEnt(singer, album);										// ent에 singer와 album의 정보 추가
			EntList.Delete(ent);													// EntList에서 ent 제거
			EntList.Add(ent);														// EntList에 갱신된 ent 추가
		}
		else										// EntList에 추가할 소속사가 없을 경우
		{
			album.SetNumberofsonginalbumIncrease();									// 앨범 수록곡수 1 증가
			album.AddMusicToAlbum(simple);											// album에 간단한 정보 추가
			singer.AddMusicToSinger(album);											// singer에 album 추가
			ent.AddMusicToEnt(singer);												// ent에 singer 추가
			EntList.Add(ent);														// EntList에 ent 추가
		}
	}


	//if (check == 1)									// 1개 존재할 때
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// 입력할 곡명으로 MusicType item의 곡명 설정
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList 끝까지 검색
	//	{
	//		if (music.GetName() == song.GetName())	// 입력할 곡명이 MasterList의 해당 index의 곡과 같을 때
	//		{
	//			SongType songitem;
	//			songitem.SetName(music.GetName());		// SongType item2의 곡명을 music의 곡명으로 설정
	//			songitem.SetId(music.GetId());			// item2의 고유번호를 music의 고유번호로 설정
	//			SongList.Add(songitem);					// 사용자 음악리스트 SongList에 item2항목 추가

	//			GenreType genreitem;
	//			genreitem.SetGenre(music.GetGenre());
	//			GenreList.Add(genreitem);

	//			AlbumType albumitem;
	//			albumitem.SetAlbumname(music.GetAlbumname());
	//			albumitem.SetSinger(music.GetSinger());
	//			albumitem.SetEnt(music.GetEnt());
	//			albumitem.SetIstitle(music.GetIstitle());
	//			AlbumList.Add(albumitem);

	//			SingerType singeritem;
	//			singeritem.SetSinger(music.GetSinger());
	//			SingerList.Add(singeritem);

	//			EntType entitem;
	//			entitem.SetEnt(music.GetEnt());
	//			EntList.Add(entitem);

	//			break;
	//		}
	//	}
	//}
	


	if (SongList.GetLength() != 0)					// SongList에 원소가 존재할 경우
		DisplayAllMusic_User();						// SongList의 원소 출력

	return 1;







	//cout << "\n\t사용자 설정 음악목록에 추가할 곡의 제목을 입력하세요\n";
	//SongType song;
	//song.SetNameFromKB();
	//MusicType music;
	//MasterList.ResetList();
	//GenreType genre;
	//GenreList.ResetList();
	//AlbumType album;
	//AlbumList.ResetList();
	//SingerType singer;
	//SingerList.ResetList();
	//EntType ent;
	//EntList.ResetList();
	//int check = 0;									// 추가할 곡명과 같은 곡이 MasterList에 몇 개나 존재하는지 확인

	//while (MasterList.GetNextItem(music) != -1)		// MasterList에서 끝까지 검색
	//	if (song.GetName() == music.GetName())		// 입력할 곡명이 MasterList에 존재할 때
	//		check++;								// check 1 증가

	//if (check == 1)									// 1개 존재할 때
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// 입력할 곡명으로 MusicType item의 곡명 설정
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList 끝까지 검색
	//	{
	//		if (music.GetName() == song.GetName())	// 입력할 곡명이 MasterList의 해당 index의 곡과 같을 때
	//		{
	//			SongType songitem;
	//			songitem.SetName(music.GetName());		// SongType item2의 곡명을 music의 곡명으로 설정
	//			songitem.SetId(music.GetId());			// item2의 고유번호를 music의 고유번호로 설정
	//			SongList.Add(songitem);					// 사용자 음악리스트 SongList에 item2항목 추가

	//			GenreType genreitem;
	//			genreitem.SetGenre(music.GetGenre());
	//			GenreList.Add(genreitem);

	//			AlbumType albumitem;
	//			albumitem.SetAlbumname(music.GetAlbumname());
	//			albumitem.SetSinger(music.GetSinger());
	//			albumitem.SetEnt(music.GetEnt());
	//			albumitem.SetIstitle(music.GetIstitle());
	//			AlbumList.Add(albumitem);

	//			SingerType singeritem;
	//			singeritem.SetSinger(music.GetSinger());
	//			SingerList.Add(singeritem);

	//			EntType entitem;
	//			entitem.SetEnt(music.GetEnt());
	//			EntList.Add(entitem);

	//			break;
	//		}
	//	}
	//}
	//else if (check > 1)								// 입력할 곡명과 같은 곡이 여러 개 존재할 때
	//{
	//	cout << "\n\t같은 곡명을 가지는 곡이 있습니다. 추가할 곡의 고유번호를 입력하세요" << endl;
	//	MusicType music;
	//	music.SetIdFromKB();						// 고유번호 비교를 통해 원하는 곡을
	//	MasterList.RetrieveMusic_Binary(music);
	//	SongType song2;
	//	song2.SetId(music.GetId());
	//	song2.SetName(music.GetName());
	//	SongList.Add(song2);
	//}
	//else {
	//	cout << "\t추가할 곡이 없습니다" << endl;
	//}
	//R_DisplayAllMusic();

	//return 1;





	//cout << "\n\t사용자 설정 음악목록에 추가할 곡의 제목을 입력하세요\n";
	//SongType song;
	//song.SetNameFromKB();
	//MusicType music;
	//MasterList.ResetList();
	//int check = 0;									// 추가할 곡명과 같은 곡이 MasterList에 몇 개나 존재하는지 확인

	//while (MasterList.GetNextItem(music) != -1)		// MasterList에서 끝까지 검색
	//	if (song.GetName() == music.GetName())		// 입력할 곡명이 MasterList에 존재할 때
	//		check++;								// check 1 증가

	//if (check == 1)									// 1개 존재할 때
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// 입력할 곡명으로 MusicType item의 곡명 설정
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList 끝까지 검색
	//	{
	//		if (music.GetName() == song.GetName())	// 입력할 곡명이 MasterList의 해당 index의 곡과 같을 때
	//		{
	//			SongType item2;
	//			item2.SetName(music.GetName());		// SongType item2의 곡명을 music의 곡명으로 설정
	//			item2.SetId(music.GetId());			// item2의 고유번호를 music의 고유번호로 설정
	//			SongList.Add(item2);				// 사용자 음악리스트 SongList에 item2항목 추가
	//			break;
	//		}
	//	}
	//}
	//else if (check > 1)								// 입력할 곡명과 같은 곡이 여러 개 존재할 때
	//{
	//	cout << "\n\t같은 곡명을 가지는 곡이 있습니다. 추가할 곡의 고유번호를 입력하세요" << endl;
	//	MusicType music;
	//	music.SetIdFromKB();						// 고유번호 비교를 통해 원하는 곡을
	//	MasterList.RetrieveMusic_Binary(music);
	//	SongType song2;
	//	song2.SetId(music.GetId());
	//	song2.SetName(music.GetName());
	//	SongList.Add(song2);
	//}
	//else {
	//	cout << "\t추가할 곡이 없습니다" << endl;
	//}
	//R_DisplayAllMusic();

	//return 1;

	//if (check != 0)
	//{
	//	cout << "\n\t추가할 곡이 MasterList에 존재합니다. 추가할 곡의 고유번호를 입력하세요" << endl;
	//	MusicType music1;
	//	music1.SetIdFromKB();
	//	MasterList.RetrieveMusic_Binary(music1);
	//	SongType song1;
	//	song1.SetId(music1.GetId());
	//	song1.SetName(music1.GetName());
	//	SongList.Add(song1);
	//}
	//else
	//	cout << "\n\t추가할 곡명과 일치하는 항목이 MasterList에 존재하지 않습니다." << endl;
	//cout << "\n\t현재 SongList의 항목" << endl;
	//R_DisplayAllMusic();
}
*/

/*
// 사용자리스트에서 항목 제거
void Application::DeleteMusic_User()
{
	cout << "\n\t삭제할 곡명을 입력하세요. " << endl;
	SongType song;
	song.SetNameFromKB();
	SongList.ResetList();
	if (SongList.Delete(song))							// 삭제할 곡명이 SongList에 존재할 경우
	{
		cout << "\n\t" << song.GetName() << " 이(가) 삭제되었습니다." << endl;
	}
	else												// 삭제할 곡명이 SongList에 존재하지 않을 경우
		cout << "\n\t" << song.GetName() << " 을(를) 곡명으로 가지는 곡이 존재하지 않습니다." << endl;


	DisplayAllMusic_User();								// SongList 모든 정보 출력
	

	//
	//cout << "\n\t삭제할 곡명을 입력하세요. " << endl;
	//SongType song;
	//song.SetNameFromKB();
	//if (SongList.Delete(song))
	//	cout << "\n\t" << song.GetName() << "이(가) 삭제되었습니다." << endl;
	//else
	//	cout << "\n\t"<<song.GetName()<<"을(를) 곡명으로 가지는 곡이 존재하지 않습니다." << endl;
	//
}
*/

/*
// 사용자리스트 모든 정보 출력
void Application::DisplayAllMusic_User()
{
	cout << "\n\t♬ 사용자 설정 음악목록 ♬" << endl << endl;
	SongType song;
	SongList.ResetList();
	while (SongList.GetNextItem(song) != -1)
	{
		song.DisplayRecordOnScreen();
		cout << endl;
	}
}
*/

/*
// 사용자리스트에서 Id로 검색
void Application::SearchById_User()
{
	cout << "\n\t검색할 곡의 고유번호를 입력하세요." << endl;
	SongType song;
	song.SetIdFromKB();
	int check = 0;
	int check1 = 0;

	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList가 끝이 아니고 검색할 Id를 SongList에서 찾지 못했을 경우
	{
		if (song.GetId() == item.GetId())											// 검색할 Id가 SongList에 존재할 경우
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList가 끝이 아니고 검색할 Id를 MasterList에서 못 찾았을 때
			{
				if (song.GetId() == music.GetId())									// 검새할 Id가 MasterList에 존재하면
				{
					check1++;
					music.DisplayRecordOnScreen();									// 해당 곡의 모든 정보 출력
				}

			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// 검색할 Id가 SongList에 존재하지 않을 경우
		cout << "\n\t" << song.GetId() << " 을(를) 고유번호로 가지는 곡이 사용자리스트에 없습니다." << endl;
}
*/

/*
// 사용자리스트에서 Name으로 검색
void Application::SearchByName_User()
{
	cout << "\n\t검색할 곡명을 입력하세요." << endl;
	SongType song;
	song.SetNameFromKB();
	int check = 0;
	int check1 = 0;
	
	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList가 끝이 아니고 검색할 name이 SongList에서 못 찾았을 때
	{
		if (song.GetName() == item.GetName())										// 검색할 name을 SontList에서 찾았을 때
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList가 끝이 아니고 검색할 name이 MasterList에서 못 찾았을 때
			{
				if (song.GetName() == music.GetName())								// 검색할 name을 MasterList에서 찾았을 때
				{
					check1++;
					music.DisplayRecordOnScreen();									// 해당 곡의 모든 정보를 출력
				}
			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// 검색할 name이 SongList에 존재하지 않을 경우
		cout << "\n\t" << song.GetName() << " 을(를) 곡명으로 가지는 곡이 사용자리스트에 없습니다." << endl;
}
*/

/*
// 사용자리스트에서 가수명으로 검색
void Application::SearchBySinger_User()
{

	cout << "\n\t검색할 가수명을 입력하세요." << endl;
	SingerType singer;
	singer.SetSingerFromKB();
	AlbumType album;
	SongType song;

	SingerType singeritem;
	SingerList.ResetList();
	AlbumType albumitem;
	AlbumList.ResetList();
	SongType songitem;
	SongList.ResetList();
	MusicType musicitem;
	MasterList.ResetList();
	int check = 0;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;


	while (SingerList.GetNextItem(singeritem) != -1 && (check == 0))						// SingerList가 끝이 아니고 SingerList에서 찾지 못했을 때
	{
		if (singer.GetSinger() == singeritem.GetSinger())									// SingerList에서 해당 가수를 찾으면
		{
			cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
			singeritem.DisplayAlbumnameOnScreen();											// 해당 가수의 모든 앨범 출력
			cout << "\n\t" << singer.GetSinger() << "의 앨범목록에서 검색할 앨범을 선택하세요." << endl;
			album.SetAlbumnameFromKB();														// 검색할 앨범명 입력
			while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))					// AlbumList가 끝이 아니고 AlbumList에서 찾지 못했을 때
			{
				cout << endl;
				if (album.GetAlbumname() == albumitem.GetAlbumname())						// AlbumList에서 해당 앨범을 찾으면
				{
					albumitem.DisplayRecordOnScreen();										// 해당 앨범의 정보를 출력
					albumitem.DisplayAlbumListOnScreen();									// 해당 앨범의 수록곡을 출력
					cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
					song.SetNameFromKB();													// 검색할 곡명 입력
					while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))			// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
					{
						if (song.GetName() == songitem.GetName())							// SongList에서 해당 곡을 찾으면
						{
							while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
							{
								if (song.GetName() == musicitem.GetName())					// MasterList에서 해당 곡을 찾으면 
								{
									check3++;
									musicitem.DisplayRecordOnScreen();						// 해당 곡의 모든 정보 출력
								}
							}
							check2++;
						}
					}
					check1++;
				}
			}
			check++;
		}
	}

	//while (SingerList.GetNextItem(singeritem) != -1 && (check == 0))
	//{
	//	if (singer.GetSinger() == singeritem.GetSinger())
	//	{
	//		cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
	//		singeritem.DisplayAlbumnameOnScreen();
	//		cout << "\n\t" << singer.GetSinger() << "의 앨범목록에서 검색할 앨범을 선택하세요." << endl;
	//		while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))
	//		{
	//			album.SetAlbumnameFromKB();
	//			cout << endl;
	//			if (album.GetAlbumname() == albumitem.GetAlbumname())
	//			{
	//				albumitem.DisplayRecordOnScreen();
	//				albumitem.DisplayAlbumListOnScreen();
	//				cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
	//				song.SetNameFromKB();
	//				while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))
	//				{
	//					if (song.GetName() == songitem.GetName())
	//					{
	//						while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))
	//						{
	//							if (song.GetName() == musicitem.GetName())
	//							{
	//								check3++;
	//								musicitem.DisplayRecordOnScreen();
	//							}
	//						}
	//						check2++;
	//					}
	//					
	//				}
	//				check1++;
	//			}
	//		}
	//		check++;
	//	}
	//}
}
*/

/*
// 사용자리스트에서 장르로 검색
void Application::SearchByGenre_User()
{

	cout << "\n\t검색할 곡의 장르를 입력하세요." << endl;
	GenreType genre;
	genre.SetGenreFromKB();
	MusicType music;

	GenreType genreitem;
	GenreList.ResetList();
	MusicType musicitem;
	MasterList.ResetList();
	int check = 0;
	int check1 = 0;

	while (GenreList.GetNextItem(genreitem) != -1 && (check == 0))							// GenreList가 끝이 아니고 GenreList에서 찾지 못했을 때
	{
		if (genre.GetGenre() == genreitem.GetGenre())										// GenreList에서 해당 장르를 찾으면
		{
			cout << "\n\t" << genre.GetGenre() << "장르에는 다음 곡들이 있습니다." << endl;
			genreitem.DisplaySongOnScreen();												// 해당 장르의 모든 곡 출력
			cout << "\n\t" << genre.GetGenre() << "의 장르중에서 검색할 곡의 고유번호를 선택하세요." << endl;
			music.SetIdFromKB();															// 검색할 고유번호 입력
			cout << endl;
			while (MasterList.GetNextItem(musicitem) != -1 && (check1 == 0))				// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
			{
				if (music.GetId() == musicitem.GetId())										// MasterList에서 해당 고유번호를 찾으면
				{
					musicitem.DisplayRecordOnScreen();										// 해당 곡의 모든 정보 출력
					check1++;
				}
			}
			check++;
		}
	}

	if (check == 0)																			// 검색할 장르가 GenreList에 존재하지 않을 때
		cout << "\n\t" << genre.GetGenre() << "장르에 고유번호 " << music.GetId() << "이(가) 존재하지 않습니다. " << endl;




	//cout << "\n\t검색할 곡의 장르를 입력하세요." << endl;
	//GenreType genre;
	//genre.SetGenreFromKB();		
	//MusicType music;
	//int check = 0;

	//if (GenreList.Get(genre))
	//{
	//	cout << "\n\t" << genre.GetGenre() << "에는 다음의 곡들이 있습니다." << endl;
	//	genre.DisplaySongOnScreen();
	//	cout << "\n\t"<<genre.GetGenre()<<"장르 중에서 검색할 곡의 고유번호를 입력하세요." << endl;
	//	music.SetIdFromKB();

	//	MusicType item;
	//	MasterList.ResetList();
	//	while ((MasterList.GetNextItem(item) != -1)&&check==0)
	//		if (item.GetId() == music.GetId())
	//		{
	//			check++;
	//			item.DisplayRecordOnScreen();
	//			cout << endl;
	//		}
	//}
	//if (check == 0)
	//		cout << "\n\t" << genre.GetGenre() << "장르에 고유번호 " <<music.GetId() << "이(가) 존재하지 않습니다. "<< endl;
}
*/

/*
// 사용자리스트에서 앨범명으로 검색
void Application::SearchByAlbumName_User()
{
	AlbumType albumitem;
	AlbumType album;
	cout << "\t검색할 앨범명을 입력하세요." << endl;
	album.SetAlbumnameFromKB();
	MusicType musicitem;
	MusicType music;
	SongType songitem;
	SongType song;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;

	if (AlbumList.Get(album))											// AlbumList에서 해당 앨범명이 존재할 때
	{
		check1++;
		cout << "\n\t" << album.GetAlbumname() << "앨범의 정보는 다음과 같습니다." << endl;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(albumitem) != -1)					// AlbumList가 끝이 아닐 때
		{
			if (album.GetAlbumname() == albumitem.GetAlbumname())		// AlbumList에서 해당 앨범명을 찾으면
			{
				albumitem.DisplayRecordOnScreen();						// 해당 앨범의 정보 출력
				albumitem.DisplayAlbumListOnScreen();					// 해당 앨범의 수록곡 출력
				cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
				song.SetNameFromKB();									// 검색할 곡명 입력
				
				SongList.ResetList();
				while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))		// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
				{
					if (SongList.Get(song))											// SongList에 해당 곡명이 존재하면
					{
						MasterList.ResetList();
						while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
						{
							if (song.GetName() == musicitem.GetName())				// MasterList에서 검색할 곡명을 찾으면
							{
								check3++;
								musicitem.DisplayRecordOnScreen();					// 해당 곡의 모든 정보 출력
							}
						}
						check2++;
					}

				}
			}
		}
	}

	if (check1 == 0)
	{
		cout << "\n\t" << album.GetAlbumname() << " 앨범이 사용자리스트에 존재하지 않습니다." << endl;
	}
	else if (check2 == 0)
		cout << "\n\t" << song.GetName() << " 은(는)" << album.GetAlbumname() << " 앨범의 수록곡이 아닙니다." << endl;
}
*/


/*
// 사용자리스트에서 소속사로 검색
void Application::SearchByEnt_User()
{
	EntType ent;
	EntType entitem;
	cout << "\n\t검색할 소속사를 입력하세요." << endl;
	ent.SetEntFromKB();
	SingerType singer;
	SingerType singeritem;
	AlbumType album;
	AlbumType albumitem;
	SongType song;
	SongType songitem;
	MusicType music;
	MusicType musicitem;
	int check = 0;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
	int check4 = 0;

	

	EntList.ResetList();
	while (EntList.GetNextItem(entitem) != -1 )									// EntList가 끝이 아닐 때
	{
		if (ent.GetEnt() == entitem.GetEnt())									// EntList에서 검색할 소속사를 찾으면
		{
			cout << "\n\t" << ent.GetEnt() << "의 소속 가수는 다음과 같습니다." << endl;
			entitem.DisplayEntListOnScreen();									// 해당 소속사의 모든 가수 출력
			cout << "\n\t" << ent.GetEnt() << "의 소속 가수중 검색할 가수를 선택하세요." << endl;
			singer.SetSingerFromKB();											// 검색할 가수입력
			SingerList.ResetList();
			while (SingerList.GetNextItem(singeritem) != -1&&(check1==0))		// SingerList가 끝이 아니고 SingerList에서 찾지 못했을 때
			{
				if (singer.GetSinger() == singeritem.GetSinger())				// SingerList에서 검색할 가수를 찾으면
				{
					cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
					singeritem.DisplayAlbumnameOnScreen();						// 해당 가수의 모든 앨범 출력
					cout << "\n\t" << singer.GetSinger() << "의 앨범목록에서 검색할 앨범을 선택하세요." << endl;
					album.SetAlbumnameFromKB();									// 검색할 앨범명 입력
					AlbumList.ResetList();
					while (AlbumList.GetNextItem(albumitem) != -1&&(check2==0))	// AlbumList가 끝이 아니고 AlbumList에서 찾지 못했을 때
					{
						cout << endl;
						if (album.GetAlbumname() == albumitem.GetAlbumname())	// AlbumList에서 검색할 앨범을 찾으면
						{
							albumitem.DisplayRecordOnScreen();					// 해당 앨범의 정보 출력
							albumitem.DisplayAlbumListOnScreen();				// 해당 앨범의 수록곡 출력
							cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;
							song.SetNameFromKB();								// 검색할 곡명 입력
							while (SongList.GetNextItem(songitem) != -1 && (check3 == 0))	// SongList가 끝이 아니고 SongList에서 찾지 못했을 때
							{
								if (song.GetName() == songitem.GetName())		// SongList에서 검색할 곡을 찾으면
								{
									MasterList.ResetList();
									while (MasterList.GetNextItem(musicitem) != -1 && (check4 == 0))	// MasterList가 끝이 아니고 MasterList에서 찾지 못했을 때
									{
										if (song.GetName() == musicitem.GetName())	// MasterList에서 검색할 곡을 찾으면
										{
											check4++;
											musicitem.DisplayRecordOnScreen();		// 해당 곡의 모든 정보 출력
										}
									}
									check3++;
								}
							}
							check2++;
						}
					}
					check1++;
				}
			}
		}
		check++;
	}

	if (check == 0)
		cout << "\n\t" << ent.GetEnt() << " 소속사가 없습니다." << endl;
	else if (check1 == 0)
		cout << "\n\t" << singer.GetSinger() << " 을(를) 찾을 수 없습니다" << endl;
	else if (check2 == 0)
		cout << "\n\t" << album.GetAlbumname() << " 앨범을 찾을 수 없습니다." << endl;
	else if (check3 == 0)
		cout << "\n\t" << song.GetName() << " 을(를) 찾을 수 없습니다." << endl;




	//if (EntList.Get(ent))
	//{
	//	cout << "\n\t" << ent.GetEnt() << "의 정보는 다음과 같습니다." << endl;
	//	ent.DisplayEntListOnScreen();
	//	cout << "\n\t" << ent.GetEnt() << "에서 검색할 가수를 선택하세요." << endl;

	//	singer.SetSingerFromKB();
	//	SingerList.Get(singer);
	//	cout << "\n\t" << singer.GetSinger() << "의 앨범은 다음과 같습니다." << endl;
	//	singer.DisplayAlbumnameOnScreen();
	//	cout << "\n\t" << singer.GetSinger() << "의 앨범 중 검색할 앨범을 선택하세요." << endl;

	//	album.SetAlbumnameFromKB();
	//	AlbumList.Get(album);
	//	cout << "\n\t" << album.GetAlbumname() << "의 정보는 다음과 같습니다." << endl;
	//	album.DisplayRecordOnScreen();
	//	album.DisplayAlbumListOnScreen();
	//	cout << "\n\t" << album.GetAlbumname() << "의 수록곡 중 모든 정보를 출력할 곡을 선택하세요." << endl;

	//	music.SetNameFromKB();
	//	MasterList.RetrieveMusic_Binary(music);
	//	music.DisplayRecordOnScreen();
	//	check++;
	//}
	//if (check == 0)
	//{
	//	cout << "\n\t" << ent.GetEnt() << "소속 " << singer.GetSinger() << "의 " << album.GetAlbumname() << "에 ";
	//	cout << music.GetName() << "이 없습니다." << endl;
	//}
}
*/




////저장할 filename을 입력하고 file이 생성되면 1, 아니면 0 리턴
//int Application::OpenOutFile(char *fileName)
//{
//	m_OutFile.open(fileName);	//저장할 fileName에 해당하는 file을 연다.
//	if (m_OutFile)	//여는데 성공하면
//		return 1;
//	else
//		return 0;
//}
//
//// 읽어들일 filename을 입력받아 open하면 file의 모든 내용을 읽고 레코드에 추가.
//// 이후 읽은 모든 값을 화면에 출력, 성공하면 1, 아니면 0 리턴
//int Application::ReadDataFromFile()
//{
//	MusicType music;
//
//	char filename[FILENAMESIZE];	//읽어들일 filename 설정
//	cout << "\tEnter Input File Name : ";
//	cin >> filename;
//
//	if (!OpenInFile(filename))	//여는데 실패하면
//	{
//		cout << "\n\tCan't open file " << filename << endl;
//		return 0;
//	}
//
//	while (!m_InFile.eof())	//파일 끝이 아닌 경우
//	{
//		music.ReadDataFromFile(m_InFile);	//m_InFile로부터 data를 읽어옴
//		MasterList.Add(music);		//읽은 data를 MusicList에 추가
//	}
//
//	m_InFile.close();	//file 닫기
//	DisplayAllMusic();	//file로부터 읽은 모든 정보 화면에 출력
//
//	return 1;
//}
//
////저장할 filename을 입력받고 레코드의 모든 내용을 file에 저장. 성공하면 1, 아니면 0 리턴
//int Application::WriteDataToFile()
//{
//	MusicType music;
//	char filename[FILENAMESIZE];	//저장할 filename 설정
//	cout << "\n\tEnter Output File Name : ";
//	cin >> filename;
//
//	if (!OpenOutFile(filename))		//file을 여는데 실패하면
//		return 0;
//
//	MasterList.ResetList();	//배열의 iterator를 -1로 초기화
//
//	int length = MasterList.GetLength();		//레코드의 길이
//	int curindex = MasterList.GetNextItem(music);		//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	while (curindex < length&&curindex != -1)		//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		music.WriteDataToFile(m_OutFile);		//iterator가 가르키는 항목의 레코드를 m_OutFil에 저장
//		curindex = MasterList.GetNextItem(music);	//다음 레코드를 가르키도록 설정
//	}
//
//	m_OutFile.close();	//file 닫기
//	return 1;
//}
//
////레코드의 모든 항목을 화면에 출력
//void Application::DisplayAllMusic()
//{
//	MusicType music;
//
//	cout << "\n\tCurrent list" << endl;
//	MasterList.ResetList();	//배열의 iterator를 -1로 초기화
//	int length = MasterList.GetLength();	//레코드의 길이
//	int curindex = MasterList.at(music.GetId())->GetNextItem(music);	//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	while (curindex < length&&curindex != -1)		//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		music.DisplayRecordOnScreen();		//해당 iterator가 가르키는 레코드의 항목 화면에 출력
//		curindex = MasterList.GetNextItem(music);	//iterator가 다음 항목 가르키도록 설정
//	}
//}
//


//
////레코드에 항목 추가
//int Application::U_AddMusic()
//{
//	if (MasterList.IsFull())	//레코드가 꽉 차있으면 0 리턴
//	{
//		cout << "List is full" << endl;
//		return 0;
//	}
//	MusicType music;
//	music.SetRecordFromKB();	//레코드를 keyboard로부터 입력받음
//	m_MusicList.Add(music);	//레코드에 항목 추가
//	cout << endl;
//	DisplayAllMusic();	//레코드에 저장된 모든 항목 화면에 출력
//	return 1;	//항목 추가에 성공하면 1 리턴
//}
//
////void Application::DeleteMusic()
////{
////	MusicType music;
////	cout << "\tEnter id number to delete";
////	music.SetIdFromKB();
////	if (m_List.Delete(music))
////		cout << "\tDelete complete" << endl;
////	else
////		cout << "\tDelete fail. There's no id match with." << endl;
////}
////
//
////keyboard로 부터 Id 입력받고 일치하는 Id의 항목 삭제
//void Application::DeleteMusicById()
//{
//	MusicType music;
//	cout << "\tEnter id to delete";
//	music.SetIdFromKB();	//keyboard로부터 Id를 입력받음.
//	if (m_MusicList.DeleteById(music))	//입력받은 Id와 일치하는 항목이 있으면 해당 항목을 제거
//		cout << "\tDelete complete" << endl;
//	else					//일치하는 항목이 없으면
//		cout << "\tDelete fail. There's no id match with." << endl;
//}
//
////void Application::ReplaceMusic()
////{
////	MusicType music;
////	cout << "\tEnter music name to replace";
////	music.SetNameFromKB();
////	if (m_List.Get(music))
////	{
////		music.SetTypeFromKB();
////		music.SetGenreFromKB();
////		music.SetMelodizerFromKB();
////		music.SetSingerFromKB();
////		music.SetIdFromKB();
////		if (m_List.Replace(music))
////			cout << "\tReplace complete." << endl;
////		else
////			cout << "\tReplace Fail." << endl;
////	}
////	else
////		cout << "\tReplace Fail. There's no name match with." << endl;
////	
////}
//
////수정할 곡의 id를 입력한 뒤 존재하면, 새로운 값으로 설정
//void Application::ReplaceMusicById()
//{
//	MusicType music;
//	cout << "\tEnter id to replace";
//	music.SetIdFromKB();	//keyboard로부터 Id를 입력받음
//	if (m_MusicList.GetFromId(music))	//입력받은 Id와 일치하는 항목이 있을 때 
//	{
//		//일치하는 MusicList의 각 변수를 keyboard로 부터 입력받음.
//		music.SetTypeFromKB();
//		music.SetGenreFromKB();
//		music.SetNameFromKB();
//		music.SetMelodizerFromKB();
//		music.SetSingerFromKB();
//		if (m_MusicList.ReplaceById(music))	//Id가 일치할 때 해당항목을 입력받은 항목으로 변경
//		{
//			cout << "\tReplace complete." << endl;
//		}
//		else					//일치하는 항목이 없으면
//			cout << "\tReplace Fail." << endl;
//	}
//	else
//		cout << "\tReplace Fail. There's no Id match with." << endl;
//}
//
//
////입력받은 Id랑 일치하는 항목을 전부 화면에 출력
//void Application::RetrieveMusic_BS()
//{
//	MusicType music;
//	MusicType search;
//	cout << endl;
//	search.SetIdFromKB();	//검색할 Id를 keyboard로부터 입력받음
//
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	
//	int length = m_MusicList.GetLength();
//	int curindex = m_MusicList.GetNextItem(music);
//	int check = 0;
//	
//	
//		
//	if (m_MusicList.RetrieveMusic_Binary(music))	//Binary search로 Id를 검색에 성공했을 때
//	{
//		cout << "\t---------------------------------------" << endl << endl;
//		music.DisplayRecordOnScreen();	//해당 레코드를 출력
//		check++;	//검색에 성공하면 check를 증가
//		/*for (curindex; curindex < length; curindex++)
//		{
//			if (music.GetId() != search.GetId())
//				m_MusicList.GetNextItem(music);
//			else
//			{
//				cout << "\t---------------------------------------" << endl << endl;
//				music.DisplayDataOnScreen();
//				check++;
//				break;
//			}
//		}*/
//	}
//	if(check==0)	//검색한 Id가 레코드에 없을 때
//		cout << "\tThere's no id number with " << search.GetId() << endl;
//	else			//검색한 Id가 레코드에 있을 때
//		cout << "\n\t-------------------------------------" << endl;
//}
//

////레코드를 초기화
//void Application::MakeEmpty()
//{
//	m_MusicList.MakeEmpty();
//}
//
////검색한 type에 해당하는 모든 항목 화면에 출력
//void Application::SearchByType()
//{
//	MusicType music;
//	cout << "\tEnter searh type (1. song	2. concertino) ";
//	int num;
//	cin >> num;
//	while (!(num == 1 || num == 2))		//type이 1 혹은 2가 아닐 경우
//	{
//		cout << "\tPlease enter 1 or 2";
//		cin >> num;
//	}
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);	//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	if (num == 1)	//검색한 type이 1인 경우
//		cout << "\tList of song type" << endl;
//	else		//검색한 type이 2인 경우
//		cout << "\tList of concertino type" << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		music.DisplayRecordOnScreen();		//해당 iterator가 가르키는 레코드의 항목 화면에 출력
//		check++;
//		curindex = m_MusicList.GetNextItem(music);		//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 type이 존재하지 않을 경우
//	{
//		cout << "\tThere's no type of ";
//		if (num == 1)
//			cout << "song" << endl;
//		else
//			cout << "concertino" << endl;
//	}
//}
//
////검색한 genre에 해당하는 모든 항목 화면에 출력
//void Application::SearchByGenre()
//{
//	MusicType music;
//	cout << "\tEnter music genre";
//	MusicType search;
//	search.SetGenreFromKB();	//keyboard로부터 검색할 genre 입력
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);	//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	cout << "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		if (music.GetGenre() == search.GetGenre())	//검색할 genre가 레코드에 존재할 경우
//		{
//			
//			music.DisplayNameOnScreen();	//해당 레코드의 name을 출력
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 genre가 레코드에 없을 경우
//	{
//		cout << "\tThere's no music genre with " << search.GetGenre() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//} 
//
////검색한 name에 해당하는 모든 항목 화면에 출력
//void Application::SearchByName()
//{
//	MusicType music;
//	cout << "\tEnter music name";
//	MusicType search;
//	search.SetNameFromKB();		//keyboard로부터 검색할 name 입력
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);		//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	while (curindex < m_MusicList.GetLength()&&curindex != -1)		//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		if (music.GetName() == search.GetName())	//검색할 name이 레코드에 존재할 경우
//		{
//			music.DisplayRecordOnScreen();		//해당 레코드를 화면에 출력
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 name이 존재하지 않을 경우
//		cout << "\tThere's no music name with " << search.GetName() << endl;
//}
//
////검색한 melodizer에 해당하는 모든 항목 화면에 출력
//void Application::SearchByMelodizer()
//{
//	MusicType music;
//	cout << "\tEnter melodizer name";
//	MusicType search;
//	search.SetMelodizerFromKB();	//keyboard로부터 검색할 melodizer 입력
//	m_MusicList.ResetList();		//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);		//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		if (music.GetMelodizer() == search.GetMelodizer())	//검색할 melodizer가 레코드에 존재할 경우
//		{
//			music.DisplayMelodizerOnScreen();		//해당 melodizer를 화면에 출력
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);		//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 melodizer가 존재하지 않을 경우
//		cout << "\tThere's no melodizer name with " << search.GetMelodizer() << endl;
//}
//
////검색한 singer에 해당하는 모든 항목 화면에 출력
//void Application::SearchBySinger()
//{
//	MusicType music;
//	cout << "\tEnter singer name";
//	MusicType search;
//	search.SetSingerFromKB();	//keyboard로부터 검색할 singer 입력
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);	//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	cout << "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		
//		if (music.GetSinger() == search.GetSinger())	//검색할 singer가 레코드에 존재할 경우
//		{
//			music.DisplayNameOnScreen();		//해당 레코드의 name을 화면에 출력
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 singer가 존재하지 않을 경우
//	{
//		cout << "\tThere's no singer name with " << search.GetSinger() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//}
//
////검색한 id에 해당하는 모든 항목 화면에 출력
//void Application::SearchById()
//{
//	MusicType music;
//	cout << "\tEnter Id";
//	MusicType search;
//	search.SetIdFromKB();	//keyboard로부터 검색할 Id 입력
//	m_MusicList.ResetList();	//배열의 iterator를 -1로 초기화
//	int curindex = m_MusicList.GetNextItem(music);	//레코드의 iterator 1증가 후 iterator 리턴. 끝이면 -1 리턴
//	int check = 0;
//	cout<< "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator가 레코드의 길이보다 작고 레코드의 끝이 아닐 때
//	{
//		if (music.GetId() == search.GetId())	//검색할 Id가 레코드에 존재할 경우
//		{
//			music.DisplayRecordOnScreen();		//해당 레코드를 화면에 출력
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);		//iterator가 다음 항목 가르키도록 설정
//	}
//	if (check == 0)		//검색한 Id가 존재하지 않을 경우
//	{
//		cout << "\tThere's no id match with " << search.GetId() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//}
//

//// Id를 검색해 레코드에 존재하면 PlayList에 추가
//void Application::AddPlayMusic()
//{
//	cout << "\tEnter music data to add." << endl;
//	PlayItemType item;
//	MusicType music;
//
//	item.SetRecordFromKB();		//keyboard로부터 저장할 항목 입력
//	music.SetId(item.GetId());	//저장할 항목의 Id를 검색할 용도
//	if (m_MusicList.GetFromId(music))	//레코드에 해당 Id가 존재할 경우
//	{
//		m_PlayList.AddToPlayList(item);	//PlayList에 저장
//		cout << endl;
//		item.DisplayRecordOnScreen();	//저장한 항목 출력
//	}
//	else
//		cout << "\tThere's no record with Id : " << music.GetId() << endl;	
//}
//
////Id를 PlayList에서 검색해 존재하면 해당 항목 삭제
//void Application::DeletePlayMusic()
//{
//	PlayItemType item;
//	m_PlayList.DeleteFrPlayList(item);
//}
//
////PlayList에 저장된 순서대로 항목 출력
//void Application::PrintAllPlayMusic()
//{
//	PlayItemType item;
//	m_PlayList.PlayInsertOrder(item);
//}
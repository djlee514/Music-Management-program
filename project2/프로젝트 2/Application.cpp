#include "Application.h"

// Application ������
Application::Application()
{
	m_Command = 0;
}

// Application �Ҹ���
Application::~Application() {}

// �⺻ ���α׷� ����
void Application::RunProgram()
{
	while (true)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{	
		case 0:
			cout << "\t�������� ���α׷��� �ݽ��ϴ�." << endl;
			return;
		case 1:
			Admin();	// �����ڿ� ��� �α��� ����
			break;
		case 2:
			User();				// �Ϲ� ����ڿ� ���� ����
			break;
		default:
			cout << "\t�߸��� ����Դϴ�. �ٽ� �Է��ϼ���." << endl;
			break;
		}
	}
}

// ��밡���� ��带 ����ϰ� �����Ͽ� �ش��ϴ� ��ɾ ��ȯ
int Application::GetCommand()
{
	int com;
	cout << "\n\t-------- �������� ���α׷� ----------" << endl;
	cout << "\t|  0 : �������� ���α׷� ����       |" << endl;
	cout << "\t|  1 : ���α׷� ������ ������ ���  |" << endl;
	cout << "\t|  2 : �Ϲ� ����� ������ ���      |" << endl;
	cout << "\t-------------------------------------" << endl;

	cout << "\t����� ��带 �Է��ϼ���--> ";
	cin >> com;
	cout << endl;

	return com;
}

// �����ڿ� ���� �α��� ���� Ȯ�� �� �����Ǹ� ������ ��� ����
void Application::Admin()
{
	while (true)
	{
		string id, pw;
		cout << endl << endl;
		cout << "\t------------------ �����ڿ� ��� ------------------" << endl;
		cout << "\t�α��� ������ �����մϴ�." << endl;
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
			cout << "\t�����ڷ� ��ϵ��� ���� �����Դϴ�." << endl;
	}
}

// ����ڿ� ���� �α��� ���� Ȯ�� �� �����Ǹ� ����� ��� ����
void Application::User()
{
	while (true)
	{
		cout << endl << endl;
		int com;

		cout << "\t------------------ ����� ���� ��� ------------------" << endl;
		cout << "\t   0 : ����� ������� ����" << endl;
		cout << "\t   1 : �α���" << endl;
		cout << "\t   2 : ȸ������" << endl;
		cout << "\t------------------------------------------------------" << endl;

		cout << "\n\t������ ��ɾ �����ϼ���--> ";
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
			cout << "\t ������ �� ���� ����Դϴ�." << endl;
		}
	}
}

// ����ڿ� ��� �α��� ��������
void Application::Login_User()
{
	while (true)
	{
		UserType user;
		cout << "\n\t----------- �α��� -----------" << endl;
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
				cout << "\n\t�α��ο� �����߽��ϴ�." << endl;
				char id;
				cout << "\n\t�α����� ID�� �ٽ� �Է����ּ���. ";
				cin >> id;
				Read_User(id);
				Run_User();
				return;
			}
			else
			{
				cout << "\n\t�α��ο� �����߽��ϴ�." << endl;
				cout << "\t���̵� Ȥ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
				cout << "\t�ʱ�ȭ������ ���ư����� y�� �Է��ϼ���." << endl;
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
			cout << "\n\t���������� ��ġ�ϴ� ������ �����ϴ�." << endl;
			cout << "\t�ʱ�ȭ������ ���ư����� y�� �Է��ϼ���." << endl;
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

// ����ڿ� ��� ȸ������
void Application::SignUp_User()
{
	while (true)
	{
		UserType user;
		cout << "\n\t------------ ���� ȸ������ ------------" << endl; 
		cout << "\t������ ������ �Է��ϼ���." << endl;
		user.SetRecordFromKB();
		cout << "\t---------------------------------------" << endl;

		if (UserList.Get(user))
		{
			system("cls");
			cout << "\n\t�ش� ������ �̹� ȸ�������� �Ǿ��ֽ��ϴ�." << endl;
			break;
		}
		else
		{
			system("cls");
			UserList.Add(user);
			cout << "\n\tȸ�������� ���������� �Ϸ�Ǿ����ϴ�." << endl;
			break;
		}
	}
}

// �Ϲ� ����� ������ ��忡�� ��밡���� ��ɾ���� ��û�� ���� ����
void Application::Run_User()
{
	while (true)
	{
		cout << endl << endl;
		int com;

		cout << "\t------------------ ���� ��� ------------------" << endl;
		cout << "\t   0 : ���� ��� ����" << endl;
		cout << "\t   1 : ����� ������Ͽ� ���� �߰�" << endl;
		cout << "\t   2 : ����� ������Ͽ��� ���� ����" << endl;
		cout << "\t   3 : ����� ������Ͽ� �ִ� ���� ���� ���" << endl;
		cout << "\t   4 : ����� ������Ͽ� �ֱ� �߰��� ������ �˻�" << endl;
		cout << "\t   5 : ����� ������Ͽ��� ���� ������ȣ�� ���� �˻�" << endl;
		cout << "\t   6 : ����� ������Ͽ��� ����� ���� �˻�" << endl;
		cout << "\t   7 : ����� ������Ͽ��� �������� ���� �˻�" << endl;
		cout << "\t   8 : ����� ������Ͽ��� �帣�� ���� �˻�" << endl;
		cout << "\t   9 : ����� ������Ͽ��� �ٹ����� ���� �˻�" << endl;
		cout << "\t   10 : ����� ������Ͽ��� �Ҽӻ縦 ���� �˻�" << endl;;
		cout << "\t---------------------------------------------" << endl;

		cout << "\n\t������ ��ɾ �����ϼ���--> ";
		cin >> com;
		cout << endl;

		
		switch (com)
		{
		case 0:			// 0�� �Է��ϸ� Release ��� ����
			system("cls");
			cout << "\n\t�α׾ƿ��ϰ� ������带 �����մϴ�." << endl;
			Save_User();
			return;
		case 1:			// 1�� �� Release program AddMusic ����
			system("cls");
			AddMusic_User();		
			break;
		case 2:			// 2�� �� Release program DeleteMusic ����
			system("cls");
			DeleteMusic_User();
			break;
		case 3:			// 3�� �� Release program DisplayAllMusic ����
			system("cls");
			DisplayAllMusic_User();
			break;
		case 4:
			system("cls");
			SearchByRecentlyMusic_User();
			break;
		case 5:			// 4�� �� Release program SearchById ����
			system("cls");
			SearchById_User();
			break;
		case 6:			// 5�� �� Release program SearchByName ����
			system("cls");
			SearchByName_User();
			break;
		case 7:			// 6�� �� Release program SearchBySinger ����
			system("cls");
			SearchBySinger_User();
			break;
		case 8:			// 7�� �� Release program SearchByGenre ����
			system("cls");
			SearchByGenre_User();
			break;
		case 9:			// 8�� �� Release program SearchByAlbumName ����
			system("cls");
			SearchByAlbumName_User();
			break;
		case 10:		// 9�� �� Release program SearchByEnt ����
			system("cls");
			SearchByEnt_User();
			break;
		/*case 11:
			system("cls");
			PlayMusic_User();*/
		default:		// �� ���� �� �Է��ϸ� default�� ������ ���� ���
			cout << "\t������ �� ���� ����Դϴ�." << endl;
			break;
		}
	}
}

// ������ ������ ��忡�� ��밡���� ��ɾ���� ��û�� ���� ����
void Application::Run_Admin()
{
	while (true)
	{
		cout << endl << endl;
		int com;
		cout << "\t-------------------- �����ڿ� ��� -------------------" << endl;
		cout << "\t   0 : �����ڿ� ��� ����" << endl;
		cout << "\t   1 : ���� �߰�" << endl;
		cout << "\t   2 : ���� ����" << endl;
		cout << "\t   3 : ���� ����" << endl;
		cout << "\t   4 : �����͸���Ʈ ��������" << endl;
		cout << "\t   5 : ��� ���� ���" << endl;
		cout << "\t------------------------------------------------------" << endl;

		cout << "\n\t������ ��ɾ �����ϼ���--> ";
		cin >> com;
		cout << endl;


		switch (com)
		{
		case 0:
			system("cls");
			cout << "\n\t�α׾ƿ��ϰ� �����ڸ�带 �����մϴ�." << endl;
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
			cout << "\t������ �� ���� ����Դϴ�." << endl;
			break;
		}
	}
}

// �����͸���Ʈ�� ���� �߰�
void Application::AddMusic_Admin()
{
	MusicType music;
	cout << "\n\t�߰��� ������ ������ �Է��ϼ���\n";
	music.SetRecordFromKB();
	MasterList.Add(music);

	
	//

	// AlbumList�� �߰��� �� �̹� �����ϴ� �ٹ��� �߰��� �� ��.

	//

	// AlbumList�� �߰�
	if (AlbumList.GetLength() == 0)					// AlbumList�� ������� �� 
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
		album.SetNumberofsonginalbumIncrease();										// �ٹ� ���ϰ� �� 1 ����
		simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum ����
		album.AddMusicToAlbum(simple);												// album�� �߰�
		AlbumList.Add(album);														// album�� AlbumList�� �߰�
	}
	else											// AlbumList�� ���Ұ� ������ ��	
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
		simple.SetRecord(music.GetId(), music.GetName());

		AlbumType temp;																// AlbumType �ӽú���
		int test = 0;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(temp) != -1)									// AlbumList ������ �˻�
		{
			if (temp.GetAlbumname() == album.GetAlbumname())	// �߰��� �ٹ����� AlbumList�� ������ ���
			{
				temp.AddMusicToAlbum(simple);										// �ش� �ٹ��� �߰�
				temp.SetNumberofsonginalbumIncrease();
				AlbumList.Replace(temp);											// AlbumList�� ����
				test++;
				break;
			}
		}
		if (test == 0)								// �߰��� �ٹ����� AlbumList�� ���� ���
		{
			album.AddMusicToAlbum(simple);											// ���ο� album�� �߰�
			album.SetNumberofsonginalbumIncrease();									// �ش� �ٹ� ���ϰ�� 1 ����
			AlbumList.Add(album);													// AlbumList�� �ش� �ٹ� �߰�
			/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
			temp.SetNumberofsonginalbumIncrease();
			temp.AddMusicToAlbum(simple);
			AlbumList.Add(temp);*/
		}
	}


	// GenreList�� �߰�
	if (GenreList.GetLength() == 0)					// GenreList�� ������� ��
	{
		GenreType genre;
		SongType song;
		genre.SetGenre(music.GetGenre());											// �߰��� genre ����
		song.SetId(music.GetId());													// �߰��� ���� Id�� ����
		song.SetName(music.GetName());												// �߰��� ���� ����� ����
		genre.AddMusicInGenre(song);												// genre�� ���� ���� �߰�
		GenreList.Add(genre);														// GenreList�� �ش� genre�� �߰�
	}
	else											// GenreList�� ���Ұ� ���� ��
	{
		GenreType genre;
		SongType song;

		genre.SetGenre(music.GetGenre());											// �߰��� genre ����
		song.SetId(music.GetId());													// �߰��� ���� id ����
		song.SetName(music.GetName());												// �߰��� ���� ��� ����

		GenreType temp;
		int test = 0;
		while (GenreList.GetNextItem(temp) != -1)									// GenreList ������ �˻�
		{
			if (temp.GetGenre() == music.GetGenre())	// GenreList�� �˻��� ���� �帣�� ������ ���
			{
				temp.AddMusicInGenre(song);											// �ش� �帣�� �� �߰�
				GenreList.Replace(temp);											// GenreList�� ����
				test++;
				break;
			}
		}
		if (test == 0)								// GenreList�� �˻��� ���� �帣�� ���� ���
		{
			genre.AddMusicInGenre(song);											// ���ο� �帣�� �߰�
			GenreList.Add(genre);													// GenreList�� �߰�
		}
	}


	// SingerList�� �߰�
	if (SingerList.GetLength() == 0)				// SingerList�� ���Ұ� ���� ���
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
		album.SetNumberofsonginalbumIncrease();										// album ���ϰ�� 1 ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
		album.AddMusicToAlbum(simple);												// album�� ���� �߰�
		singer.AddMusicToSinger(album);												// singer�� album �߰�
		SingerList.Add(singer);														// SingerList�� singer �߰�
	}
	else											// SingerList�� ���Ұ� ���� ���
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;
		singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
		if (SingerList.Get(singer))					// SingerList�� �߰��� ������ ������ ���
		{
			singer.AddMusicToSinger(album, simple);									// ������ album�� ������ ������ �߰�
			SingerList.Delete(singer);												// SingerList���� �ش� ������ ����
			SingerList.Add(singer);													// SingerList�� ���ŵ� ������ ������ �߰�
		}
		else										// SingerList�� �߰��� ������ ���� ���
		{
			album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
			album.AddMusicToAlbum(simple);											// album�� ���� �߰�
			singer.AddMusicToSinger(album);											// singer�� album �߰�
			SingerList.Add(singer);													// SingerList�� singer �߰�
		}
	}



	// EntList�� �߰�
	if (EntList.GetLength() == 0)					// EntList�� ���Ұ� ���� ���
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// �߰��� ent ����
		singer.SetSinger(music.GetSinger());										// �߰��� singer ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
		album.AddMusicToAlbum(simple);												// album�� ������ ���� �߰�
		singer.AddMusicToSinger(album);												// singer�� album �߰�
		ent.AddMusicToEnt(singer);													// ent�� singer �߰�
		EntList.Add(ent);															// EntList�� ent �߰�
	}
	else											// EntList�� ���Ұ� ���� ���
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// �߰��� ent ����
		singer.SetSinger(music.GetSinger());										// �߰��� singer ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
		if (EntList.Get(ent))						// EntList�� �߰��� �Ҽӻ簡 ���� ���
		{
			ent.AddMusicToEnt(singer, album);										// ent�� singer�� album�� ���� �߰�
			EntList.Delete(ent);													// EntList���� ent ����
			EntList.Add(ent);														// EntList�� ���ŵ� ent �߰�
		}
		else										// EntList�� �߰��� �Ҽӻ簡 ���� ���
		{
			album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
			album.AddMusicToAlbum(simple);											// album�� ������ ���� �߰�
			singer.AddMusicToSinger(album);											// singer�� album �߰�
			ent.AddMusicToEnt(singer);												// ent�� singer �߰�
			EntList.Add(ent);														// EntList�� ent �߰�
		}
	}
}


// �����͸���Ʈ���� ���� ����
void Application::DeleteMusic_Admin()
{
	cout << "\t������ �� ���� ������ȣ�� �Է��ϼ���." << endl;
	MusicType music;
	music.SetIdFromKB();
	if (MasterList.Get(music))
	{
		// �����͸���Ʈ���� ����
		MasterList.Delete(music);

		// AlbumList���� ����
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

		// SingerList���� ����
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

		// GenreList���� ����
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

		// EntList���� ����
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

		cout << "\n\t������ �Ϸ��߽��ϴ�." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\t������ �����߽��ϴ�. ��ġ�ϴ� ������ �����͸���Ʈ�� �������� �ʽ��ϴ�." << endl;
	}
}

// �����͸���Ʈ ����
void Application::ReplaceMusic_Admin()
{
	cout << "\n\t������ ���� ������ȣ�� �Է��ϼ���" << endl;
	MusicType music;
	music.SetIdFromKB();
	if (MasterList.Get(music))
	{
		// �����͸���Ʈ���� ����
		MasterList.Delete(music);

		// AlbumList���� ����
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

		// SingerList���� ����
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

		// GenreList���� ����
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

		// EntList���� ����
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


		// ���� �Է¹��� �׸� �߰�
		MasterList.Add(music);

		// AlbumList�� �߰�
		if (AlbumList.GetLength() == 0)					// AlbumList�� ������� �� 
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
			album.SetNumberofsonginalbumIncrease();										// �ٹ� ���ϰ� �� 1 ����
			simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum ����
			album.AddMusicToAlbum(simple);												// album�� �߰�
			AlbumList.Add(album);														// album�� AlbumList�� �߰�
		}
		else											// AlbumList�� ���Ұ� ������ ��	
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
			simple.SetRecord(music.GetId(), music.GetName());

			AlbumType temp;																// AlbumType �ӽú���
			int test = 0;
			while (AlbumList.GetNextItem(temp) != -1)									// AlbumList ������ �˻�
			{
				if (temp.GetAlbumname() == album.GetAlbumname())	// �߰��� �ٹ����� AlbumList�� ������ ���
				{
					temp.AddMusicToAlbum(simple);										// �ش� �ٹ��� �߰�
					temp.SetNumberofsonginalbumIncrease();
					AlbumList.Replace(temp);											// AlbumList�� ����
					test++;
					break;
				}
			}
			if (test == 0)								// �߰��� �ٹ����� AlbumList�� ���� ���
			{
				album.AddMusicToAlbum(simple);											// ���ο� album�� �߰�
				album.SetNumberofsonginalbumIncrease();									// �ش� �ٹ� ���ϰ�� 1 ����
				AlbumList.Add(album);													// AlbumList�� �ش� �ٹ� �߰�
				/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
				temp.SetNumberofsonginalbumIncrease();
				temp.AddMusicToAlbum(simple);
				AlbumList.Add(temp);*/
			}
		}


		// GenreList�� �߰�
		if (GenreList.GetLength() == 0)					// GenreList�� ������� ��
		{
			GenreType genre;
			SongType song;
			genre.SetGenre(music.GetGenre());											// �߰��� genre ����
			song.SetId(music.GetId());													// �߰��� ���� Id�� ����
			song.SetName(music.GetName());												// �߰��� ���� ����� ����
			genre.AddMusicInGenre(song);												// genre�� ���� ���� �߰�
			GenreList.Add(genre);														// GenreList�� �ش� genre�� �߰�
		}
		else											// GenreList�� ���Ұ� ���� ��
		{
			GenreType genre;
			SongType song;

			genre.SetGenre(music.GetGenre());											// �߰��� genre ����
			song.SetId(music.GetId());													// �߰��� ���� id ����
			song.SetName(music.GetName());												// �߰��� ���� ��� ����

			GenreType temp;
			int test = 0;
			while (GenreList.GetNextItem(temp) != -1)									// GenreList ������ �˻�
			{
				if (temp.GetGenre() == music.GetGenre())	// GenreList�� �˻��� ���� �帣�� ������ ���
				{
					temp.AddMusicInGenre(song);											// �ش� �帣�� �� �߰�
					GenreList.Replace(temp);											// GenreList�� ����
					test++;
					break;
				}
			}
			if (test == 0)								// GenreList�� �˻��� ���� �帣�� ���� ���
			{
				genre.AddMusicInGenre(song);											// ���ο� �帣�� �߰�
				GenreList.Add(genre);													// GenreList�� �߰�
			}
		}


		// SingerList�� �߰�
		if (SingerList.GetLength() == 0)				// SingerList�� ���Ұ� ���� ���
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
			album.SetNumberofsonginalbumIncrease();										// album ���ϰ�� 1 ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
			album.AddMusicToAlbum(simple);												// album�� ���� �߰�
			singer.AddMusicToSinger(album);												// singer�� album �߰�
			SingerList.Add(singer);														// SingerList�� singer �߰�
		}
		else											// SingerList�� ���Ұ� ���� ���
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;
			singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
			if (SingerList.Get(singer))					// SingerList�� �߰��� ������ ������ ���
			{
				singer.AddMusicToSinger(album, simple);									// ������ album�� ������ ������ �߰�
				SingerList.Delete(singer);												// SingerList���� �ش� ������ ����
				SingerList.Add(singer);													// SingerList�� ���ŵ� ������ ������ �߰�
			}
			else										// SingerList�� �߰��� ������ ���� ���
			{
				album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
				album.AddMusicToAlbum(simple);											// album�� ���� �߰�
				singer.AddMusicToSinger(album);											// singer�� album �߰�
				SingerList.Add(singer);													// SingerList�� singer �߰�
			}
		}



		// EntList�� �߰�
		if (EntList.GetLength() == 0)					// EntList�� ���Ұ� ���� ���
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// �߰��� ent ����
			singer.SetSinger(music.GetSinger());										// �߰��� singer ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
			album.AddMusicToAlbum(simple);												// album�� ������ ���� �߰�
			singer.AddMusicToSinger(album);												// singer�� album �߰�
			ent.AddMusicToEnt(singer);													// ent�� singer �߰�
			EntList.Add(ent);															// EntList�� ent �߰�
		}
		else											// EntList�� ���Ұ� ���� ���
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// �߰��� ent ����
			singer.SetSinger(music.GetSinger());										// �߰��� singer ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
			if (EntList.Get(ent))						// EntList�� �߰��� �Ҽӻ簡 ���� ���
			{
				ent.AddMusicToEnt(singer, album);										// ent�� singer�� album�� ���� �߰�
				EntList.Delete(ent);													// EntList���� ent ����
				EntList.Add(ent);														// EntList�� ���ŵ� ent �߰�
			}
			else										// EntList�� �߰��� �Ҽӻ簡 ���� ���
			{
				album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
				album.AddMusicToAlbum(simple);											// album�� ������ ���� �߰�
				singer.AddMusicToSinger(album);											// singer�� album �߰�
				ent.AddMusicToEnt(singer);												// ent�� singer �߰�
				EntList.Add(ent);														// EntList�� ent �߰�
			}
		}
		system("cls");
		cout << "\n\t���� �Է��� �׸����� �����͸���Ʈ�� ���ŵǾ����ϴ�." << endl;
	}
}

// �����͸���Ʈ ��������
int Application::LoadMasterList_Admin()
{
	int index = 0;
	MusicType music;

	char filename[FILENAMESIZE];
	cout << "\n\t�ҷ��� ���ϸ��� �Է��ϼ��� : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_InFile.eof())
	{
		music.ReadDataFromFile(m_InFile);
		MasterList.Add(music);
	

		// AlbumList�� �߰�
		if (AlbumList.GetLength() == 0)					// AlbumList�� ������� �� 
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
			album.SetNumberofsonginalbumIncrease();										// �ٹ� ���ϰ� �� 1 ����
			simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum ����
			album.AddMusicToAlbum(simple);												// album�� �߰�
			AlbumList.Add(album);														// album�� AlbumList�� �߰�
		}
		else											// AlbumList�� ���Ұ� ������ ��	
		{
			AlbumType album;
			SimpleTypeForAlbum simple;
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
			simple.SetRecord(music.GetId(), music.GetName());

			AlbumType temp;																// AlbumType �ӽú���
			int test = 0;
			while (AlbumList.GetNextItem(temp) != -1)									// AlbumList ������ �˻�
			{
				if (temp.GetAlbumname() == album.GetAlbumname())	// �߰��� �ٹ����� AlbumList�� ������ ���
				{
					temp.AddMusicToAlbum(simple);										// �ش� �ٹ��� �߰�
					temp.SetNumberofsonginalbumIncrease();
					AlbumList.Replace(temp);											// AlbumList�� ����
					test++;
					break;
				}
			}
			if (test == 0)								// �߰��� �ٹ����� AlbumList�� ���� ���
			{
				album.AddMusicToAlbum(simple);											// ���ο� album�� �߰�
				album.SetNumberofsonginalbumIncrease();									// �ش� �ٹ� ���ϰ�� 1 ����
				AlbumList.Add(album);													// AlbumList�� �ش� �ٹ� �߰�
				/*temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
				temp.SetNumberofsonginalbumIncrease();
				temp.AddMusicToAlbum(simple);
				AlbumList.Add(temp);*/
			}
		}


		// GenreList�� �߰�
		if (GenreList.GetLength() == 0)					// GenreList�� ������� ��
		{
			GenreType genre;
			SongType song;
			genre.SetGenre(music.GetGenre());											// �߰��� genre ����
			song.SetId(music.GetId());													// �߰��� ���� Id�� ����
			song.SetName(music.GetName());												// �߰��� ���� ����� ����
			genre.AddMusicInGenre(song);												// genre�� ���� ���� �߰�
			GenreList.Add(genre);														// GenreList�� �ش� genre�� �߰�
		}
		else											// GenreList�� ���Ұ� ���� ��
		{
			GenreType genre;
			SongType song;

			genre.SetGenre(music.GetGenre());											// �߰��� genre ����
			song.SetId(music.GetId());													// �߰��� ���� id ����
			song.SetName(music.GetName());												// �߰��� ���� ��� ����

			GenreType temp;
			int test = 0;
			while (GenreList.GetNextItem(temp) != -1)									// GenreList ������ �˻�
			{
				if (temp.GetGenre() == music.GetGenre())	// GenreList�� �˻��� ���� �帣�� ������ ���
				{
					temp.AddMusicInGenre(song);											// �ش� �帣�� �� �߰�
					GenreList.Replace(temp);											// GenreList�� ����
					test++;
					break;
				}
			}
			if (test == 0)								// GenreList�� �˻��� ���� �帣�� ���� ���
			{
				genre.AddMusicInGenre(song);											// ���ο� �帣�� �߰�
				GenreList.Add(genre);													// GenreList�� �߰�
			}
		}


		// SingerList�� �߰�
		if (SingerList.GetLength() == 0)				// SingerList�� ���Ұ� ���� ���
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
			album.SetNumberofsonginalbumIncrease();										// album ���ϰ�� 1 ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
			album.AddMusicToAlbum(simple);												// album�� ���� �߰�
			singer.AddMusicToSinger(album);												// singer�� album �߰�
			SingerList.Add(singer);														// SingerList�� singer �߰�
		}
		else											// SingerList�� ���Ұ� ���� ���
		{
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;
			singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
			if (SingerList.Get(singer))					// SingerList�� �߰��� ������ ������ ���
			{
				singer.AddMusicToSinger(album, simple);									// ������ album�� ������ ������ �߰�
				SingerList.Delete(singer);												// SingerList���� �ش� ������ ����
				SingerList.Add(singer);													// SingerList�� ���ŵ� ������ ������ �߰�
			}
			else										// SingerList�� �߰��� ������ ���� ���
			{
				album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
				album.AddMusicToAlbum(simple);											// album�� ���� �߰�
				singer.AddMusicToSinger(album);											// singer�� album �߰�
				SingerList.Add(singer);													// SingerList�� singer �߰�
			}
		}



		// EntList�� �߰�
		if (EntList.GetLength() == 0)					// EntList�� ���Ұ� ���� ���
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// �߰��� ent ����
			singer.SetSinger(music.GetSinger());										// �߰��� singer ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
			album.AddMusicToAlbum(simple);												// album�� ������ ���� �߰�
			singer.AddMusicToSinger(album);												// singer�� album �߰�
			ent.AddMusicToEnt(singer);													// ent�� singer �߰�
			EntList.Add(ent);															// EntList�� ent �߰�
		}
		else											// EntList�� ���Ұ� ���� ���
		{
			EntType ent;
			SingerType singer;
			AlbumType album;
			SimpleTypeForAlbum simple;

			ent.SetEnt(music.GetEnt());													// �߰��� ent ����
			singer.SetSinger(music.GetSinger());										// �߰��� singer ����
			album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
			simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
			if (EntList.Get(ent))						// EntList�� �߰��� �Ҽӻ簡 ���� ���
			{
				ent.AddMusicToEnt(singer, album);										// ent�� singer�� album�� ���� �߰�
				EntList.Delete(ent);													// EntList���� ent ����
				EntList.Add(ent);														// EntList�� ���ŵ� ent �߰�
			}
			else										// EntList�� �߰��� �Ҽӻ簡 ���� ���
			{
				album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
				album.AddMusicToAlbum(simple);											// album�� ������ ���� �߰�
				singer.AddMusicToSinger(album);											// singer�� album �߰�
				ent.AddMusicToEnt(singer);												// ent�� singer �߰�
				EntList.Add(ent);														// EntList�� ent �߰�
			}
		}
	}

	m_InFile.close();

	cout << "\n\t" << filename << "������ ��� ���� ����" << endl;
	DisplayAllMusic_Admin();

	return 1;	
}

// �����͸���Ʈ�� ��� �������� ���
void Application::DisplayAllMusic_Admin()
{
	MusicType data;
	cout << "\n\t �� ��ü �� ���� �� " << endl;
	MasterList.ResetList();
	if (MasterList.GetLength() == 0)
	{
		system("cls");
		cout << "\n\t�����͸���Ʈ�� ���������� �������� �ʽ��ϴ�." << endl;
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
//	cout << "\n\t�����͸���Ʈ�� �����մϴ�." << endl;
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


// ����� ���� ��� ó�� �߰��� � ���°� �����ؾߵ�


//
// ����ڸ���Ʈ�� �׸� �߰�
int Application::AddMusic_User()
{
	cout << "\n\t����� ���Ǹ�Ͽ� �߰��� ����� �Է��ϼ���." << endl;
	SongType song;
	song.SetNameFromKB();
	MusicType music;
	cout << endl;
	int check = 0;

	MasterList.ResetList();
	cout << "\n\t" << song.GetName() << "��(��) ������� ���� ������" << endl << endl;
	while (MasterList.GetNextItem(music) != -1)			// MasterList���� ������ �˻�
	{
		if (music.GetName() == song.GetName())			// �Է��� ����� MasterList�� ������ ��
		{
			music.DisplayIdOnScreen();
			music.DisplayNameOnScreen();
			cout << endl;
			check++;									// check 1 ����
		}
	}


	if (check == 1)
	{
		MusicType item;
		item.SetName(song.GetName());				// item�� ��� song�� ����� ����

		MasterList.ResetList();
		while (MasterList.GetNextItem(music) != -1) // MasterList���� ������ �˻�
		{
			if (music.GetName() == song.GetName())	// MasterList���� �߰��� ���� ��ġ�ϴ� ���� ���� ��
			{
				SongType song2;
				song2.SetName(music.GetName());
				song2.SetId(music.GetId());
				SongList.Add(song2);				// �ش� ���� ����ڸ���Ʈ�� �߰�
				RecentlyList.EnQueue(song2);
				break;
			}
		}
	}
	else if (check > 1)								// �Է��� ���� ���� ���� ���� �� ������ ��
	{
		cout << "\n\t���� ����� ������ ���� �ֽ��ϴ�. �߰��� ���� ������ȣ�� �Է��ϼ���" << endl;
		MusicType music2;
		music2.SetIdFromKB();						// ������ȣ �񱳸� ���� ���ϴ� ���� �Է�
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
		cout << "\n\t�߰��� ���� MasterList�� �������� �ʽ��ϴ�." << endl;
	}
	DisplayAllMusic_User();

	return 1;
}


// ����ڸ���Ʈ���� �׸� ����
void Application::DeleteMusic_User()
{
	cout << "\n\t����� ���Ǹ�Ͽ��� ������ ����� �Է��ϼ���." << endl;
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
		cout << "\n\t"<<song.GetName()<<"�� ������� ���� ������" << endl;
		while (SongList.GetNextItem(temp) != -1)
		{
			if (temp.GetName() == song.GetName())
			{
				temp.DisplayRecordOnScreen();
			}
		}
		cout << "\n\t������ ������ ������ȣ�� �Է��ϼ���." << endl;
		song.SetIdFromKB();
		if (SongList.Delete(song))
		{
			system("cls");
			cout << "\n\t" << song.GetName() << " ������ ������ �Ϸ�Ǿ����ϴ�." << endl;
		}
		else
		{
			system("cls");
			cout << "\n\t������ ������ ������ �������� �ʽ��ϴ�." << endl;
		}
	}
	else
	{
		system("cls");
		cout << "\n\t������ ������ ������ �������� �ʽ��ϴ�." << endl;
	}

	DisplayAllMusic_User();
}


// ����ڸ���Ʈ�� ��� �� ���� ���
void Application::DisplayAllMusic_User()
{
	cout << "\n\t �� ����ڸ���Ʈ ���Ǹ�� �� " << endl << endl;
	SongType song;
	SongList.ResetList();
	if (SongList.GetLength() == 0)
	{
		cout << "\n\t ����� ������Ͽ� ������ �����ϴ�." << endl;
	}
	while (SongList.GetNextItem(song) != -1)
	{
		song.DisplayRecordOnScreen();
		cout << endl;
	}
}

// �ֱ� �߰��� ����� ������Ͽ��� �˻�
void Application::SearchByRecentlyMusic_User()
{
	SongType song;
	RecentlyList.ResetCurPointer();
	cout << "\n\t�� ����ڸ���Ʈ ���Ǹ�� ��" << endl;
	while (RecentlyList.GetNextItem(song) != -1)
	{
		song.DisplayRecordOnScreen();
		cout << endl;
	}
	if (!RecentlyList.IsEmpty())
	{
		cout << "\n\t�˻��� ������ ������ȣ�� �Է��ϼ��� : ";
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

// ����ڸ���Ʈ���� ������ȣ�� �˻�
void Application::SearchById_User()
{
	SongType song;
	cout << "\n\t�˻��� ������ ������ȣ�� �Է��ϼ���." << endl;
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
		cout << "\n\t������ȣ " << song.GetId() << "�� �ش��ϴ� ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	}
}

// ����ڸ���Ʈ���� ������� �˻�
void Application::SearchByName_User()
{
	cout << "\n\t�˻��� ������ ������ �Է��ϼ���." << endl;
	SongType song;
	song.SetNameFromKB();
	int check = 0;
	int check1 = 0;

	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList�� ���� �ƴϰ� �˻��� name�� SongList���� �� ã���� ��
	{
		if (song.GetName() == item.GetName())										// �˻��� name�� SontList���� ã���� ��
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList�� ���� �ƴϰ� �˻��� name�� MasterList���� �� ã���� ��
			{
				if (song.GetName() == music.GetName())								// �˻��� name�� MasterList���� ã���� ��
				{
					check1++;
					music.DisplayRecordOnScreen();									// �ش� ���� ��� ������ ���
				}
			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// �˻��� name�� SongList�� �������� ���� ���
		cout << "\n\t" << song.GetName() << " ��(��) �������� ������ ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	/*SongType song;
	cout << "\n\t�˻��� ������ ������ �Է��ϼ���." << endl;
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
			cout << "\t����� ���� ����Դϴ�." << endl;
			SongList.ResetList();
			while (SongList.GetNextItem(temp) != -1)
			{
				if (temp.GetName() == song.GetName())
				{
					temp.DisplayRecordOnScreen();
				}
			}
		}
		cout << "\n\t�˻��� ������ ������ȣ�� �Է��ϼ���." << endl;
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
				cout << "\n\t" << song.GetName() << "��(��) �������� ������ ���� �� " << search.GetId() << "�� ������ȣ�� ���� ������ �������� �ʽ��ϴ�." << endl;
			}
		}
	
	}
	if (!test)
		cout << "\n\t" << song.GetName() << "��(��) �������� ������ ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;*/
}

// ����ڸ���Ʈ���� ���������� �˻�
void Application::SearchBySinger_User()
{
	SingerType singer;
	cout << "\n\t�˻��� �������� �Է��ϼ���." << endl;
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


	while (SingerList.GetNextItem(singeritem) != -1 && (check == 0))						// SingerList�� ���� �ƴϰ� SingerList���� ã�� ������ ��
	{
		if (singer.GetSinger() == singeritem.GetSinger())									// SingerList���� �ش� ������ ã����
		{
			cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
			singeritem.DisplayAlbumnameOnScreen();											// �ش� ������ ��� �ٹ� ���
			cout << "\n\t" << singer.GetSinger() << "�� �ٹ���Ͽ��� �˻��� �ٹ��� �����ϼ���." << endl;
			album.SetAlbumnameFromKB();														// �˻��� �ٹ��� �Է�
			while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))					// AlbumList�� ���� �ƴϰ� AlbumList���� ã�� ������ ��
			{
				cout << endl;
				if (album.GetAlbumname() == albumitem.GetAlbumname())						// AlbumList���� �ش� �ٹ��� ã����
				{
					albumitem.DisplayRecordOnScreen();										// �ش� �ٹ��� ������ ���
					albumitem.DisplayAlbumListOnScreen();									// �ش� �ٹ��� ���ϰ��� ���
					cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
					song.SetNameFromKB();													// �˻��� ��� �Է�
					while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))			// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
					{
						if (song.GetName() == songitem.GetName())							// SongList���� �ش� ���� ã����
						{
							while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
							{
								if (song.GetName() == musicitem.GetName())					// MasterList���� �ش� ���� ã���� 
								{
									check3++;
									musicitem.DisplayRecordOnScreen();						// �ش� ���� ��� ���� ���
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
		cout << "\n\t" << singer.GetSinger() << "�� ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	else if (check!=0&&check1 == 0)
		cout << "\n\t" << album.GetAlbumname() << "�ٹ��� ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	if (check != 0 && check1 != 0 && check2 == 0)
		cout << "\n\t" << song.GetName() << " ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	else if (check != 0 && check1 != 0 && check2 != 0 && check3 == 0)
		cout << "\n\t" << song.GetName() << " ��(��)" << album.GetAlbumname() << " �ٹ��� ���ϰ��� �ƴմϴ�." << endl;
}

// ����ڸ���Ʈ���� �帣�� �˻�
void Application::SearchByGenre_User()
{
	cout << "\n\t�˻��� ���� �帣�� �Է��ϼ���." << endl;
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

	while (GenreList.GetNextItem(genreitem) != -1 && (check == 0))							// GenreList�� ���� �ƴϰ� GenreList���� ã�� ������ ��
	{
		if (genre.GetGenre() == genreitem.GetGenre())										// GenreList���� �ش� �帣�� ã����
		{
			cout << "\n\t" << genre.GetGenre() << "�帣���� ���� ����� �ֽ��ϴ�." << endl;
			genreitem.DisplaySongOnScreen();												// �ش� �帣�� ��� �� ���
			cout << "\n\t" << genre.GetGenre() << "�� �帣�߿��� �˻��� ���� ������ȣ�� �����ϼ���." << endl;
			song.SetIdFromKB();																// �˻��� ������ȣ �Է�
			cout << endl;
			SongList.ResetList();
			while (SongList.GetNextItem(songitem) != -1&&(check1==0))
			{
				if (song.GetId() == songitem.GetId())
				{
					check1++;
					song.SetName(songitem.GetName());
					while (MasterList.GetNextItem(musicitem) != -1 && (check2 == 0))				// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
					{
						if (song.GetId() == musicitem.GetId())										// MasterList���� �ش� ������ȣ�� ã����
						{
							check2++;
							musicitem.DisplayRecordOnScreen();										// �ش� ���� ��� ���� ���
						}
					}
				}
			}
			check++;
		}
	}
	
	if (check == 0)
		cout << "\n\t" << genre.GetGenre() << "�帣�� ������ �������� �ʽ��ϴ�." << endl;
	else if (check != 0 && check1 == 0)																			// �˻��� �帣�� GenreList�� �������� ���� ��
		cout << "\n\t" << genre.GetGenre() << "�帣 �� " << song.GetId() << "��(��) ������ȣ�� ���� ������ ����� ������Ͽ� �������� �ʽ��ϴ�. " << endl;
}

// ����ڸ���Ʈ���� �ٹ������� �˻�
void Application::SearchByAlbumName_User()
{
	AlbumType albumitem;
	AlbumType album;
	cout << "\n\t�˻��� �ٹ����� �Է��ϼ���." << endl;
	album.SetAlbumnameFromKB();
	MusicType musicitem;
	MusicType music;
	SongType songitem;
	SongType song;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;

	if (AlbumList.Get(album))											// AlbumList���� �ش� �ٹ����� ������ ��
	{
		check1++;
		cout << "\n\t" << album.GetAlbumname() << "�ٹ��� ������ ������ �����ϴ�." << endl;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(albumitem) != -1)					// AlbumList�� ���� �ƴ� ��
		{
			if (album.GetAlbumname() == albumitem.GetAlbumname())		// AlbumList���� �ش� �ٹ����� ã����
			{
				albumitem.DisplayRecordOnScreen();						// �ش� �ٹ��� ���� ���
				albumitem.DisplayAlbumListOnScreen();					// �ش� �ٹ��� ���ϰ� ���
				cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ������ ������ȣ�� �Է��ϼ���." << endl;
				song.SetIdFromKB();									// �˻��� ���� ������ȣ �Է�

				SongList.ResetList();
				while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))		// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
				{
					if (SongList.Get(song))											// SongList�� �ش� ������ �����ϸ�
					{
						MasterList.ResetList();
						while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
						{

							if (song.GetId() == musicitem.GetId())				// MasterList���� �˻��� ����� ã����
							{
								check3++;
								musicitem.DisplayRecordOnScreen();					// �ش� ���� ��� ���� ���
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
		cout << "\n\t" << album.GetAlbumname() << " �ٹ��� ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	}
	else if (check1 != 0 && check2 == 0)
	{
		cout << "\n\t" << album.GetAlbumname() << " �ٹ����� �˻��� ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	}
	/*else if (check1 != 0 && check2 != 0 && check3 == 0)
		cout << "\n\t" << song.GetName() << " ��(��)" << album.GetAlbumname() << " �ٹ��� ���ϰ��� �ƴմϴ�." << endl;*/
}

// ����ڸ���Ʈ���� �Ҽӻ������ �˻�
void Application::SearchByEnt_User()
{
	{
		// ����ڸ���Ʈ���� �Ҽӻ������ �˻�
		EntType ent;
		EntType entitem;
		cout << "\n\t�˻��� �Ҽӻ縦 �Է��ϼ���." << endl;
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
		while (EntList.GetNextItem(entitem) != -1)									// EntList�� ���� �ƴ� ��
		{
			if (ent.GetEnt() == entitem.GetEnt())									// EntList���� �˻��� �Ҽӻ縦 ã����
			{
				cout << "\n\t" << ent.GetEnt() << "�� �Ҽ� ������ ������ �����ϴ�." << endl;
				entitem.DisplayEntListOnScreen();									// �ش� �Ҽӻ��� ��� ���� ���
				cout << "\n\t" << ent.GetEnt() << "�� �Ҽ� ������ �˻��� ������ �����ϼ���." << endl;
				singer.SetSingerFromKB();											// �˻��� �����Է�
				SingerList.ResetList();
				while (SingerList.GetNextItem(singeritem) != -1 && (check1 == 0))		// SingerList�� ���� �ƴϰ� SingerList���� ã�� ������ ��
				{
					if (singer.GetSinger() == singeritem.GetSinger())				// SingerList���� �˻��� ������ ã����
					{
						cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
						singeritem.DisplayAlbumnameOnScreen();						// �ش� ������ ��� �ٹ� ���
						cout << "\n\t" << singer.GetSinger() << "�� �ٹ���Ͽ��� �˻��� �ٹ��� �����ϼ���." << endl;
						album.SetAlbumnameFromKB();									// �˻��� �ٹ��� �Է�
						AlbumList.ResetList();
						while (AlbumList.GetNextItem(albumitem) != -1 && (check2 == 0))	// AlbumList�� ���� �ƴϰ� AlbumList���� ã�� ������ ��
						{
							cout << endl;
							if (album.GetAlbumname() == albumitem.GetAlbumname())	// AlbumList���� �˻��� �ٹ��� ã����
							{
								albumitem.DisplayRecordOnScreen();					// �ش� �ٹ��� ���� ���
								albumitem.DisplayAlbumListOnScreen();				// �ش� �ٹ��� ���ϰ� ���
								cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
								song.SetNameFromKB();								// �˻��� ��� �Է�
								while (SongList.GetNextItem(songitem) != -1 && (check3 == 0))	// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
								{
									if (song.GetName() == songitem.GetName())		// SongList���� �˻��� ���� ã����
									{
										MasterList.ResetList();
										while (MasterList.GetNextItem(musicitem) != -1 && (check4 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
										{
											if (song.GetName() == musicitem.GetName())	// MasterList���� �˻��� ���� ã����
											{
												check4++;
												musicitem.DisplayRecordOnScreen();		// �ش� ���� ��� ���� ���
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
			cout << "\n\t" << ent.GetEnt() << " �Ҽӻ��� ������ �����ϴ�." << endl;
		/*else if (check != 0 && check1 == 0)
			cout << "\n\t" << singer.GetSinger() << " ��(��) "<<ent.GetEnt()<<"�Ҽӻ��� ������ �ƴմϴ�." << endl;
		else if (check != 0 && check1 != 0 && check2 == 0)
			cout << "\n\t" << album.GetAlbumname() << " �ٹ��� " << singer.GetSinger() << " ��(��) �۾��� �ٹ��� �ƴմϴ�." << endl;*/
		else if (check != 0 && check1 != 0 && check2 != 0 && check3 == 0)
			cout << "\n\t" << song.GetName() << " ������ ����� ������Ͽ� �������� �ʽ��ϴ�." << endl;
	}
}

//// ����� ������Ͽ��� ���
//void Application::PlayMusic_User()
//{
//	cout << "\n\t�� ����� ������� ��" << endl;
//	PlaySongType playsong;
//	PlayList.ResetList();
//	while (PlayList.GetNextItem(playsong) != -1)
//	{
//		playsong.DisplayRecordOnScreen();
//		cout << endl;
//	}
//
//	cout << "\n\t����� ������Ͽ��� ����� ����� �Է��ϼ���." << endl;
//	string name;
//	cout << "\t��� : ";
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
//			// ���� ����
//			  // MCI_OPEN_PARAMS ����ü ���� mc
//
//			mciOpen.lpstrDeviceType = TEXT("mpegvideo");  // mpegvideo : mp3, waveaudio : wav, avivideo : avi
//			mciOpen.lpstrElementName = TEXT(songname); // �����̸�
//
//			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);
//			//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);
//
//			// ���
//			dwID = mciOpen.wDeviceID;
//			MCI_PLAY_PARMS m_mciPlayParms;
//
//			mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
//
//			// int �� �Է½� ���� �� �ʱ�ȭ�� ����
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
//		cout << "\n\n\t�ش������� �����ϴ�" << endl;
//	}
//}

// ����� ��������� ����� ID�� ���ϸ����� ����
int Application::Save_User()
{
	SongType song;
	char filename[FILENAMESIZE];

	cout << "\n\t����� ��������� �����մϴ�." << endl;
	cout << "\n\t�α����� ID�� �Է��ϼ��� : ";
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

// ����� ID�� ���ϸ��� ����� ����������� ������
int Application::Read_User(char id)
{
	SongType song;

	cout << "\n\t����� ��������� �ҷ��ɴϴ�." << endl;

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

	//// ���� �� �����϶� �ҷ����� ��� ���� �����ϴ°� �����ؾߵ�
	//while (!m_InFile.eof())
	//{
	//	if (data!=" ")
	//	{
	//		cout << "\n\t�ҷ��� ������ ����� ������Ͽ� �����մϴ�." << endl;
	//		song.ReadDataFromFile(m_InFile);
	//		SongList.Add(song);
	//	}
	//	else if (data==" ")
	//	{
	//		cout << "\n\t�ҷ��� ������ ����ֽ��ϴ�. �ش� ������ �����մϴ�.";
	//		remove(erase);
	//		break;
	//	}
	//}

	m_InFile.close();
	DisplayAllMusic_User();
}


// �ҷ��� filename�� �����ϸ� ���� 1 ����, �ƴϸ� 0 ����
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	//�ҷ��� fileName�� �ش��ϴ� file�� ����
	if (m_InFile)	//���µ� �����ϸ�
		return 1;
	else
		return 0;
}

int Application::OpenOutFile(char * fileName)
{
	m_OutFile.open(fileName);	//������ fileName�� �ش��ϴ� file�� ����.
	if (m_OutFile)	//���µ� �����ϸ�
		return 1;
	else
		return 0;
}

/*
// ����� ����Ʈ�� �׸� �߰�
int Application::AddMusic_User()
{
	cout << "\n\t����� ���� ���Ǹ�Ͽ� �߰��� ���� ������ �Է��ϼ���\n";
	SongType song;
	song.SetNameFromKB();			// �߰��� ���� ����
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
	int check = 0;									// �߰��� ���� ���� ���� MasterList�� �� ���� �����ϴ��� Ȯ��

	while (MasterList.GetNextItem(music) != -1)		// MasterList���� ������ �˻�
		if (song.GetName() == music.GetName())		// �Է��� ����� MasterList�� ������ ��
			check++;								// check 1 ����

	// SongList�� �߰�
	if (check == 1)
	{
		MusicType item;
		item.SetName(song.GetName());				// item�� ��� song�� ����� ����
		MasterList.ResetList();
		while (MasterList.GetNextItem(music) != -1) // MasterList���� ������ �˻�
		{
			if (music.GetName() == song.GetName())	// MasterList���� �߰��� ���� ��ġ�ϴ� ���� ���� ��
			{
				SongType song2;
				song2.SetName(music.GetName());
				song2.SetId(music.GetId());
				SongList.Add(song2);				// �ش� ���� ����ڸ���Ʈ�� �߰�
				break;
			}
		}
	}
	else if (check > 1)								// �Է��� ���� ���� ���� ���� �� ������ ��
	{
		cout << "\n\t���� ����� ������ ���� �ֽ��ϴ�. �߰��� ���� ������ȣ�� �Է��ϼ���" << endl;
		MusicType music;
		music.SetIdFromKB();						// ������ȣ �񱳸� ���� ���ϴ� ���� �Է�
		MasterList.RetrieveMusic_Binary(music);
		SongType song2;
		song2.SetId(music.GetId());
		song2.SetName(music.GetName());
		SongList.Add(song2);
	}
	else 
	{
		cout << "\n\t�߰��� ���� MasterList�� �������� �ʽ��ϴ�." << endl;
	}


	// AlbumList�� �߰�
	if (AlbumList.GetLength() == 0)					// AlbumList�� ������� �� 
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
		album.SetNumberofsonginalbumIncrease();										// �ٹ� ���ϰ� �� 1 ����
		simple.SetRecord(music.GetId(), music.GetName());							// SimpleTypeForAlbum ����
		album.AddMusicToAlbum(simple);												// album�� �߰�
		AlbumList.Add(album);														// album�� AlbumList�� �߰�
	}
	else											// AlbumList�� ���Ұ� ������ ��	
	{
		AlbumType album;
		SimpleTypeForAlbum simple;
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� AlbumType ����
		simple.SetRecord(music.GetId(), music.GetName());

		AlbumType temp;																// AlbumType �ӽú���
		int test = 0;
		while (AlbumList.GetNextItem(temp) != -1)									// AlbumList ������ �˻�
		{
			if (temp.GetAlbumname() == album.GetAlbumname())	// �߰��� �ٹ����� AlbumList�� ������ ���
			{
				temp.AddMusicToAlbum(simple);										// �ش� �ٹ��� �߰�
				temp.SetNumberofsonginalbumIncrease();
				AlbumList.Replace(temp);											// AlbumList�� ����
				test++;
				break;
			}
		}
		if (test == 0)								// �߰��� �ٹ����� AlbumList�� ���� ���
		{
			album.AddMusicToAlbum(simple);											// ���ο� album�� �߰�
			album.SetNumberofsonginalbumIncrease();									// �ش� �ٹ� ���ϰ�� 1 ����
			AlbumList.Add(album);													// AlbumList�� �ش� �ٹ� �߰�
			//temp.SetRecord(music.GetAlbumname(), music.GetName(), music.GetEnt());
			//temp.SetNumberofsonginalbumIncrease();
			//temp.AddMusicToAlbum(simple);
			//AlbumList.Add(temp);
		}
	}
	

	// GenreList�� �߰�
	if (GenreList.GetLength() == 0)					// GenreList�� ������� ��
	{
		GenreType genre;
		SongType song;
		genre.SetGenre(music.GetGenre());											// �߰��� genre ����
		song.SetId(music.GetId());													// �߰��� ���� Id�� ����
		song.SetName(music.GetName());												// �߰��� ���� ����� ����
		genre.AddMusicInGenre(song);												// genre�� ���� ���� �߰�
		GenreList.Add(genre);														// GenreList�� �ش� genre�� �߰�
	}
	else											// GenreList�� ���Ұ� ���� ��
	{
		GenreType genre;
		SongType song;

		genre.SetGenre(music.GetGenre());											// �߰��� genre ����
		song.SetId(music.GetId());													// �߰��� ���� id ����
		song.SetName(music.GetName());												// �߰��� ���� ��� ����

		GenreType temp;
		int test = 0;
		while (GenreList.GetNextItem(temp) != -1)									// GenreList ������ �˻�
		{
			if (temp.GetGenre() == music.GetGenre())	// GenreList�� �˻��� ���� �帣�� ������ ���
			{
				temp.AddMusicInGenre(song);											// �ش� �帣�� �� �߰�
				GenreList.Replace(temp);											// GenreList�� ����
				test++;
				break;
			}
		}
		if (test == 0)								// GenreList�� �˻��� ���� �帣�� ���� ���
		{
			genre.AddMusicInGenre(song);											// ���ο� �帣�� �߰�
			GenreList.Add(genre);													// GenreList�� �߰�
		}
	}
	

	// SingerList�� �߰�
	if (SingerList.GetLength() == 0)				// SingerList�� ���Ұ� ���� ���
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
		album.SetNumberofsonginalbumIncrease();										// album ���ϰ�� 1 ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
		album.AddMusicToAlbum(simple);												// album�� ���� �߰�
		singer.AddMusicToSinger(album);												// singer�� album �߰�
		SingerList.Add(singer);														// SingerList�� singer �߰�
	}
	else											// SingerList�� ���Ұ� ���� ���
	{
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;
		singer.SetSinger(music.GetSinger());										// �߰��� �����̸� ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� ����� ������ ���� ����
		if (SingerList.Get(singer))					// SingerList�� �߰��� ������ ������ ���
		{
			singer.AddMusicToSinger(album, simple);									// ������ album�� ������ ������ �߰�
			SingerList.Delete(singer);												// SingerList���� �ش� ������ ����
			SingerList.Add(singer);													// SingerList�� ���ŵ� ������ ������ �߰�
		}
		else										// SingerList�� �߰��� ������ ���� ���
		{
			album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
			album.AddMusicToAlbum(simple);											// album�� ���� �߰�
			singer.AddMusicToSinger(album);											// singer�� album �߰�
			SingerList.Add(singer);													// SingerList�� singer �߰�
		}
	}

	

	// EntList�� �߰�
	if (EntList.GetLength() == 0)					// EntList�� ���Ұ� ���� ���
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// �߰��� ent ����
		singer.SetSinger(music.GetSinger());										// �߰��� singer ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
		album.AddMusicToAlbum(simple);												// album�� ������ ���� �߰�
		singer.AddMusicToSinger(album);												// singer�� album �߰�
		ent.AddMusicToEnt(singer);													// ent�� singer �߰�
		EntList.Add(ent);															// EntList�� ent �߰�
	}
	else											// EntList�� ���Ұ� ���� ���
	{
		EntType ent;
		SingerType singer;
		AlbumType album;
		SimpleTypeForAlbum simple;

		ent.SetEnt(music.GetEnt());													// �߰��� ent ����
		singer.SetSinger(music.GetSinger());										// �߰��� singer ����
		album.SetRecord(music.GetAlbumname(), music.GetSinger(), music.GetEnt());	// �߰��� album ����
		simple.SetRecord(music.GetId(), music.GetName());							// album�� �߰��� ������ ���� �߰�
		if (EntList.Get(ent))						// EntList�� �߰��� �Ҽӻ簡 ���� ���
		{
			ent.AddMusicToEnt(singer, album);										// ent�� singer�� album�� ���� �߰�
			EntList.Delete(ent);													// EntList���� ent ����
			EntList.Add(ent);														// EntList�� ���ŵ� ent �߰�
		}
		else										// EntList�� �߰��� �Ҽӻ簡 ���� ���
		{
			album.SetNumberofsonginalbumIncrease();									// �ٹ� ���ϰ�� 1 ����
			album.AddMusicToAlbum(simple);											// album�� ������ ���� �߰�
			singer.AddMusicToSinger(album);											// singer�� album �߰�
			ent.AddMusicToEnt(singer);												// ent�� singer �߰�
			EntList.Add(ent);														// EntList�� ent �߰�
		}
	}


	//if (check == 1)									// 1�� ������ ��
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// �Է��� ������� MusicType item�� ��� ����
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList ������ �˻�
	//	{
	//		if (music.GetName() == song.GetName())	// �Է��� ����� MasterList�� �ش� index�� ��� ���� ��
	//		{
	//			SongType songitem;
	//			songitem.SetName(music.GetName());		// SongType item2�� ����� music�� ������� ����
	//			songitem.SetId(music.GetId());			// item2�� ������ȣ�� music�� ������ȣ�� ����
	//			SongList.Add(songitem);					// ����� ���Ǹ���Ʈ SongList�� item2�׸� �߰�

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
	


	if (SongList.GetLength() != 0)					// SongList�� ���Ұ� ������ ���
		DisplayAllMusic_User();						// SongList�� ���� ���

	return 1;







	//cout << "\n\t����� ���� ���Ǹ�Ͽ� �߰��� ���� ������ �Է��ϼ���\n";
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
	//int check = 0;									// �߰��� ���� ���� ���� MasterList�� �� ���� �����ϴ��� Ȯ��

	//while (MasterList.GetNextItem(music) != -1)		// MasterList���� ������ �˻�
	//	if (song.GetName() == music.GetName())		// �Է��� ����� MasterList�� ������ ��
	//		check++;								// check 1 ����

	//if (check == 1)									// 1�� ������ ��
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// �Է��� ������� MusicType item�� ��� ����
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList ������ �˻�
	//	{
	//		if (music.GetName() == song.GetName())	// �Է��� ����� MasterList�� �ش� index�� ��� ���� ��
	//		{
	//			SongType songitem;
	//			songitem.SetName(music.GetName());		// SongType item2�� ����� music�� ������� ����
	//			songitem.SetId(music.GetId());			// item2�� ������ȣ�� music�� ������ȣ�� ����
	//			SongList.Add(songitem);					// ����� ���Ǹ���Ʈ SongList�� item2�׸� �߰�

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
	//else if (check > 1)								// �Է��� ���� ���� ���� ���� �� ������ ��
	//{
	//	cout << "\n\t���� ����� ������ ���� �ֽ��ϴ�. �߰��� ���� ������ȣ�� �Է��ϼ���" << endl;
	//	MusicType music;
	//	music.SetIdFromKB();						// ������ȣ �񱳸� ���� ���ϴ� ����
	//	MasterList.RetrieveMusic_Binary(music);
	//	SongType song2;
	//	song2.SetId(music.GetId());
	//	song2.SetName(music.GetName());
	//	SongList.Add(song2);
	//}
	//else {
	//	cout << "\t�߰��� ���� �����ϴ�" << endl;
	//}
	//R_DisplayAllMusic();

	//return 1;





	//cout << "\n\t����� ���� ���Ǹ�Ͽ� �߰��� ���� ������ �Է��ϼ���\n";
	//SongType song;
	//song.SetNameFromKB();
	//MusicType music;
	//MasterList.ResetList();
	//int check = 0;									// �߰��� ���� ���� ���� MasterList�� �� ���� �����ϴ��� Ȯ��

	//while (MasterList.GetNextItem(music) != -1)		// MasterList���� ������ �˻�
	//	if (song.GetName() == music.GetName())		// �Է��� ����� MasterList�� ������ ��
	//		check++;								// check 1 ����

	//if (check == 1)									// 1�� ������ ��
	//{
	//	MusicType item;
	//	item.SetName(song.GetName());				// �Է��� ������� MusicType item�� ��� ����
	//	MasterList.ResetList();
	//	while (MasterList.GetNextItem(music) != -1) // MasterList ������ �˻�
	//	{
	//		if (music.GetName() == song.GetName())	// �Է��� ����� MasterList�� �ش� index�� ��� ���� ��
	//		{
	//			SongType item2;
	//			item2.SetName(music.GetName());		// SongType item2�� ����� music�� ������� ����
	//			item2.SetId(music.GetId());			// item2�� ������ȣ�� music�� ������ȣ�� ����
	//			SongList.Add(item2);				// ����� ���Ǹ���Ʈ SongList�� item2�׸� �߰�
	//			break;
	//		}
	//	}
	//}
	//else if (check > 1)								// �Է��� ���� ���� ���� ���� �� ������ ��
	//{
	//	cout << "\n\t���� ����� ������ ���� �ֽ��ϴ�. �߰��� ���� ������ȣ�� �Է��ϼ���" << endl;
	//	MusicType music;
	//	music.SetIdFromKB();						// ������ȣ �񱳸� ���� ���ϴ� ����
	//	MasterList.RetrieveMusic_Binary(music);
	//	SongType song2;
	//	song2.SetId(music.GetId());
	//	song2.SetName(music.GetName());
	//	SongList.Add(song2);
	//}
	//else {
	//	cout << "\t�߰��� ���� �����ϴ�" << endl;
	//}
	//R_DisplayAllMusic();

	//return 1;

	//if (check != 0)
	//{
	//	cout << "\n\t�߰��� ���� MasterList�� �����մϴ�. �߰��� ���� ������ȣ�� �Է��ϼ���" << endl;
	//	MusicType music1;
	//	music1.SetIdFromKB();
	//	MasterList.RetrieveMusic_Binary(music1);
	//	SongType song1;
	//	song1.SetId(music1.GetId());
	//	song1.SetName(music1.GetName());
	//	SongList.Add(song1);
	//}
	//else
	//	cout << "\n\t�߰��� ���� ��ġ�ϴ� �׸��� MasterList�� �������� �ʽ��ϴ�." << endl;
	//cout << "\n\t���� SongList�� �׸�" << endl;
	//R_DisplayAllMusic();
}
*/

/*
// ����ڸ���Ʈ���� �׸� ����
void Application::DeleteMusic_User()
{
	cout << "\n\t������ ����� �Է��ϼ���. " << endl;
	SongType song;
	song.SetNameFromKB();
	SongList.ResetList();
	if (SongList.Delete(song))							// ������ ����� SongList�� ������ ���
	{
		cout << "\n\t" << song.GetName() << " ��(��) �����Ǿ����ϴ�." << endl;
	}
	else												// ������ ����� SongList�� �������� ���� ���
		cout << "\n\t" << song.GetName() << " ��(��) ������� ������ ���� �������� �ʽ��ϴ�." << endl;


	DisplayAllMusic_User();								// SongList ��� ���� ���
	

	//
	//cout << "\n\t������ ����� �Է��ϼ���. " << endl;
	//SongType song;
	//song.SetNameFromKB();
	//if (SongList.Delete(song))
	//	cout << "\n\t" << song.GetName() << "��(��) �����Ǿ����ϴ�." << endl;
	//else
	//	cout << "\n\t"<<song.GetName()<<"��(��) ������� ������ ���� �������� �ʽ��ϴ�." << endl;
	//
}
*/

/*
// ����ڸ���Ʈ ��� ���� ���
void Application::DisplayAllMusic_User()
{
	cout << "\n\t�� ����� ���� ���Ǹ�� ��" << endl << endl;
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
// ����ڸ���Ʈ���� Id�� �˻�
void Application::SearchById_User()
{
	cout << "\n\t�˻��� ���� ������ȣ�� �Է��ϼ���." << endl;
	SongType song;
	song.SetIdFromKB();
	int check = 0;
	int check1 = 0;

	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList�� ���� �ƴϰ� �˻��� Id�� SongList���� ã�� ������ ���
	{
		if (song.GetId() == item.GetId())											// �˻��� Id�� SongList�� ������ ���
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList�� ���� �ƴϰ� �˻��� Id�� MasterList���� �� ã���� ��
			{
				if (song.GetId() == music.GetId())									// �˻��� Id�� MasterList�� �����ϸ�
				{
					check1++;
					music.DisplayRecordOnScreen();									// �ش� ���� ��� ���� ���
				}

			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// �˻��� Id�� SongList�� �������� ���� ���
		cout << "\n\t" << song.GetId() << " ��(��) ������ȣ�� ������ ���� ����ڸ���Ʈ�� �����ϴ�." << endl;
}
*/

/*
// ����ڸ���Ʈ���� Name���� �˻�
void Application::SearchByName_User()
{
	cout << "\n\t�˻��� ����� �Է��ϼ���." << endl;
	SongType song;
	song.SetNameFromKB();
	int check = 0;
	int check1 = 0;
	
	SongType item;
	SongList.ResetList();
	MusicType music;
	MasterList.ResetList();
	while ((SongList.GetNextItem(item) != -1) && (check == 0))						// SongList�� ���� �ƴϰ� �˻��� name�� SongList���� �� ã���� ��
	{
		if (song.GetName() == item.GetName())										// �˻��� name�� SontList���� ã���� ��
		{
			while (MasterList.GetNextItem(music) != -1 && (check1 == 0))			// MasterList�� ���� �ƴϰ� �˻��� name�� MasterList���� �� ã���� ��
			{
				if (song.GetName() == music.GetName())								// �˻��� name�� MasterList���� ã���� ��
				{
					check1++;
					music.DisplayRecordOnScreen();									// �ش� ���� ��� ������ ���
				}
			}
			check++;
			cout << endl;
		}
	}
	if (check == 0)																	// �˻��� name�� SongList�� �������� ���� ���
		cout << "\n\t" << song.GetName() << " ��(��) ������� ������ ���� ����ڸ���Ʈ�� �����ϴ�." << endl;
}
*/

/*
// ����ڸ���Ʈ���� ���������� �˻�
void Application::SearchBySinger_User()
{

	cout << "\n\t�˻��� �������� �Է��ϼ���." << endl;
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


	while (SingerList.GetNextItem(singeritem) != -1 && (check == 0))						// SingerList�� ���� �ƴϰ� SingerList���� ã�� ������ ��
	{
		if (singer.GetSinger() == singeritem.GetSinger())									// SingerList���� �ش� ������ ã����
		{
			cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
			singeritem.DisplayAlbumnameOnScreen();											// �ش� ������ ��� �ٹ� ���
			cout << "\n\t" << singer.GetSinger() << "�� �ٹ���Ͽ��� �˻��� �ٹ��� �����ϼ���." << endl;
			album.SetAlbumnameFromKB();														// �˻��� �ٹ��� �Է�
			while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))					// AlbumList�� ���� �ƴϰ� AlbumList���� ã�� ������ ��
			{
				cout << endl;
				if (album.GetAlbumname() == albumitem.GetAlbumname())						// AlbumList���� �ش� �ٹ��� ã����
				{
					albumitem.DisplayRecordOnScreen();										// �ش� �ٹ��� ������ ���
					albumitem.DisplayAlbumListOnScreen();									// �ش� �ٹ��� ���ϰ��� ���
					cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
					song.SetNameFromKB();													// �˻��� ��� �Է�
					while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))			// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
					{
						if (song.GetName() == songitem.GetName())							// SongList���� �ش� ���� ã����
						{
							while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
							{
								if (song.GetName() == musicitem.GetName())					// MasterList���� �ش� ���� ã���� 
								{
									check3++;
									musicitem.DisplayRecordOnScreen();						// �ش� ���� ��� ���� ���
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
	//		cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
	//		singeritem.DisplayAlbumnameOnScreen();
	//		cout << "\n\t" << singer.GetSinger() << "�� �ٹ���Ͽ��� �˻��� �ٹ��� �����ϼ���." << endl;
	//		while (AlbumList.GetNextItem(albumitem) != -1 && (check1 == 0))
	//		{
	//			album.SetAlbumnameFromKB();
	//			cout << endl;
	//			if (album.GetAlbumname() == albumitem.GetAlbumname())
	//			{
	//				albumitem.DisplayRecordOnScreen();
	//				albumitem.DisplayAlbumListOnScreen();
	//				cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
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
// ����ڸ���Ʈ���� �帣�� �˻�
void Application::SearchByGenre_User()
{

	cout << "\n\t�˻��� ���� �帣�� �Է��ϼ���." << endl;
	GenreType genre;
	genre.SetGenreFromKB();
	MusicType music;

	GenreType genreitem;
	GenreList.ResetList();
	MusicType musicitem;
	MasterList.ResetList();
	int check = 0;
	int check1 = 0;

	while (GenreList.GetNextItem(genreitem) != -1 && (check == 0))							// GenreList�� ���� �ƴϰ� GenreList���� ã�� ������ ��
	{
		if (genre.GetGenre() == genreitem.GetGenre())										// GenreList���� �ش� �帣�� ã����
		{
			cout << "\n\t" << genre.GetGenre() << "�帣���� ���� ����� �ֽ��ϴ�." << endl;
			genreitem.DisplaySongOnScreen();												// �ش� �帣�� ��� �� ���
			cout << "\n\t" << genre.GetGenre() << "�� �帣�߿��� �˻��� ���� ������ȣ�� �����ϼ���." << endl;
			music.SetIdFromKB();															// �˻��� ������ȣ �Է�
			cout << endl;
			while (MasterList.GetNextItem(musicitem) != -1 && (check1 == 0))				// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
			{
				if (music.GetId() == musicitem.GetId())										// MasterList���� �ش� ������ȣ�� ã����
				{
					musicitem.DisplayRecordOnScreen();										// �ش� ���� ��� ���� ���
					check1++;
				}
			}
			check++;
		}
	}

	if (check == 0)																			// �˻��� �帣�� GenreList�� �������� ���� ��
		cout << "\n\t" << genre.GetGenre() << "�帣�� ������ȣ " << music.GetId() << "��(��) �������� �ʽ��ϴ�. " << endl;




	//cout << "\n\t�˻��� ���� �帣�� �Է��ϼ���." << endl;
	//GenreType genre;
	//genre.SetGenreFromKB();		
	//MusicType music;
	//int check = 0;

	//if (GenreList.Get(genre))
	//{
	//	cout << "\n\t" << genre.GetGenre() << "���� ������ ����� �ֽ��ϴ�." << endl;
	//	genre.DisplaySongOnScreen();
	//	cout << "\n\t"<<genre.GetGenre()<<"�帣 �߿��� �˻��� ���� ������ȣ�� �Է��ϼ���." << endl;
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
	//		cout << "\n\t" << genre.GetGenre() << "�帣�� ������ȣ " <<music.GetId() << "��(��) �������� �ʽ��ϴ�. "<< endl;
}
*/

/*
// ����ڸ���Ʈ���� �ٹ������� �˻�
void Application::SearchByAlbumName_User()
{
	AlbumType albumitem;
	AlbumType album;
	cout << "\t�˻��� �ٹ����� �Է��ϼ���." << endl;
	album.SetAlbumnameFromKB();
	MusicType musicitem;
	MusicType music;
	SongType songitem;
	SongType song;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;

	if (AlbumList.Get(album))											// AlbumList���� �ش� �ٹ����� ������ ��
	{
		check1++;
		cout << "\n\t" << album.GetAlbumname() << "�ٹ��� ������ ������ �����ϴ�." << endl;
		AlbumList.ResetList();
		while (AlbumList.GetNextItem(albumitem) != -1)					// AlbumList�� ���� �ƴ� ��
		{
			if (album.GetAlbumname() == albumitem.GetAlbumname())		// AlbumList���� �ش� �ٹ����� ã����
			{
				albumitem.DisplayRecordOnScreen();						// �ش� �ٹ��� ���� ���
				albumitem.DisplayAlbumListOnScreen();					// �ش� �ٹ��� ���ϰ� ���
				cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
				song.SetNameFromKB();									// �˻��� ��� �Է�
				
				SongList.ResetList();
				while (SongList.GetNextItem(songitem) != -1 && (check2 == 0))		// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
				{
					if (SongList.Get(song))											// SongList�� �ش� ����� �����ϸ�
					{
						MasterList.ResetList();
						while (MasterList.GetNextItem(musicitem) != -1 && (check3 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
						{
							if (song.GetName() == musicitem.GetName())				// MasterList���� �˻��� ����� ã����
							{
								check3++;
								musicitem.DisplayRecordOnScreen();					// �ش� ���� ��� ���� ���
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
		cout << "\n\t" << album.GetAlbumname() << " �ٹ��� ����ڸ���Ʈ�� �������� �ʽ��ϴ�." << endl;
	}
	else if (check2 == 0)
		cout << "\n\t" << song.GetName() << " ��(��)" << album.GetAlbumname() << " �ٹ��� ���ϰ��� �ƴմϴ�." << endl;
}
*/


/*
// ����ڸ���Ʈ���� �Ҽӻ�� �˻�
void Application::SearchByEnt_User()
{
	EntType ent;
	EntType entitem;
	cout << "\n\t�˻��� �Ҽӻ縦 �Է��ϼ���." << endl;
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
	while (EntList.GetNextItem(entitem) != -1 )									// EntList�� ���� �ƴ� ��
	{
		if (ent.GetEnt() == entitem.GetEnt())									// EntList���� �˻��� �Ҽӻ縦 ã����
		{
			cout << "\n\t" << ent.GetEnt() << "�� �Ҽ� ������ ������ �����ϴ�." << endl;
			entitem.DisplayEntListOnScreen();									// �ش� �Ҽӻ��� ��� ���� ���
			cout << "\n\t" << ent.GetEnt() << "�� �Ҽ� ������ �˻��� ������ �����ϼ���." << endl;
			singer.SetSingerFromKB();											// �˻��� �����Է�
			SingerList.ResetList();
			while (SingerList.GetNextItem(singeritem) != -1&&(check1==0))		// SingerList�� ���� �ƴϰ� SingerList���� ã�� ������ ��
			{
				if (singer.GetSinger() == singeritem.GetSinger())				// SingerList���� �˻��� ������ ã����
				{
					cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
					singeritem.DisplayAlbumnameOnScreen();						// �ش� ������ ��� �ٹ� ���
					cout << "\n\t" << singer.GetSinger() << "�� �ٹ���Ͽ��� �˻��� �ٹ��� �����ϼ���." << endl;
					album.SetAlbumnameFromKB();									// �˻��� �ٹ��� �Է�
					AlbumList.ResetList();
					while (AlbumList.GetNextItem(albumitem) != -1&&(check2==0))	// AlbumList�� ���� �ƴϰ� AlbumList���� ã�� ������ ��
					{
						cout << endl;
						if (album.GetAlbumname() == albumitem.GetAlbumname())	// AlbumList���� �˻��� �ٹ��� ã����
						{
							albumitem.DisplayRecordOnScreen();					// �ش� �ٹ��� ���� ���
							albumitem.DisplayAlbumListOnScreen();				// �ش� �ٹ��� ���ϰ� ���
							cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;
							song.SetNameFromKB();								// �˻��� ��� �Է�
							while (SongList.GetNextItem(songitem) != -1 && (check3 == 0))	// SongList�� ���� �ƴϰ� SongList���� ã�� ������ ��
							{
								if (song.GetName() == songitem.GetName())		// SongList���� �˻��� ���� ã����
								{
									MasterList.ResetList();
									while (MasterList.GetNextItem(musicitem) != -1 && (check4 == 0))	// MasterList�� ���� �ƴϰ� MasterList���� ã�� ������ ��
									{
										if (song.GetName() == musicitem.GetName())	// MasterList���� �˻��� ���� ã����
										{
											check4++;
											musicitem.DisplayRecordOnScreen();		// �ش� ���� ��� ���� ���
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
		cout << "\n\t" << ent.GetEnt() << " �Ҽӻ簡 �����ϴ�." << endl;
	else if (check1 == 0)
		cout << "\n\t" << singer.GetSinger() << " ��(��) ã�� �� �����ϴ�" << endl;
	else if (check2 == 0)
		cout << "\n\t" << album.GetAlbumname() << " �ٹ��� ã�� �� �����ϴ�." << endl;
	else if (check3 == 0)
		cout << "\n\t" << song.GetName() << " ��(��) ã�� �� �����ϴ�." << endl;




	//if (EntList.Get(ent))
	//{
	//	cout << "\n\t" << ent.GetEnt() << "�� ������ ������ �����ϴ�." << endl;
	//	ent.DisplayEntListOnScreen();
	//	cout << "\n\t" << ent.GetEnt() << "���� �˻��� ������ �����ϼ���." << endl;

	//	singer.SetSingerFromKB();
	//	SingerList.Get(singer);
	//	cout << "\n\t" << singer.GetSinger() << "�� �ٹ��� ������ �����ϴ�." << endl;
	//	singer.DisplayAlbumnameOnScreen();
	//	cout << "\n\t" << singer.GetSinger() << "�� �ٹ� �� �˻��� �ٹ��� �����ϼ���." << endl;

	//	album.SetAlbumnameFromKB();
	//	AlbumList.Get(album);
	//	cout << "\n\t" << album.GetAlbumname() << "�� ������ ������ �����ϴ�." << endl;
	//	album.DisplayRecordOnScreen();
	//	album.DisplayAlbumListOnScreen();
	//	cout << "\n\t" << album.GetAlbumname() << "�� ���ϰ� �� ��� ������ ����� ���� �����ϼ���." << endl;

	//	music.SetNameFromKB();
	//	MasterList.RetrieveMusic_Binary(music);
	//	music.DisplayRecordOnScreen();
	//	check++;
	//}
	//if (check == 0)
	//{
	//	cout << "\n\t" << ent.GetEnt() << "�Ҽ� " << singer.GetSinger() << "�� " << album.GetAlbumname() << "�� ";
	//	cout << music.GetName() << "�� �����ϴ�." << endl;
	//}
}
*/




////������ filename�� �Է��ϰ� file�� �����Ǹ� 1, �ƴϸ� 0 ����
//int Application::OpenOutFile(char *fileName)
//{
//	m_OutFile.open(fileName);	//������ fileName�� �ش��ϴ� file�� ����.
//	if (m_OutFile)	//���µ� �����ϸ�
//		return 1;
//	else
//		return 0;
//}
//
//// �о���� filename�� �Է¹޾� open�ϸ� file�� ��� ������ �а� ���ڵ忡 �߰�.
//// ���� ���� ��� ���� ȭ�鿡 ���, �����ϸ� 1, �ƴϸ� 0 ����
//int Application::ReadDataFromFile()
//{
//	MusicType music;
//
//	char filename[FILENAMESIZE];	//�о���� filename ����
//	cout << "\tEnter Input File Name : ";
//	cin >> filename;
//
//	if (!OpenInFile(filename))	//���µ� �����ϸ�
//	{
//		cout << "\n\tCan't open file " << filename << endl;
//		return 0;
//	}
//
//	while (!m_InFile.eof())	//���� ���� �ƴ� ���
//	{
//		music.ReadDataFromFile(m_InFile);	//m_InFile�κ��� data�� �о��
//		MasterList.Add(music);		//���� data�� MusicList�� �߰�
//	}
//
//	m_InFile.close();	//file �ݱ�
//	DisplayAllMusic();	//file�κ��� ���� ��� ���� ȭ�鿡 ���
//
//	return 1;
//}
//
////������ filename�� �Է¹ް� ���ڵ��� ��� ������ file�� ����. �����ϸ� 1, �ƴϸ� 0 ����
//int Application::WriteDataToFile()
//{
//	MusicType music;
//	char filename[FILENAMESIZE];	//������ filename ����
//	cout << "\n\tEnter Output File Name : ";
//	cin >> filename;
//
//	if (!OpenOutFile(filename))		//file�� ���µ� �����ϸ�
//		return 0;
//
//	MasterList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//
//	int length = MasterList.GetLength();		//���ڵ��� ����
//	int curindex = MasterList.GetNextItem(music);		//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	while (curindex < length&&curindex != -1)		//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		music.WriteDataToFile(m_OutFile);		//iterator�� ����Ű�� �׸��� ���ڵ带 m_OutFil�� ����
//		curindex = MasterList.GetNextItem(music);	//���� ���ڵ带 ����Ű���� ����
//	}
//
//	m_OutFile.close();	//file �ݱ�
//	return 1;
//}
//
////���ڵ��� ��� �׸��� ȭ�鿡 ���
//void Application::DisplayAllMusic()
//{
//	MusicType music;
//
//	cout << "\n\tCurrent list" << endl;
//	MasterList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int length = MasterList.GetLength();	//���ڵ��� ����
//	int curindex = MasterList.at(music.GetId())->GetNextItem(music);	//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	while (curindex < length&&curindex != -1)		//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		music.DisplayRecordOnScreen();		//�ش� iterator�� ����Ű�� ���ڵ��� �׸� ȭ�鿡 ���
//		curindex = MasterList.GetNextItem(music);	//iterator�� ���� �׸� ����Ű���� ����
//	}
//}
//


//
////���ڵ忡 �׸� �߰�
//int Application::U_AddMusic()
//{
//	if (MasterList.IsFull())	//���ڵ尡 �� �������� 0 ����
//	{
//		cout << "List is full" << endl;
//		return 0;
//	}
//	MusicType music;
//	music.SetRecordFromKB();	//���ڵ带 keyboard�κ��� �Է¹���
//	m_MusicList.Add(music);	//���ڵ忡 �׸� �߰�
//	cout << endl;
//	DisplayAllMusic();	//���ڵ忡 ����� ��� �׸� ȭ�鿡 ���
//	return 1;	//�׸� �߰��� �����ϸ� 1 ����
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
////keyboard�� ���� Id �Է¹ް� ��ġ�ϴ� Id�� �׸� ����
//void Application::DeleteMusicById()
//{
//	MusicType music;
//	cout << "\tEnter id to delete";
//	music.SetIdFromKB();	//keyboard�κ��� Id�� �Է¹���.
//	if (m_MusicList.DeleteById(music))	//�Է¹��� Id�� ��ġ�ϴ� �׸��� ������ �ش� �׸��� ����
//		cout << "\tDelete complete" << endl;
//	else					//��ġ�ϴ� �׸��� ������
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
////������ ���� id�� �Է��� �� �����ϸ�, ���ο� ������ ����
//void Application::ReplaceMusicById()
//{
//	MusicType music;
//	cout << "\tEnter id to replace";
//	music.SetIdFromKB();	//keyboard�κ��� Id�� �Է¹���
//	if (m_MusicList.GetFromId(music))	//�Է¹��� Id�� ��ġ�ϴ� �׸��� ���� �� 
//	{
//		//��ġ�ϴ� MusicList�� �� ������ keyboard�� ���� �Է¹���.
//		music.SetTypeFromKB();
//		music.SetGenreFromKB();
//		music.SetNameFromKB();
//		music.SetMelodizerFromKB();
//		music.SetSingerFromKB();
//		if (m_MusicList.ReplaceById(music))	//Id�� ��ġ�� �� �ش��׸��� �Է¹��� �׸����� ����
//		{
//			cout << "\tReplace complete." << endl;
//		}
//		else					//��ġ�ϴ� �׸��� ������
//			cout << "\tReplace Fail." << endl;
//	}
//	else
//		cout << "\tReplace Fail. There's no Id match with." << endl;
//}
//
//
////�Է¹��� Id�� ��ġ�ϴ� �׸��� ���� ȭ�鿡 ���
//void Application::RetrieveMusic_BS()
//{
//	MusicType music;
//	MusicType search;
//	cout << endl;
//	search.SetIdFromKB();	//�˻��� Id�� keyboard�κ��� �Է¹���
//
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	
//	int length = m_MusicList.GetLength();
//	int curindex = m_MusicList.GetNextItem(music);
//	int check = 0;
//	
//	
//		
//	if (m_MusicList.RetrieveMusic_Binary(music))	//Binary search�� Id�� �˻��� �������� ��
//	{
//		cout << "\t---------------------------------------" << endl << endl;
//		music.DisplayRecordOnScreen();	//�ش� ���ڵ带 ���
//		check++;	//�˻��� �����ϸ� check�� ����
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
//	if(check==0)	//�˻��� Id�� ���ڵ忡 ���� ��
//		cout << "\tThere's no id number with " << search.GetId() << endl;
//	else			//�˻��� Id�� ���ڵ忡 ���� ��
//		cout << "\n\t-------------------------------------" << endl;
//}
//

////���ڵ带 �ʱ�ȭ
//void Application::MakeEmpty()
//{
//	m_MusicList.MakeEmpty();
//}
//
////�˻��� type�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchByType()
//{
//	MusicType music;
//	cout << "\tEnter searh type (1. song	2. concertino) ";
//	int num;
//	cin >> num;
//	while (!(num == 1 || num == 2))		//type�� 1 Ȥ�� 2�� �ƴ� ���
//	{
//		cout << "\tPlease enter 1 or 2";
//		cin >> num;
//	}
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);	//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	if (num == 1)	//�˻��� type�� 1�� ���
//		cout << "\tList of song type" << endl;
//	else		//�˻��� type�� 2�� ���
//		cout << "\tList of concertino type" << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		music.DisplayRecordOnScreen();		//�ش� iterator�� ����Ű�� ���ڵ��� �׸� ȭ�鿡 ���
//		check++;
//		curindex = m_MusicList.GetNextItem(music);		//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� type�� �������� ���� ���
//	{
//		cout << "\tThere's no type of ";
//		if (num == 1)
//			cout << "song" << endl;
//		else
//			cout << "concertino" << endl;
//	}
//}
//
////�˻��� genre�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchByGenre()
//{
//	MusicType music;
//	cout << "\tEnter music genre";
//	MusicType search;
//	search.SetGenreFromKB();	//keyboard�κ��� �˻��� genre �Է�
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);	//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	cout << "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		if (music.GetGenre() == search.GetGenre())	//�˻��� genre�� ���ڵ忡 ������ ���
//		{
//			
//			music.DisplayNameOnScreen();	//�ش� ���ڵ��� name�� ���
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� genre�� ���ڵ忡 ���� ���
//	{
//		cout << "\tThere's no music genre with " << search.GetGenre() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//} 
//
////�˻��� name�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchByName()
//{
//	MusicType music;
//	cout << "\tEnter music name";
//	MusicType search;
//	search.SetNameFromKB();		//keyboard�κ��� �˻��� name �Է�
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);		//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	while (curindex < m_MusicList.GetLength()&&curindex != -1)		//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		if (music.GetName() == search.GetName())	//�˻��� name�� ���ڵ忡 ������ ���
//		{
//			music.DisplayRecordOnScreen();		//�ش� ���ڵ带 ȭ�鿡 ���
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� name�� �������� ���� ���
//		cout << "\tThere's no music name with " << search.GetName() << endl;
//}
//
////�˻��� melodizer�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchByMelodizer()
//{
//	MusicType music;
//	cout << "\tEnter melodizer name";
//	MusicType search;
//	search.SetMelodizerFromKB();	//keyboard�κ��� �˻��� melodizer �Է�
//	m_MusicList.ResetList();		//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);		//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		if (music.GetMelodizer() == search.GetMelodizer())	//�˻��� melodizer�� ���ڵ忡 ������ ���
//		{
//			music.DisplayMelodizerOnScreen();		//�ش� melodizer�� ȭ�鿡 ���
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);		//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� melodizer�� �������� ���� ���
//		cout << "\tThere's no melodizer name with " << search.GetMelodizer() << endl;
//}
//
////�˻��� singer�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchBySinger()
//{
//	MusicType music;
//	cout << "\tEnter singer name";
//	MusicType search;
//	search.SetSingerFromKB();	//keyboard�κ��� �˻��� singer �Է�
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);	//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	cout << "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		
//		if (music.GetSinger() == search.GetSinger())	//�˻��� singer�� ���ڵ忡 ������ ���
//		{
//			music.DisplayNameOnScreen();		//�ش� ���ڵ��� name�� ȭ�鿡 ���
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);	//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� singer�� �������� ���� ���
//	{
//		cout << "\tThere's no singer name with " << search.GetSinger() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//}
//
////�˻��� id�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
//void Application::SearchById()
//{
//	MusicType music;
//	cout << "\tEnter Id";
//	MusicType search;
//	search.SetIdFromKB();	//keyboard�κ��� �˻��� Id �Է�
//	m_MusicList.ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
//	int curindex = m_MusicList.GetNextItem(music);	//���ڵ��� iterator 1���� �� iterator ����. ���̸� -1 ����
//	int check = 0;
//	cout<< "\n\t-------------------------------------" << endl << endl;
//	while (curindex < m_MusicList.GetLength() && curindex != -1)	//iterator�� ���ڵ��� ���̺��� �۰� ���ڵ��� ���� �ƴ� ��
//	{
//		if (music.GetId() == search.GetId())	//�˻��� Id�� ���ڵ忡 ������ ���
//		{
//			music.DisplayRecordOnScreen();		//�ش� ���ڵ带 ȭ�鿡 ���
//			check++;
//		}
//		curindex = m_MusicList.GetNextItem(music);		//iterator�� ���� �׸� ����Ű���� ����
//	}
//	if (check == 0)		//�˻��� Id�� �������� ���� ���
//	{
//		cout << "\tThere's no id match with " << search.GetId() << endl;
//		cout << "\n\t-------------------------------------" << endl << endl;
//	}
//	else
//		cout << "\n\t-------------------------------------" << endl;
//}
//

//// Id�� �˻��� ���ڵ忡 �����ϸ� PlayList�� �߰�
//void Application::AddPlayMusic()
//{
//	cout << "\tEnter music data to add." << endl;
//	PlayItemType item;
//	MusicType music;
//
//	item.SetRecordFromKB();		//keyboard�κ��� ������ �׸� �Է�
//	music.SetId(item.GetId());	//������ �׸��� Id�� �˻��� �뵵
//	if (m_MusicList.GetFromId(music))	//���ڵ忡 �ش� Id�� ������ ���
//	{
//		m_PlayList.AddToPlayList(item);	//PlayList�� ����
//		cout << endl;
//		item.DisplayRecordOnScreen();	//������ �׸� ���
//	}
//	else
//		cout << "\tThere's no record with Id : " << music.GetId() << endl;	
//}
//
////Id�� PlayList���� �˻��� �����ϸ� �ش� �׸� ����
//void Application::DeletePlayMusic()
//{
//	PlayItemType item;
//	m_PlayList.DeleteFrPlayList(item);
//}
//
////PlayList�� ����� ������� �׸� ���
//void Application::PrintAllPlayMusic()
//{
//	PlayItemType item;
//	m_PlayList.PlayInsertOrder(item);
//}
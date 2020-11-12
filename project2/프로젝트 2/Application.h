#pragma once

#define FILENAMESIZE 1024

#include "AlbumType.h"
#include "EntType.h"
#include "GenreType.h"
#include "LinkedList.h"
#include "MusicType.h"
#include "SimpleTypeForAlbum.h"
#include "SingerType.h"
#include "SongType.h"
#include "SortedList.h"
#include "UserType.h"
#include "CircularQueueType.h"
#include "PlaySongType.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib,"winmm.lib")
// MusicList->GenreList
// MusicList->AlbumList->SingerList->EntList



using namespace std;

class Application
{
private:
	int m_Command;
	ifstream m_InFile;
	ofstream m_OutFile;

	SortedList<MusicType> MasterList;		// ��ü ���� ����Ʈ
	LinkedList<SongType> SongList;			// ����� ���� ���� ����Ʈ
	LinkedList<GenreType> GenreList;		// �帣���� ���е� ���� ����Ʈ
	LinkedList<AlbumType> AlbumList;		// �ٹ����� ���е� ���� ����Ʈ
	LinkedList<SingerType> SingerList;		// �������� ���е� ���� ����Ʈ
	LinkedList<EntType> EntList;			// �Ҽӻ纰�� ���е� ���� ����Ʈ
	LinkedList<UserType> UserList;			// ���� ����Ʈ
	LinkedList<PlaySongType> PlayList;		// ���� ����� ���� ����Ʈ


	CircularQueueType<SongType> RecentlyList;	// �ֱ� �߰��� ���� ����Ʈ


	MCI_OPEN_PARMS mciOpen;					// �������� ����
	MCI_PLAY_PARMS mciPlay;					// ���� ����
	int dwID;

public:
	// Application ������
	Application();

	// Application �Ҹ���
	~Application();

	void RunProgram();	// �Է��ϴ� command�� ���� �Լ� ����
	int GetCommand();	// command �Է¹ް� �ش� command ����



	// User : �Ϲ� ����� ������ ��� �Լ���
	void User();						// ����ڿ� ���� �α��� ���� Ȯ�� �� �����Ǹ� ����� ��� ����
	void Run_User();					// �Ϲ� ����� ������ ���	(Release��)
	void Login_User();					// ����ڿ� ��� �α��� ��������
	void SignUp_User();					// ����ڿ� ��� ȸ������
	int AddMusic_User();				// ���ڵ忡 �׸� �߰�
	void DeleteMusic_User();			// keyboard�κ��� ����� �Է¹ް� ��ġ�ϴ� ���� ����
	void DisplayAllMusic_User();		// SongList�� �����ϴ� ��� ���� ���
	void SearchByRecentlyMusic_User();	// �ֱ� �߰��� ����� ������Ͽ��� �˻�
	void SearchById_User();				// ������ȣ�� �˻�
	void SearchByName_User();			// ������� �˻�
	void SearchBySinger_User();			// ������ �˻�
	void SearchByGenre_User();			// �帣�� �˻�
	void SearchByAlbumName_User();		// �ٹ������� �˻�
	void SearchByEnt_User();			// �Ҽӻ�� �˻�
	void PlayMusic_User();				// ����� ������Ͽ��� ���
	int Save_User();					// ����� ��������� ����� ID�� ���ϸ����� ����
	int Read_User(char id);				// ����� ID�� ���ϸ��� ����� ����������� ������


	// Admin : �����ڿ� ��� �Լ���
	void Admin();						// �����ڿ� ���� �α��� ���� Ȯ�� �� �����Ǹ� ������ ��� ����
	void Run_Admin();					// ������ ������ ��忡�� ��밡���� ��ɾ���� ��û�� ���� ����
	void AddMusic_Admin();				// �����͸���Ʈ�� ���� �߰�
	void DeleteMusic_Admin();			// �����͸���Ʈ���� ���� ����
	void ReplaceMusic_Admin();			// �����͸���Ʈ ����
	int LoadMasterList_Admin();			// �����͸���Ʈ ��������
	void DisplayAllMusic_Admin();		// �����͸���Ʈ�� ��� �������� ���
	//int Save_Admin();					// �����͸���Ʈ�� �������� ����



	int OpenInFile(char *fileName);	// �ش� filename�� �����ϸ� ���� 1 ����, �ƴϸ� 0 ����
	int OpenOutFile(char *fileName);	// ������ filename�� �Է��ϰ� file�� �����Ǹ� 1, �ƴϸ� 0 ����





	/*
	int ReadDataFromFile();	// �о���� filename�� �Է¹޾� open�ϸ� file�� ��� ������ �а� ���ڵ忡 �߰�.
							// ���� ���� ��� ���� ȭ�鿡 ���, �����ϸ� 1, �ƴϸ� 0 ����
	int WriteDataToFile();	// ������ filename�� �Է¹ް� ���ڵ��� ��� ������ file�� ����. �����ϸ� 1, �ƴϸ� 0 ����
	void DisplayAllMusic();	// ���ڵ��� ��� �׸��� ȭ�鿡 ���


	
	void ReplaceMusic();	// ������ ���� id�� �Է��� �� �����ϸ�, ���ο� ������ ����
	void RetrieveMusic_BS();	// �Է¹��� Id�� ��ġ�ϴ� �׸��� ���� ȭ�鿡 ���
	void MakeEmpty();		// ���ڵ带 �ʱ�ȭ
	void SearchByType();	// �˻��� type�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void SearchByGenre();	// �˻��� genre�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void SearchByName();	// �˻��� name�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void SearchByMelodizer();	// �˻��� melodizer�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void SearchBySinger();	// �˻��� singer�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void SearchById();		// �˻��� id�� �ش��ϴ� ��� �׸� ȭ�鿡 ���
	void AddPlayMusic();	// Id�� �˻��� ���ڵ忡 �����ϸ� PlayList�� �߰�
	void DeletePlayMusic();	// Id�� PlayList���� �˻��� �����ϸ� �ش� �׸� ����
	void PrintAllPlayMusic();	// PlayList�� ����� ������� �׸� ���
	*/
};
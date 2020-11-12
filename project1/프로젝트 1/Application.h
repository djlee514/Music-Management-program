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

// MusicList->SongList->GenreList->AlbumList->SingerList->EntList

#include <iostream>
#include <fstream>
#include <string>
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

public:
	// Application ������
	Application();

	// Application �Ҹ���
	~Application();

	void RunProgram();	// �Է��ϴ� command�� ���� �Լ� ����
	int GetCommand();	// command �Է¹ް� �ش� command ����


	void RunForAdministrator();		// ���α׷� ������ ������ ���


	// Release : �Ϲ� ����� ������ ��� �Լ���
	void R_Run();				// �Ϲ� ����� ������ ���	(Release��)
	int R_AddMusic();			// ���ڵ忡 �׸� �߰�
	void R_DeleteMusic();		// keyboard�κ��� ����� �Է¹ް� ��ġ�ϴ� ���� ����
	void R_DisplayAllMusic();	// SongList�� �����ϴ� ��� ���� ���
	void R_SearchById();		// ������ȣ�� �˻�
	void R_SearchByName();		// ������� �˻�
	void R_SearchBySinger();	// ������ �˻�
	void R_SearchByGenre();		// �帣�� �˻�
	void R_SearchByAlbumName();	// �ٹ������� �˻�
	void R_SearchByEnt();		//�Ҽӻ�� �˻�



	int OpenInFile(char *fileName);	// �ش� filename�� �����ϸ� ���� 1 ����, �ƴϸ� 0 ����
	int OpenOutFile(char *fileName);	// ������ filename�� �Է��ϰ� file�� �����Ǹ� 1, �ƴϸ� 0 ����
	int ReadDataFromFile();	// �о���� filename�� �Է¹޾� open�ϸ� file�� ��� ������ �а� ���ڵ忡 �߰�.
							// ���� ���� ��� ���� ȭ�鿡 ���, �����ϸ� 1, �ƴϸ� 0 ����
	int WriteDataToFile();	// ������ filename�� �Է¹ް� ���ڵ��� ��� ������ file�� ����. �����ϸ� 1, �ƴϸ� 0 ����
	void DisplayAllMusic();	// ���ڵ��� ��� �׸��� ȭ�鿡 ���


	/*
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
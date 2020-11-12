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

	SortedList<MusicType> MasterList;		// 전체 음악 리스트
	LinkedList<SongType> SongList;			// 사용자 생성 음악 리스트
	LinkedList<GenreType> GenreList;		// 장르별로 구분된 음악 리스트
	LinkedList<AlbumType> AlbumList;		// 앨범별로 구분된 음악 리스트
	LinkedList<SingerType> SingerList;		// 가수별로 구분된 음악 리스트
	LinkedList<EntType> EntList;			// 소속사별로 구분된 음악 리스트

public:
	// Application 생성자
	Application();

	// Application 소멸자
	~Application();

	void RunProgram();	// 입력하는 command에 따라 함수 실행
	int GetCommand();	// command 입력받고 해당 command 리턴


	void RunForAdministrator();		// 프로그램 관리자 지원용 모드


	// Release : 일반 사용자 지원용 모드 함수들
	void R_Run();				// 일반 사용자 지원용 모드	(Release용)
	int R_AddMusic();			// 레코드에 항목 추가
	void R_DeleteMusic();		// keyboard로부터 곡명을 입력받고 일치하는 곡을 삭제
	void R_DisplayAllMusic();	// SongList에 존재하는 모든 정보 출력
	void R_SearchById();		// 고유번호로 검색
	void R_SearchByName();		// 곡명으로 검색
	void R_SearchBySinger();	// 가수로 검색
	void R_SearchByGenre();		// 장르로 검색
	void R_SearchByAlbumName();	// 앨범명으로 검색
	void R_SearchByEnt();		//소속사로 검색



	int OpenInFile(char *fileName);	// 해당 filename이 존재하면 열고 1 리턴, 아니면 0 리턴
	int OpenOutFile(char *fileName);	// 저장할 filename을 입력하고 file이 생성되면 1, 아니면 0 리턴
	int ReadDataFromFile();	// 읽어들일 filename을 입력받아 open하면 file의 모든 내용을 읽고 레코드에 추가.
							// 이후 읽은 모든 값을 화면에 출력, 성공하면 1, 아니면 0 리턴
	int WriteDataToFile();	// 저장할 filename을 입력받고 레코드의 모든 내용을 file에 저장. 성공하면 1, 아니면 0 리턴
	void DisplayAllMusic();	// 레코드의 모든 항목을 화면에 출력


	/*
	void ReplaceMusic();	// 수정할 곡의 id를 입력한 뒤 존재하면, 새로운 값으로 설정
	void RetrieveMusic_BS();	// 입력받은 Id랑 일치하는 항목을 전부 화면에 출력
	void MakeEmpty();		// 레코드를 초기화
	void SearchByType();	// 검색한 type에 해당하는 모든 항목 화면에 출력
	void SearchByGenre();	// 검색한 genre에 해당하는 모든 항목 화면에 출력
	void SearchByName();	// 검색한 name에 해당하는 모든 항목 화면에 출력
	void SearchByMelodizer();	// 검색한 melodizer에 해당하는 모든 항목 화면에 출력
	void SearchBySinger();	// 검색한 singer에 해당하는 모든 항목 화면에 출력
	void SearchById();		// 검색한 id에 해당하는 모든 항목 화면에 출력
	void AddPlayMusic();	// Id를 검색해 레코드에 존재하면 PlayList에 추가
	void DeletePlayMusic();	// Id를 PlayList에서 검색해 존재하면 해당 항목 삭제
	void PrintAllPlayMusic();	// PlayList에 저장된 순서대로 항목 출력
	*/
};
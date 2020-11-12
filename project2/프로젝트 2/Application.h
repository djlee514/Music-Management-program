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

	SortedList<MusicType> MasterList;		// 전체 음악 리스트
	LinkedList<SongType> SongList;			// 사용자 생성 음악 리스트
	LinkedList<GenreType> GenreList;		// 장르별로 구분된 음악 리스트
	LinkedList<AlbumType> AlbumList;		// 앨범별로 구분된 음악 리스트
	LinkedList<SingerType> SingerList;		// 가수별로 구분된 음악 리스트
	LinkedList<EntType> EntList;			// 소속사별로 구분된 음악 리스트
	LinkedList<UserType> UserList;			// 유저 리스트
	LinkedList<PlaySongType> PlayList;		// 음악 재생을 위한 리스트


	CircularQueueType<SongType> RecentlyList;	// 최근 추가된 음원 리스트


	MCI_OPEN_PARMS mciOpen;					// 음악파일 열기
	MCI_PLAY_PARMS mciPlay;					// 음악 실행
	int dwID;

public:
	// Application 생성자
	Application();

	// Application 소멸자
	~Application();

	void RunProgram();	// 입력하는 command에 따라 함수 실행
	int GetCommand();	// command 입력받고 해당 command 리턴



	// User : 일반 사용자 지원용 모드 함수들
	void User();						// 사용자용 모드로 로그인 조건 확인 후 인증되면 사용자 모드 실행
	void Run_User();					// 일반 사용자 지원용 모드	(Release용)
	void Login_User();					// 사용자용 모드 로그인 인증과정
	void SignUp_User();					// 사용자용 모드 회원가입
	int AddMusic_User();				// 레코드에 항목 추가
	void DeleteMusic_User();			// keyboard로부터 곡명을 입력받고 일치하는 곡을 삭제
	void DisplayAllMusic_User();		// SongList에 존재하는 모든 정보 출력
	void SearchByRecentlyMusic_User();	// 최근 추가된 사용자 음원목록에서 검색
	void SearchById_User();				// 고유번호로 검색
	void SearchByName_User();			// 곡명으로 검색
	void SearchBySinger_User();			// 가수로 검색
	void SearchByGenre_User();			// 장르로 검색
	void SearchByAlbumName_User();		// 앨범명으로 검색
	void SearchByEnt_User();			// 소속사로 검색
	void PlayMusic_User();				// 사용자 음원목록에서 재생
	int Save_User();					// 사용자 음원목록을 사용자 ID의 파일명으로 저장
	int Read_User(char id);				// 사용자 ID의 파일명을 사용자 음원목록으로 가져옴


	// Admin : 관리자용 모드 함수들
	void Admin();						// 관리자용 모드로 로그인 조건 확인 후 인증되면 관리자 모드 실행
	void Run_Admin();					// 관리자 지원용 모드에서 사용가능한 명령어들을 요청에 따라 실행
	void AddMusic_Admin();				// 마스터리스트에 음악 추가
	void DeleteMusic_Admin();			// 마스터리스트에서 음악 삭제
	void ReplaceMusic_Admin();			// 마스터리스트 갱신
	int LoadMasterList_Admin();			// 마스터리스트 가져오기
	void DisplayAllMusic_Admin();		// 마스터리스트의 모든 음악정보 출력
	//int Save_Admin();					// 마스터리스트를 파일으로 저장



	int OpenInFile(char *fileName);	// 해당 filename이 존재하면 열고 1 리턴, 아니면 0 리턴
	int OpenOutFile(char *fileName);	// 저장할 filename을 입력하고 file이 생성되면 1, 아니면 0 리턴





	/*
	int ReadDataFromFile();	// 읽어들일 filename을 입력받아 open하면 file의 모든 내용을 읽고 레코드에 추가.
							// 이후 읽은 모든 값을 화면에 출력, 성공하면 1, 아니면 0 리턴
	int WriteDataToFile();	// 저장할 filename을 입력받고 레코드의 모든 내용을 file에 저장. 성공하면 1, 아니면 0 리턴
	void DisplayAllMusic();	// 레코드의 모든 항목을 화면에 출력


	
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
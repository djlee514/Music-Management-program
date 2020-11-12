#pragma once
#define MAXSIZE 10

#include <iostream>
#include <string>
using namespace std;


template <typename T>
class SortedList
{
public:
	// =연산자 오버로딩
	void operator =(const SortedList& _p)
	{
		m_MAXSIZE = _p.m_MAXSIZE;
		m_Length = _p.m_Length;
		m_CurPointer = _p.m_CurPointer;
		delete[] m_list;
		m_list = new T[m_MAXSIZE];
		for(int i = 0; i < m_Length; i++)
			m_list[i] = _p.m_list[i];
	}

	// ==연산자 오버로딩
	bool operator==(const SortedList &_p)
	{
		if (this->m_name == _p.m_albumname)
			return true;
		else
			return false;
	}

	// >연산자 오버로딩
	bool operator>(const AlbumType &_p)
	{
		if (this->m_albumname > _p.m_albumname)
			return  true;
		else
			return false;
	}

	// <연산자 오버로딩
	bool operator<(const AlbumType &_p)
	{
		if (this->m_albumname < _p.m_albumname)
			return true;
		else
			return false;
	}

	// >=연산자 오버로딩
	bool operator>=(const AlbumType &_p)
	{
		if (this->m_albumname >= _p.m_albumname)
			return true;
		else
			return false;
	}

	// <=연산자 오버로딩
	bool operator<=(const AlbumType &_p)
	{
		if (this->m_albumname <= _p.m_albumname)
			return true;
		else
			return false;
	}

	//SortedList 생성자
	SortedList();

	//SortedList 소멸자
	~SortedList();

	bool IsEmpty();		//배열이 비어있는지 확인 후 비어있으면 ture, 아니면 false 리턴
	int GetFromName(T& data);	//입력받은 data의 name과 일치하는 name의 항목을 data에 저장 후 1 리턴. 실패시 0 리턴
	int GetFromId(T& data);		//입력받은 data의 id과 일치하는 id의 항목을 data에 저장 후 1 리턴. 실패시 0 리턴
	int DeleteById(T data);	//입력받은 data의 id와 일치하는 항목을 삭제하고 1 리턴, 실패시 0 리턴
	int ReplaceById(T data);//입력받은 data의 id와 일치하는 항목을 새로운 값으로 설정하고 1 리턴, 실패시 0 리턴
	void MakeEmpty();	//배열의 길이를 0으로 초기화
	int GetLength();	//배열의 길이를 리턴
	bool IsFull();		//배열이 꽉 차있는지 확인 후 맞으면 true, 아니면 false 리턴
	int Add(const T& data);	//배열에 Primary key를 기준으로 정렬해 새로운 항목을 추가
	void ResetList();	//배열의 iterator를 -1로 초기화
	int GetNextItem(T& data);	//iterator를 1 증가시키고 끝이 아니면 iterator를, 끝이면 -1 리턴
	int RetrieveMusic(T& data);	//배열에서 입력받은 data의 name과 동일한 name이 배열에 있으면 1, 아니면 0 리턴
	int RetrieveMusic_Binary(T& data);	//Binary Search로 RetrieveMusic 실행. 찾으면 1, 아니면 0 리턴
private:
	T * m_list;	//배열
	int m_Length;		//배열의 길이
	int m_CurPointer;	//배열의 current pointer
	int m_MAXSIZE;		//배열의 MAXSIZE 이상 입력받을 시 예외처리를 위한 int 변수
};

template<typename T>
SortedList<T>::SortedList()
{
	m_MAXSIZE = MAXSIZE;
	m_Length = 0;
	ResetList();
	m_list = new T[m_MAXSIZE];
}

template<typename T>
SortedList<T>::~SortedList()
{
	delete[] m_list;
}

template<typename T>
bool SortedList<T>::IsEmpty()
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

template<typename T>
int SortedList<T>::GetFromName(T& data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_list[m_CurPointer] == data) {
			data = m_list[m_CurPointer];
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList<T>::GetFromId(T& data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_list[m_CurPointer] == data)
		{
			data = m_list[m_CurPointer];
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList<T>::DeleteById(T data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_list[m_CurPointer] == data) {
			for (int i = m_CurPointer; i < m_Length - 1; i++)
			{
				m_list[i] = m_list[i + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList<T>::ReplaceById(T data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (m_list[m_CurPointer] == data)
		{
			m_list[m_CurPointer] = data;
			/*m_list[m_CurPointer].SetData(data.GetType(), data.GetGenre(), data.GetName(), data.GetMelodizer(), data.GetSinger(), data.GetId());*/
			return 1;
		}
	}
	return 0;
}

template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

template<typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > m_MAXSIZE - 1)
		return true;
	else
		return false;
}

template<typename T>
int SortedList<T>::Add(const T& data)
{
	if (IsFull())	//배열이 꽉 차있을 경우 배열의 최대 사이즈를 늘려준다.
	{
		T* templist = new T[m_Length];
		for (int i = 0; i < m_Length; i++)
		{
			templist[i] = m_list[i];
		}
		delete[] m_list;
		m_MAXSIZE = m_MAXSIZE + MAXSIZE;
		m_list = new T[m_MAXSIZE];
		for (int i = 0; i < m_Length; i++)
		{
			m_list[i] = templist[i];
		}
		delete[] templist;
	}

	//꽉 차지 않았으면 항목 추가
	if (m_Length == 0)	//배열이 비어있으면 항목 추가
	{
		m_list[m_Length] = data;
		m_Length++;
		return 1;		//추가에 성공해서 1 반환 후 length 1 증가
	}
	else			//배열에 항목이 존재할 때
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_list[i] < data)	//존재하는 항목보다 입력한 항목이 클 때
			{
				if (i == m_Length - 1)	//배열 마지막값보다도 크면 맨 마지막에 추가
				{
					m_list[m_Length] = data;
					m_Length++;
					return 1;	//추가에 성공해서 1 반환 후 length 1 증가
				}
			}
			else if (m_list[i] > data)	//존재하는 항목이 입력한 항목보다 클 때
			{
				for (int j = m_Length; j > i; j--)	//기존 항목을 뒤로 한 칸씩 이동
					m_list[j] = m_list[j - 1];
				m_list[i] = data;	//신규 항목 추가
				m_Length++;
				return 1;	//추가에 성공해서 1 반환 후 length 1 증가
			}
			else if (m_list[i] == data)	//존재하는 항목과 입력한 항목이 같을 때
			{
				/*cout << "\tThe same item exist in the list" << endl;*/
				return -1;	//추가할 수 없으므로 -1 리턴
			}
		}
	}
}

template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int SortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;

	if (m_CurPointer == m_MAXSIZE)
		return -1;
	data = m_list[m_CurPointer];
	return m_CurPointer;
}

template<typename T>
int SortedList<T>::RetrieveMusic(T& data)
{
	ResetList();
	m_CurPointer++;
	for (m_CurPointer; m_CurPointer < m_Length; m_CurPointer++)
		if (m_list[m_CurPointer] == data)
			return 1;
		else
			return 0;
}

template<typename T>
int SortedList<T>::RetrieveMusic_Binary(T& data)
{
	if (m_Length == 0)	//배열이 비어있으면 0 리턴
		return 0;
	int first = 0;
	int last = m_Length - 1;

	bool test = false;
	while (first <= last)	//first가 last값보다 작거나 같을 때만 while문 실행
	{
		int mid = (first + last) / 2;
		if (test == true)	//while문 종결 조건
			break;
		for (int i = 0; i < m_Length; i++)
		{
			if (data < m_list[mid])	//찾을 data가 배열의 중간값보다 작은 경우
			{
				last = mid - 1;	//중간값보다 작을 경우 last를 mid - 1로 변경.
			}
			else if (data > m_list[mid])	//찾을 data가 배열의 중간값보다 큰 경우
			{
				first = mid + 1;	//중간값보다 클 경우 last를 mid + 1로 변경
			}
			else if (data == m_list[mid])	//찾을 data가 배열의 중간값과 같은 경우
			{
				data = m_list[mid];	//data에 배열의 중간값의 항목들을 복사.
				return 1;	//성공했으므로 1 리턴
			}
		}
	}
	return 0;
}
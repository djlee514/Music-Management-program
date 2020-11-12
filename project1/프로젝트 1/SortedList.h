#pragma once
#define MAXSIZE 10

#include <iostream>
#include <string>
using namespace std;


template <typename T>
class SortedList
{
public:
	// =������ �����ε�
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

	// ==������ �����ε�
	bool operator==(const SortedList &_p)
	{
		if (this->m_name == _p.m_albumname)
			return true;
		else
			return false;
	}

	// >������ �����ε�
	bool operator>(const AlbumType &_p)
	{
		if (this->m_albumname > _p.m_albumname)
			return  true;
		else
			return false;
	}

	// <������ �����ε�
	bool operator<(const AlbumType &_p)
	{
		if (this->m_albumname < _p.m_albumname)
			return true;
		else
			return false;
	}

	// >=������ �����ε�
	bool operator>=(const AlbumType &_p)
	{
		if (this->m_albumname >= _p.m_albumname)
			return true;
		else
			return false;
	}

	// <=������ �����ε�
	bool operator<=(const AlbumType &_p)
	{
		if (this->m_albumname <= _p.m_albumname)
			return true;
		else
			return false;
	}

	//SortedList ������
	SortedList();

	//SortedList �Ҹ���
	~SortedList();

	bool IsEmpty();		//�迭�� ����ִ��� Ȯ�� �� ��������� ture, �ƴϸ� false ����
	int GetFromName(T& data);	//�Է¹��� data�� name�� ��ġ�ϴ� name�� �׸��� data�� ���� �� 1 ����. ���н� 0 ����
	int GetFromId(T& data);		//�Է¹��� data�� id�� ��ġ�ϴ� id�� �׸��� data�� ���� �� 1 ����. ���н� 0 ����
	int DeleteById(T data);	//�Է¹��� data�� id�� ��ġ�ϴ� �׸��� �����ϰ� 1 ����, ���н� 0 ����
	int ReplaceById(T data);//�Է¹��� data�� id�� ��ġ�ϴ� �׸��� ���ο� ������ �����ϰ� 1 ����, ���н� 0 ����
	void MakeEmpty();	//�迭�� ���̸� 0���� �ʱ�ȭ
	int GetLength();	//�迭�� ���̸� ����
	bool IsFull();		//�迭�� �� ���ִ��� Ȯ�� �� ������ true, �ƴϸ� false ����
	int Add(const T& data);	//�迭�� Primary key�� �������� ������ ���ο� �׸��� �߰�
	void ResetList();	//�迭�� iterator�� -1�� �ʱ�ȭ
	int GetNextItem(T& data);	//iterator�� 1 ������Ű�� ���� �ƴϸ� iterator��, ���̸� -1 ����
	int RetrieveMusic(T& data);	//�迭���� �Է¹��� data�� name�� ������ name�� �迭�� ������ 1, �ƴϸ� 0 ����
	int RetrieveMusic_Binary(T& data);	//Binary Search�� RetrieveMusic ����. ã���� 1, �ƴϸ� 0 ����
private:
	T * m_list;	//�迭
	int m_Length;		//�迭�� ����
	int m_CurPointer;	//�迭�� current pointer
	int m_MAXSIZE;		//�迭�� MAXSIZE �̻� �Է¹��� �� ����ó���� ���� int ����
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
	if (IsFull())	//�迭�� �� ������ ��� �迭�� �ִ� ����� �÷��ش�.
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

	//�� ���� �ʾ����� �׸� �߰�
	if (m_Length == 0)	//�迭�� ��������� �׸� �߰�
	{
		m_list[m_Length] = data;
		m_Length++;
		return 1;		//�߰��� �����ؼ� 1 ��ȯ �� length 1 ����
	}
	else			//�迭�� �׸��� ������ ��
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (m_list[i] < data)	//�����ϴ� �׸񺸴� �Է��� �׸��� Ŭ ��
			{
				if (i == m_Length - 1)	//�迭 �����������ٵ� ũ�� �� �������� �߰�
				{
					m_list[m_Length] = data;
					m_Length++;
					return 1;	//�߰��� �����ؼ� 1 ��ȯ �� length 1 ����
				}
			}
			else if (m_list[i] > data)	//�����ϴ� �׸��� �Է��� �׸񺸴� Ŭ ��
			{
				for (int j = m_Length; j > i; j--)	//���� �׸��� �ڷ� �� ĭ�� �̵�
					m_list[j] = m_list[j - 1];
				m_list[i] = data;	//�ű� �׸� �߰�
				m_Length++;
				return 1;	//�߰��� �����ؼ� 1 ��ȯ �� length 1 ����
			}
			else if (m_list[i] == data)	//�����ϴ� �׸�� �Է��� �׸��� ���� ��
			{
				/*cout << "\tThe same item exist in the list" << endl;*/
				return -1;	//�߰��� �� �����Ƿ� -1 ����
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
	if (m_Length == 0)	//�迭�� ��������� 0 ����
		return 0;
	int first = 0;
	int last = m_Length - 1;

	bool test = false;
	while (first <= last)	//first�� last������ �۰ų� ���� ���� while�� ����
	{
		int mid = (first + last) / 2;
		if (test == true)	//while�� ���� ����
			break;
		for (int i = 0; i < m_Length; i++)
		{
			if (data < m_list[mid])	//ã�� data�� �迭�� �߰������� ���� ���
			{
				last = mid - 1;	//�߰������� ���� ��� last�� mid - 1�� ����.
			}
			else if (data > m_list[mid])	//ã�� data�� �迭�� �߰������� ū ���
			{
				first = mid + 1;	//�߰������� Ŭ ��� last�� mid + 1�� ����
			}
			else if (data == m_list[mid])	//ã�� data�� �迭�� �߰����� ���� ���
			{
				data = m_list[mid];	//data�� �迭�� �߰����� �׸���� ����.
				return 1;	//���������Ƿ� 1 ����
			}
		}
	}
	return 0;
}
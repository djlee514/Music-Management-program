#pragma once

template<typename T>
struct NodeType
{
	T info;			// 각각의 node에 저장된 정보
	NodeType* next = nullptr;	// 연속된 다음의 node를 가르킴
	void operator=(const NodeType<T>& _p)
	{
		info = _p.info;
	}
};

template<typename T>
class LinkedList
{
private:
	NodeType<T> *m_List;		// 첫 번째 노드 가르킴
	NodeType<T> *m_CurPointer;	// 현재 가르키는 노드
	int m_Length;				// list에 있는 node의 갯수

public:
	LinkedList();		// LinkedList 생성자
	~LinkedList();		// LinkedList 소멸자

	// =연산자 오버로딩
	void operator=(LinkedList<T> & _p)
	{
		MakeEmpty();		// 기존 node 초기화
		if (_p.GetLength())	// _p에 node가 있을 경우
		{
			_p.ResetList();	// _p의 m_CurPointer를 NULL로 초기화
			T item;
			while (_p.GetNextItem(item) == 0)	// m_CurPointer가 NULL일 때만
				Add(item);						// item을 추가
		}
	}

	void MakeEmpty();			// list를 비움
	int GetLength() const;		// m_Length 리턴
	int Add(T& item);			// list에 item 원소 추가
	int Delete(T& item);		// list에서 item과 일치하는 원소 삭제
	int Replace(T& item);		// list에서 item과 일치하는 원소 교체
	int Get(T& item);			// list에서 item과 일치하는 원소를 찾으면 1, 아니면 0 리턴
	void ResetList();			// m_CurPointer를 NULL로 초기화
	int GetNextItem(T& item);	// list에서 다음 항목을 가져옴.
};

// LinkedList 생성자
template<typename T>
LinkedList<T>::LinkedList()
{
	m_List = nullptr;
	m_CurPointer = nullptr;
	m_Length = 0;
}

// LinkedList 소멸자
template<typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

// list를 비움
template<typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T>* temptr;
	while (m_List != NULL)
	{
		temptr = m_List;
		m_List = m_List->next;
		delete temptr;		// list내 모든 node를 제거
	}

	m_Length = 0;	// list의 length를 0으로 초기화
}

// m_Length 리턴
template<typename T>
int LinkedList<T>::GetLength() const
{
	return m_Length;
}

// list에 item 원소 추가
template<typename T>
int LinkedList<T>::Add(T& item)
{
	ResetList();	// list 초기화

	NodeType<T> *node = new NodeType<T>;	// list에 추가할 node pointer
	NodeType<T> *preloc;					// 추가할 자리 이전의 node를 가르키는 pointer
	T temp;

	node->info = item;			// node에 입력받은 data 저장
	node->next = nullptr;			// 다음 node를 NULL로 초기화

	if (!m_Length)		// list에 node가 없을 경우
	{
		m_List = node;	// 처음에 추가
		m_Length++;		// list의 길이 1 증가
		return 1;		// 1 리턴
	}
	else				// list에 node가 있을 경우
	{
		if (Get(item) == 1)	// 해당 item이 이미 list에 있을 경우
			return 0;		// 0 리턴
		else				// item이 list에 없을 경우
		{
			while (true)
			{
				preloc = m_CurPointer;		// 이전 node를 가르키는 pointer를 m_CurPointer로 갱식
				GetNextItem(temp);			// node pointer 갱신
				if (m_CurPointer->info > node->info)	// node가 가르키는 data가 이전 node가 가르키는 data보다 작을 때
				{
					if (preloc == NULL)			// 넣을 자리 이전의 원소가 존재하지 않을 경우
					{
						node->next = m_CurPointer;	// node의 다음을 m_CurPointer로 설정
						m_List = node;				// 처음 자리에 저장
						break;
					}
					else								// node가 가르키는 data가 이전 node가 가르키는 data보다 클 때
					{
						node->next = m_CurPointer;		// node의 다음을 m_CurPointer로 설정
						preloc->next = node;			// 이전node의 다음에 저장
						break;
					}
				}
				if (m_CurPointer->next == NULL)			// node pointer가 마지막 node를 가리키면
				{
					m_CurPointer->next = node;			// 그 다음 자리에 node 저장
					break;
				}
			}
		}
	}
	m_Length++;
	return 1;
}

// list에서 item과 일치하는 원소 삭제
template<typename T>
int LinkedList<T>::Delete(T& item)
{
	NodeType<T>* preloc = nullptr;		// 새로운 node pointer 선언

	m_CurPointer = m_List;
	bool MoreToSearch = (m_CurPointer != nullptr);
	bool found = false;

	while (MoreToSearch && !found)		// list의 끝이 아니면서 찾지 못했을 경우
	{
		if (item == m_CurPointer->info)		// 현재 pointer의 info와 찾으려는 값이 일치할 경우
		{
			found = true;				// found를 true로 변경
			if (preloc == nullptr)		// 현재 pointer 이전에 다른 항목이 없을 경우
				m_List = m_CurPointer->next;	// 현재 pointer 다음 값을 list의 처음 원소로 설정
			else		// 현재 pointer 이전에 다른 항목이 있을 경우
			{
				preloc->next = m_CurPointer->next;	// 이전 pointer의 다음 pointer를 현재 pointer의 다음으로 설정
				delete m_CurPointer;		// 현재 pointer 제거
			}
			m_Length--;		// 항목을 하나 지웠으므로 길이 -1
		}
		else			// 일치하지 않을 경우
		{
			preloc = m_CurPointer;	// 이전 pointer는 현재 pointer를 가르키도록 지시
			m_CurPointer = m_CurPointer->next;	// 현재 pointer를 다음을 가르키도록 지시
			MoreToSearch = (m_CurPointer != nullptr);	// list의 끝인지 검사
		}
	}

	if (found == true)		// 삭제하고자 하는 값을 찾으면
		return 1;			// 1 리턴
	else					// 못 찾으면
		return 0;			// 0 리턴
}

// list에서 item과 일치하는 원소 교체
template<typename T>
int LinkedList<T>::Replace(T& item)
{
	NodeType<T>* loc;		// node pointer 변수 선언

	loc = m_List;			
	bool MoreToSearch = (loc != nullptr);
	bool found = false;

	while (MoreToSearch && !found)		// list의 끝이 아니면서 찾지 못했을 경우
	{
		if (item == loc->info)			// 일치하는 항목을 찾았을 경우
		{
			loc->info = item;			// 해당 pointer가 가르키는 값을 item으로 변경
			found = true;				// while문 빠져나가기 위해 값 변경
		}
		else							// 찾지 못했을 경우
		{
			loc = loc->next;			// pointer를 다음을 가르키도록 지시
			MoreToSearch = (m_CurPointer != nullptr);		// list의 끝인지 검사
		}
	}

	if (found == true)		// 교체하고자 하는 값을 찾았을 경우
		return 1;			// 1 리턴
	else					// 못 찾았을 경우
		return 0;			// 0 리턴
}

// list에서 item과 일치하는 원소를 찾으면 1, 아니면 0 리턴
template<typename T>
int LinkedList<T>::Get(T& item)
{
	NodeType<T>* loc;		// node pointer 변수 선언

	loc = m_List;
	bool MoreToSearch = (loc != NULL);
	bool found = false;

	while (MoreToSearch && !found)		// list의 끝이 아니고 찾지 못했을 경우
	{
		if (item == loc->info)			// 일치하는 항목 찾았을 경우
		{
			item = loc->info;			// item을 pointer가 가르키는 값으로 변경
			found = true;				// while문 나가기 위해 값 변경
		}
		else							// 찾지 못했을 경우
		{
			loc = loc->next;			// pointer를 다음을 가르키도록 지시
			MoreToSearch = (loc != nullptr);	// list의 끝인지 검사
		}
	}

	if (found == true)		// 찾았을 경우
		return 1;			// 1 리턴
	else					// 못 찾았을 경우
		return 0;			// 0 리턴
}

// m_CurPointer를 nullptr로 초기화
template<typename T>
void LinkedList<T>::ResetList()
{
	m_CurPointer = nullptr;
}

// list에서 다음 항목을 가져옴.
template<typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	if (m_CurPointer == nullptr)		// 현재 포인터가 nullptr이면 list의 첫 node를 가르킨다
	{
		m_CurPointer = m_List;
	}
	else				// 현재 포인터가 nullptr이 아니면
		m_CurPointer = m_CurPointer->next;	// 현재 포인터를 다음을 가르키도록 설정

	if (m_CurPointer == nullptr)		// 현재 포인터가 nullptr이면 1 리턴
		return -1;
	else								// 현재 포인터가 nullptr이 아니면
		item = m_CurPointer->info;		// item값에 현재 포인터의 info값 대입

	return 0;
}
#pragma once

template<typename T>
struct NodeType
{
	T info;			// ������ node�� ����� ����
	NodeType* next = nullptr;	// ���ӵ� ������ node�� ����Ŵ
	void operator=(const NodeType<T>& _p)
	{
		info = _p.info;
	}
};

template<typename T>
class LinkedList
{
private:
	NodeType<T> *m_List;		// ù ��° ��� ����Ŵ
	NodeType<T> *m_CurPointer;	// ���� ����Ű�� ���
	int m_Length;				// list�� �ִ� node�� ����

public:
	LinkedList();		// LinkedList ������
	~LinkedList();		// LinkedList �Ҹ���

	// =������ �����ε�
	void operator=(LinkedList<T> & _p)
	{
		MakeEmpty();		// ���� node �ʱ�ȭ
		if (_p.GetLength())	// _p�� node�� ���� ���
		{
			_p.ResetList();	// _p�� m_CurPointer�� NULL�� �ʱ�ȭ
			T item;
			while (_p.GetNextItem(item) == 0)	// m_CurPointer�� NULL�� ����
				Add(item);						// item�� �߰�
		}
	}

	void MakeEmpty();			// list�� ���
	int GetLength() const;		// m_Length ����
	int Add(T& item);			// list�� item ���� �߰�
	int Delete(T& item);		// list���� item�� ��ġ�ϴ� ���� ����
	int Replace(T& item);		// list���� item�� ��ġ�ϴ� ���� ��ü
	int Get(T& item);			// list���� item�� ��ġ�ϴ� ���Ҹ� ã���� 1, �ƴϸ� 0 ����
	void ResetList();			// m_CurPointer�� NULL�� �ʱ�ȭ
	int GetNextItem(T& item);	// list���� ���� �׸��� ������.
};

// LinkedList ������
template<typename T>
LinkedList<T>::LinkedList()
{
	m_List = nullptr;
	m_CurPointer = nullptr;
	m_Length = 0;
}

// LinkedList �Ҹ���
template<typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty();
}

// list�� ���
template<typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T>* temptr;
	while (m_List != NULL)
	{
		temptr = m_List;
		m_List = m_List->next;
		delete temptr;		// list�� ��� node�� ����
	}

	m_Length = 0;	// list�� length�� 0���� �ʱ�ȭ
}

// m_Length ����
template<typename T>
int LinkedList<T>::GetLength() const
{
	return m_Length;
}

// list�� item ���� �߰�
template<typename T>
int LinkedList<T>::Add(T& item)
{
	ResetList();	// list �ʱ�ȭ

	NodeType<T> *node = new NodeType<T>;	// list�� �߰��� node pointer
	NodeType<T> *preloc;					// �߰��� �ڸ� ������ node�� ����Ű�� pointer
	T temp;

	node->info = item;			// node�� �Է¹��� data ����
	node->next = nullptr;			// ���� node�� NULL�� �ʱ�ȭ

	if (!m_Length)		// list�� node�� ���� ���
	{
		m_List = node;	// ó���� �߰�
		m_Length++;		// list�� ���� 1 ����
		return 1;		// 1 ����
	}
	else				// list�� node�� ���� ���
	{
		if (Get(item) == 1)	// �ش� item�� �̹� list�� ���� ���
			return 0;		// 0 ����
		else				// item�� list�� ���� ���
		{
			while (true)
			{
				preloc = m_CurPointer;		// ���� node�� ����Ű�� pointer�� m_CurPointer�� ����
				GetNextItem(temp);			// node pointer ����
				if (m_CurPointer->info > node->info)	// node�� ����Ű�� data�� ���� node�� ����Ű�� data���� ���� ��
				{
					if (preloc == NULL)			// ���� �ڸ� ������ ���Ұ� �������� ���� ���
					{
						node->next = m_CurPointer;	// node�� ������ m_CurPointer�� ����
						m_List = node;				// ó�� �ڸ��� ����
						break;
					}
					else								// node�� ����Ű�� data�� ���� node�� ����Ű�� data���� Ŭ ��
					{
						node->next = m_CurPointer;		// node�� ������ m_CurPointer�� ����
						preloc->next = node;			// ����node�� ������ ����
						break;
					}
				}
				if (m_CurPointer->next == NULL)			// node pointer�� ������ node�� ����Ű��
				{
					m_CurPointer->next = node;			// �� ���� �ڸ��� node ����
					break;
				}
			}
		}
	}
	m_Length++;
	return 1;
}

// list���� item�� ��ġ�ϴ� ���� ����
template<typename T>
int LinkedList<T>::Delete(T& item)
{
	NodeType<T>* preloc = nullptr;		// ���ο� node pointer ����

	m_CurPointer = m_List;
	bool MoreToSearch = (m_CurPointer != nullptr);
	bool found = false;

	while (MoreToSearch && !found)		// list�� ���� �ƴϸ鼭 ã�� ������ ���
	{
		if (item == m_CurPointer->info)		// ���� pointer�� info�� ã������ ���� ��ġ�� ���
		{
			found = true;				// found�� true�� ����
			if (preloc == nullptr)		// ���� pointer ������ �ٸ� �׸��� ���� ���
				m_List = m_CurPointer->next;	// ���� pointer ���� ���� list�� ó�� ���ҷ� ����
			else		// ���� pointer ������ �ٸ� �׸��� ���� ���
			{
				preloc->next = m_CurPointer->next;	// ���� pointer�� ���� pointer�� ���� pointer�� �������� ����
				delete m_CurPointer;		// ���� pointer ����
			}
			m_Length--;		// �׸��� �ϳ� �������Ƿ� ���� -1
		}
		else			// ��ġ���� ���� ���
		{
			preloc = m_CurPointer;	// ���� pointer�� ���� pointer�� ����Ű���� ����
			m_CurPointer = m_CurPointer->next;	// ���� pointer�� ������ ����Ű���� ����
			MoreToSearch = (m_CurPointer != nullptr);	// list�� ������ �˻�
		}
	}

	if (found == true)		// �����ϰ��� �ϴ� ���� ã����
		return 1;			// 1 ����
	else					// �� ã����
		return 0;			// 0 ����
}

// list���� item�� ��ġ�ϴ� ���� ��ü
template<typename T>
int LinkedList<T>::Replace(T& item)
{
	NodeType<T>* loc;		// node pointer ���� ����

	loc = m_List;			
	bool MoreToSearch = (loc != nullptr);
	bool found = false;

	while (MoreToSearch && !found)		// list�� ���� �ƴϸ鼭 ã�� ������ ���
	{
		if (item == loc->info)			// ��ġ�ϴ� �׸��� ã���� ���
		{
			loc->info = item;			// �ش� pointer�� ����Ű�� ���� item���� ����
			found = true;				// while�� ���������� ���� �� ����
		}
		else							// ã�� ������ ���
		{
			loc = loc->next;			// pointer�� ������ ����Ű���� ����
			MoreToSearch = (m_CurPointer != nullptr);		// list�� ������ �˻�
		}
	}

	if (found == true)		// ��ü�ϰ��� �ϴ� ���� ã���� ���
		return 1;			// 1 ����
	else					// �� ã���� ���
		return 0;			// 0 ����
}

// list���� item�� ��ġ�ϴ� ���Ҹ� ã���� 1, �ƴϸ� 0 ����
template<typename T>
int LinkedList<T>::Get(T& item)
{
	NodeType<T>* loc;		// node pointer ���� ����

	loc = m_List;
	bool MoreToSearch = (loc != NULL);
	bool found = false;

	while (MoreToSearch && !found)		// list�� ���� �ƴϰ� ã�� ������ ���
	{
		if (item == loc->info)			// ��ġ�ϴ� �׸� ã���� ���
		{
			item = loc->info;			// item�� pointer�� ����Ű�� ������ ����
			found = true;				// while�� ������ ���� �� ����
		}
		else							// ã�� ������ ���
		{
			loc = loc->next;			// pointer�� ������ ����Ű���� ����
			MoreToSearch = (loc != nullptr);	// list�� ������ �˻�
		}
	}

	if (found == true)		// ã���� ���
		return 1;			// 1 ����
	else					// �� ã���� ���
		return 0;			// 0 ����
}

// m_CurPointer�� nullptr�� �ʱ�ȭ
template<typename T>
void LinkedList<T>::ResetList()
{
	m_CurPointer = nullptr;
}

// list���� ���� �׸��� ������.
template<typename T>
int LinkedList<T>::GetNextItem(T& item)
{
	if (m_CurPointer == nullptr)		// ���� �����Ͱ� nullptr�̸� list�� ù node�� ����Ų��
	{
		m_CurPointer = m_List;
	}
	else				// ���� �����Ͱ� nullptr�� �ƴϸ�
		m_CurPointer = m_CurPointer->next;	// ���� �����͸� ������ ����Ű���� ����

	if (m_CurPointer == nullptr)		// ���� �����Ͱ� nullptr�̸� 1 ����
		return -1;
	else								// ���� �����Ͱ� nullptr�� �ƴϸ�
		item = m_CurPointer->info;		// item���� ���� �������� info�� ����

	return 0;
}
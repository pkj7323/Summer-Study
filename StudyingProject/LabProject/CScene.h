#pragma once

// ���� ����  : Ŭ������ ���� �ϰ� ������ ���߿� �Ѵ�.
// �����Ϸ� �ӵ��� �������� ���� �����ϱ����� ����Ѵ�.
// ���� ������ Ŭ������ ����ǵ� �������� �ٽ��� �ʿ䰡 ����.
class CObject;
class CScene
{
public:
	CScene();
	virtual ~CScene();	//�׷��� �Ҹ��ڴ� �����Լ��� �������Ѵ�. ���� �Լ��� ����� �ڽ� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�.
	//��? -> �ڽ� Ŭ������ �Ҹ��ڸ� ȣ�� ���� �� �θ� Ŭ������ �Ҹ��ڰ� ȣ����� �ʴ´�. �׷��� �����Լ��� �������Ѵ�.

	virtual void Enter() = 0;
	virtual	void Exit() = 0;	//���� �����Լ��� ���� ��ӹ��� Ŭ�������� �����ϵ��� �Ѵ�.
	
	virtual void Update(); //������Ʈ�� ������ �ʿ伺�� ���� ���� �ִ�.
	void Render(HDC hDC);	//�������� ������ �ʿ伺�� ���� ���� �ִ�.

	

	inline void SetName(const wstring& strName) { m_strName = strName; }
	const wstring& GetName() { return m_strName; }
protected:
	template<typename T>
	T* AddObject(GROUP_TYPE eGroupType) {
		T* pObj = new T;
		m_vecObj[static_cast<UINT>(eGroupType)].push_back(pObj);
		return dynamic_cast<T*>(m_vecObj[static_cast<UINT>(eGroupType)].back());
	}

	void DeleteObject(GROUP_TYPE eGroupType);
private:
	vector<CObject*>	m_vecObj[static_cast<UINT>(GROUP_TYPE::END)];//32���� �迭�� �����.
	//2���� �迭ó�� �������� �迭�� ���� ������ 2���� �迭ó�� ����Ǿ� ���� �ʴ�.
	//�׷�Ÿ�Կ� �´� ������Ʈ�� �߰��ϱ� ���� ����Ѵ�. �⺻�� 32�� �̹Ƿ� 32���� �迭�� �����.
	wstring				m_strName;
};


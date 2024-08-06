#pragma once

// ���� ����  : Ŭ������ ���� �ϰ� ������ ���߿� �Ѵ�.
// �����Ϸ� �ӵ��� �������� ���� �����ϱ����� ����Ѵ�.
// ���� ������ Ŭ������ ����ǵ� �������� �ٽ��� �ʿ䰡 ����.
class CObject;
class Missile;
class CScene
{
public:
	CScene();
	virtual ~CScene();	//�׷��� �Ҹ��ڴ� �����Լ��� �������Ѵ�. ���� �Լ��� ����� �ڽ� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�.
	//��? -> �ڽ� Ŭ������ �Ҹ��ڸ� ȣ�� ���� �� �θ� Ŭ������ �Ҹ��ڰ� ȣ����� �ʴ´�. �׷��� �����Լ��� �������Ѵ�.

	virtual void Enter() = 0;
	virtual	void Exit() = 0;	//���� �����Լ��� ���� ��ӹ��� Ŭ�������� �����ϵ��� �Ѵ�.
	
	void Update(); //������Ʈ�� ������ �ʿ伺�� ���� ���� �ִ�.
	void Render(HDC hDC);	//�������� ������ �ʿ伺�� ���� ���� �ִ�.

	void Shoot(Vec2 pos, float damage, float speed, Vec2 Dir);
	
	
	vector<CObject*>& GetObjectArr(GROUP_TYPE eGroupType) { return m_vecObj[static_cast<UINT>(eGroupType)]; }

	inline void SetName(const wstring& strName) { m_strName = strName; }
	const wstring& GetName() { return m_strName; }
protected:
	template<typename T>
	T* AddObject(GROUP_TYPE eGroupType)
	{
		T* pObj = new T;
		pObj->SetGroupType(eGroupType);
		m_vecObj[static_cast<UINT>(eGroupType)].push_back(pObj);
		return dynamic_cast<T*>(m_vecObj[static_cast<UINT>(eGroupType)].back());
	}

	void DeleteObject();
	
private:
	vector<CObject*>	m_vecObj[static_cast<UINT>(GROUP_TYPE::END)];//32���� �迭�� �����.
	//2���� �迭ó�� �������� �迭�� ���� ������ 2���� �迭ó�� ����Ǿ� ���� �ʴ�.
	//�׷�Ÿ�Կ� �´� ������Ʈ�� �߰��ϱ� ���� ����Ѵ�. �⺻�� 32�� �̹Ƿ� 32���� �迭�� �����.
	wstring				m_strName;
};



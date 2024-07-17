#pragma once

// ���� ����  : Ŭ������ ���� �ϰ� ������ ���߿� �Ѵ�.
// �����Ϸ� �ӵ��� �������� ���� �����ϱ����� ����Ѵ�.
// ���� ������ Ŭ������ ����ǵ� �������� �ٽ��� �ʿ䰡 ����.
class CObject;
class CScene
{
public:
	CScene();
	~CScene();

	virtual void Enter() = 0;
	virtual	void Exit() = 0;//���� �����Լ��� ���� ��ӹ��� Ŭ�������� �����ϵ��� �Ѵ�.
	virtual void Update();
	virtual void Render(HDC hDC);

	inline void SetName(const wstring& strName) { m_strName = strName; }
	wstring GetName() { return m_strName; }
private:
	vector<CObject*>	m_vecObj[static_cast<UINT>(GROUP_TYPE::END)];//32���� �迭�� �����.
	//2���� �迭ó�� �������� �迭�� ���� ������ 2���� �迭ó�� ����Ǿ� ���� �ʴ�.
	//�׷�Ÿ�Կ� �´� ������Ʈ�� �߰��ϱ� ���� ����Ѵ�. �⺻�� 32�� �̹Ƿ� 32���� �迭�� �����.
	wstring				m_strName;
};


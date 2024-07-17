#pragma once

// 전방 선언  : 클래스의 선언만 하고 구현은 나중에 한다.
// 컴파일러 속도가 느려지는 것을 방지하기위해 사용한다.
// 전방 선언한 클래스가 변경되도 컴파일을 다시할 필요가 없다.
class CObject;
class CScene
{
public:
	CScene();
	~CScene();

	virtual void Enter() = 0;
	virtual	void Exit() = 0;//순수 가상함수로 만들어서 상속받은 클래스에서 구현하도록 한다.
	virtual void Update();
	virtual void Render(HDC hDC);

	inline void SetName(const wstring& strName) { m_strName = strName; }
	wstring GetName() { return m_strName; }
private:
	vector<CObject*>	m_vecObj[static_cast<UINT>(GROUP_TYPE::END)];//32개의 배열을 만든다.
	//2차원 배열처럼 여러개의 배열이 생성 되지만 2차원 배열처럼 연결되어 있지 않다.
	//그룹타입에 맞는 오브젝트를 추가하기 위해 사용한다. 기본이 32개 이므로 32개의 배열을 만든다.
	wstring				m_strName;
};


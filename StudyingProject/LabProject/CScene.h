#pragma once

// 전방 선언  : 클래스의 선언만 하고 구현은 나중에 한다.
// 컴파일러 속도가 느려지는 것을 방지하기위해 사용한다.
// 전방 선언한 클래스가 변경되도 컴파일을 다시할 필요가 없다.
class CObject;
class CScene
{
public:
	CScene();
	virtual ~CScene();	//그러나 소멸자는 가상함수로 만들어야한다. 가상 함수로 만들면 자식 클래스의 소멸자가 호출된다.
	//왜? -> 자식 클래스가 소멸자를 호출 햇을 때 부모 클래스의 소멸자가 호출되지 않는다. 그래서 가상함수로 만들어야한다.

	virtual void Enter() = 0;
	virtual	void Exit() = 0;	//순수 가상함수로 만들어서 상속받은 클래스에서 구현하도록 한다.
	
	virtual void Update(); //업데이트를 강제할 필요성이 없을 수도 있다.
	void Render(HDC hDC);	//렌더링을 강제할 필요성이 없을 수도 있다.

	

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
	vector<CObject*>	m_vecObj[static_cast<UINT>(GROUP_TYPE::END)];//32개의 배열을 만든다.
	//2차원 배열처럼 여러개의 배열이 생성 되지만 2차원 배열처럼 연결되어 있지 않다.
	//그룹타입에 맞는 오브젝트를 추가하기 위해 사용한다. 기본이 32개 이므로 32개의 배열을 만든다.
	wstring				m_strName;
};


#pragma once
class CObject;
class CComponent
{
public:
	CComponent(ComponentType _ComponentType);
	virtual ~CComponent();
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC hDC);

	void SetOwner(CObject* pOwner) { this->m_pOwner = pOwner; }
	CObject* GetOwner() const { return m_pOwner; }


	ComponentType GetComponentType() const { return m_eComponentType; }

private:
	CObject*		m_pOwner;
	ComponentType	m_eComponentType;
};


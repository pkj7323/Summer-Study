#pragma once
class CComponent;
class CObject
{

public:
	CObject();
	~CObject();

	template <typename T>
	T* AddComponent(ComponentType eGroupType)
	{
		T* pComponent = new T;
		pComponent->SetOwner(this);
		m_vecComponents.at(static_cast<UINT>(pComponent->GetComponentType())) = pComponent;
		pComponent->Init();
		return pComponent;
	}
	template <typename T>
	T* GetComponent(ComponentType eGroupType)
	{
		T* comp = nullptr;
		for (auto component : m_vecComponents )
		{
			comp = dynamic_cast<T*>(component);
			if (comp) break;
		}
		return  comp;
		
	}

	Vec2 GetPos() { return vPos; }
	void SetPos(Vec2 Pos) { this->vPos = Pos; }

	Vec2 GetScale() { return vScale; }
	void SetScale(Vec2 scale) { this->vScale = scale; }
	
	virtual void Update();
	virtual void Render(HDC hDC);

	virtual void SetIsDead(bool isDead) { bDead = isDead; }
	virtual bool GetIsDead() { return bDead; }

	virtual void SetGroupType(GROUP_TYPE eGroupType) { this->eGroupType = eGroupType; }
	virtual GROUP_TYPE GetGroupType() { return eGroupType; }

	virtual void SetDamage(float damage) { bDamage = damage; }
	virtual float GetDamage() { return bDamage; }
private:
	vector<CComponent*> m_vecComponents;
	Vec2				vPos;
	Vec2				vScale;
	bool				bDead;
	float				bDamage;
	GROUP_TYPE			eGroupType;
};


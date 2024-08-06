#pragma once
class CObject
{
private:
	Vec2	vPos;
	Vec2	vScale;
	bool	bDead;
public:
	CObject();
	~CObject();

	Vec2 GetPos() { return vPos; }
	void SetPos(Vec2 Pos) { this->vPos = Pos; }

	Vec2 GetScale() { return vScale; }
	void SetScale(Vec2 scale) { this->vScale = scale; }
	
	virtual void Update() = 0;
	virtual void Render(HDC hDC);

	virtual void SetIsDead(bool isDead) { bDead = isDead; }
	virtual bool GetIsDead() { return bDead; }
};


#pragma once
class CObject
{
private:
	Vec2	vPos;
	Vec2	vScale;
public:
	CObject();
	~CObject();

	Vec2 GetPos() { return vPos; }
	void SetPos(Vec2 Pos) { this->vPos = Pos; }

	Vec2 GetSacle() { return vScale; }
	void SetScale(Vec2 scale) { this->vScale = scale; }
	
	virtual void Update();
	virtual void Render(HDC hDC);
};


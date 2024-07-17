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
	void setPos(Vec2 Pos) { this->vPos = Pos; }

	Vec2 GetSacle() { return vScale; }
	void setScale(Vec2 scale) { this->vScale = scale; }
};


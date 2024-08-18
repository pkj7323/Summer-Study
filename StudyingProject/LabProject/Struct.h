#include <cmath>
struct Vec2 {
	float x, y;

	Vec2() : x{ 0.f }, y{ 0.f } {}
	Vec2(int x, int y) : x{ static_cast<float>(x) }, y{ static_cast<float>(y) } {}
	Vec2(float x, float y) : x{ x }, y{ y } {}
	Vec2(double x, double y) : x{ static_cast<float>(x) }, y{ static_cast<float>(y) } {}
	Vec2(const POINT& other)
		: x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) } {}
	Vec2& operator=(const POINT& other) {
		x = static_cast<float>(other.x);
		y = static_cast<float>(other.y);
	}
	Vec2& operator+=(const Vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	bool operator==(const Vec2& other) {
		if (x == other.x && y == other.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Normalize() {
		if (x == 0 && y == 0)
		{
			return;
		}
		float absSize = sqrtf(x * x + y * y);
		x /= absSize;
		y /= absSize;
	}
	void Rotate(float angle) {
		float radian = angle * PI / 180.f;
		float cosTheta = cosf(radian);
		float sinTheta = sinf(radian);
		float tempX = x;
		x = x * cosTheta - y * sinTheta;
		y = tempX * sinTheta + y * cosTheta;
	}
	//벡터의 정규화 만들고 그거 이용해서 미사일 만들어오기
	//절대경로, 상대경로 알아오기
};
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
	//벡터의 정규화 만들고 그거 이용해서 미사일 만들어오기
	//절대경로, 상대경로 알아오기
};
#pragma once

enum class KEY_STATE {
	NONE,
	TAP,
	HOLD,
	AWAY
};
enum class KEY {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	ENTER,
	ESC,
	ALT,
	Q,
	W,
	E,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	R,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	LSHIFT,
	END,

	LAST
};

struct KeyInfo
{
	KEY_STATE	state;
	bool		prev;
};


class KeyMgr
{
	SINGLE(KeyMgr);
public:
	void Init();
	void Update();

	KEY_STATE GetKeyState(KEY key) { return vecKey[(int)key].state; }
private:
	vector<KeyInfo>		vecKey;
};


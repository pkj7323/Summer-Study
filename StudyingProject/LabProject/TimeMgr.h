#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void	Init();
	void	Update();
	void	Render();

	double	GetDeltaTime() { return dDT; }
	float	GetDeltaTimeF() { return (float)dDT; }
private:
	LARGE_INTEGER	curCount;	//현재 시간
	LARGE_INTEGER	prevCount;	//이전 시간	
	LARGE_INTEGER	preQuency;	//성능 카운터가 초당 몇번 진행 되는지
	double			dDT;		//(delta time)현재시간 - 이전시간 차이를 구해서 시스템 성능 카운터의 주파수를 나눠서 계산
	double			dAcc;		//누적 시간 : 1초를 초과하면 fps초기화
	UINT			iFPS;		//frame per second : 1초당 업데이트 호출 횟수
	UINT			iCallCount;	//update 호출 횟수


};


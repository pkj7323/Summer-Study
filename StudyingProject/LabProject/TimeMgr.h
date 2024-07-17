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
	LARGE_INTEGER	curCount;	//���� �ð�
	LARGE_INTEGER	prevCount;	//���� �ð�	
	LARGE_INTEGER	preQuency;	//���� ī���Ͱ� �ʴ� ��� ���� �Ǵ���
	double			dDT;		//(delta time)����ð� - �����ð� ���̸� ���ؼ� �ý��� ���� ī������ ���ļ��� ������ ���
	double			dAcc;		//���� �ð� : 1�ʸ� �ʰ��ϸ� fps�ʱ�ȭ
	UINT			iFPS;		//frame per second : 1�ʴ� ������Ʈ ȣ�� Ƚ��
	UINT			iCallCount;	//update ȣ�� Ƚ��


};


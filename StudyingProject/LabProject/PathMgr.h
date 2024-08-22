#pragma once
class PathMgr
{
	SINGLE(PathMgr);
public:
	void Init();

	const wstring& GetPath() { return m_Paths; }
private:
	wstring	 m_Paths;
};


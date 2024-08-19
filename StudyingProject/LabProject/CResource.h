#pragma once
class CResource
{
public:
	CResource(const ResourceType& _Type);
	virtual ~CResource();

	virtual HRESULT Load(const wstring& _path) = 0;

	void SetPath(const wstring& path) { m_Path = path; }
	const wstring& GetPath() const { return m_Path; }

private:
	wstring			m_Path;
	ResourceType	m_Type;
};


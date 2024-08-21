#pragma once
class CResource
{
public:
	CResource(const ResourceType& _Type);
	virtual ~CResource();

	virtual HRESULT Load(const wstring& _path) = 0;

	void SetPath(const wstring& path) { m_Path = path; }
	const wstring& GetPath() const { return m_Path; }

	void SetKey(const wstring& _Key) { m_Key = _Key; }
	const wstring& GetKey() const { return m_Key; }
private:
	wstring			m_Key;
	wstring			m_Path;
	ResourceType	m_Type;
};


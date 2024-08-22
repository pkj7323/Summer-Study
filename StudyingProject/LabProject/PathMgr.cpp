#include "pch.h"
#include "PathMgr.h"
#include <filesystem>
PathMgr::PathMgr()
{
}
PathMgr::~PathMgr()
{
	

}

void PathMgr::Init()
{
	std::filesystem::path path = std::filesystem::current_path();
	m_Paths = path.wstring();
	m_Paths += L"\\Contents\\";
}

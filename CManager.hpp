#pragma once

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>
#include <regex>


#include "CAuthor.hpp"
#include "tools.hpp"

class CManager
{
public:
	CManager() = default;
	CManager(const CManager&) = delete;
	~CManager() = default;

	static void Initialize();
	static void HandlingMessage(bool& status, std::string& msg);

private:
	static std::vector<CAuthor> authorList;
};
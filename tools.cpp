#include "tools.hpp"


std::vector<std::string> split(std::string str, const std::string& delimiter)
{
	std::vector<std::string> splited;
	std::size_t npos;

	while ((npos = str.find(delimiter)) != std::string::npos)
	{
		std::string token = str.substr(0, npos);
		splited.push_back(token);
		str.erase(0, npos + delimiter.length());
	}
	splited.push_back(str);

	return splited;
}
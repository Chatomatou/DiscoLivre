#include "CAuthor.hpp"
#include "CManager.hpp"
#include "tools.hpp" 

int main()
{
	CManager::Initialize();

	bool status = true;
	std::string buffer;
 
	while (status)
	{
		std::cout << "> ";
		std::getline(std::cin, buffer);

		CManager::HandlingMessage(status, buffer);
	}


	return 0;
}
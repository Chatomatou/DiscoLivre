#include "CManager.hpp"

std::vector<CAuthor> CManager::authorList;


void CManager::Initialize()
{
	std::cout << "=======================" << std::endl;
	std::cout << "=WELCOME TO DiscoLivre=" << std::endl;
	std::cout << "=======================" << std::endl;

	std::cout << "This program records information about the works of art of an author." << std::endl;
	std::cout << "Type help for listing all the commands available in this program." << std::endl;

	std::ifstream file{ "save.txt" };

	if (!file)
	{
		std::cerr << "Error : Connot open save.txt" << std::endl;
		return;
	}

	std::string buffer;
 
	for (auto j = 0; std::getline(file, buffer); j ++)
	{
		std::vector<std::string> data = split(buffer, ";");

		for (std::size_t i = 0; i < data.size(); i++)
		{
			if (i == 0)
			{
				std::vector<std::string> author_info = split(data[0], " ");
				authorList.push_back({ author_info[0], author_info[1], author_info[2] });
			}
			else
			{
				std::vector<std::string> artwork_info = split(data[i], " ");
				Project::Type type;

				if (artwork_info[0] != "END")
				{
					if (artwork_info[0] == "BOOK")
						type = Project::Type::BOOK;
					if (artwork_info[0] == "MUSIC")
						type = Project::Type::MUSIC;

					authorList[j].addArtwork({ type, artwork_info[1], artwork_info[2], artwork_info[3] });
				}
 			}
		}
 	}
}

void CManager::HandlingMessage(bool& status, std::string& msg)
{
	std::transform(std::begin(msg), std::end(msg), std::begin(msg), [](unsigned char c) {return std::tolower(c); });

	if (msg == "exit")
	{
		status = !status;
	 
		std::ofstream file{ "save.txt" };

		if (!file)
		{
			std::cerr << "Error : Connot open save.txt" << std::endl;
		}
		
		for (CAuthor& author : authorList)
		{
			file << author.getFirstname() << " " << author.getLastname() << " " << author.getBirthdate() << ";";

			for (const CArtwork& artwork : author.getArtworksList())
			{
				if(artwork.getType() == Project::Type::MUSIC)
					file << "MUSIC" << " ";
				if (artwork.getType() == Project::Type::BOOK)
					file << "BOOK" << " ";
				file << artwork.getName() << " " << artwork.getRelease() << " " << artwork.getDescription() << ";";
 			}
			file << "END" << "\n";
		}

 	}
 	else if (msg == "help")
	{
		std::ifstream file{ "help.txt" };
		std::stringstream buffer;

		buffer << file.rdbuf();

		std::cout << buffer.str() << std::endl;
	}
	else if (msg == "create author")
	{
		CAuthor author;
		std::unordered_map<std::string, std::string> author_info{
			{"[+] Enter a firstname", ""}, 
			{"[+] Enter a lastname", ""},
			{"[+] Enter a birthdate", ""}
		};
 

		for (std::pair<std::string, std::string> pair : author_info)
		{
			std::cout << pair.first << " => ";
			std::getline(std::cin, pair.second);

			author_info[pair.first] = pair.second;
		}
		
		author.setFirstname(author_info["[+] Enter a firstname"]);
		author.setLastname(author_info["[+] Enter a lastname"]);
		author.setBirthdate(author_info["[+] Enter a lastname"]);

		authorList.push_back(author);
	}
	else if (msg == "display authors")
	{
		std::cout << "Listing of differents authors existing in your data list : " << std::endl;
		for (const CAuthor& author : authorList)
		{
			std::cout << "firstname => " << author.getFirstname() << std::endl;
			std::cout << "lastname => " << author.getLastname() << std::endl;
			std::cout << "birthday => " << author.getBirthdate() << std::endl;
			std::cout << std::endl;
		}
	}
	else if (msg == "display all contents")
	{
		for (CAuthor author : authorList)
		{
			std::cout << "firstname => " << author.getFirstname() << std::endl;
			std::cout << "lastname => " << author.getLastname() << std::endl;
			std::cout << "birthday => " << author.getBirthdate() << std::endl;
			std::cout << std::endl;

			for (const CArtwork& artwork : author.getArtworksList())
			{
				
				if (artwork.getType() == Project::Type::MUSIC)
					std::cout << "\t-> TYPE : MUSIC" << std::endl;
				if (artwork.getType() == Project::Type::BOOK)
					std::cout << "\t-> TYPE : BOOK" << std::endl;

				std::cout << "\t-> NAME : " << artwork.getName() << std::endl;
				std::cout << "\t-> RELEASE : " << artwork.getRelease() << std::endl;
				std::cout << "\t-> DESCRIPTION : " << artwork.getDescription() << std::endl;

				std::cout << std::endl;
			}
 		}
	}
	else if (std::regex_search(msg, std::regex{"push artwork (.)"}))
	{
		std::vector<std::string> splited = split(msg, " ");

		if(splited.size() != 4)
			std::cerr << "Error : '" << msg << " is unknow command." << std::endl;
		else
		{
			bool exists = false;
			int index = -1;

 
			for (std::size_t i = 0; i < authorList.size(); i++)
			{
				std::string firstname = authorList[i].getFirstname();
				std::string lastname = authorList[i].getLastname();
  
				std::transform(std::begin(firstname), std::end(firstname), std::begin(firstname), [](unsigned char c) {return std::tolower(c); });
				std::transform(std::begin(lastname), std::end(lastname), std::begin(lastname), [](unsigned char c) {return std::tolower(c); });

				if (firstname == splited[2] && lastname == splited[3])
				{
					index = i;
					i = authorList.size();
 				}
			}
			std::cout << index << std::endl;
			if (index != -1)
			{
				CArtwork artwork;
				std::unordered_map<std::string, std::string> artwork_info{
					{"[+] Enter a type", ""},
					{"[+] Enter a name", ""},
					{"[+] Enter a release", ""},
					{"[+] Enter a description", ""}
				};


				for (std::pair<std::string, std::string> pair : artwork_info)
				{
					std::cout << pair.first << " => ";
					std::getline(std::cin, pair.second);

					std::replace(pair.second.begin(), pair.second.end(), ' ', '_');
					artwork_info[pair.first] = pair.second;
				}

				if (artwork_info["[+] Enter a type"] == "BOOK")
					artwork.setType(Project::Type::BOOK);
				if (artwork_info["[+] Enter a type"] == "MUSIC")
					artwork.setType(Project::Type::BOOK);

				artwork.setName(artwork_info["[+] Enter a name"]);
				artwork.setRelease(artwork_info["[+] Enter a release"]);
				artwork.setDescription(artwork_info["[+] Enter a description"]);

				authorList[index].addArtwork(artwork);
			}
			else
			{
				std::cerr << "Error : " << msg << " unknow author." << std::endl;
			}
 
		}
	}
	else
		std::cerr << "Error : '" << msg << " is unknow command." << std::endl;
}
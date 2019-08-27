#include "CAuthor.hpp"

 
CAuthor::CAuthor(const std::string& firstname, const std::string& lastname, const std::string& birthdate) :
	m_firstname{ firstname },
	m_lastname{lastname},
	m_birthdate{birthdate}
{

}

void CAuthor::setFirstname(const std::string& firstname)
{
	m_firstname = firstname;
}
void CAuthor::setLastname(const std::string& lastname)
{
	m_lastname = lastname;
}
void CAuthor::setBirthdate(const std::string& birthdate)
{
	m_birthdate = birthdate;
}

std::vector<CArtwork> CAuthor::getArtworksList()
{
	return m_artworks;
}
std::string CAuthor::getFirstname() const
{
	return m_firstname;
}
std::string CAuthor::getLastname() const
{
	return m_lastname;
}
std::string CAuthor::getBirthdate() const
{
	return m_birthdate;
}

void CAuthor::addArtwork(const CArtwork& artwork)
{
	m_artworks.push_back(artwork);
}

void CAuthor::show_author()
{
	std::cout << "================================" << std::endl;
	std::cout << "=          AUTHOR INFO         =" << std::endl;
	std::cout << "================================" << std::endl;

	std::cout << "-\t" << std::endl;
	std::cout << "\t\t" << m_firstname << std::endl;
	std::cout << "\t\t" << m_lastname << std::endl;
	std::cout << "\t\t" << m_birthdate << std::endl;
	std::cout << std::endl;
	std::cout << "| THE AUTHOR INFO ARE PRINT IN THE SCREEN |" << std::endl;	
}

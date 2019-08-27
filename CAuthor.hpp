#pragma once

#include <iostream>
#include <string>
#include <vector>
 
#include "CArtwork.hpp"
 

class CAuthor
{
public:
	CAuthor() = default;
	CAuthor(const std::string& firstname, const std::string& lastname, const std::string& birthdate);
	~CAuthor() = default;
 
	void setFirstname(const std::string& firstname);
	void setLastname(const std::string& lastname);
	void setBirthdate(const std::string& birthdate);
	
	std::vector<CArtwork> getArtworksList();
	std::string getFirstname() const;
	std::string getLastname() const;
	std::string getBirthdate() const;

	void addArtwork(const CArtwork& artwork);

	void show_author();

private:
	std::vector<CArtwork> m_artworks;
	std::string m_firstname;
	std::string m_lastname;
	std::string m_birthdate;
};
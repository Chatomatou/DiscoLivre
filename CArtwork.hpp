#pragma once

#include <iostream>
#include <string>
#include "EProject.hpp"


class CArtwork 
{
public:
	CArtwork() = default;
	CArtwork(const Project::Type& type, const std::string& name, const std::string& release, const std::string& description);
	~CArtwork() = default;

	void setType(Project::Type type);
	void setName(const std::string& name);
	void setRelease(const std::string& release);
	void setDescription(const std::string& description);


	Project::Type getType() const;
	std::string getName() const;
	std::string getRelease() const;
	std::string getDescription() const;
 
private:
	Project::Type m_type;
	std::string m_name;
	std::string m_release;
	std::string m_description;
};
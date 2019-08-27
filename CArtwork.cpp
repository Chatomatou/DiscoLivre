#include "CArtwork.hpp"


CArtwork::CArtwork(const Project::Type& type, const std::string& name, const std::string& release, const std::string& description) :
	m_type{ type },
	m_name{name},
	m_release{release},
	m_description{description}
{

}


void CArtwork::setType(Project::Type type)
{
	m_type = type;
}
void CArtwork::setName(const std::string& name)
{
	m_name = name;
}
void CArtwork::setRelease(const std::string& release)
{
	m_release = release;
}
void CArtwork::setDescription(const std::string& description)
{
	m_description = description;
}


Project::Type CArtwork::getType() const
{
	return m_type;
}
std::string CArtwork::getName() const
{
	return m_name;
}
std::string CArtwork::getRelease() const
{
	return m_release;
}
std::string CArtwork::getDescription() const
{
	return m_description;
}
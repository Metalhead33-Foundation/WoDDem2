#include "HasName.hpp"

HasName::HasName()
	: name("")
{
	;
}
HasName::HasName(const QString& name)
	: name(name)
{
	;
}
const QString& HasName::getName() const
{
	return name;
}
void HasName::setName(const QString& newName)
{
	name = newName;
}

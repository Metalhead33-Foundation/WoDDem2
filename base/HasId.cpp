#include "HasId.hpp"

HasId::HasId()
	: id(0)
{

}
HasId::HasId(int id)
	: id(id)
{

}
int HasId::getId() const
{
	return id;
}
void HasId::setId(int newId)
{
	id = newId;
}

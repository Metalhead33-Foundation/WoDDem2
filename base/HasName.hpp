#ifndef HASNAME_HPP
#define HASNAME_HPP
#include <QString>

class HasName
{
protected:
	QString name;
public:
	HasName();
	HasName(const QString& name);
	virtual ~HasName() = default;
	virtual const QString& getName() const;
	virtual void setName(const QString& newName);
};

#endif // HASNAME_HPP

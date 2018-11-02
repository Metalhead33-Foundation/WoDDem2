#ifndef COUNTRY_HPP
#define COUNTRY_HPP
#include <QJsonObject>
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(Country)
class Country : public HasId, public HasName
{
public:
	Country();
	Country(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // COUNTRY_HPP

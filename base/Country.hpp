#ifndef COUNTRY_HPP
#define COUNTRY_HPP
#include <QJsonObject>
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "GeographicalArea.hpp"

DEFINE_CLASS(Country)
DEFINE_CLASS(Region)
class Country : public GeographicalArea, public HasId, public HasName
{
private:
	wvRegion regions;
public:
	Country();
	Country(int mId, const QString& mName);
	bool addRegion(const sRegion region);
	const wvRegion& getRegions() const;
	GeographicalAreaType getGeographicalAreaType() const;
	OptionalInt getRow() const;
	pGeographicalArea getParent() const;
	pGeographicalArea getChild(int row) const;
	OptionalInt getRowCount() const;

	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // COUNTRY_HPP

#ifndef REGION_HPP
#define REGION_HPP
#include "Country.hpp"

DEFINE_CLASS(Region)
DEFINE_CLASS(Area)
class Region : public GeographicalArea, public HasId, public HasName
{
protected:
	sCountry mCountry;
private:
	wvArea areas;
public:
	Region();
	Region(int mId, const QString& mName, sCountry mCountry);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

	sCountry getCountry() const;
	void setCountry(sCountry newCountry);
	GeographicalAreaType getGeographicalAreaType() const;
	OptionalInt getRow() const;
	pGeographicalArea getParent() const;
	pGeographicalArea getChild(int row) const;
	OptionalInt getRowCount() const;

	bool addArea(const sArea area);
	const wvArea& getAreas() const;
};

#endif // REGION_HPP

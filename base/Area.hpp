#ifndef AREA_HPP
#define AREA_HPP
#include "Region.hpp"

DEFINE_CLASS(Area)
class Area : public GeographicalArea, public HasId, public HasName
{
protected:
	sRegion mRegion;
public:
	Area();
	Area(int mId, const QString& mName, sCountry mCountry);
	sRegion getRegion() const;
	void setRegion(sRegion newCountry);
	GeographicalAreaType getGeographicalAreaType() const;
	OptionalInt getRow() const;
	pGeographicalArea getParent() const;
	pGeographicalArea getChild(int row) const;
	OptionalInt getRowCount() const;

};

#endif // AREA_HPP

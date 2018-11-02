#include "Country.hpp"
#include "Region.hpp"

Country::Country()
{

}
Country::Country(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Country::read(const QJsonObject &json)
{
	id = json["countryId"].toInt();
	name = json["countryName"].toString();
}
void Country::write(QJsonObject &json) const
{
	json["countryId"] = id;
	json["countryName"] = name;
}
bool Country::addRegion(const sRegion region)
{
	for(auto it = regions.begin(); it != regions.end();++it)
	{
		if(it->lock() == region) return false;
	}
	regions.append(region);
	return true;
}
const wvRegion& Country::getRegions() const
{
	return regions;
}
Country::GeographicalAreaType Country::getGeographicalAreaType() const
{
	return COUNTRY;
}
OptionalInt Country::getRow() const
{
	return {};
}
pGeographicalArea Country::getParent() const
{
	return nullptr;
}
pGeographicalArea Country::getChild(int row) const
{
	if(regions[row].isNull()) return nullptr;
	else return regions[row].toStrongRef().get();
}

OptionalInt Country::getRowCount() const
{
	return regions.size();
}

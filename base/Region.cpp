#include "Region.hpp"
#include "Area.hpp"

Region::Region()
{

}
Region::Region(int mId, const QString& mName, sCountry mCountry)
	: HasId(mId), HasName(mName), mCountry(mCountry)
{
	;
}
void Region::read(const QJsonObject &json)
{
	id = json["regionId"].toInt();
	name = json["regionName"].toString();
}
void Region::write(QJsonObject &json) const
{
	json["regionId"] = id;
	json["regionName"] = name;
	if(mCountry) json["countryId"] = mCountry->getId();
	else json["countryId"];
}
sCountry Region::getCountry() const
{
	return mCountry;
}
void Region::setCountry(sCountry newCountry)
{
	mCountry = newCountry;
}
bool Region::addArea(const sArea area)
{
	for(auto it = areas.begin(); it != areas.end();++it)
	{
		if(it->lock() == area) return false;
	}
	areas.append(area);
	return true;
}
const wvArea& Region::getAreas() const
{
	return areas;
}
Region::GeographicalAreaType Region::getGeographicalAreaType() const
{
	return REGION;
}
OptionalInt Region::getRow() const
{
	if(!mCountry) return {};
	const auto& iterator = mCountry->getRegions();
	int i = 0;
	for(auto it = iterator.begin(); it != iterator.end(); ++it)
	{
		if(!it->isNull())
		{
			const auto s = it->toStrongRef();
			if(s.get() == this) return i;
		}
		++i;
	}
	return {};
}
pGeographicalArea Region::getParent() const
{
	if(mCountry) return mCountry.get();
	else return nullptr;
}
pGeographicalArea Region::getChild(int row) const
{
	if(areas[row].isNull()) return nullptr;
	else return areas[row].toStrongRef().get();
}
OptionalInt Region::getRowCount() const
{
	return areas.size();
}



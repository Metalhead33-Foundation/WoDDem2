#include "Region.hpp"

Region::Region()
{

}
Region::Region(int mId, const QString& mName, pCountry mCountry)
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
pCountry Region::getCountry() const
{
	return mCountry;
}
void Region::setCountry(pCountry newCountry)
{
	mCountry = newCountry;
}

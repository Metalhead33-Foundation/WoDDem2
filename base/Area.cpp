#include "Area.hpp"

Area::Area()
{
	;
}
Area::Area(int mId, const QString& mName, sCountry mCountry)
	: HasId(mId), HasName(mName)
{
	;
}
sRegion Area::getRegion() const
{
	return mRegion;
}
void Area::setRegion(sRegion newCountry)
{
	mRegion = newCountry;
}
Area::GeographicalAreaType Area::getGeographicalAreaType() const
{
	return AREA;
}
OptionalInt Area::getRow() const
{
	if(!mRegion) return {};
	const auto& iterator = mRegion->getAreas();
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
pGeographicalArea Area::getParent() const
{
	if(mRegion) return mRegion.get();
	else return nullptr;
}
pGeographicalArea Area::getChild(int row) const
{
	(void)(row);
	return nullptr;
}
OptionalInt Area::getRowCount() const
{
	return {};
}

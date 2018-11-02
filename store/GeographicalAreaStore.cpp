#include "GeographicalAreaStore.hpp"

sGeographicalAreaStore GeographicalAreaStore::singleton = nullptr;

sGeographicalAreaStore GeographicalAreaStore::getSingleton()
{
	if(singleton) return singleton;
	else
	{
		singleton = sGeographicalAreaStore(new GeographicalAreaStore());
		return  singleton;
	}
}

GeographicalAreaStore::GeographicalAreaStore()
{

}

const svCountry& GeographicalAreaStore::getCountries() const
{
	return countries;
}
const svRegion& GeographicalAreaStore::getRegions() const
{
	return regions;
}
const svArea& GeographicalAreaStore::getAreas() const
{
	return areas;
}

QModelIndex GeographicalAreaStore::index(int row, int column, const QModelIndex &parent) const
{
	if(!parent.isValid())
	{
		return createIndex(row,column,countries[row].get());
	}
	pGeographicalArea pgear = reinterpret_cast<pGeographicalArea>(parent.internalPointer());
	Q_ASSERT(pgear);
	if(pgear->getGeographicalAreaType() == GeographicalArea::AREA) return QModelIndex();
	return createIndex(row,column,pgear->getChild(row));
}

QModelIndex GeographicalAreaStore::parent(const QModelIndex &index) const
{
	if(!index.isValid()) return QModelIndex();
	pGeographicalArea pgear = reinterpret_cast<pGeographicalArea>(index.internalPointer());
	Q_ASSERT(pgear);
	if(pgear->getGeographicalAreaType() == GeographicalArea::COUNTRY) return QModelIndex();
	auto opt = pgear->getRow();
	if(opt.has_value()) return createIndex(opt.value(),0,pgear->getParent());
	else return QModelIndex();
}

int GeographicalAreaStore::rowCount(const QModelIndex &parent) const
{
	if(!parent.isValid()) return countries.size()+1;
	pGeographicalArea pgear = reinterpret_cast<pGeographicalArea>(parent.internalPointer());
	Q_ASSERT(pgear);
	auto opt = pgear->getRowCount();
	if(opt.has_value()) return opt.value();
	else return 1;
}

int GeographicalAreaStore::columnCount(const QModelIndex &parent) const
{
	return 1;
}

QVariant GeographicalAreaStore::data(const QModelIndex &index, int role) const
{

}

bool GeographicalAreaStore::hasChildren(const QModelIndex &parent) const
{
	if(!parent.isValid()) return true;
	pGeographicalArea pgear = reinterpret_cast<pGeographicalArea>(parent.internalPointer());
	Q_ASSERT(pgear);
	auto opt = pgear->getRowCount();
	if(opt.has_value()) return true;
	else return false;
}

bool GeographicalAreaStore::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

Qt::ItemFlags GeographicalAreaStore::flags(const QModelIndex &index) const
{

}

bool GeographicalAreaStore::insertRows(int row, int count, const QModelIndex &parent)
{

}

bool GeographicalAreaStore::removeRows(int row, int count, const QModelIndex &parent)
{

}

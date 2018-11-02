#ifndef GEOGRAPHICALAREASTORE_HPP
#define GEOGRAPHICALAREASTORE_HPP
#include <QAbstractItemModel>
#include "../base/Country.hpp"
#include "../base/Region.hpp"
#include "../base/Area.hpp"

DEFINE_CLASS(GeographicalAreaStore)
class GeographicalAreaStore : public QAbstractItemModel
{
private:
	svCountry countries;
	svRegion regions;
	svArea areas;
	static sGeographicalAreaStore singleton;
public:
	enum Column {
		COUNTRY = 0,
		REGION = 1,
		AREA = 2,
		INVALID = 3
	};

	GeographicalAreaStore();
	static sGeographicalAreaStore getSingleton();
	const svCountry& getCountries() const;
	const svRegion& getRegions() const;
	const svArea& getAreas() const;

	// Mandatory and read-only
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	// Optional, but still useful
	bool hasChildren(const QModelIndex &parent = QModelIndex()) const;
	// For editing
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
};

#endif // GEOGRAPHICALAREASTORE_HPP

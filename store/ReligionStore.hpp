#ifndef RELIGIONSTORE_HPP
#define RELIGIONSTORE_HPP
#include "../base/Religion.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(ReligionStore)
class ReligionStore : public QAbstractListModel
{
private:
	pvReligion genders;
	static pReligionStore singleton;
	ReligionStore();
public:
	static pReligionStore getSingleton();
	pReligion get(int id);
	pReligion create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const pvReligion& getReligions() const;
};
#endif // RELIGIONSTORE_HPP

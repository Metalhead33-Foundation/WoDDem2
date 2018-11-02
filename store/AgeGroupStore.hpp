#ifndef AGEGROUPSTORE_HPP
#define AGEGROUPSTORE_HPP
#include "../base/AgeGroup.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(AgeGroupStore)
class AgeGroupStore : public QAbstractListModel
{
private:
	pvAgeGroup ageGroups;
	static pAgeGroupStore singleton;
	AgeGroupStore();
public:
	static pAgeGroupStore getSingleton();
	pAgeGroup get(int id);
	pAgeGroup create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
};

#endif // AGEGROUPSTORE_HPP

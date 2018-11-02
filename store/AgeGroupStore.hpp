#ifndef AGEGROUPSTORE_HPP
#define AGEGROUPSTORE_HPP
#include "../base/AgeGroup.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(AgeGroupStore)
class AgeGroupStore : public QAbstractListModel
{
private:
	svAgeGroup ageGroups;
	static sAgeGroupStore singleton;
	AgeGroupStore();
public:
	static sAgeGroupStore getSingleton();
	sAgeGroup get(int id);
	sAgeGroup create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const svAgeGroup& getAgeGroups() const;
};

#endif // AGEGROUPSTORE_HPP

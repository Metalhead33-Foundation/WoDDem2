#ifndef RACESTORE_HPP
#define RACESTORE_HPP
#include "../base/Race.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(RaceStore)
class RaceStore : public QAbstractListModel
{
private:
	svRace genders;
	static sRaceStore singleton;
	RaceStore();
public:
	static sRaceStore getSingleton();
	sRace get(int id);
	sRace create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const svRace& getRaces() const;
};
#endif // RACESTORE_HPP

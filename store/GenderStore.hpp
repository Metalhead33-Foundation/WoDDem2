#ifndef GENDERSTORE_HPP
#define GENDERSTORE_HPP
#include "../base/Gender.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(GenderStore)
class GenderStore : public QAbstractListModel
{
private:
	svGender genders;
	static sGenderStore singleton;
	GenderStore();
public:
	static sGenderStore getSingleton();
	sGender get(int id);
	sGender create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const svGender& getGenders() const;
};

#endif // GENDERSTORE_HPP

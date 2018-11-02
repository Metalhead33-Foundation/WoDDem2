#ifndef GENDERSTORE_HPP
#define GENDERSTORE_HPP
#include "../base/Gender.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(GenderStore)
class GenderStore : public QAbstractListModel
{
private:
	pvGender genders;
	static pGenderStore singleton;
	GenderStore();
public:
	static pGenderStore getSingleton();
	pGender get(int id);
	pGender create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const pvGender& getGenders() const;
};

#endif // GENDERSTORE_HPP

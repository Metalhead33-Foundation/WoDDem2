#include "GenderStore.hpp"

pGenderStore GenderStore::singleton = nullptr;

pGenderStore GenderStore::getSingleton()
{
	if(singleton) return singleton;
	else
	{
		singleton = pGenderStore(new GenderStore());
		return  singleton;
	}
}
GenderStore::GenderStore()
{

}
pGender GenderStore::get(int id)
{
	if(id < genders.size()) return genders[id];
	else return nullptr;
}
pGender GenderStore::create(const QString& name)
{
	int id = genders.size();
	beginInsertRows(QModelIndex(), id, id);
	pGender tmp = pGender(new Gender(id,name));
	genders.push_back(tmp);
	endInsertRows();
	return tmp;
}
void GenderStore::remove(int id)
{
	genders.remove(id);
}
int GenderStore::rowCount(const QModelIndex& parent) const
{
	if(parent.isValid()) return 0;
	else return genders.size() + 1;
}
QVariant GenderStore::data(const QModelIndex &index, int role) const
{
	if(index.row() < 0 || index.row() > genders.size())
		return QVariant();

	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return QVariant();

	if(index.row() < genders.size()) {
		auto ageGroup = genders.at(index.row());
		if(!ageGroup)
			return QVariant();
		return ageGroup->getName();
	}

	return "<create new>";
}
Qt::ItemFlags GenderStore::flags(const QModelIndex &index) const
{
	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}
bool GenderStore::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(index.row() > genders.size()) return false;

	if(index.row() == genders.size())
	{
			beginInsertRows(QModelIndex(), index.row(), index.row());
			genders.insert(index.row(), pGender(new Gender(index.row(), value.toString())));
			endInsertRows();
			return true;
	}

	genders[index.row()]->setName(value.toString());
	emit dataChanged(index,index);
	return true;
}
bool GenderStore::insertRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= genders.size())
	{
		beginInsertRows(parent,row,row+count);
		for(int i = 0; i < count; ++i)
		{
			genders.insert(row+i,pGender(new Gender(row+i,QString(row))));
		}
		endInsertRows();
		return true;
	} else return false;
}
bool GenderStore::removeRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= genders.size())
	{
		beginRemoveRows(parent,row,row+count);
		genders.erase(&genders[row],&genders[row+count]);
		endRemoveRows();
		return true;
	} else return false;
}
const pvGender& GenderStore::getGenders() const
{
	return genders;
}

#include "AgeGroupStore.hpp"

sAgeGroupStore AgeGroupStore::singleton = nullptr;

sAgeGroupStore AgeGroupStore::getSingleton()
{
	if(singleton) return singleton;
	else
	{
		singleton = sAgeGroupStore(new AgeGroupStore());
		return  singleton;
	}
}
AgeGroupStore::AgeGroupStore()
{

}
sAgeGroup AgeGroupStore::get(int id)
{
	if(id < ageGroups.size()) return ageGroups[id];
	else return nullptr;
}
sAgeGroup AgeGroupStore::create(const QString& name)
{
	int id = ageGroups.size();
	beginInsertRows(QModelIndex(), id, id);
	sAgeGroup tmp = sAgeGroup(new AgeGroup(id,name));
	ageGroups.push_back(tmp);
	endInsertRows();
	return tmp;
}
void AgeGroupStore::remove(int id)
{
	ageGroups.remove(id);
}
int AgeGroupStore::rowCount(const QModelIndex& parent) const
{
	if(parent.isValid()) return 0;
	else return ageGroups.size() + 1;
}
QVariant AgeGroupStore::data(const QModelIndex &index, int role) const
{
	if(index.row() < 0 || index.row() > ageGroups.size())
		return QVariant();

	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return QVariant();

	if(index.row() < ageGroups.size()) {
		auto ageGroup = ageGroups.at(index.row());
		if(!ageGroup)
			return QVariant();
		return ageGroup->getName();
	}

	return "<create new>";
}
Qt::ItemFlags AgeGroupStore::flags(const QModelIndex &index) const
{
	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}
bool AgeGroupStore::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(index.row() > ageGroups.size()) return false;

	if(index.row() == ageGroups.size())
	{
			beginInsertRows(QModelIndex(), index.row(), index.row());
			ageGroups.insert(index.row(), sAgeGroup(new AgeGroup(index.row(), value.toString())));
			endInsertRows();
			return true;
	}

	ageGroups[index.row()]->setName(value.toString());
	emit dataChanged(index,index);
	return true;
}
bool AgeGroupStore::insertRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= ageGroups.size())
	{
		beginInsertRows(parent,row,row+count);
		for(int i = 0; i < count; ++i)
		{
			ageGroups.insert(row+i,sAgeGroup(new AgeGroup(row+i,QString(row))));
		}
		endInsertRows();
		return true;
	} else return false;
}
bool AgeGroupStore::removeRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= ageGroups.size())
	{
		beginRemoveRows(parent,row,row+count);
		ageGroups.erase(&ageGroups[row],&ageGroups[row+count]);
		endRemoveRows();
		return true;
	} else return false;
}

const svAgeGroup& AgeGroupStore::getAgeGroups() const
{
	return ageGroups;
}

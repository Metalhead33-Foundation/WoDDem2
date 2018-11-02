#include "AgeGroupStore.hpp"

pAgeGroupStore AgeGroupStore::singleton = nullptr;

pAgeGroupStore AgeGroupStore::getSingleton()
{
	if(singleton) return singleton;
	else
	{
		singleton = pAgeGroupStore(new AgeGroupStore());
		return  singleton;
	}
}
AgeGroupStore::AgeGroupStore()
{

}
pAgeGroup AgeGroupStore::get(int id)
{
	if(id < ageGroups.size()) return ageGroups[id];
	else return nullptr;
}
pAgeGroup AgeGroupStore::create(const QString& name)
{
	int id = ageGroups.size();
	pAgeGroup tmp = pAgeGroup(new AgeGroup(id,name));
	ageGroups.push_back(tmp);
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
	/*if(index.isValid() && index.row() < ageGroups.size()) return QVariant(ageGroups[index.row()]->getName());
	else if(role == Qt::DisplayRole && index.row() == ageGroups.size()) return QVariant(QString("<create>"));
	else if(role == Qt::EditRole) return QVariant(QString(""));
	else return QVariant();*/
	if((role == Qt::DisplayRole || role == Qt::EditRole) && index.row() == ageGroups.size()) return QVariant(QString("<create>"));
	if(index.row() < 0 || index.row() > ageGroups.size())
		return QVariant();
	auto a = ageGroups[index.row()];
	if(!a) return QVariant();
	else return ageGroups[index.row()]->getName();
}
Qt::ItemFlags AgeGroupStore::flags(const QModelIndex &index) const
{
	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}
bool AgeGroupStore::setData(const QModelIndex &index, const QVariant &value, int role)
{
	// if(!index.isValid()) return false;
	if(index.row() < ageGroups.size())
	{
		ageGroups[index.row()]->setName(value.toString());
		emit dataChanged(index,index);
		return true;
	} else if(index.row() == ageGroups.size())
	{
		beginInsertRows(QModelIndex(), index.row(), index.row());
		ageGroups.insert(index.row(), pAgeGroup(new AgeGroup(index.row(), value.toString())));
		endInsertRows();
		// emit dataChanged(index,index);
		return true;
	} else return false;
}
bool AgeGroupStore::insertRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= ageGroups.size())
	{
		beginInsertRows(parent,row,row+count);
		for(int i = 0; i < count; ++i)
		{
			ageGroups.insert(row+i,pAgeGroup(new AgeGroup(row+i,"")));
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

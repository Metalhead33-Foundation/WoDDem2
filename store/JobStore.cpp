#include "JobStore.hpp"

pJobStore JobStore::singleton = nullptr;

pJobStore JobStore::getSingleton()
{
	if(singleton) return singleton;
	else
	{
		singleton = pJobStore(new JobStore());
		return  singleton;
	}
}
JobStore::JobStore()
{

}
pJob JobStore::get(int id)
{
	if(id < jobs.size()) return jobs[id];
	else return nullptr;
}
pJob JobStore::create(const QString& name)
{
	int id = jobs.size();
	beginInsertRows(QModelIndex(), id, id);
	pJob tmp = pJob(new Job(id,name));
	jobs.push_back(tmp);
	endInsertRows();
	return tmp;
}
void JobStore::remove(int id)
{
	jobs.remove(id);
}
int JobStore::rowCount(const QModelIndex& parent) const
{
	if(parent.isValid()) return 0;
	else return jobs.size() + 1;
}
QVariant JobStore::data(const QModelIndex &index, int role) const
{
	if(index.row() < 0 || index.row() > jobs.size())
		return QVariant();

	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return QVariant();

	if(index.row() < jobs.size()) {
		auto ageGroup = jobs.at(index.row());
		if(!ageGroup)
			return QVariant();
		return ageGroup->getName();
	}

	return "<create new>";
}
Qt::ItemFlags JobStore::flags(const QModelIndex &index) const
{
	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}
bool JobStore::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if(index.row() > jobs.size()) return false;

	if(index.row() == jobs.size())
	{
			beginInsertRows(QModelIndex(), index.row(), index.row());
			jobs.insert(index.row(), pJob(new Job(index.row(), value.toString())));
			endInsertRows();
			return true;
	}

	jobs[index.row()]->setName(value.toString());
	emit dataChanged(index,index);
	return true;
}
bool JobStore::insertRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= jobs.size())
	{
		beginInsertRows(parent,row,row+count);
		for(int i = 0; i < count; ++i)
		{
			jobs.insert(row+i,pJob(new Job(row+i,QString(row))));
		}
		endInsertRows();
		return true;
	} else return false;
}
bool JobStore::removeRows(int row, int count, const QModelIndex &parent)
{
	if(parent.isValid()) return false;
	if(row <= jobs.size())
	{
		beginRemoveRows(parent,row,row+count);
		jobs.erase(&jobs[row],&jobs[row+count]);
		endRemoveRows();
		return true;
	} else return false;
}
const pvJob& JobStore::getJobs() const
{
	return jobs;
}

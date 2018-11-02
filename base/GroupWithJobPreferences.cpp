#include "GroupWithJobPreferences.hpp"
#include "../store/JobStore.hpp"
#include <QJsonArray>

GroupWithJobPreferences::GroupWithJobPreferences()
{

}

void GroupWithJobPreferences::addPreference(int jobId, float preferenceValue)
{
	auto it = jobs.find(jobId);
	if(it == jobs.end() && !isZero(preferenceValue)) jobs.insert(std::make_pair(jobId,preferenceValue));
	else
	{
		if(isZero(preferenceValue)) jobs.erase(it);
		else it->second = preferenceValue;
	}
}
float GroupWithJobPreferences::getPreference(int jobId) const
{
	auto it = jobs.find(jobId);
	if(it == jobs.end()) return 0.0f;
	else return it->second;
}
void GroupWithJobPreferences::readJobPref(const QJsonObject &json)
{
	if(json["jobPreferences"].isArray())
	{
		auto arr = json["jobPreferences"].toArray();
		for(auto it = arr.begin(); it != arr.end();++it)
		{
			if(it->isObject())
			{
				auto obj = it->toObject();
				addPreference(obj["jobId"].toInt(),obj["preference"].toDouble());
			}
		}
	}
}
void GroupWithJobPreferences::writeJobPref(QJsonObject &json) const
{
	QJsonArray arr;
	for(auto it = jobs.begin(); it != jobs.end();++it)
	{
		QJsonObject obj;
		obj["jobId"] = it->first;
		obj["preference"] = it->second;
		arr.push_back(obj);
	}
	json["jobPreferences"] = arr;
}

int GroupWithJobPreferences::rowCount(const QModelIndex & parent) const
{
	if(parent.isValid()) return 0;
	return getTotalJobCount();
}
int GroupWithJobPreferences::columnCount(const QModelIndex & parent) const
{
	if(parent.isValid()) return 0;
	return 2;
}
QVariant GroupWithJobPreferences::data(const QModelIndex & index, int role) const
{
	if((index.row() < 0 || index.row() >= getTotalJobCount()) || (index.column() < 0 || index.column() >= 2))
		return QVariant();

	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return QVariant();

	switch(index.column())
	{
		case 0:
		{
			auto job = JobStore::getSingleton()->getJobs()[index.row()];
			if(!job) return QVariant();
			return QVariant(job->getName());
		}
		case 1:
		{
			return QVariant(getPreference(index.row()));
		}
	}

	return QVariant();
}
bool GroupWithJobPreferences::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if((index.row() < 0 || index.row() >= getTotalJobCount()) || index.column() != 1)
		return false;

	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return false;

	addPreference(index.row(),value.toFloat());
	emit dataChanged(index,index);
	return true;
}
QVariant GroupWithJobPreferences::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role != Qt::DisplayRole && role != Qt::EditRole)
		return QVariant();

	switch(orientation)
	{
		case Qt::Orientation::Horizontal:
		{
		switch (section) {
			case 0: return "Job Title";
			case 1: return "Preference";
			default: return QVariant();
		}
		}
		case Qt::Orientation::Vertical:
		{
			return QVariant();
		}
	}
}
Qt::ItemFlags GroupWithJobPreferences::flags(const QModelIndex & index) const
{
	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

int GroupWithJobPreferences::getTotalJobCount()
{
	return JobStore::getSingleton()->getJobs().size();
}

#include "GroupWithJobPreferences.hpp"
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

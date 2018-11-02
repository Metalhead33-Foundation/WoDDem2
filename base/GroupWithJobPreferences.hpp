#ifndef GROUPWITHJOBPREFERENCES_HPP
#define GROUPWITHJOBPREFERENCES_HPP
#include "JobPrefTable.hpp"
#include <QJsonObject>

class GroupWithJobPreferences
{
protected:
	JobPrefTable jobs;
	void readJobPref(const QJsonObject &json);
	void writeJobPref(QJsonObject &json) const;
public:
	GroupWithJobPreferences();
	virtual ~GroupWithJobPreferences() = default;
	void addPreference(int jobId, float preferenceValue);
	float getPreference(int jobId) const;
};

#endif // GROUPWITHJOBPREFERENCES_HPP

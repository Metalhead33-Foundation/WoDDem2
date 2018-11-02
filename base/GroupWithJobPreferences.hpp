#ifndef GROUPWITHJOBPREFERENCES_HPP
#define GROUPWITHJOBPREFERENCES_HPP
#include "JobPrefTable.hpp"
#include <QJsonObject>
#include <QAbstractTableModel>

class GroupWithJobPreferences : public QAbstractTableModel
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

	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	int columnCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex & index) const;

	static int getTotalJobCount();
};

#endif // GROUPWITHJOBPREFERENCES_HPP

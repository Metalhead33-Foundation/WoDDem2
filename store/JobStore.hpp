#ifndef JOBSTORE_HPP
#define JOBSTORE_HPP
#include "../base/Job.hpp"
#include <QAbstractListModel>

DEFINE_CLASS(JobStore)
class JobStore : public QAbstractListModel
{
private:
	pvJob jobs;
	static pJobStore singleton;
	JobStore();
public:
	static pJobStore getSingleton();
	pJob get(int id);
	pJob create(const QString& name);
	void remove(int id);

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

	const pvJob& getJobs() const;
};

#endif // JOBSTORE_HPP

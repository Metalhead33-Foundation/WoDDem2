#include "Job.hpp"

Job::Job()
{

}
Job::Job(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Job::read(const QJsonObject &json)
{
	id = json["jobId"].toInt();
	name = json["jobName"].toString();
}
void Job::write(QJsonObject &json) const
{
	json["jobId"] = id;
	json["jobName"] = name;
}

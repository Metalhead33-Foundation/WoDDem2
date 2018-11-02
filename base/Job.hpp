#ifndef JOB_HPP
#define JOB_HPP
#include <QJsonObject>
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(Job)
class Job : public HasId, public HasName
{
public:
	Job();
	Job(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // JOB_HPP

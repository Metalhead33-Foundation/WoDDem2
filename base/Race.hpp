#ifndef RACE_HPP
#define RACE_HPP
#include "GroupWithJobPreferences.hpp"
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(Race)
class Race : public GroupWithJobPreferences, public HasId, public HasName
{
public:
	Race();
	Race(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // RACE_HPP

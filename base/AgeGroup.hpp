#ifndef AGEGROUP_HPP
#define AGEGROUP_HPP
#include "GroupWithJobPreferences.hpp"
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(AgeGroup)
class AgeGroup : public GroupWithJobPreferences, public HasId, public HasName
{
public:
	AgeGroup();
	AgeGroup(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // AGEGROUP_HPP

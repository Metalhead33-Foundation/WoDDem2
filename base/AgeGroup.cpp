#include "AgeGroup.hpp"

AgeGroup::AgeGroup()
{

}
AgeGroup::AgeGroup(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void AgeGroup::read(const QJsonObject &json)
{
	id = json["agegroupId"].toInt();
	name = json["agegroupName"].toString();
	readJobPref(json);
}
void AgeGroup::write(QJsonObject &json) const
{
	json["agegroupId"] = id;
	json["agegroupName"] = name;
	writeJobPref(json);
}

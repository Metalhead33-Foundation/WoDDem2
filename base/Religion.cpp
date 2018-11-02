#include "Religion.hpp"

Religion::Religion()
{

}
Religion::Religion(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Religion::read(const QJsonObject &json)
{
	id = json["religionId"].toInt();
	name = json["religionName"].toString();
	readJobPref(json);
}
void Religion::write(QJsonObject &json) const
{
	json["religionId"] = id;
	json["raceName"] = name;
	writeJobPref(json);
}

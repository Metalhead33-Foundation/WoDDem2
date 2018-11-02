#include "Race.hpp"
#include <QJsonObject>

Race::Race()
{

}
Race::Race(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Race::read(const QJsonObject &json)
{
	id = json["raceId"].toInt();
	name = json["raceName"].toString();
	readJobPref(json);
}
void Race::write(QJsonObject &json) const
{
	json["raceId"] = id;
	json["raceName"] = name;
	writeJobPref(json);
}

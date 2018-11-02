#include "Gender.hpp"

Gender::Gender()
{
	;
}
Gender::Gender(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Gender::read(const QJsonObject &json)
{
	id = json["genderId"].toInt();
	name = json["genderName"].toString();
	readJobPref(json);
}
void Gender::write(QJsonObject &json) const
{
	json["genderId"] = id;
	json["genderName"] = name;
	writeJobPref(json);
}

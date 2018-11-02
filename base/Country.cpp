#include "Country.hpp"

Country::Country()
{

}
Country::Country(int mId, const QString& mName)
	: HasId(mId), HasName(mName)
{
	;
}
void Country::read(const QJsonObject &json)
{
	id = json["countryId"].toInt();
	name = json["countryName"].toString();
}
void Country::write(QJsonObject &json) const
{
	json["countryId"] = id;
	json["countryName"] = name;
}

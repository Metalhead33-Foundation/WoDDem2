#ifndef GENDER_HPP
#define GENDER_HPP
#include "GroupWithJobPreferences.hpp"
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(Gender)
class Gender : public GroupWithJobPreferences, public HasId, public HasName
{
public:
	Gender();
	Gender(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // GENDER_HPP

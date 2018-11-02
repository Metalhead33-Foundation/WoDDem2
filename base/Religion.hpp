#ifndef RELIGION_HPP
#define RELIGION_HPP
#include "GroupWithJobPreferences.hpp"
#include "HasId.hpp"
#include "HasName.hpp"
#include <QJsonArray>
#include "../QPtr.hpp"

DEFINE_CLASS(Religion)
class Religion : public GroupWithJobPreferences, public HasId, public HasName
{
public:
	Religion();
	Religion(int mId, const QString& mName);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;
};

#endif // RELIGION_HPP

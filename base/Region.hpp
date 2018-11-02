#ifndef REGION_HPP
#define REGION_HPP
#include "Country.hpp"

DEFINE_CLASS(Region)
class Region : public HasId, public HasName
{
protected:
	pCountry mCountry;
public:
	Region();
	Region(int mId, const QString& mName, pCountry mCountry);
	void read(const QJsonObject &json);
	void write(QJsonObject &json) const;

	pCountry getCountry() const;
	void setCountry(pCountry newCountry);
};

#endif // REGION_HPP

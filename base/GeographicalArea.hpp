#ifndef GEOGRAPHICALAREA_HPP
#define GEOGRAPHICALAREA_HPP
#include "../QPtr.hpp"
#include <optional>

typedef std::optional<int> OptionalInt;

DEFINE_CLASS(GeographicalArea)
class GeographicalArea
{
public:
	virtual ~GeographicalArea() = default;
	enum GeographicalAreaType {
		COUNTRY,
		REGION,
		AREA
	};
	virtual GeographicalAreaType getGeographicalAreaType() const = 0;
	virtual OptionalInt getRow() const = 0;
	virtual pGeographicalArea getParent() const = 0;
	virtual pGeographicalArea getChild(int row) const = 0;
	virtual OptionalInt getRowCount() const = 0;
};

#endif // GEOGRAPHICALAREA_HPP

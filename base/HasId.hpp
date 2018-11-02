#ifndef HASID_HPP
#define HASID_HPP


class HasId
{
protected:
	int id;
public:
	HasId();
	HasId(int id);
	virtual ~HasId() = default;
	virtual int getId() const;
	virtual void setId(int newId);
};

#endif // HASID_HPP

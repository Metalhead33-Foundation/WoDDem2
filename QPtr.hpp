#ifndef QPTR_HPP
#define QPTR_HPP
#include <QVector>
#include <QList>
#include <QJsonArray>
#include <QSharedPointer>

#define DEFINE_CLASS(klass) class klass; \
	typedef QSharedPointer<klass> p##klass; \
	typedef QVector<p##klass> pv##klass; \
	typedef QList<p##klass> pl##klass;


#endif // QPTR_HPP

#ifndef QPTR_HPP
#define QPTR_HPP
#include <QVector>
#include <QList>
#include <QJsonArray>
#include <QSharedPointer>
#include <QWeakPointer>

#define DEFINE_CLASS(klass) class klass; \
	typedef klass* p##klass; \
	typedef QSharedPointer<klass> s##klass; \
	typedef QWeakPointer<klass> w##klass; \
	typedef QVector<p##klass> pv##klass; \
	typedef QList<p##klass> pl##klass; \
	typedef QVector<s##klass> sv##klass; \
	typedef QList<s##klass> sl##klass; \
	typedef QVector<w##klass> wv##klass; \
	typedef QList<w##klass> wl##klass;


#endif // QPTR_HPP

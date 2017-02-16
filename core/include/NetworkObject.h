/*
 * NetworkObject.h - data class representing a network object
 *
 * Copyright (c) 2017 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of iTALC - http://italc.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef NETWORK_OBJECT_H
#define NETWORK_OBJECT_H

#include <QUuid>
#include <QString>

class NetworkObject
{
public:
	typedef QUuid Uid;

	typedef enum Types
	{
		None,
		Root,
		Group,
		Host,
		TypeCount
	} Type;

	NetworkObject( const NetworkObject& other );
	explicit NetworkObject( Type type = None,
							const QString& name = QString(),
							const QString& hostAddress = QString(),
							const QString& macAddress = QString(),
							const QString& directoryAddress = QString() );

	bool operator ==( const NetworkObject& other ) const;

	const Uid& uid() const
	{
		return m_uid;
	}

	Type type() const
	{
		return m_type;
	}

	const QString& name() const
	{
		return m_name;
	}

	const QString& hostAddress() const
	{
		return m_hostAddress;
	}

	const QString& macAddress() const
	{
		return m_macAddress;
	}

	const QString& directoryAddress() const
	{
		return m_directoryAddress;
	}

private:
	Uid calculateUid() const;

	Type m_type;
	QString m_name;
	QString m_hostAddress;
	QString m_macAddress;
	QString m_directoryAddress;
	Uid m_uid;

	static const QUuid networkObjectNamespace;

};


static inline uint qHash( const NetworkObject& networkObject )
{
	return qHash( networkObject.uid() );
}

#endif // NETWORK_OBJECT_H

/*
** table.h
**
** This file is part of mkxp.
**
** Copyright (C) 2013 Jonas Kulla <Nyocurio@gmail.com>
**
** mkxp is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** mkxp is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with mkxp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TABLE_H
#define TABLE_H

#include "serializable.h"

#include <stdint.h>
#include <sigc++/signal.h>

class Table : public Serializable
{
public:
	Table(int x, int y = 1, int z = 1);
	virtual ~Table();

	int xSize() const { return m_x; }
	int ySize() const { return m_y; }
	int zSize() const { return m_z; }

	int16_t get(int x, int y = 0, int z = 0) const;
	void set(int16_t value, int x, int y = 0, int z = 0);

	inline int16_t &at(int x, int y = 0, int z = 0)
	{
		int16_t &value = data[m_x*m_y*z + m_x*y + x];

		return value;
	}

	inline int16_t &at(int x, int y = 0, int z = 0) const
	{
		int16_t &value = data[m_x*m_y*z + m_x*y + x];

		return value;
	}

	void resize(int x, int y, int z);
	void resize(int x, int y);
	void resize(int x);

	int serialSize() const;
	void serialize(char *buffer) const;
	static Table *deserialize(const char *data, int len);

	sigc::signal<void> modified;

private:
	int m_x, m_y, m_z;

	int16_t *data;
};

#endif // TABLE_H

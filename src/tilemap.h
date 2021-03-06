/*
** tilemap.h
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

#ifndef TILEMAP_H
#define TILEMAP_H

#include "disposable.h"

#include "util.h"

class Viewport;
class Bitmap;
class Table;

struct TilemapPrivate;

class Tilemap : public Disposable
{
public:
	class Autotiles
	{
	public:
		void set(int i, Bitmap *bitmap);
		Bitmap *get(int i) const;

	private:
		TilemapPrivate *p;
		friend class Tilemap;
	};

	Tilemap(Viewport *viewport = 0);
	~Tilemap();

	void update();

	Autotiles &getAutotiles() const;

#ifndef RGSS2
	Viewport *getViewport() const;
#else
	DECL_ATTR( Viewport,   Viewport* )
#endif
	DECL_ATTR( Tileset,    Bitmap*   )
	DECL_ATTR( MapData,    Table*    )
	DECL_ATTR( FlashData,  Table*    )
	DECL_ATTR( Priorities, Table*    )
	DECL_ATTR( Visible,    bool      )
	DECL_ATTR( OX,         int       )
	DECL_ATTR( OY,         int       )

private:
	TilemapPrivate *p;

	void releaseResources();
};

#endif // TILEMAP_H

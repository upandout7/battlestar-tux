/* FighterAmmo.h
 *
 * Copyright 2005 Eliot Eshelman
 * eliot@6by9.net
 *
 *
 *  This file is part of Battlestar Tux.
 *
 *  Battlestar Tux is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  Battlestar Tux is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Battlestar Tux; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef FIGHTERAMMO_H_
#define FIGHTERAMMO_H_

#include "SDL_opengl.h"

#include "Displayable.h"
#include "FighterAmmoList.h"
#include "Game.h"
#include "ListItem.h"

class FighterAmmo : public Displayable, public ListItem {
	public:
				FighterAmmo( FighterAmmoType f, FighterAmmoList* l, Game* g );

				void Draw();

	private:
				// Constant Z position of the ammo.
				static const float zPos = -1.4;

				FighterAmmoType type;

				GLuint texture;
};


#endif /*FIGHTERAMMO_H_*/
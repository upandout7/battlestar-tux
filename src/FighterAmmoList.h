/* FighterAmmoList.h
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


#ifndef FIGHTERAMMOLIST_H_
#define FIGHTERAMMOLIST_H_

#include "SDL_opengl.h"

#include "Displayable.h"

class FighterAmmo;


enum FighterAmmoType {
	BASIC_LASER				// Default weapon
};
static const int numFighterAmmo = 1;


/* Holds, updates and draws the fighter's shots. */
class FighterAmmoList {
	public:
				FighterAmmoList( Game* g );
				~FighterAmmoList();

				// Move all the ammo to their next position.
				void UpdatePositions();

				// Draw all the objects.
				void DrawObjects();

				// Determine if any object collides with 'object'.
				void CheckCollisions( Displayable* object );

				// Remove any objects that are out of bounds.
				void CullObjects();

				// Get a texture ID.
				GLuint getTexture( int index );

				// Add a new object to be managed.
				void addObject( FighterAmmo* obj );

				// Remove an object.
				void remObject( FighterAmmo* obj );

	private:
				FighterAmmo* rootObj;

				// Texture for each type of ammo.
				GLuint textures[numFighterAmmo];

				Game* game;
};


#endif /*FIGHTERAMMOLIST_H_*/
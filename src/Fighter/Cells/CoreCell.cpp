/* CoreCell.cpp
 *
 * Copyright 2007 Eliot Eshelman
 * battlestartux@6by9.net
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


#include "CoreCell.h"
#include "TextureManager.h"

CoreCell::CoreCell( Fighter* f, Game* g, const ivec2 &pos  ) : HexCell( f, g, CORE_CELL, pos )  {
	texture = game->getTextureManager()->loadTexture( "data/gfx/hex_cell_0001-16.png" );
}


CoreCell::~CoreCell() {
	game->getTextureManager()->freeTextures( 1, &texture );
}


void CoreCell::Update( int speed ) {
	HexCell::Update( speed );
}


void CoreCell::Draw() {
	glBindTexture( GL_TEXTURE_2D, texture );

	glColor4f( 0.3, 0.3, 0.3, 1.0 );
	drawHex( HEX_CELL_SIZE[0], HEX_CELL_SIZE[1], HEX_CELL_SIZE[2] );

	glColor4f( 0.9, 0.4, 0.0, 1.0 );
	drawHex( 0.25, HEX_CELL_SIZE[1], HEX_CELL_SIZE[2] );
}


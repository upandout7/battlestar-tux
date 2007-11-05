/* PropulsionCell.cpp
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


#include "Fighter.h"
#include "PropulsionCell.h"
#include "TextureManager.h"

PropulsionCell::PropulsionCell( Fighter* f, Game* g, const ivec2 &pos  ) : HexCell( f, g, PROPULSION_CELL, pos )  {
	accelerationRate = 0.001; 
	powerRate = 10000;

	texture = game->getTextureManager()->loadTexture( "data/gfx/hex_cell_0001-16.png" );

	particles = new ParticleGenerator( game->getTextureManager(), 100, 2 );
}


PropulsionCell::~PropulsionCell() {
	game->getTextureManager()->freeTextures( 1, &texture );
	delete particles;
}


void PropulsionCell::Update( int speed ) {
	particles->Update( speed, game->getGameFrame()%1000, cellPosition[0] + cellPosition[1] );

	HexCell::Update( speed );
}


void PropulsionCell::Draw() {
	glBindTexture( GL_TEXTURE_2D, texture );

	glColor4f( 0.3, 0.3, 0.3, 1.0 );
	drawHex( HEX_CELL_SIZE[0], HEX_CELL_SIZE[1], HEX_CELL_SIZE[2] );

	glColor4f( 0.46, 0.55, 0.6, 1.0 );
	drawHex( 0.35, HEX_CELL_SIZE[0], HEX_CELL_SIZE[2] );

	// We're not sorting polygons.  If we draw these first,
	// their alphas will screw up the fighter's cells.
	particles->Draw();
}


vec3 PropulsionCell::accelerate( const vec3 &accel ) {
	vec3 actualAccel = accel;
	float length = actualAccel.length();

	// Ensure the cell can exert this much force.
	if( length > accelerationRate ) {
		actualAccel *= accelerationRate / length;
		length = accelerationRate;
	}

	// Get as much power as is needed to accelerate.
	float neededPower = length * powerRate;
	float power = fighter->getPower( neededPower );

	// Accelerate using as much power as was obtained.
	if( power < neededPower )
		actualAccel *= power / neededPower;

	fighter->accel( actualAccel );

	return accel - actualAccel;
}


void PropulsionCell::setAccelerationRate( float r ) { accelerationRate = r; }
float PropulsionCell::getAccelerationRate() { return accelerationRate; }
void PropulsionCell::setPowerRate( float r ) { powerRate = r; }


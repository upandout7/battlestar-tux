/* LoadCampaignMenu.cpp
 *
 * Copyright 2006 Eliot Eshelman
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


#include <string>
#include <iostream>

#include "Button.h"
#include "HorizontalContainer.h"
#include "Label.h"
#include "LoadCampaignMenu.h"
#include "VerticalPane.h"

LoadCampaignMenu::LoadCampaignMenu( MainMenu* menu, Game* g, int w, int h ) : GUI( w, h, menu ) {
	mainMenu = menu;
	game = g;
}


LoadCampaignMenu::~LoadCampaignMenu() {}


void LoadCampaignMenu::CreateWidgets() {
	// Display load campaign options.
	VerticalPane* credits = new VerticalPane( this, true, HORIZ_CENTER, VERTI_CENTER );
	Label* label = new Label( this, "Load Campaign", HORIZ_CENTER, VERTI_CENTER );
	label->setFont( boldFont );
	credits->AddWidget( label );

	label = new Label( this, "None Currently Available", HORIZ_CENTER, VERTI_CENTER );
	credits->AddWidget( label );

	HorizontalContainer* closePanel = new HorizontalContainer( this, false, HORIZ_RIGHT, VERTI_CENTER );
	Button* button = new Button( this, "Cancel", HORIZ_CENTER, VERTI_CENTER );
	button->AddListener( this );
	closePanel->AddWidget( button );
	credits->AddWidget( closePanel );

	credits->setPos( CONTAINER_MC );
	addObject( credits );
}


void LoadCampaignMenu::EventGenerated( ButtonClickEvent* e ) {
	std::string text = e->getButtonText();

	if( text == "Cancel" )
		mainMenu->ChangeMenu( OPENING_MENU );
}
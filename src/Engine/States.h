
/* ------------------------------------------------

	@File		: States.h
	@Date		: 08/11/2013
	@Purpose	:

		This is a include file that has some
		globals declared so that switching 
		states is easier and includes all 
		states if this file is included

 ------------------------------------------------ */

#pragma once

// States Declarations
#include "CharecterSelection.h"
#include "SplashScreen.h"
#include "ShopState.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Credits.h"
#include "Combat.h"
#include "Map.h"

// Identifiers for states
enum : unsigned int {
	g_CharacterSelection = 5,
	g_SplashScreen = 0,
	g_GameOver = 7,
	g_Credits = 2,
	g_Battle = 6,
	g_Store = 4,
	g_Menu = 1,
	g_Map = 3
};
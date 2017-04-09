
/* ------------------------------------------------

	@File		: Player.h
	@Date		: 21/11/2013
	@Purpose	:

		This is the players class, and it has 
		its own stats, and a some functions
		for moving the player around the map.

 ------------------------------------------------ */

#pragma once

#include "Character.h"

#pragma region Stats Struct
class PlayerFile;
struct PlayerStats  {
	int StartHealth;
	int StartStrength;
	int StartSpeed;
	int Strength;
	int Health;
	int Speed; 
	int Cash;
	int Dead;
};
#pragma endregion

class Player : public Character {
	private:

		PlayerStats playerStats;
		PlayerFile* playerfile;

	public:

	Player(PlayerFile *);

		void moveX(int);
		void moveY(int);

		PlayerStats& getStats(){ return playerStats; }
		bool isKilled(){ return playerStats.Dead; }
		void Reset();
		void Load();
		void Save();
		void Kill();

	~Player();
};
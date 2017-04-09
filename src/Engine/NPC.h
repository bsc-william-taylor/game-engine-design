
/* ------------------------------------------------

	@File		: NPC.h
	@Date		: 21/11/2013
	@Purpose	:

		This is a class the construct enemys
		for the player to batter it has its
		own stats and has its own various 
		functions.

 ------------------------------------------------ */

#pragma once

#include "Character.h"

#pragma region Stats

class MonsterFile;
class Player;
struct MonsterStats  {
	int StartHealth;
	int DropChance;
	int Strength;
	int Health;
	int Speed; 
	int Cash;
	int Dead;
};

#pragma endregion

class NPC : public Character {
	private: 

		MonsterStats stats;
		MonsterFile* file;

	public:

	NPC(MonsterFile *);
	NPC(Character *);

		MonsterStats& getStats(){ return stats; }
		bool isKilled();

		void DropItem(Player *);
		void Reset();
		void Load();
		void Save();
		void Kill();

	~NPC();
};
#include "EnemyController.h"
#include "Enemy.h" // to actualy use the field Enemy declared in the header by forward declaration, we use the field here
#include <stdlib.h> 

void EnemyController::Init(int maximumEnemies, int step, Point initialLocation)
{
	this->enemies = new Enemy[maximumEnemies]; 
	this->stepSize = step;
	this->startinLocation = initialLocation;
	this->nrofUnits = maximumEnemies;

	for (int i = 0; i < maximumEnemies; i++)
		this->enemies[i].Init(initialLocation, ENEMY_HEALTH);
}

void EnemyController::Uninit()
{
	
	free(this->enemies); 
	
}

void EnemyController::Move()
{
	for (int i = 0; i < this->nrofUnits; i++)
		this->enemies[i].Move(this->dir, this->stepSize);
}

void EnemyController::DamageAll()
{
	for (int i = 0; i < this->nrofUnits; i++)
	{
		this->enemies[i].Shoot(i + 1);
	}
}

int EnemyController::CountKilledEnemies()
{
	int killedUnits = 0;

	for (int i = 0; i < this->nrofUnits; i++) 
		if (this->enemies[i].IsDead() == true)
			killedUnits++;

	return killedUnits;
}

bool EnemyController::SpawnEnemy()
{
	if (this->CountKilledEnemies() == this->nrofUnits)
		return false;
	else return true;
}
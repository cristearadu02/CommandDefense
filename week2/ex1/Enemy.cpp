#include "Enemy.h"

void Enemy::Init(Point intitialLocation, int initialHealh)
{
	this->location = intitialLocation; 
	this->health = initialHealh; 
}

void Enemy::Move(EnemyDirection direction, int step)
{
	switch (direction) {
	case EnemyDirection::UpDirection: 
		this->location.y = this->location.y - step;
		break;
	case EnemyDirection::LeftDirection:
		this->location.x = this->location.x - step;
		break;
	case EnemyDirection::DownDirection:
		this->location.y = this->location.y + step;
		break;
	case EnemyDirection::RightDirection:
		this->location.x = this->location.x + step;
	}
}

bool Enemy::IsDead()
{
	if (this->health <= 0) 
		return true;
	else
		return false;
}

void Enemy::Shoot(int damage)
{
	this->health = this->health - damage;
}
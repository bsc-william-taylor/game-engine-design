
#include "PlayerFile.h"
#include "Player.h"

Player::Player(PlayerFile * file) : Character()
{
    this->playerfile = file;
    load();
}

Player::~Player()
{
}

void Player::reset()
{
    int x = playerfile->getStart().getX();
    int y = playerfile->getStart().getY();

    playerStats = playerfile->getStats();
    playerStats.strength = playerStats.StartStrength;
    playerStats.health = playerStats.startHealth;
    playerStats.speed = playerStats.StartSpeed;
    playerStats.cash = 0;
    playerStats.dead = 0;

    playerfile->setPosition(Vector<int>(x, y));
    playerfile->setStats(playerStats);
    playerfile->push();

    turnOnObservers();
}

void Player::load()
{
    text.textToTexture(playerfile->getName());

    int x = playerfile->getPosition().getX();
    int y = playerfile->getPosition().getY();
    int w = playerfile->getSize().getX();
    int h = playerfile->getSize().getY();

    playerStats = playerfile->getStats();
    colour = playerfile->getColour();

    setPosition(Vector<int>(x, y));
    setSize(Vector<int>(w, h));
}

void Player::save()
{
    Vector<int> position = getPosition();
    playerfile->setPosition(position);
    playerfile->setStats(playerStats);
    playerfile->push();
}

void Player::Kill()
{
    playerStats.dead = true;
    turnOffObservers();
}

void Player::moveX(int x)
{
    position.set(position.getX() + x, position.getY());

    if (!playerStats.dead)
    {
        notify();
    }
}

void Player::moveY(int y)
{
    position.set(position.getX(), position.getY() + y);

    if (!playerStats.dead)
    {
        notify();
    }
}
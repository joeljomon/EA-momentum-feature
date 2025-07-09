#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <string>
#include <vector>

// Base class for all game objects
class GameObject {
protected:
    std::string name;
    float x, y; // Position coordinates

public:
    GameObject(const std::string& name, float x, float y);
    virtual ~GameObject();
    
    virtual void update() = 0; // Pure virtual function for updating object state
    std::string getName() const;
    float getX() const;
    float getY() const;
    void setPosition(float newX, float newY);
};

// Player class
class Player : public GameObject {
private:
    int health;
    int score;

public:
    Player(const std::string& name, float x, float y);
    
    void update() override;
    void takeDamage(int amount);
    void addScore(int points);
    int getHealth() const;
    int getScore() const;
};

// Enemy class
class Enemy : public GameObject {
private:
    int damage;
    float speed;

public:
    Enemy(const std::string& name, float x, float y, int damage, float speed);
    
    void update() override;
    int getDamage() const;
    float getSpeed() const;
};

// Item class (for power-ups, weapons, etc.)
class Item : public GameObject {
private:
    std::string type;

public:
    Item(const std::string& name, float x, float y, const std::string& type);
    
    void update() override;
    std::string getType() const;
};

#endif // GAMEOBJECTS_H
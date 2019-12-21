#ifndef MODELWORLD_H
#define MODELWORLD_H

#include "world.h"
#include "QObject"
#include "QGraphicsPixmapItem"
#include "direction.h"
#include "mytile.h"
#include "myenemy.h"
#include "myhealthpack.h"
#include "mypenemy.h"

class ModelWorld : public QObject
{
    Q_OBJECT

public:
    ModelWorld(unsigned int nrOfEnemies, unsigned int nrOfHealthpacks);
    const std::vector<std::shared_ptr<Tile>>& getTiles() const{return tiles;}
    const std::vector<std::shared_ptr<Enemy>>& getEnemies() const{return enemies;}
    const std::vector<std::shared_ptr<Tile>>& getHealthPacks() const{return healthPacks;}
    const std::shared_ptr<Protagonist>& getProtagonist() const{return protagonist;}

private:
    void createWorld(QString filename, unsigned int nrOfEnemies, unsigned int nrOfHealthpacks);
    void initializeCollections();
    void moveProtagonist(Direction direction);
    void addOccupantToTile(std::shared_ptr<Tile> newEnemy);

    World world;
    int rows;
    int columns;

    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::shared_ptr<MyTile>> myTiles;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Tile>> healthPacks;

    std::shared_ptr<Protagonist> protagonist;

    std::vector<std::vector<std::shared_ptr<MyTile>>> representation_2D;

public slots:
    //void damageProtagonist(float damage);
    void protagonistMoveRequested(Direction direction);
    void poisonTile(float value, int x, int y);
signals:
    void updateView();

};

#endif // MODELWORLD_H

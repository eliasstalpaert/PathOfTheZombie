#ifndef STRATEGY_H
#define STRATEGY_H

#include "modelworld.h"

class Strategy : public QObject
{
    Q_OBJECT
public:
    Strategy(std::shared_ptr<ModelWorld> model);
private:
    std::shared_ptr<ModelWorld> model;

    std::vector<std::vector<std::shared_ptr<MyTile>>>* representation_2D;
    std::vector<std::vector<MyTile>>* original_representation_2D;

    MyProtagonist* protagonist;
    void followPath(std::shared_ptr<std::vector<std::pair<int, int>>> path);
    void calculateBestPath();
    GridLocation protagonist_loc, destination_loc;
    std::shared_ptr<std::vector<std::pair<int,int>>> currentPath, bestPath, altBestPath, pathToBeFollowed;

    int moveIndex;
    bool strategyEnabled, gameEnded;
public slots:
    void gameEnd();
    void enableStrategy(bool enabled);
    void nextMove();
signals:
    void requestMove(Direction d);
    void noPossibleSolution(QString reason);
    void newPathfindingResult(std::shared_ptr<std::vector<std::pair<int,int>>> result);
    void pathfindingAvailable();
};

#endif // STRATEGY_H

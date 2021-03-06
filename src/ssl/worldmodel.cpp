#include "worldmodel.h"

double WorldModel::var[10];

WorldModel::WorldModel(OutputBuffer *outputBuffer)
{
    time = 0;
    ref_goalie_our = 0;
    ref_goalie_opp = 0;
    gs = STATE_Null;
    gs_last = STATE_Null;
    isSim = false;
    kn = new Knowledge(this);
//    numberOfBalls = 0;
    numberOfShapes = 0;

    for(int i=0; i<PLAYERS_MAX_NUM; i++)
    {
        ourRobot[i].setID(i);
        ourRobot[i].setOutputBuffer(outputBuffer);
        ourRobot[i].setWorldModel(this);
    }

    for(int i=0; i<10; i++)
        var[i] = 0;
}

void WorldModel::clean()
{
    shapes4Region1.clear();
    shapes4Region2.clear();
    positiveShapes.clear();
    negativeShapes.clear();
    //balls.clear();
    obstacles.clear();
}

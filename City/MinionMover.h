/**
 * \file MinionMover.h
 *
 * \author Elizabeth Lipin
 *
 * Class that visits transporters and moves minions
 */
#pragma once
#include "TileVisitor.h"
#include <vector>
/**
 * Class that visits transporters and moves minions
 */
class CMinionMover :
    public CTileVisitor
{
public:
    /**
    * set the locations to move from and to
    * \param from from where to move 
    * \param to where to move
    */
    void SetFromDestLocs(int from, int to) { mFromLoc = from, mDestLoc = to; }
    /**
    * visit transporter
    * \param transporter transporter to visit
    */
    void VisitTransporter(CTileTransporter* transporter);

private:
    int mCurrentLoc = 0; ///< current location in tiles
    int mFromLoc = 0; ///< where we take minion
    int mDestLoc = 0; ///<where we move minion
};


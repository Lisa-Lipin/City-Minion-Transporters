/**
 * \file BuildingCounter.h
 *
 * \author Elizabeth Lipin
 *
 * Class that visits buildings and counts how many
 */
#pragma once
#include "TileVisitor.h"

/**
* Class that visits buildings and counts how many
*/
class CBuildingCounter :
    public CTileVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }
    /** Visit a building
     * \param building building to visit */
    void VisitBuilding(CTileBuilding* building);
private:
    /// Buildings counter
    int mNumBuildings = 0;
    
};


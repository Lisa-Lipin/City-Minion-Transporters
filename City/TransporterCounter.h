/**
 * \file TransporterCounter.h
 *
 * \author Elizabeth Lipin
 *
 * visitor for transporters counts and gets minion location
 */
#pragma once
#include "TileVisitor.h"
/**
*visitor for transporters counts and gets minion location
*/
class CTransporterCounter :
    public CTileVisitor
{
public:
    /** Get the number of transporters
     * \returns Number of transporters */
    int GetNumTransporters() const { return mNumTransporters; }
    /** Get the location of minion
     * \returns location of minion */
    int GetMinionLocation() const { return mMinionLocation; }
    /**
    * resets member variable to initial values
    */
    void Reset() { mNumTransporters = 0, mAccepted = false, mMinionLocation = -1; }
    /**
    * returns true
    * \return true
    */
    bool CanTransport() const { return mAccepted; }
    /**
    * Visit transporter
    * \param transporter transporter to visit
    */
    void VisitTransporter(CTileTransporter* transporter);
private:
    /// Transporters counter
    int mNumTransporters = 0;
    /// whether can transport
    bool mAccepted = false;
    /// minion location
    int mMinionLocation = -1;
};


/**
 * \file MinionMover.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "MinionMover.h"
#include "TileTransporter.h"
/**
* visits transporter
* \param transporter transporter to visit
*/
void CMinionMover::VisitTransporter(CTileTransporter* transporter)
{
	//add and remove minion at locations
	if (mCurrentLoc == mDestLoc)
	{
		transporter->AddMinion();
	}
	if (mCurrentLoc == mFromLoc)
	{
		transporter->RemoveMinion();
	}
	mCurrentLoc++;
}

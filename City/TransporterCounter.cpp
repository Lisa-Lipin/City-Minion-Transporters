/**
 * \file TransporterCounter.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "TransporterCounter.h"
#include "TileTransporter.h"

/** Visit a CTileTransporter object
* \param transporter Transporter we are visiting */
void CTransporterCounter::VisitTransporter(CTileTransporter* transporter)
{
	mAccepted = true;
	//set minion location and add up transporters
	if (transporter->HasMinion())
	{
		mMinionLocation = mNumTransporters;
	}
	mNumTransporters++;
}
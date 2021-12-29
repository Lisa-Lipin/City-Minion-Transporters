/**
 * \file TileTransporter.cpp
 *
 * \author Elizabeth Lipin
 */
#include "pch.h"
#include "TileTransporter.h"
#include "TransporterCounter.h"
#include "MinionMover.h"
using namespace std;
using namespace Gdiplus;

/** Constructor
* \param city The city this is a member of
*/
CTileTransporter::CTileTransporter(CCity* city) : CTile(city)
{
    SetAdjacencies(false, false, false, false);
}

/**
*  Destructor
*/
CTileTransporter::~CTileTransporter()
{
}

/**  Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Pointer to the crated node
 */
std::shared_ptr<xmlnode::CXmlNode> CTileTransporter::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"transporter");

    return itemNode;
}


/**
 *  Indicate the Transporter tiles adjacent to this one
 *
 * The Transporter tile image chosen is dependent on the tiles around
 * it. This is where the adjacency of Transporter tiles is indicated.
 *
 * \param ul True if Transporter tile to upper left
 * \param ur True if Transporter tile to upper right
 * \param ll True if Transporter tile to lower left
 * \param lr True if Transporter tile to lower right
 */
void CTileTransporter::SetAdjacencies(bool ul, bool ur, bool ll, bool lr)
{
    // Create the adjacency code
    int code = (ul ? 1 : 0) | (ur ? 2 : 0) | (ll ? 4 : 0) | (lr ? 8 : 0);
    if (mCurrentAdj == code)
    {
        // We are already set. Do nothing
        return;
    
    };

    // Select the appropriate image
    SetImage(L"transporter.png");
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CTileTransporter::SetMinionImage(const std::wstring& file)
{
    if (!file.empty())
    {
        wstring filename = ImagesDirectory + file;
        mMinionImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mMinionImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        mMinionImage.release();
    }

    mMinionFile = file;
}

/**
* draw minion
* \param graphics graphics to draw with
*/
void CTileTransporter::Draw(Gdiplus::Graphics* graphics)
{
    CTile::Draw(graphics);
    if (mHasMinion)
    {
        SetMinionImage(L"transporter-minion.png");


        int wid = mMinionImage->GetWidth();
        int hit = mMinionImage->GetHeight();
        graphics->DrawImage(mMinionImage.get(), GetX() - OffsetLeft, GetY() + OffsetDown - hit, wid, hit);
    }
}

//Add a minion to tile
void CTileTransporter::AddMinion()
{
    mHasMinion = true;
}

//remove minion from tile
void CTileTransporter::RemoveMinion()
{
    mHasMinion = false;
}
/**
 * \file TileTransporter.h
 *
 * \author Elizabeth Lipin
 *
 * class for transporter tiles in our city
 */
#pragma once
#include "Tile.h"

/**
* class for transporter tiles in our city
*/
class CTileTransporter :
    public CTile
{
public:
    CTileTransporter(CCity* city);

    ///  Default constructor (disabled)
    CTileTransporter() = delete;

    ///  Copy constructor (disabled)
    CTileTransporter(const CTileTransporter&) = delete;

    ~CTileTransporter();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void SetAdjacencies(bool ul, bool ur, bool ll, bool lr);
    /**
    *returns whether transporter has minion
    * \return return if have minion
    */
    bool HasMinion() { return mHasMinion; }
    /**
    *sets minion image given file name
    * \param file file for minion image
    */
    void SetMinionImage(const std::wstring& file);
    /**
    *draws minion given graphics
    * \param graphics graphics to draw with
    */
    void Draw(Gdiplus::Graphics* graphics) override;
    /**
    * changes which transporter has minion
    */
    void AddMinion();
    /**
    * changes which transporter has minion
    */
    void RemoveMinion();

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitTransporter(this); }
private:
    /// The current adjacency integer or -1 if none
    int mCurrentAdj = -1;
    /// Whether tile contains minion
    bool mHasMinion = false;
    /// The image of the minion
    std::unique_ptr<Gdiplus::Bitmap> mMinionImage;
    /// The file for this item
    std::wstring mMinionFile;
};


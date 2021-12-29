/**
 * \file City.h
 *
 * \author Charles B. Owen
 *
 *  Class that implements a simple city with tiles we can manipulate
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>

#include "XmlNode.h"
#include "Tile.h"

/**
 *  Implements a simple city with tiles we can manipulate
 */
class CCity
{
public:
    CCity();
    virtual ~CCity();

    /// The spacing between grid locations
    static const int GridSpacing = 32;

    /**
    * Add a tile to the city
    * \param tile to add
    */
    void Add(std::shared_ptr<CTile> item);
    /**
    * get tile clicked on
    * \param x x position
    * \param y y position
    * \return tile clicked on
    */
    std::shared_ptr<CTile> HitTest(int x, int y);
    /**
    * move clicked tile to end of vector
    * \param item to move
    */
    void MoveToFront(std::shared_ptr<CTile> item);
    /**
    * Remove a tile from the city
    * \param item to remove
    */
    void DeleteItem(std::shared_ptr<CTile> item);

    /**
    * draw item
    * \param graphics to draw with
    */
    void OnDraw(Gdiplus::Graphics *graphics);
    /**
    * save file
    * \param filename file to save
    */
    void Save(const std::wstring &filename);
    /**
    * load file
    * \param filename file to load
    */
    void Load(const std::wstring &filename);
    /**
    * clear vector
    */
    void Clear();

    /**
    * update city
    * \param elapsed time spent
    */
    void Update(double elapsed);
    /**
    * sort tiles
    */
    void SortTiles();

    /**
    * get adjacent tile
    * \param tile to check
    * \param dx x position
    * \param dy y position
    * \return tile
    */
    std::shared_ptr<CTile> GetAdjacent(std::shared_ptr<CTile> tile, int dx, int dy);
    /**
    * get adjacent tile
    * \param tile to check
    * \param dx x position
    * \param dy y position
    * \return tile
    */
    std::shared_ptr<CTile> GetAdjacent(CTile *tile, int dx, int dy);

    /**
    * accept visitor
    * \param visitor to accept
    */
    void Accept(CTileVisitor* visitor);

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * \param city The city we are iterating over
         *\param pos position in city
         */
        Iter(CCity* city, int pos) : mCity(city), mPos(pos) {}

        /** Test for end of the iterator
        * \param other another iterator to check
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        std::shared_ptr<CTile> operator *() const { return mCity->mTiles[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CCity* mCity;   ///< City we are iterating over
        int mPos;       ///< Position in the collection
    };
    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mTiles.size()); }
private:
	void XmlTile(const std::shared_ptr<xmlnode::CXmlNode> &node); ///<tile for saving/loading
	void BuildAdjacencies(); 

	/// All of the tiles that make up our city
	std::vector<std::shared_ptr<CTile> > mTiles;

	/// Adjacency lookup support
	std::map<std::pair<int, int>, std::shared_ptr<CTile> > mAdjacency;
};


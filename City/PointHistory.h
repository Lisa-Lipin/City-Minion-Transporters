/**
* \file PointHistory.cpp
*
* \author Charles Owen
* 
* \author Elizabeth Lipin
* 
* 
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

  
protected:
    /// Data is stored in a linked list of data buckets,
    /// where each data bucket is a point and the next 
    /// to the next point in the array of points.

    /**
     * Bucket that stores a single point.
     */
    class PointBucket {
    public:
        Gdiplus::Point mPoint; ///< a point in mPoints
        int mNext = -1; ///< the next point
    };

    /// Array containing all available points in buckets.
    std::vector<PointBucket> mPoints;

    /// Array of all available locations in mPoints. 
    std::vector<int> mAvailables;

    /// Index to the first item in the linked list 
    /// of point history. Initially none.
    int mPointFirst = -1;

    /// Index to the last item in the linked list of
    /// point history. Initially none.
    int mPointLast = -1;

    /// Random number generator to use for shuffling
    std::default_random_engine mRandInt;

public:
    /** Iterator that iterates over the items in the collection */
    class Iter
    {
    public:
        /** Constructor
        * \param history The collection we are iterating over 
        * \param pos position in history
        */
        Iter(CPointHistory* history, int pos) : mPoints(history->mPoints), mPos(pos) {}
        /** Test for end of the iterator
        * \param other another point to check
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** copies iterator
        *\param other another point to check
        * \returns other point */
        const Iter& operator=(const Iter& other) 
        {
            mPoints = other.mPoints;
            mPos = other.mPos;
            return *this;
        }

        /** Get value at current position
        * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const { return mPoints[mPos].mPoint; }

        /** Increment the iterator
        * \returns Reference to this iterator */
        const Iter& operator++()
        {
            if (mPos != -1)
            {
                mPos = mPoints[mPos].mNext;
            }

            return *this;
        }

    private:
        std::vector<PointBucket> &mPoints;	///< Collection we are iterating over
        int mPos;	///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at last location in the array */
   Iter begin() { return Iter(this, mPointFirst); }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the front */
   Iter end() { return Iter(this, -1); }
};


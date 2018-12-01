//------------------------------------------------------------------------------
//
//      Tracks loader for ZDSimulator routes
//      (c) maisvendoo, 26/11/2018
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Tracks loader for ZDSimulator routes
 * \copyright maisvendoo
 * \author maisvendoo
 * \date 26/11/2018
 */

#ifndef     ROUTE_PATH_H
#define     ROUTE_PATH_H

#include    <fstream>

#include    <osg/Referenced>
#include    <osgDB/FileUtils>
#include    <osgDB/FileNameUtils>

#include    "track.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class RoutePath : public osg::Referenced
{
public:

    /// Constructor with automatic track loading
    RoutePath(const std::string &track_file_path);    

    /// Get cartesian position of track point
    osg::Vec3 getPosition(float railway_coord);

    osg::Vec3 getPosition(float railway_coord, osg::Vec3 &attitude);

    float getLength() const;

    osg::Group *getTrackLine(const osg::Vec4 &color);

protected:

    float                   length;
    std::vector<track_t>    track_data;

    bool load(const std::string &track_file_path);

    bool load(std::istream &stream);

    std::string getLine(std::istream &stream) const;

    track_t findTrack(float railway_coord, track_t &next_track);
};

#endif // ROUTE_PATH_H

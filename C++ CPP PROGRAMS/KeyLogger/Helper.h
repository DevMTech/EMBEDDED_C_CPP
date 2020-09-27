#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
//#include <iostream>

namespace Helper
{
    template <class T>

    std::string ToString(const T &);

    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time(&ms);
            struct tm *info = localtime(&ms);

            y = 1900 + info->tm_year;
            m = info->tm_mon + 1;
            d = info->tm_mday;


            H = info->tm_hour;
            M = info->tm_min;
            S = info->tm_sec;
        }

        DateTime(int y, int m, int d, int H, int M, int S): y(y), m(m), d(d), H(H), M(M), S(S) {}
        DateTime(int y, int m, int d): y(y), m(m), d(d), H(0), M(0), S(0) {}

        DateTime Now() const
        {
            return DateTime();
        }

        int y, m, d, H, M, S;

        std::string GetDateString() const
        {   // dd.mm.yy
            return  std::string(d < 10 ? "0" : "") + ToString(d) + "." +
                    std::string(m < 10 ? "0" : "") + ToString(m) + "." +
                    ToString(y);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {   // HH.MM.SS
            return  std::string(H < 10 ? "0" : "") + ToString(H) + sep +
                    std::string(M < 10 ? "0" : "") + ToString(M) + sep +
                    std::string(S < 10 ? "0" : "") + ToString(S);
        }

        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template <class T>

    std::string ToString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog(const std::string &s)
    {
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" << "\n" << s << std::endl << "\n";
        file.close();
    }
}

#endif // HELPER_H

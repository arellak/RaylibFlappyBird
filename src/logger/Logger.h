//
// Created by master on 25/03/2021.
//

#ifndef RAYLIBB_LOGGER_H
#define RAYLIBB_LOGGER_H

#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include <algorithm>

class Logger {
public:
    static inline std::string path;
    static inline bool DEBUG = true;
    static inline std::vector<std::string> buffer;

    static void setPath(std::string _path);
    static void log(std::string text);
    static void error(std::string text);
    static void warning(std::string text);

    static void write(std::string type, std::string text);
    static void writeBuffer(std::string text);
    static void saveBuffer();

    static void clearLogger();

    static std::string getTime();
};


#endif //RAYLIBB_LOGGER_H
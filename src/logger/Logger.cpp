//
// Created by master on 25/03/2021.
//

#include "Logger.h"

void Logger::log(std::string log) {
    write("LOG", log);
}

void Logger::error(std::string error) {
    write("ERROR", error);
}

void Logger::warning(std::string warning) {
    write("WARNING", warning);
}

void Logger::write(std::string type, std::string text) {
    // "[" << getTime() << "][" << type << "] " << text.c_str() << "\n"
    std::string bf("[");
    bf.append(getTime())
        .append("][")
        .append(type)
        .append("]")
        .append(text)
        .append("\n");
    buffer.push_back(bf);
}

void Logger::writeBuffer(std::string text) {
    if(DEBUG) {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file << text;
        file.close();
    }
}

void Logger::saveBuffer() {
    for(auto bufferLine : buffer) {
        writeBuffer(bufferLine);
    }
}

void Logger::setPath(std::string _path) {
    path = _path;
}

std::string Logger::getTime() {
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string sTime = ctime(&time);
    sTime.erase(std::remove(sTime.begin(), sTime.end(), '\n'), sTime.end());
    return sTime.substr(11, 8);
}

void Logger::clearLogger() {
    std::remove(path.c_str());
}

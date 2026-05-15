#pragma once
#include "Command.h"
#include <fstream>

class FileCommand : public Command {
private:
    std::string filename;
    std::string text;

public:
    FileCommand(const std::string& file,
                const std::string& txt)
        : filename(file), text(txt) {}

    void execute() override {
        std::ofstream out(filename, std::ios::app);

        if (out.is_open()) {
            out << text << std::endl;
        }
    }
};
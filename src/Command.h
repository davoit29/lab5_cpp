#pragma once
#include <string>

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};
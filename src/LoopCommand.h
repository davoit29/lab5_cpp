#pragma once
#include "Command.h"
#include <vector>

class LoopCommand : public Command {
private:
    int count;
    std::vector<Command*> commands;

public:
    LoopCommand(int c,
                const std::vector<Command*>& cmds)
        : count(c), commands(cmds) {}

    void execute() override {

        for (int i = 0; i < count; i++) {

            for (auto cmd : commands) {
                cmd->execute();
            }
        }
    }

    ~LoopCommand() {

        for (auto cmd : commands) {
            delete cmd;
        }
    }
};
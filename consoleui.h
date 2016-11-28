#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();
private:
    ServiceLayer _service;
};

#endif // CONSOLEUI_H

#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <servicelayer.h>
#include <stdlib.h>
#include <cstdio>


class ConsoleUI
{
public:
    ConsoleUI();
    void clearscreen ();
    void run();
private:
    ServiceLayer _service;
};

#endif //CONSOLEUI_H

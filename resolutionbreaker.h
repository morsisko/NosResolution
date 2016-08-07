#ifndef RESOLUTIONBREAKER_H
#define RESOLUTIONBREAKER_H
#include <Windows.h>
#include "patternscan.h"

class ResolutionBreaker
{
private:
    DWORD callAddy;
    DWORD formClose;
    DWORD windowBase;
    PatternScanner scanner;
public:
    ResolutionBreaker();
    void changeResolution(int x, int y);
};

#endif // RESOLUTIONBREAKER_H

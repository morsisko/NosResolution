#ifndef FPSBREAKER_H
#define FPSBREAKER_H
#include <qdebug.h>
#include <patternscan.h>

class FpsBreaker
{
private:
    PatternScanner scanner;
    int* fpsLimit;
public:
    FpsBreaker();
    void setFpsLimit(int value);
};

#endif // FPSBREAKER_H

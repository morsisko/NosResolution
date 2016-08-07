#ifndef FPSBREAKER_H
#define FPSBREAKER_H
#include <qdebug.h>

class FpsBreaker
{
private:
    int* fpsLimit;
public:
    FpsBreaker();
    void setFpsLimit(int value);
};

#endif // FPSBREAKER_H

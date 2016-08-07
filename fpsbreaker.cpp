#include "fpsbreaker.h"

FpsBreaker::FpsBreaker()
{
    fpsLimit = *(int**)(scanner.findPattern((BYTE*)(0x400000),
                                            0x200000,
                                            (BYTE*)("\xA3\x00\x00\x00\x00\xEB\x0A"),
                                            (char*)("x????xx")) + 1);
}

void FpsBreaker::setFpsLimit(int value)
{
    *fpsLimit = value;
}

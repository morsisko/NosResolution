#include "resolutionbreaker.h"

ResolutionBreaker::ResolutionBreaker()
{
    callAddy = (DWORD)(scanner.findPattern((BYTE*)(0x400000), 0x200000, (BYTE*)("\x55\x8B\xEC\x51\x53\x56\x57\x8B\xF9\x8B\xF2\x8B\xD8\xC6\x45\xFF\x01\x8B\x45\x08"), (char*)("xxxxxxxxxxxxxxxxxxxx")));
    formClose = *(DWORD*)(scanner.findPattern((BYTE*)(0x550000), 0x200000, (BYTE*)("\xA1\x00\x00\x00\x00\x8B\x80\x00\x00\x00\x00\x8B\x50\x5C"), (char*)("x????xx????xxx")) + 1);
    windowBase = *(DWORD*)(scanner.findPattern((BYTE*)(0x550000), 0x200000, (BYTE*)("\x8B\x1D\x00\x00\x00\x00\x8A\x1B\xA1\x00\x00\x00\x00"), (char*)("xx????xxx????")) + 2);
}

void ResolutionBreaker::changeResolution(int x, int y)
{
    //just for __asm
    DWORD callAddy = this->callAddy;
    DWORD formClose = this->formClose;
    DWORD windowBase = this->windowBase;

    __asm
    {
        push 0x10;
        push 0x3c;
        push 1;
        mov eax,dword ptr ds:[windowBase];
        mov eax,dword ptr ds:[eax];
        push eax;
        mov ecx,y;
        mov edx,x;
        mov eax, dword ptr ds:[formClose];
        mov eax, dword ptr ds:[eax];
        call callAddy;
    }

}

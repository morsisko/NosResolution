#pragma once
#include <Windows.h>

//Thanks to this: http://www.unknowncheats.me/forum/1064672-post23.html

class PatternScanner
{
public:
    PatternScanner() {};
    ~PatternScanner() {};
    bool dataCompare(BYTE* pData, BYTE* bSig, char* szMask)
    {
        for (; *szMask; ++szMask, ++pData, ++bSig)
        {
            if (*szMask == 'x' && *pData != *bSig)
                return false;
        }
        return (*szMask) == NULL;
    }

    BYTE* findPattern(BYTE* dwAddress, DWORD dwSize, BYTE* pbSig, char* szMask)
    {
        for (DWORD i = NULL; i < dwSize; i++)
        {
            if (dataCompare(dwAddress + i, pbSig, szMask))
                return dwAddress + i;
        }
        return 0;
    }
};



#include "base_layer.h"

internal void SeedRandom()
{
    srand((unsigned int)time(NULL));
}

internal f32 RandomF32(f32 min, f32 max)
{
    f32 scale = rand() / (f32) RAND_MAX;
    return min + scale * ( max - min );
}

internal String StringInit(char* cstr)
{
    String result = { 0 };
    result.str = (u8*)cstr;
    result.size = CStringLength(cstr);
    
    return result;
}

internal char CharToUpper(char c)
{
    if(c >= 'a' && c <= 'z')
        return(c - 32);
}

internal char CharToLower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return(c + 32);
}

internal void PrintString(String* str)
{
    printf("%s\n", str->str);
}

internal b32 CharIsAlpha(char c)
{
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'));
}

internal b32 CharIsDigit(char c)
{
    return (c >= '0' && c <= '9');
}

internal b32 CharIsSymbol(char c)
{
    return (c == '~' ||
            c == '!' ||
            c == '%' ||
            c == '^' ||
            c == '&' ||
            c == '*' ||
            c == '(' ||
            c == ')' ||
            c == '[' ||
            c == ']' ||
            c == '{' ||
            c == '}' ||
            c == '-' ||
            c == '+' ||
            c == '=' ||
            c == ';' ||
            c == ':' ||
            c == '<' ||
            c == '>' ||
            c == '/' ||
            c == '?' ||
            c == '.' ||
            c == ',');
}

internal b32 MatchString(String a, String b, MatchType flags)
{
    b32 result = 0;
    if(a.size == b.size)
    {
        result = 1;
        for(int i = 0; i < a.size; i++)
        {
            b32 char_match = 0;
            
            if(a.str[i] == b.str[i])
                char_match = 1;
            
            if(flags == MatchType_NoCaseCheck)
            {
                if(CharToUpper(a.str[i]) == CharToUpper(b.str[i]))
                    char_match = 1;
            }
            
            if(!char_match)
            {
                result = 0;
                break;
            }
        }
    }
    
    return result;
}
#ifndef INC_INCLUDEALL_H
#define INC_INCLUDEALL_H

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include <math.h>

typedef struct Sentence Sentence;
typedef struct Text Text;

struct Sentence{
    int CountSymbols;
    int MaxCountSymbols;
    wchar_t* sentence;
    wchar_t* ChangeSentence;
    int NewCount;
    int MaxNewCount;
};

struct Text{
    Sentence** text;
    int CountSentence;
    int MaxCountSentence;
    wchar_t* word;
};

#endif

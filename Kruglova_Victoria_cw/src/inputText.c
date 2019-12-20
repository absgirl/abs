#include "inputText.h"

#define ARRAY_SIZE 32

void input(Text* txt) {
    txt->word = malloc(sizeof(wchar_t) * ARRAY_SIZE);
    fgetws(txt->word, ARRAY_SIZE, stdin);
    while (wcschr(txt->word, L'\n') == NULL) {
        txt->word = realloc(txt->word, sizeof(wchar_t) * (wcslen(txt->word) + ARRAY_SIZE));
        fgetws(txt->word + wcslen(txt->word), ARRAY_SIZE, stdin);
    }
}
void InputInStruct(Text* txt){
    txt->CountSentence = 0;
    int bool = 1;
    txt->MaxCountSentence = ARRAY_SIZE;
    txt->text = malloc(ARRAY_SIZE * sizeof(Sentence*));
    for (int i = 0; txt->word[i] != '\n'; i++){
        if (txt->CountSentence == txt->MaxCountSentence){
            txt->MaxCountSentence += ARRAY_SIZE;
            txt->text = realloc(txt->text, txt->MaxCountSentence * sizeof(Sentence*));
        }
        if (bool == 1){
            txt->text[txt->CountSentence] = malloc(sizeof(Sentence));
            txt->text[txt->CountSentence]->CountSymbols = 0;
            txt->text[txt->CountSentence]->MaxCountSymbols = ARRAY_SIZE;
            txt->text[txt->CountSentence]->sentence = malloc( txt->text[txt->CountSentence]->MaxCountSymbols *
                                                                   sizeof(wchar_t));
            bool = 0;
        }
        if ( txt->text[txt->CountSentence]->MaxCountSymbols ==  txt->text[txt->CountSentence]->CountSymbols){
            txt->text[txt->CountSentence]->MaxCountSymbols += ARRAY_SIZE;
            txt->text[txt->CountSentence]->sentence = realloc( txt->text[txt->CountSentence]->sentence,  txt->text[txt->CountSentence]->MaxCountSymbols *
                                                                                                                   sizeof(wchar_t));
        }
        if(txt->word[i] != '.'){
            if(((txt->word[i] == ' ') || (txt->word[i] == ',')) && (txt->text[txt->CountSentence]->CountSymbols == 0)){
                continue;
            }
            txt->text[txt->CountSentence]->sentence[txt->text[txt->CountSentence]->CountSymbols] = txt->word[i];
            txt->text[txt->CountSentence]->CountSymbols++;
        }
        else{
            if( txt->text[txt->CountSentence]->CountSymbols == 0){
                continue;
            }
            txt->text[txt->CountSentence]->sentence = realloc( txt->text[txt->CountSentence]->sentence,  (txt->text[txt->CountSentence]->MaxCountSymbols + 1) *
                                                                                                                   sizeof(wchar_t));
            txt->text[txt->CountSentence]->sentence[txt->text[txt->CountSentence]->CountSymbols] = '.';
            txt->text[txt->CountSentence]->CountSymbols++;
            txt->text[txt->CountSentence]->sentence[txt->text[txt->CountSentence]->CountSymbols] = '\0';
            txt->CountSentence++;
            bool = 1;

        }
    }
    free(txt->word);
}

void output(Text* txt){
    for(int i = 0; i < txt->CountSentence; i++){
        wprintf(L"%ls\n", txt->text[i]->sentence);
    }
}


void CleanerSame(Text* txt){
    for(int i = 0; i < txt->CountSentence; i++){
        for(int j = 0; j < txt->CountSentence - 1; j++){
            if (i == j){
                continue;
            }
            else{
                if(txt->text[i]->CountSymbols == txt->text[j]->CountSymbols){
                    char f = 1;
                    for(int k = 0; k < txt->text[i]->CountSymbols; k++){
                        if (towupper(txt->text[i]->sentence[k]) != towupper(txt->text[j]->sentence[k])){
                            f = 0;
                        }
                    }
                    if (f == 1){
                        free(txt->text[j]);
                        txt->CountSentence--;
                        for (int k = j; k < txt->CountSentence; k++){
                            txt->text[k] = txt->text[k+1];
                        }
                        j--;
                    }
                }
            }
        }
    }
}



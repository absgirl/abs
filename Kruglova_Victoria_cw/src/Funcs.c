#include "Funcs.h"
#define ARRAY_SIZE 32

void change(Text* txt){
    for(int i = 0; i< txt->CountSentence; i++) {
        if (wcsstr(txt->text[i]->sentence, L"@") != NULL || wcsstr(txt->text[i]->sentence, L"#") != NULL ||
            wcsstr(txt->text[i]->sentence, L"%") != NULL) {
            txt->text[i]->MaxNewCount = ARRAY_SIZE;
            txt->text[i]->ChangeSentence = malloc(txt->text[i]->MaxNewCount * sizeof(wchar_t));
            txt->text[i]->NewCount = 0;
            for (int j = 0; j < txt->text[i]->CountSymbols; j++) {
                if (txt->text[i]->CountSymbols == txt->text[i]->MaxNewCount) {
                    txt->text[i]->MaxNewCount += ARRAY_SIZE;
                    txt->text[i]->ChangeSentence = realloc(txt->text[i]->ChangeSentence, txt->text[i]->MaxNewCount *
                                                                                         sizeof(wchar_t));
                }
                if (txt->text[i]->sentence[j] == '@') {
                    txt->text[i]->MaxNewCount += 4;
                    txt->text[i]->ChangeSentence = realloc(txt->text[i]->ChangeSentence, txt->text[i]->MaxNewCount *
                                                                                         sizeof(wchar_t));
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = '(';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'a';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 't';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = ')';
                    txt->text[i]->NewCount++;
                } else if (txt->text[i]->sentence[j] == '#') {
                    txt->text[i]->MaxNewCount += 9;
                    txt->text[i]->ChangeSentence = realloc(txt->text[i]->ChangeSentence, txt->text[i]->MaxNewCount *
                                                                                         sizeof(wchar_t));
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'<';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'р';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'е';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'ш';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'ё';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'т';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'к';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = L'а';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = '>';
                    txt->text[i]->NewCount++;
                } else if (txt->text[i]->sentence[j] == '%') {
                    txt->text[i]->MaxNewCount += 9;
                    txt->text[i]->ChangeSentence = realloc(txt->text[i]->ChangeSentence, txt->text[i]->MaxNewCount *
                                                                                         sizeof(wchar_t));
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = '<';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'p';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'e';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'r';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 's';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'e';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 'n';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = 't';
                    txt->text[i]->NewCount++;
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = '>';
                    txt->text[i]->NewCount++;
                } else {
                    txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = txt->text[i]->sentence[j];
                    txt->text[i]->NewCount++;
                }
            }
            txt->text[i]->ChangeSentence[txt->text[i]->NewCount] = '\0';
            free(txt->text[i]->sentence);
            txt->text[i]->sentence = txt->text[i]->ChangeSentence;
            txt->text[i]->CountSymbols = txt->text[i]->NewCount;
        }
    }
}

int WordNumb(wchar_t* a){
    int Space = 0;
    int Numb = 0;
    for(int i = 0; i < wcslen(a); i++){
        if(Space > 0){
            break;
        }
        if (iswspace(a[i]) || a[i] == ','){
            Space++;
        } else{
            Numb += (int)a[i];
        }
    }
    return Numb;
}



int cmp(const void* a, const void* b) {
    return (WordNumb((*(Sentence **) a)->sentence) - WordNumb((*(Sentence **) b)->sentence));

}
void sort(Text* txt) {
    qsort(txt->text, txt->CountSentence, sizeof(txt->text), cmp);
}

void del(Text* txt){
    int bool;
    int backbool;
    wchar_t consonant[] = {L'b', L'c', L'd', L'f', L'g', L'h', L'k', L'j', L'l', L'm', L'n', L'p', L'q', L'r', L's', L't', L'v', L'w', L'x', L'z', L'й' , L'ц', L'к', L'н', L'м', L'ш', L'щ', L'з', L'х', L'ф', L'в', L'п', L'р', L'с', L'д', L'ж', L'ч', L'л', L'г', L'б', L'т'};
    for(int i = 0; i < txt->CountSentence; i++){
        bool = 0;
        for(int j = txt->text[i]->CountSymbols - 2; j >= 0; j--){
            backbool = bool;
            for(int k = 0; k < wcslen(consonant); k++){
                if(txt->text[i]->sentence[j] == consonant[k]){
                    bool += 1;
                    break;
                }
            }
            if(backbool == bool){
                bool = 4;
            }
            if(bool == 3){
                free(txt->text[i]);
                txt->CountSentence--;
                for (int k = i; k < txt->CountSentence; k++){
                    txt->text[k] = txt->text[k+1];
                }
                i--;
                break;
            }
        }
    }
}

void CounterMin(Text* txt){
   int minute;
   int CountMinute = 0;
   int level;
   int TenToThePowerOf;
   for(int i = 0; i < txt->CountSentence; i++){
       for(int j = 0; j < wcslen(txt->text[i]->sentence) - 2; j++){
           if((j + 2) < wcslen(txt->text[i]->sentence) - 1){
               if ((txt->text[i]->sentence[j] == L's') 
&& (txt->text[i]->sentence[j+1] == L'e') 
&& (txt->text[i]->sentence[j+2] == L'c')  
&& (txt->text[i]->sentence[j-1] == L' '))
		   {
                   minute = 0;
                   level = 0;
                   for(int k = j - 2; (!iswspace(txt->text[i]->sentence[k]) && k >= 0); k--){
                       TenToThePowerOf = 1;
                       for(int p = 0; p < level; p++){
                           TenToThePowerOf *= 10;
                       }
                       minute += atoi((const char *) (txt->text[i]->sentence + k)) * TenToThePowerOf;
                       level++;
                   }
                   CountMinute += minute;
               }
           }
       }
   }
   wprintf(L"\t%d min\n", CountMinute / 60);
}





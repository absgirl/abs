#include "IncludeAll.h"
#include "inputText.h"
#include "Funcs.h"


int main() {
    setlocale(LC_ALL, "");
    Text txt;
    wprintf(L"///////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
            L"\t\t\t\t\tInput your text.\n"
            L"///////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    input(&txt);
    InputInStruct(&txt);
    CleanerSame(&txt);
    int NumberOfFunction = 0;
    int bool;
    while (NumberOfFunction != 8){
        wprintf(L"///////////////////////////////////////////////////////////////////////////////////////////////////////////\n"
                "\tChoose command:\n"
                L"\tPress 0, to output all text.\n"
                L"\tPress 1, to count minutes.\n"
                L"\tPress 2, to sort.\n"
                L"\tPress 3, to change @, %, #.\n"
                L"\tPress 4, to delete sentences.\n"
                L"\tPress else to close.\n"
                "///////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
        bool = wscanf(L"%d", &NumberOfFunction);
        if (bool != 1){
            NumberOfFunction = 8;
        }
        switch (NumberOfFunction) {
            case 0:
                output(&txt);
                break;
            case 1:
                CounterMin(&txt);
                break;
            case 2:
                sort(&txt);
                output(&txt);
                break;
            case 3:
                change(&txt);
                output(&txt);
                break;
            case 4:
                del(&txt);
                output(&txt);
                break;
            default:
                for(int i = 0; i < txt.CountSentence; i++){
                    free(txt.text[i]->sentence);
                    free(txt.text[i]);
                }
                free(txt.text);
                wprintf(L"See you.\n");
                NumberOfFunction = 8;
                break;
        }
    }
    return 0;
}

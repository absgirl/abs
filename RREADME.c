//Отсотировать слова в предложениях по количеству Кириллических букв. 
// Все слова, которые поменяли расположение вывести зеленым цветом на белом фоне.

//У меня нет разбиения на слова, я хз как это делать# abs

// нужно написать функцию сравнения строк
int w_cmp (void *str, void *str);
/*который будет пробегать по строкам и считать кирилические символы
символ кирилический, если его int значение лежит в таком промежутке [1040, 1103] (концы включены) */

int w_cmp(void *w1, void *w2) {
    wchar_t *ww1 = *((wchar_t **)w1);
    wchar_t *ww2 = *((wchar_t**) w2);
    int c1, c2 = 0;
    while (*ww1 != L'\0')
        if (1040 <= *ww1 <= 1103)
            c1++;
    while (*ww2 != L'\0')
        if (1040 <= *ww2 <= 1103)
            c2++;
    if (c1 < c2) return  -1;
    if (c1 == c2) return  0;
    if (c1 > c2) return  1;

/*
дальше надо пройти по wchar_t* предложения и сделать следующее:
скопируй строку в другую. это, чтобы не испортить оригинал
wchar_t *new_str = malloc(sizeof(wchar_t)*(strlen(sentence->что-то)+2));
wcscpy(sentence->что-то, new_str);
*/
    
void some_func (wchar_t* snt) {
    wchar_t *new_snt = malloc(sizeof(wchar_t)*(wcslen(snt)+2));
    wchar_t **some_arr = malloc(sizeof(wchar_t*)*wcslen(snt)); //этого точно хватит
    int arr_len = 0;
    wchar_t *p, *tmp = NULL;
    p = wcstok(p, " ,.", tmp);
    while (p) {
        some_arr[arr_len] = malloc(sizeof(wchar_t)*(wcslen(p)+20));
        wcscpy(some_arr[arr_len++], p);
        p = wcstok(p, " ,.", tmp);
    }
    wchar_t **cp_arr = malloc(sizeof(wchar_t*)*wcslen(snt));
    qsort(cp_arr, arr_len, sizeof(wchar_t*), w_cmp);
    
    for (int i = 0; i <arr_len; i++) {
        if (!wcscmp(some_arr[i], cp_arr[i])) {
            wchar_t* tmp = malloc (sizeof(wchar_t)*strlen(cp_arr[i]));
            wcscpy(tmp, /*тэг цвета*/);
            wcscpy(tmp+wcslen("тэг цвета "), cp_arr[i]);
            wcacpy(tmp+wcslen("тэг цвета ")+wcslen(cp_arr[i]), "закрыть тэг цвета");
        }
    }
    
    int i, j = 0;
    while(i < arr_len) {
        wcscpy(new_snt+j, cp_arr[i]);
        i ++;
        j += wcslen(cp_arr[i]);
    }
    
    /* тут надо заменить snt в структуре на new_snt  и освободить память */
}
/*
дальше можно использовать wcstok, чтобы разбить его на слова
их можно записывать в массив
потом отсортировать это массив функцией выше

дальше надо сравнить этот массив с тем, какой он был до этого
(до сортировки делаем комию массива)
сравниваем и там, где поменялись слова местами, добавляем флаги для цветной печати

склеиваем новый массив в строку и заменяем старую строку в структуре
*/



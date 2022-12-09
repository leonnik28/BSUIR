#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include "Array.h"

int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int if_letter(char s)
{
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        return 1;
    return 0;
}
int find_amount_word(char* s)
{
    int i = 0, cnt = 0;
     while (s[i] != '\0')
        {
            if ((i == 0 && if_letter(s[i]) == 1) ||
                (if_letter(s[i - 1]) == 0 && if_letter(s[i]) == 1))
                cnt++;

            if (s[i+1] == '\0')
                return cnt;
            i++;
        }
     return -1;
}

void search_word(char*& str, int* arr1, int amound) {
    int size = 0, j=0;
    int* arr = allocate(amound);
    for (int i = 0; i < amound; i++) {
        arr[i] == arr1[i];
    }
    int i = -1;
    while (str[i] != '\0' && j < amound)
    {
        i++;
        size = 0;
        if (if_letter(str[i]) == 1) {
            for (j++; if_letter(str[i]) == 1; i++) {     
                size++;
                arr[j] = size;
            }
       }      
    }
    printf(" \n");  
    int max = 0, num = 0;
    search_max(arr, amound, max, num);
    printf("%d \n%d \n", max, num);
    int  cnt = 0, k = 0, wright = 1;
    while (wright < max) {
        
        if (((k == 0 && if_letter(str[k]) == 1) ||
            (if_letter(str[k - 1]) == 0 && if_letter(str[k]) == 1)) && cnt <= num) {
            cnt++;
           
        }

        while ((if_letter(str[k]) == 1) && cnt >= num) {
            printf("%c", str[k]);
            k++;
            wright++;
        }

        k++;
    }
  
}

void search_max(int* arr, int size, int &max, int &num) {
    for (int i = 0; i < size+1; i++) {
        if (arr[i] > max) {
            max = arr[i];
            num = i;
        }
    }
}

char* search_word_one(char* str, char*& S) {
    int i = 0, k = 0;
    while (if_letter(str[i]) == 1) {
      
        if (S[k] == str[i] && if_letter(S[k-1]) == 0 ) {
            search(str, S, i, k);
            int c = 0;
            int q = k;
            int x = 0;
            while (i > 0) {
                char* els = (char*)malloc((num(S) - i-1)* sizeof(char));
                
                while (els[c+1] != '\0') {
                    if ((k - i) != x) {
                        els[c] = S[x];
                        c++;
                        x++;
                    }

                    
                    else {
                            els[c] = S[q];
                            c++;
                            q++;                       
                    }
                    
                } 
                char* e = search_word_one(str, els);
                if (e[c + 1] == '\0') {
                    return e;
                }
            }
        }
  
        
        else {
          k++; 
        }
        if (S[k + 1] == '\0') {
            return S;
        }
       
       
    }
    return S;
    free(S);
}

void search(char* str, char* S, int &i, int &k) {
    while (S[k] == str[i] && if_letter(str[i]) == 1) {

        i++;

        k++;
       
        if ((if_letter(S[k]) == 1 && if_letter(str[i]) == 0) || ((if_letter(S[k]) == 0 && if_letter(str[i]) == 1)) || (if_letter(str[i]) == 1 && str[i]!= S[k])) {
            i = 0;
            continue;
        }
    }
}

int search_min(char* str) {
    int i = 0, min = 0;
    
    while (if_letter(str[i]) == 0) i++;
    while (if_letter(str[i]) == 1) {
        i++;
        min++;
    }
    while (str[i] != '\0') {
        if (if_letter(str[i - 1]) == 0 && if_letter(str[i]) == 1) {
            int k = 0;
            while (if_letter(str[i]) == 1) {
                i++;
                k++;
                if (if_letter(str[i]) == 0 && min > k) min = k;
            }
        }
        i++;
    }
    printf("%d ", min);
    return min;
}

void str_copy(char* str1, char*& str2) {
    int len = str_len(str1);
    int i = 0;
    str2 = (char*)calloc(len + 1, sizeof(char));
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}


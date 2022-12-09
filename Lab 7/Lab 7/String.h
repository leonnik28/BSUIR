#ifndef STRING_HEADER
#define STRING_HEADER

int str_len(char* str);
int if_letter(char s);
int find_amount_word(char* s);
void search_word(char*& str, int* arr1, int amound);
void search_max(int* arr, int size, int &max, int &num);
char* search_word_one(char* str, char*& S);
void search(char* str, char* S, int& i, int &k);
void str_copy(char* str1, char*& str2);
int search_min(char* str);
#endif

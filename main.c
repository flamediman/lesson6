#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
char *END_OF_ARRAY = "FLAG";

void show_menu() {
  printf(
    "1. Выделить память\n"
    "2. Заполнить ячейки данными\n"
    "3. Заменить элемент\n"
    "4. Перевернуть массив\n"
    "5. Перевернуть строки\n"
    "6. Вывести массив\n"
    "0. Выход\n");
}

char **allocate_memory() {
  int num_words;
  int num_chars;
  printf("Сколько строк?\n");
  scanf("%d", &num_words);
  printf("Сколько символов в строке?\n");
  scanf("%d", &num_chars);

  char **new_pointer = malloc((num_words + 1) * sizeof(char *));
  for(int i = 0; i < num_words + 1; ++i) {
    new_pointer[i] = malloc(num_chars * sizeof(char));
  }

  new_pointer[num_words] = END_OF_ARRAY;
  return new_pointer;
}

void fill_memory(char **pointer) {
  printf("Введите текст:\n");

  for(int i = 0; strcmp(pointer[i], END_OF_ARRAY) != 0; ++i) {
    scanf("%s", pointer[i]);
  }
}

void print_memory(char **pointer) {

  for(int i = 0; strcmp(pointer[i], END_OF_ARRAY) != 0; ++i) {
    printf("%s\n", pointer[i]);
  }
}

void replace_memory(char **pointer) {
  int index;
  printf("Введите номер элемента, который вы хотите заменить\n");
  scanf("%d", &index);
  printf("Введите новый элемент\n");
  scanf("%s", pointer[index - 1]);
}

int lenght_of_array(char **pointer) {
  int i = 0;
  while(strcmp(pointer[i], END_OF_ARRAY) != 0) {
    i++;
  }
  return i - 1;
}

void reverse_array(char **pointer) {
  int length = lenght_of_array(pointer);
  int j = length;

  for(int i = 0; i < length; i++, j--) {
    char *mediator = malloc(strlen(pointer[i]) * sizeof(char));
    mediator = pointer[i];
    pointer[i] = pointer[j];
    pointer[j] = mediator;
    mediator = pointer[i];
  }
}

int main() {
  int action;
  char **pointer;
  pointer = malloc(5 * sizeof(char *));
  pointer[0] = "asd";
  pointer[1] = "123";
  pointer[2] = "lald";
  pointer[3] = "mnmn";
  pointer[4] = END_OF_ARRAY;

  while(1) {
    show_menu();
    scanf("%d", &action);
    switch(action) {
      case 0:
         exit(0);
        break;
      case 1:
        pointer = allocate_memory();
        break;
      case 2:
        fill_memory(pointer);
        break;
      case 3:
        replace_memory(pointer);
        break;
      case 4:
        reverse_array(pointer);
        break;
      case 5:

        break;
      case 6:
        print_memory(pointer);
        break;
    }
  }
}

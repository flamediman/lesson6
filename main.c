#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
char *END_OF_ARRAY = "FLAG";

void show_menu() {
  printf("1. Выделить память\n2. Заполнить ячейки данными\n3. Заменить элемент\n4. Вывести массив\n0. Выход\n");
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

int main() {
  int action;
  char **pointer;

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
        print_memory(pointer);
        break;
    }
  }
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// for debug
#include <Windows.h>
using namespace std;

void showcurrentdir() {
  char path[MAX_PATH];
  GetCurrentDirectoryA(MAX_PATH, path);
  printf("%s\n", path);
}

void checkbuffer(const char buffer[], const size_t length) {
  int wordStart = 0;
  bool hasLetterO = false;

  for (size_t i = 0; i < length; i++) {
    char ch = buffer[i];

    if (ch == ' ' || ch == '\n') {
      if (hasLetterO) {
        printf("%.*s\n", i - wordStart, buffer + wordStart);
        hasLetterO = false;
      }

      wordStart = i + 1;
    }
    else if (ch == 'о' || ch == 'О') {
      hasLetterO = true;
    }
  }

  if (hasLetterO)
    printf("%.*s\n", length - wordStart, buffer + wordStart);
}

int main() {
  setlocale(LC_ALL, "ru-RU");
  SetConsoleOutputCP(1251);
  // for debug
  showcurrentdir();

  FILE* const file = fopen("test.txt", "r");

  if (file == NULL) {
    printf("Не удалось открыть файл");
    getchar(); 

    return 0;
  }

  char buffer[256];
  size_t length;

  do {
    length = fread(buffer, 1, 256, file);

    checkbuffer(buffer, length);
  } while (length == 256);

  fclose(file);
  getchar();

  return 0;
}
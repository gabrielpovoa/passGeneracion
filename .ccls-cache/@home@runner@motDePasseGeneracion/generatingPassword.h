#include <cctype>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

void showOptions() {
  cout << "**********OPTION**********" << endl;
   cout << "Choose an option:" << endl;
      cout << "1. Generate password" << endl;
      cout << "2. View password" << endl;
      cout << "3. Exit" << endl;
      cout << "Option: ";
  cout << "***************************" << endl;
}

const char SETTING_LOWERCASE[] = "abcdefghijklmnopqrstuvwxyz";
const char SETTING_UPPERCASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char SETTING_UP_DIGITS[] = "0123456789";
const char SETTING_UP_SPECIAL_CHARACTERS[] = "!@#$%^*_/'',.:;~?";

class GEN_PASSWORD {
  random_device rd{};
  mt19937 rng{rd()};

public:
  string generate(size_t length, bool lowercase, bool uppercase, bool digits,
                  bool specialCharacters) {
    string result, password;

    if (!lowercase && uppercase && digits && specialCharacters) {
      return "";
    }
    if (lowercase) {
      result += SETTING_LOWERCASE;
    }
    if (uppercase) {
      result += SETTING_UPPERCASE;
    }
    if (digits) {
      result += SETTING_UP_DIGITS;
    }
    if (specialCharacters) {
      result += SETTING_UP_SPECIAL_CHARACTERS;
    }

    /*
    Objeto dist usado da classe abaixo que é usado para gerar números inteiros
    aleatórios uniformemente distribuídos e o intervalo dele é de zero a índice
    máximo válido para a string result ``result.length() - 1``.
    */
    uniform_int_distribution<int> dist(0, result.length() - 1);

    for (size_t i = 0; i < length; i++) {
      password += result[dist(rng)];
    }
    cout << password << endl;
    system("cls");
  }
};

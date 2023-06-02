#include "generatingPassword.h"
#include "userClass.h"
#include <iostream>
#include <vector>

using namespace std;
int main() {
  // showOptions();

  vector<User> usersClass;
  usersClass.emplace_back("tm105600", "tmrodrigo");
  usersClass.emplace_back("tm294800", "tmgabriel");
  usersClass.emplace_back("tm613200", "tmvitor");

  string initialInputId, initialInputPass;
  cout << "                    LOGIN\n                    " << endl;
  cout << "Enter your ID (Registry)" << endl;
  cin >> initialInputId;
  cout << "Enter your PASSWORD" << endl;
  cin >> initialInputPass;
  cout << "=============================================" << endl;

  // Criando a opção do usário logado poder gerar uma senha e ver essa senha;

  bool isLogged = false;
  // estamos percorrendo o vetor usersClass e verificando se o que foi inserido
  // pelo usuário como senha e login coincide com o que foi definido na classe.
  // Esse auto & permite q o compilador deduza a variável e o & (e comercial é
  // para avisar de que estamos usando como referência). Enquanto o const serve
  // para evitar cópias desnecessárias do noso vetor.
  for (const auto &user : usersClass) {
    if (user.getId() == initialInputId &&
        user.getPassword() == initialInputPass) {
      isLogged = true;
      break;
    }
  }

  if (isLogged) {
    GEN_PASSWORD gp;
    cout << "Você está logado, agora pode gerar senhas e vizualizá-las\n";
    // criar as opções para o usuário do que ele quer na senha e preencher aqui;
    // em seguida mostras a opção de senah salvas e sair;

    int option;
    while (true) {
      cout << "Choose an option:" << endl;
      cout << "1. Generate password" << endl;
      cout << "2. View password" << endl;
      cout << "3. Exit" << endl;
      cout << "Option: ";
      cin >> option;

      switch (option) {
      case 1:
        size_t length;
        bool lowercase, uppercase, digits, specialCharacters;
        string newPasword;
        cout << "Enter password length: ";
        cin >> length;
        cout << "Include lowercase? (0 - No, 1 - Yes): ";
        cin >> lowercase;
        cout << "Include uppercase? (0 - No, 1 - Yes): ";
        cin >> uppercase;
        cout << "Include digits? (0 - No, 1 - Yes): ";
        cin >> digits;
        cout << "Include special characters? (0 - No, 1 - Yes): ";
        cin >> specialCharacters;

        GEN_PASSWORD gp;
        newPasword = gp.generate(length, lowercase, uppercase, digits,
                                 specialCharacters);
        cout << "You generated password is : " << newPasword << endl;
        break;
      }
    }
  }
}
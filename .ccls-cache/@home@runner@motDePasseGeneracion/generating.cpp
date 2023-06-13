#include "generatingPassword.h"
#include "userClass.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void showOptions() {
  cout << "**********OPTION**********" << endl;
  cout << "Choose an option:" << endl;
  cout << "1. Generate password" << endl;
  cout << "2. View passwords" << endl;
  cout << "3. Exit" << endl;
  cout << "Option: ";
  cout << "***************************" << endl;
}

int main() {
  vector<User> usersClass;

  bool isLogged = false;
  string initialInputId, initialInputPass;

  while (!isLogged) {
    int loginOption;

    cout << "LOGIN" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Exit" << endl;
    cout << "Option: ";
    cin >> loginOption;

    switch (loginOption) {
    case 1:
      cout << "Enter your ID (Registry): ";
      cin >> initialInputId;
      cout << "Enter your PASSWORD: ";
      cin >> initialInputPass;

      for (const auto &user : usersClass) {
        if (user.getId() == initialInputId &&
            user.getPassword() == initialInputPass) {
          isLogged = true;
          break;
        }
      }

      if (!isLogged) {
        cout << "Invalid credentials. Please try again." << endl;
      }

      break;

    case 2: {
      string newId, newPassword;

      cout << "Enter your new ID (Registry): ";
      cin >> newId;
      cout << "Enter your new PASSWORD: ";
      cin >> newPassword;

      usersClass.emplace_back(newId, newPassword);
      cout << "Account created successfully. Please login." << endl;
      break;
    }

    case 3:
      cout << "Exiting..." << endl;
      return 0;

    default:
      cout << "Invalid option. Please try again." << endl;
      break;
    }
  }

  GEN_PASSWORD gp;
  vector<string> passwords;

  cout << "You are logged in and can now generate and view passwords." << endl;

  int option;
  do {

    showOptions();
    cin >> option;

    switch (option) {
    case 1: {
      size_t length;
      bool lowercase, uppercase, digits, specialCharacters;
      string newPassword;

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

      newPassword =
          gp.generate(length, lowercase, uppercase, digits, specialCharacters);
      passwords.push_back(newPassword);

      cout << "Your generated password is: " << newPassword << endl;
      showOptions(); // Display menu options again
      break;
    }

    case 2:
      showOptions(); // Display menu options again
      cout << "Viewing passwords..." << endl;
      reverse(passwords.begin(), passwords.end());
      for (const auto &password : passwords) {
        cout << password << endl;
      }
      break;

    case 3:
      cout << "Exiting..." << endl;
      return 0;

    default:
      cout << "Invalid option. Please try again." << endl;
      break;
    }
  } while (true);
}
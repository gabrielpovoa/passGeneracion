
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const char SETTING_LOWERCASE[] = "abcdefghijklmnopqrstuvwxyz";
const char SETTING_UPPERCASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char SETTING_UP_DIGITS[] = "0123456789";
const char SETTING_UP_SPECIAL_CHARACTERS[] = "!@#$%^*_/'',.:;~?";

class GEN_PASSWORD {
  // Declaração da instância rd para obter números aleatórios da máquina do
  // usuáriuo
  random_device rd{};
  // gerar numeros quase aleatórios e é inicializada pela instância do
  // random_device
  mt19937 rng{rd()};

public:
  string generate(size_t length, bool lowercase, bool uppercase, bool digits,
                  bool specialCharacters) {
    string result, password;

    // após criar nossa função generate, realizamos as verificações necessárias
    // e criamos varivés publicas responsáveis por armarzenar o resultado,
    // concatenar com nossas variáveis constantes.

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
    aleatórios distribuídos e o intervalo dele é de zero a índice
    máximo válido para a string result ``result.length() - 1``.
    */
    uniform_int_distribution<int> dist(0, result.length() - 1);

    // Iteramos o resultado length vezes armarzenado na nossa variavel result
    // através do objeto dist que é usado para armarzenar e adicinar esses
    // caracteres criados a variável string password.
    for (size_t i = 0; i < length; i++) {
      password += result[dist(rng)];
    }
    cout << password << endl;
  }
};

// O nosso método generate apenas fornece o método para gerar as senhas de
// acordo com o que o usuário deseja.
#include <iostream>
using namespace std;

class User {
  User();
  string id;
  string password;

public:
  /*
  User é definido como User(const string &_id, const string &_password).
  recebe dois parâmetros do tipo const string&: _id e _password. Esses
  parâmetros são usados para inicializar o id e password da classe. a  " _ "
  antes do nome dos parâmetros é para indicar que eles são parâmetros da
  classe.
  o const indica que não pode ser alterado o valor referencia em outra posição,
  que neste caso, esse valor é o "string&". e usamos essa referência para evitar
  cópias desnecessárias da string quando chamamos a função
*/

  /*
  Contrutor que inicializa as variáveis id e password da class User
  */
  User(const string &_id, const string &_password)
      : id(_id), password(_password) {}

  string getId() const { return id; }

  string getPassword() const { return password; }
};
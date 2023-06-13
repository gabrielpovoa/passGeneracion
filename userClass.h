#include <iostream>
using namespace std;

class User {
  User();
  string id;
  string password;

public:
  // User é definido como User(const string &_id, const string &_password). Ele
  // recebe dois parâmetros do tipo const string&: _id e _password. Esses
  // parâmetros são usados para inicializar o id e password da classe. a  " _ "
  // antes do nome dos parâmetros é para indicar que eles são parâmetros da
  // classe.

  User(const string &_id, const string &_password)
      : id(_id), password(_password) {}

  string getId() const { return id; }

  string getPassword() const { return password; }
};
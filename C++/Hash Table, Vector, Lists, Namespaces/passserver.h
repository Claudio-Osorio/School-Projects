#ifndef HASH_TABLE
#define HASH_TABLE
#include "hashtable.h"
#include <crypt.h>
#include <string>

using namespace COP4530;
using namespace std;

class PassServer
{
public:
    explicit PassServer(size_t size = 101);
    ~PassServer();
    bool load(const char *filename);
    bool addUser(std::pair<string, string> & kv);
    bool addUser(std::pair<string, string> && kv);
    bool removeUser(const string & k);
    bool changePassword(const pair<string, string> &p, const string & newpassword);
    bool find(const string & user);
    void dump();
    size_t size();
    bool write_to_file(const char *filename);

private:
    string encrypt(const string & str);
    HashTable<string, string> myServer;
};

#endif


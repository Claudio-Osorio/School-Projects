#include "passserver.h"
#include "hashtable.h"
// ************************************************************
// * Constructor, creates a hash table of the specified size. *
// ************************************************************
PassServer::PassServer(size_t size) : myServer(size)
{
}

// **************
// * Destructor *
// **************
PassServer::~PassServer()
{
    myServer.clear();
}

// *****************************************************************
// * Load a password file into the HashTable object.               *
// * Each line contains a pair of username and encrypted password. *
// *****************************************************************
bool PassServer::load(const char* filename)
{
    bool worked;
    worked = myServer.load(filename);
    return worked;
}

// *******************************************************************
// * Add a new username and password.                                *
// * The password passed in is in plaintext, it should be encrypted  *
// * before insertion.                                               *
// *******************************************************************
bool PassServer::addUser(std::pair<string, string>& kv)
{
    bool worked;
    pair<string,string> tempPair;
    tempPair.first = kv.first;
    tempPair.second = encrypt(kv.second);
    worked = myServer.insert(tempPair);
    return worked;
}

// ***************************
// * move version of addUser *
// ***************************
bool PassServer::addUser(std::pair<string, string>&& kv)
{
    bool worked;
    pair<string,string> tempPair;
    tempPair.first = kv.first;
    tempPair.second = encrypt(kv.second);
    worked = myServer.insert(move(tempPair));
    return worked;
}

// ********************************************
// * Deletes an existing user with username k *
// ********************************************
bool PassServer::removeUser(const string& k)
{
    bool worked;
    worked = myServer.remove(k);
    return worked;
}

// *********************************************************************
// * Changes an existing user's password.                              *
// * Note that both passwords passed in are in plaintext. They should  *
// * be encrypted before you interact with the hash table.             *
// * If the user is not in the hash table, return false. If p.second   *
// * does not match the current password, return false. Also return    *
// * false if the new password and the old password are the same       *
// * (i.e., we cannot update the password).                            *
// *********************************************************************
bool PassServer::changePassword(const pair<string, string>& p, const string& newpassword)
{
    pair<string,string> tempPair;
    tempPair.first = p.first;
    tempPair.second = encrypt(p.second);

    if(encrypt(p.second) != encrypt(newpassword) && myServer.match(tempPair) == true)
    {
        myServer.insert(make_pair(p.first, encrypt(newpassword)));
        return true;
    }
    return false;
}

// *********************************************************
// * Check if a user exists (if user is in the hash table) *
// *********************************************************
bool PassServer::find(const string& user)
{
    return(myServer.contains(user));
}

// *************************************************************************
// * Show the structure and contents of the HashTable object to the screen *
// * Same format as the dump() function in the HashTable class template.   *
// *************************************************************************
void PassServer::dump()
{
    myServer.dump();
}

//*********************************************************
//* Returns the size of the HashTable                     *
//* (The number of username/password pairs in the table)  *
//*********************************************************
size_t PassServer::size()
{
    return myServer.getsize();
}

// **********************************************************************
// * Save the username and password combination into a file.            *
// * Same format as the write_to_file() function in the HashTable class *
// * template.                                                          *
// **********************************************************************
bool PassServer::write_to_file(const char* filename)
{
    bool worked;
    worked = myServer.write_to_file((filename));
    return worked;
}

// *************************************************************
// * Encrypt the parameter str and return the encrypted string *
// *************************************************************
string PassServer::encrypt(const string& str)
{
    char *password = new char [100];
    char salt[] = "$1$########";
    string encPass = strcpy ( password, crypt(str.c_str(), salt));
    return encPass.substr(12);

}
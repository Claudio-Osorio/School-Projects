#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <iterator>
#include <vector>
#include <list>
#include <unistd.h>
#include <crypt.h>
#include <cstring>

using namespace std;
// max_prime is used by the helpful functions provided
// to you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity
// of the underlying vector of the hash table is zero.
static const unsigned int default_capacity = 11;

namespace COP4530
{
    //********************
    //* HELPER FUNCTIONS *
    //********************
    template <typename K, typename V>
    unsigned long prime_below (unsigned long);

    //********************
    //* CLASS DEFINITION *
    //********************
    template <typename K, typename V>
    class HashTable
    {
    public:
        HashTable(size_t size = 101);
        ~HashTable();
        bool contains(const K & k);
        bool match(const std::pair<K, V> &kv);
        bool insert(const std::pair<K, V> & kv);
        bool insert (std::pair<K, V> && kv);
        bool remove(const K & k);
        void clear();
        bool load(const char *filename);
        void dump();
        bool write_to_file(const char *filename);
        int getsize();

    private:
        size_t myhash(const K &k);
        size_t hsize;
        vector<list<pair<K, V>>> htable;
        void makeEmpty();
        void rehash();
        unsigned long prime_below (unsigned long n);
        void setPrimes(vector<unsigned long>& vprimes);
    };

//*************************************************
//* A D D I N G     I M P L E M E N T A T I O N S *
//*************************************************
#include "hashtable.hpp"

}
#endif

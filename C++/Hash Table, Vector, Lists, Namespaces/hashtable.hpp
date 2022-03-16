// *****         I M P L E M E N T A T I O N S         *****
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

// *********************************************************************
// * Constructor. Creates a hash table where the size of the vector is *
// * set to prime_below(size) (where size is default to 101), where    *
// * prime_below() is a private member function of the HashTable       *
// *********************************************************************
template <typename K, typename V>
HashTable<K, V>:: HashTable(size_t size)
{
    htable.resize(prime_below(size));
    hsize = 0;
}

// ***************************************************
// * Destructor. Deletes all elements in hash table. *
// ***************************************************
template <typename K, typename V>
HashTable<K, V>:: ~HashTable()
{
    if (hsize != 0 )
    {
        clear();
    }

}

// ****************************************
// * Checks if key K is in the hash table *
// ****************************************
template <typename K, typename V>
bool HashTable<K, V>:: contains(const K & k)
{
    size_t location = myhash(k);

    for (auto itr = htable[location].begin(); itr != htable[location].end(); ++itr)
    {
        if (itr->first == k)
        {
            return true;
        }
    }

    return false;
}

// *************************************************************
// * Checks if key-value pair "pair<K,V>" is in the hash table *
// *************************************************************
template <typename K, typename V>
bool HashTable<K, V>:: match(const std::pair<K, V> &kv)
{
    auto myK = kv.first;
    unsigned long location = myhash(myK);

    for(auto itr = htable[location].begin(); itr != htable[location].end(); ++itr)
    {
        if (*itr == kv )
        {
            return true;
        }
    }
    return false;
}

// ************************************************************
// * Adds the key-value pair "pair<K,V>" into the hash table. *
// * Don't add if kv is already in the hash table.            *
// * If the key is the hash table but with a different value, *
// * the value should be updated to the new one with kv.      *
// * Return true if kv is inserted or the value is updated;   *
// * return false otherwise (i.e. if kv is in the hash table) *
// ************************************************************
template <typename K, typename V>
bool HashTable<K, V>:: insert(const std::pair<K, V> & kv)
{
    if ( (hsize+1) > htable.size())
        rehash();

    auto & specificList = htable[myhash(kv.first)];

    for(auto itr = specificList.begin(); itr != specificList.end(); itr++)
    {
        if(itr->first == kv.first)
        {
            cout << "ERROR: This key already exists in the hashtable and cannot be added" << endl;
            return false;
        }
    }

    specificList.push_back(kv);
    hsize++;
    return true;
}

// **************************
// * Move version of insert *
// **************************
template <typename K, typename V>
bool HashTable<K, V>:: insert (std::pair<K, V> && kv)
{
    if ( (hsize+1) > htable.size())
        rehash();

    auto & specificList = htable[myhash(kv.first)];

    for(auto itr = specificList.begin(); itr != specificList.end(); itr++)
    {
        if(itr->first == kv.first)
        {
            cout << "ERROR: This key already exists in the hashtable and cannot be added" << endl;
            return false;
        }
    }

    specificList.push_back(move(kv));
    hsize++;
    return true;
}

// **********************************************************************
// * Deletes the key K and the corresponding value if it is in the hash *
// * table. Return true if k is deleted, return false otherwise         *
// * (i.e. if key k is not in the hash table).                          *
// **********************************************************************
template <typename K, typename V>
bool HashTable<K, V>:: remove(const K & k)
{
    auto & specificList = htable[myhash(k)];

    for(auto itr = specificList.begin(); itr != specificList.end(); itr++)
    {
        if(itr->first == k)
        {
            specificList.erase(itr);
            hsize--;
            return true;
        }
    }
    return false;
}

// ******************************************
// * Deletes all elements in the hash table *
// ******************************************
template <typename K, typename V>
void HashTable<K, V>:: clear()
{
    makeEmpty();
}

// ***********************************************************************
// * load the content of the file with name filename into the hash table.*
// * In the file, each line contains a single pair of key and value,     *
// * separated by a white space.                                         *
// ***********************************************************************
template <typename K, typename V>
bool HashTable<K, V>:: load(const char *filename)
{
    ifstream instream;
    instream.clear();
    instream.open(filename);
    K key;
    V value;

    if(!instream)
    { return false; }

    while(!instream.eof())
    {
        instream >> key >> value;
        insert(make_pair(key, value));
    }

    instream.close();
    return true;
}

// *************************************************************************
// * Displays all entries in the hash table. If an entry contains multiple *
// * key-value pairs, separate them by a semicolon character (:)           *
// * (see the provided executable for the exact output format).            *
// *************************************************************************
template <typename K, typename V>
void HashTable<K, V>:: dump()
{
    for(int count = 0; count < htable.size(); count++)
    {
        cout << "v[" << count << "]: ";
        for(auto itr = htable[count].begin(); itr != htable[count].end(); itr++)
        {
            if(itr != htable[count].begin())
            {
                cout << " | ";
            }
            cout << itr->first << ' ' << itr->second;
        }
        cout << endl;
    }
}

// *************************************************************************
// * Writes all elements in the hash table into a file with name filename. *
// * Similar to the file format in the load function, each line contains a *
// * pair of key-value pair, separated by a white space.                   *
// *************************************************************************
template <typename K, typename V>
bool HashTable<K, V>:: write_to_file(const char *filename)
{
    K key;
    V value;
    ofstream outstream;
    outstream.open(filename);

    if(!outstream)
    { return false; }

    for(int x = 0; x < htable.size(); x++){
        auto & myL = htable[x];
        auto myItr = myL.begin();

        if(!myL.empty()){
            outstream << myItr->first << " " << myItr->second << endl;
            while(++myItr != myL.end())
            {
                outstream << myItr->first << " " << myItr->second << endl;
            }
        }
    }

    outstream.close();
    return true;
}

// *******************************************************************
// * returns largest prime number <= n or zero if input is too large *
// * This is likely to be more efficient than prime_above(), because *
// * it only needs a vector of size n                                *
// *******************************************************************
template <typename K, typename V>
unsigned long HashTable <K, V>::prime_below (unsigned long n)
{
    if (n > max_prime)
    {
        cout << "ERROR: Input greater than expected for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        cout << "ERROR: Input should be at least greater than 1" << endl;
        return 0;
    }

    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}


// ***********************************************************************
// * Sets all prime number indexes to 1. Called by method prime_below(n) *
// ***********************************************************************
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

// ***** H E L P E R   F U N C T I O N S *****

// *********************************************************
// * Deletes all elements in the hash table.               *
// * The public interface clear() will call this function. *
// *********************************************************
template <typename K, typename V>
void HashTable<K, V>:: makeEmpty()
{
    hsize = 0;
    for(auto & element : htable)
    {
        element.clear();
    }
}

// *********************************************************
// *  Called when the number of elements in the hash table *
// *  is greater than the size of the vector.              *
// *********************************************************
template <typename K, typename V>
void HashTable<K, V>:: rehash()
{
    auto oldLists = htable;
    htable.resize(prime_below(2 * htable.size()));
    makeEmpty();
    for(auto & thisList : oldLists)
        for(auto & x : thisList)
            insert(move(x));
}

// ******************************************************************
// * Returns the index of the vector entry where k should be stored *
// ******************************************************************
template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K &k)
{
    static hash<K> hashed;
    return hashed(k) % htable.size();
}

// *************************************
// * Returns the size of the hashtable *
// *************************************
template <typename K, typename V>
int HashTable<K, V>::getsize()
{
    return hsize;
}

#endif



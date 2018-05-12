#include "../inc/hash_table.h"

namespace lab8{
    unsigned hash_table::hash_1(std::string to_hash) {
        // DJB2 Hashing Algorithm
        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    unsigned hash_table::hash_2(std::string to_hash) {
        // BKDR Hashing Algorithm
        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {// PRIME[n+1]= next prime after 2*PRIME[n]. Use this for setting max size
        int n= 0;
        while(max_size>PRIMES[n]){
            n++;
        }
        key_value *toCopy = new key_value[max_size];
        for(int i=0; i<max_size; i++){
            toCopy[i].key = hash_table_array[i].key;
            toCopy[i].value= hash_table_array[i].value;
        }
        delete[] hash_table_array;
        hash_table_array = new key_value[PRIMES[n]];
        for(int k =0; k<PRIMES[n]; k++){
            hash_table_array[k].key = "\0";
            hash_table_array[k].value = 0;
        }
        for(int l=0; l<PRIMES[n]; l++){
            if(toCopy[l].key !="\0"){
                insert(toCopy[l].key,toCopy[l].value);
            }
        }
        max_size = PRIMES[n];
        // Expand the hash table by a factor of 2 every time this function is called
    }

    hash_table::hash_table(char type) {
        int attempt = 1;
        if(type == 'l'){ //hash_1() + attempt
        probing = 'l';
        }
        if(type == 'q'){
        probing = 'q';
        }
        if(type == 'd'){
        probing = 'd';
        }
        else{
            probing = 'l';
        }
        max_size = 100;
        hash_table_array[max_size];
        for(int i=0; i<max_size; i++){
            hash_table_array[i].key = "\0";
            hash_table_array[i].value= 0;
        }
        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         *
         * Create a hash table with an initial size of 100
         */
    }

    hash_table::~hash_table() {
    current_size =0;
    max_size =0;
    delete[] hash_table_array;
    }

    bool hash_table::insert(std::string key, int value) {
        int attempt = 1;
        int hash = hash_1(key);
        int hash2 = hash_2(key);
        if (hash_table_array[hash % max_size].key == '\0') {
            hash_table_array[hash % max_size].key = key;
            hash_table_array[hash % max_size].value = value;
            return true;
        }
        if (in_table(key)) {
            return false; //returns so we don't duplicate on accident. May double the complexity
        }
        if (current_size >= max_size * 0.65) {
            expand();//haven't done the expand function yet but i remember this in lab
        }//0.65-0.80 full
        if (probing == 'l') {//hash1 + attempt
            while (hash_table_array[hash % max_size].key != '\0') {
                attempt++;
                if (hash_table_array[hash % max_size].key == '\0') {
                    hash_table_array[hash % max_size].key = key;
                    hash_table_array[hash % max_size].value = value;
                    return true;
                }
            }
        }
        if (probing == 'q') { //hash1 + attempt^2
        while(hash_table_array[hash+(attempt^2) %max_size].key != '\0'){
attempt++;
            if (hash_table_array[hash+(attempt^2)% max_size].key == '\0') {
                hash_table_array[hash+(attempt^2) % max_size].key = key;
                hash_table_array[hash+(attempt^2) % max_size].value = value;
                return true;
            }
        }
        }
        if (probing == 'd') { //hash 1 + attempt*has 2
            while(hash_table_array[hash+(attempt * hash2) %max_size].key != '\0'){
                attempt++;
                if (hash_table_array[hash+(attempt * hash2)% max_size].key == '\0') {
                    hash_table_array[hash+(attempt * hash2) % max_size].key = key;
                    hash_table_array[hash+(attempt * hash2) % max_size].value = value;
                    return true;
                }
            }
        }
        // Insert a key according to the defined probing technique
        // If you run into an issue where you get an infinite collision loop,
        //   figure out a way to get out of the loop.
        return true;
    }

    bool hash_table::in_table(std::string key) {
        int attempt = 1;
        int hash = hash_1(key);
        int hash2 = hash_2(key);
        if (hash_table_array[hash % max_size].key == key) {
            return true;
        }
        if (probing == 'l') { //hash 1else {//Linear
            while (hash_table_array[hash % max_size].key != key) {
                attempt++;
                if (hash_table_array[hash % max_size].key == key) {
                    return true;
                }
                if (attempt == max_size) {
                    return false; // gets out of the while loop
                }
            }
            return false;
        }
        if (probing == 'q') {//quad hash_1 + attempt^2
            while (hash_table_array[hash + (attempt ^ 2) % max_size].key != key) {
                attempt++;
                if (hash_table_array[hash + (attempt ^ 2) % max_size].key == key) {
                    return true;
                }
            }
            return false;
        }
        if (probing == 'd') { // double hash_1 + attempt * hash_2
            while (hash_table_array[(hash + (attempt * hash2)) % max_size].key != key) {
                attempt++;
                if (hash_table_array[(hash + (attempt * hash2)) % max_size].key == key) {
                    return true;
                }
            }
            return false;
        }
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind
    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        // Use the specified probing technique
        return 0;
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hash table.
        // Keep collisions in mind
        // Use the specified probing technique
    }

    void hash_table::remove(std::string key){
        // Remove an item from the hash table. Keep collisions in mind
        // Use the specified probing technique
        // If the item isn't in the table, do nothing.
    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}
    return std::string();
    }
}
//        if(probing == 'l'){//hash1 + attempt
//
//        }
//        if(probing == 'q'){ //hash1 + attempt^2
//
//        }
//        if(probing == 'd'){ //hash 1 + attempt*has 2
//
//        }
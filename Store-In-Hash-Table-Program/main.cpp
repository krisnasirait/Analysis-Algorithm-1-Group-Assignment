#include <vector>
#include "chaining.cpp"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
template <typename T>
class HashTable {
    public:
    vector<chaining<T>> table;
	int hashFunction (T str) { // hash function
		int p = 67; // close prime number to the number of possible different characters in the string
		int m = size();
		unsigned long long power_of_p = 1L;
		unsigned long long hash_val = 0L;
		for (int i = 0; i < str.length(); i++) {
			
			hash_val = ((hash_val + (str[i] - '.' + 1)) * power_of_p) % m;
			power_of_p = (power_of_p * p) % m;        
		}
		return hash_val;
	}
	
	HashTable (int size) {
		table.resize (size); // resize vector to support size elements.
	}
	~HashTable() {
		for (int i = 0; i < table.size(); i++)
		  table[i].genEmpty();
	}
	int size() {
		return table.size();
	}
	void insert (T newItem) {
		table[hashFunction(newItem)].insertFront(newItem);

	}
	int retrieve (T & target) {
		return table[hashFunction(target)].search(target);
	}
    T retrieveByIndex (int index) {
		return table[index].getLast(); // get last element in the list
	}
	int numberOfCollusion(){
		int numberOfCollusion = 0;
		for (int i = 0; i < size(); ++i){
			if(table[i].size > 1)
				numberOfCollusion += table[i].size - 1;
		}
        return numberOfCollusion;
	}
};

int main(){
    int setChoice;
    int size = 0;
    cout << "Program 1a - Hash table with chaining" << endl;
    cout << "1. Set A (100 email addresses) \n2. Set B (1,000,000 email addresses) \n3. Set C (5,000,000 email addresses) "  << endl;
    cout << "Enter number of data set you want to test: ";
    cin >> setChoice; 

    cout << "\n\nChaining hash table, size of the table = " << (0.9 * ((setChoice == 1) ? 100 : ((setChoice == 2) ? 100000 : 500000))) << endl;
    size = (0.9 * ((setChoice == 1) ? 100 : ((setChoice == 2) ? 100000 : 500000)));   

    // cout << size;     
    string  chosenFile = (setChoice == 1 ? "A" : (setChoice == 2 ? "B" : "C"));
    string fileName = "set" +  chosenFile + ".txt";
    ifstream fileInput(fileName);
    string email;
    string target;
    string foundTargets[10];
    string notFoundTargets[10] = {"00gt5.oetw2.Aytep@com", "00gt5.oetw2.Aytep@ewfe", "00gt5.oetw2.Aytep@225", "00gt5.1452.Aytep@123", "00gt5.1452.Aytep@sfd", "00gt5.1452.Aytep@uyf",
    "00gt5.1452.Aytep@32f", "00gt5.1452.saddw@344", "53d63.1452.Aytep@uyf","00gt5.1452.Aytep@uyf" };
    
    HashTable<string> ht(size);
    auto startInsert = chrono::system_clock::now();
    while(fileInput >> email){
        ht.insert(email);
    }
    auto endInsert = chrono::system_clock::now();
    chrono::duration<double> Insertduration = endInsert - startInsert;
    cout << "Inserting duration: " << Insertduration.count() << "s\n";
   

    srand((unsigned) time(0));

     for(int i = 0; i < 10; ++i){
        int randIndex = (rand() % size);
        if(ht.table[randIndex].size != 0)
            foundTargets[i] = ht.retrieveByIndex(randIndex); // get 10 random emails from the hash table and assign them to the could be found targets.
        else
            --i;
    }




    int foundAt[10];
    auto startSearchFound = chrono::system_clock::now();
    for(int j = 0; j < 10; ++j){
        foundAt[j] = ht.retrieve(foundTargets[j]); // store the index of the list where the email is found
    }
    auto endSearchFound = chrono::system_clock::now();
    chrono::duration<double> searchFoundDuration = endSearchFound - startSearchFound;
    cout << "Search duration(found): " << searchFoundDuration.count() << "s\n";

    auto startSearchNotFound = chrono::system_clock::now();
    for(int j = 0; j < 10; ++j){
        ht.retrieve(notFoundTargets[j]);
    }
    auto endSearchNotFound = chrono::system_clock::now();
    chrono::duration<double> searchNotFoundDuration = endSearchNotFound - startSearchNotFound;
    cout << "Search duration(not found): " << searchNotFoundDuration.count() << "s\n";

    cout << "Number of collusions: " << ht.numberOfCollusion() << endl;
    cout << endl;
    for(int i = 0; i < 10; ++i){
        cout << "Target #" << i << ": " <<  foundTargets[i] << " found at list: " << ht.hashFunction(foundTargets[i]) << " at index: "<<foundAt[i] << endl;
    }

    // cout << ht.retrieveByIndex(0);
    return 0;
}
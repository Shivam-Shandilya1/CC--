#include <bits/stdc++.h>
using namespace std;
class GameEntry { 
public:
	GameEntry(const string &n = "", int s = 0); 
	string getName() const;						
	int getScore() const;						
private:
	string name; 
	int score;	 
};
GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {
}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }
class Scores { 
public:
	Scores(int maxEnt = 10);				  
	~Scores();								  
	void add(const GameEntry &e);			  
	GameEntry remove(int i) ; 
	void printAllScores();
private:
	int maxEntries;		// maximum number of entries
	int numEntries;		// actual number of entries
	GameEntry *entries; // array of game entries
};
Scores::Scores(int maxEnt) {			 // constructor
	maxEntries = maxEnt;				 // save the max size
	entries = new GameEntry[maxEntries]; // allocate array storage
	numEntries = 0;						 // initially no elements
}
Scores::~Scores() { 
	delete[] entries;
}
void Scores::add(const GameEntry &e) {
	int newScore = e.getScore(); // score to add
	if (numEntries == maxEntries) { // the array is full
		if (newScore <= entries[maxEntries - 1].getScore())
			return; // not high enough - ignore
	}
	else
		numEntries++; // if not full, one more entry
	int i = numEntries - 2; // start with the next to last
	while (i >= 0 && newScore > entries[i].getScore() ) {
		entries[i + 1] = entries[i]; // shift right if smaller
		i--;
	}
	entries[i + 1] = e; // put e in the empty spot
}
GameEntry Scores::remove(int i) 
{
	if ((i < 0) || (i >= numEntries)) // invalid index
		throw("IndexOutOfBounds - Invalid index");
	GameEntry e = entries[i]; // save the removed object
	for (int j = i + 1; j < numEntries; j++)
		entries[j - 1] = entries[j]; // shift entries left
	numEntries--;					 // one fewer entry
	return e;						 // return the removed object
}
void Scores::printAllScores()
{
	for (int i = 0; i < numEntries; i++)
	{
		cout << entries[i].getName() << " : " << entries[i].getScore() << "\n";
	}
}
int main()
{
    Scores S;
    int i=-1;
    while(i!=4)
    {
        cout<<"1: Add Player"<<endl;
        cout<<"2: Remove Player By Index"<<endl;
        cout<<"3: Print Scores"<<endl;
        cout<<"4: Exit"<<endl;
        cin>>i;
        switch(i)
        {
            case 1:
            {
                string str;
                int sc;
                cout<<"Enter Player Name and Score: "<<endl;
                cin>>str>>sc;
                S.add(GameEntry(str,sc));
                break;
            } 
            case 2:
            {
                int i;
                cout<<"Choose Index to Remove Player: ";
                cin>>i;
                S.remove(i);
                break;
            } 
            case 3: S.printAllScores(); break;
            case 4: break;
            default: cout<<"Choose Correct options."<<endl;break;
        }
    }
}
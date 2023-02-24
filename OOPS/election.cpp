#include <iostream>

using namespace std;

class Election{
    int candCount[6];

    public:
    bool checkAndIncrement(int candNumber){
        if(candNumber < 1 && candNumber > 5)
            return false;

        this->candCount[candNumber]++;
        return true;
    }

    void incrementVote(int candNumber){
        if(!checkAndIncrement(candNumber)){
            this->candCount[0]++;
        }
    }

    void printVotes(){
        cout << endl << "Received votes:" << endl;
        int maxIndex = 1;
        for(int i = 1; i < 6; i++){
            cout << "Candidate " << i << ":\t" << this->candCount[i] << endl;
            if(maxIndex != 0 && this->candCount[i] > this->candCount[maxIndex])
                maxIndex = i;
        }
        cout << "Spoil votes:\t" << this->candCount[0] << endl << endl;
        cout << "Candidate " << maxIndex << " won" << endl;
    }
};

int main()
{
    cout << "This is a voting system" << endl;
    bool cont = true;
    Election el;
    while(cont){
        int cand;
        cout << "Candidates:" << endl;
        cout << "\tPut 1 for Candidate ABC" << endl << "\tPut 2 for Candidate DEF" << endl << "\tPut 3 for Candidate GHI" << "\tPut 4 for Candidate JKL" << endl << "\tPut 5 for Candidate MNO" << endl << "\tExit Vote -> -1" << endl;;
        cout << "Enter your vote for candidate number: ";
        cin >> cand;

        if(cand == -1)
            break;

        el.incrementVote(cand);
    }

    el.printVotes();

    return 0;
}
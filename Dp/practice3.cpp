// //Q. Simulate a poker game in language of your choice: 
// Start basic – code to compare 2 hands: 
// 2 players 
// Straight Flush > Flush > Straight
// No shuffling etc.; just logic to compare two hands 

// -----------------------------------------------------------------------------------------------------
// Context
// -----------------------------------------------------------------------------------------------------

// - A "card" has two properties - "suite" and "rank". 
//   - 4 "suites" - "Hearts", "Spades", "Clubs", "Diamonds"
//   - 13 "ranks" - "A" (Ace, 1) , "2", "3", "4", "5", "6", "7", "8", "9", "10", "J" (Jack, 11), "Q" (Queen, 12), "K" (King, 13)
//   - Total possible cards - 13 * 4 = 52 combinations
//   - Input will be in following form : `(suites, rank)`. For e.g. ("Hearts","A") , ("Spades", "10").
//   - Read up here - https://en.wikipedia.org/wiki/Standard_52-card_deck#:~:text=A%20standard%2052%2Dcard%20French,(i.e.%20double%20headed)%20images.

// - A collection of five cards is called a "hand". 
//   - A hand can have special characteristics (also called "ranking") like it being a "straight", "flush" etc. 
//   - Read up here 
//     - https://www.pokernews.com/poker-hands.htm
//     - https://www.888poker.com/magazine/how-to-play-poker/hands

// - TODO:
//   - Define a class "card" which takes "suite" and "rank" as Strings
//   - Define a class "hand" which has following two properties
//     * "cards" = list of 5 cards, 
//     * "ranking" = best possible "ranking" (e.g. "straight", "three-of-a-kind", "flush")
//   - Write methods to check the following - 
//     - getRanking: Method which call above methods and return the "ranking" 
//       (for now only consider "straight", "flush", "straight-flush", and "none")
//     - You can define the following helper methods:
//       - isFlush: Checks if a given "hand" is a "flush"
//       - isStraight: Checks if a given "hand" is a "straight"
//         - Important Note: While checking for "straight", "A" (Ace) can be used as both 1 or 14

// -----------------------------------------------------------------------------------------------------

// Solution:

// -----------------------------------------------------------------------------------------------------

// Tests:

// ("Hearts","A"), ("Hearts","4"), ("Hearts","6"), ("Hearts","J"), ("Hearts","Q") : Flush
// ("Clubs","A"), ("Hearts","4"), ("Diamonds","3"), ("Spades","2"), ("Spades","5") : Straight
// ("Clubs","A"), ("Hearts","J"), ("Diamonds","Q"), ("Spades","K"), ("Spades","10") : Straight
// ("Clubs","A"), ("Clubs","4"), ("Clubs","3"), ("Clubs","2"), ("Clubs","5") : Straight Flush
// ("Clubs","A"), ("Hearts","J"), ("Diamonds","Q"), ("Spades","9"), ("Spades","10") : None

// -----------------------------------------------------------------------------------------------------
// /

#include <bits/stdc++.h>
using namespace std;

map<string,int>ValuesRanks={
    {"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"J",11},{"Q",12},{"K",13},{"A",14}
};

//card class
class Card{
    public:
    string suit;
    string rank;

    Card(string s,string r):suit(s),rank(r){}

};

//class hand
class Hand{

    public:
    vector<Card> cards;

    Hand(vector<Card>c):cards(c){}

    bool isFlush()
    {
        string s =cards[0].suit;
        for(auto & card:cards){
            if(card.suit!=s){
                return false;
            }
           
        }
         return true;
    }

    bool isStraight(){

        vector<int>values;
        for(auto& card: cards){
            values.push_back(ValuesRanks[card.rank]);

        }
       sort(values.begin(),values.end());

       bool temp=true;
       for(int i=1;i<5;i++){
        if(values[i]!=values[i-1]+1){
            temp=false;

        }

       }

    //    bool AceAsLow=false;
    //    if(values[4]==14){
    //     vector<int>lowAceVal=values;
    //     lowAceVal[4]=1;
    //     sort(values.begin(),values.end());

    //     AceAsLow=true;
    //     for(int i=1;i<5;i++){
    //         if(values[i]!=values[i-1]+1){
    //             AceAsLow=false;
    //         }
    //     }
    //    }
       return temp;
    }

    string getRanking(){
        bool flush=isFlush();
        bool straight=isStraight();
        
        if(flush&&straight)return "Straight-Flush";
       else if(flush)return "Flush";
       else if(straight)return "Straight";
       else return "None";
    }
};

int main() {
  
    vector<Card> hand1={
        Card ("Hearts","A"), Card("Hearts","4"), Card("Hearts","6"), Card("Hearts","J"), Card("Hearts","Q")

    };

      vector<Card> hand2={
        Card("Clubs","A"), Card("Hearts","4"), Card("Diamonds","3"), Card("Spades","2"), Card("Spades","5")

    };

        vector<Card> hand3={
       Card ("Clubs","A"), Card("Hearts","J"),Card ("Diamonds","Q"), Card("Spades","K"), Card("Spades","10")

    };
            vector<Card> hand4={
       Card("Clubs","A"),Card ("Clubs","4"),Card ("Clubs","3"),Card ("Clubs","2"),Card ("Clubs","5")
    };
                vector<Card> hand5={
      Card("Clubs","A"), Card("Hearts","J"),Card ("Diamonds","Q"), Card("Spades","9"), Card("Spades","10")};

      vector<Card>hand6={Card("Clubs","K"),Card ("Hearts","J"),Card ("Diamonds","Q"),Card ("Spades","K"), Card("Spades","10")};

    
    Hand h1(hand1);
    Hand h2(hand2);
    Hand h3(hand3);
    Hand h4(hand4);
    Hand h5(hand5);
    Hand h6(hand6);
    cout<<h1.getRanking()<<endl;
    cout<<h2.getRanking()<<endl;
    cout<<h3.getRanking()<<endl;
    cout<<h4.getRanking()<<endl;
    cout<<h5.getRanking()<<endl;
    cout<<h6.getRanking()<<endl;
    
    return 0;
}
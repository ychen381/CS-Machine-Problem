/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */

	vector< string > vectorWords;
	ifstream words(word_list_fname);
	string word;
	if(words.is_open())
	{
    /* Reads a line from words into word until the file ends. */
   		while(getline(words, word))
        {
			if(word.length() == 5)
				vectorWords.push_back(word);
		}
	}
	for(auto & eWord : vectorWords)
	{
		std:: string removeFirst = eWord.substr(1);
		std:: string removeSecond;
		removeSecond.append(eWord.begin(),eWord.begin()+1);
		removeSecond.append(removeFirst.begin()+1,removeFirst.end());
		if(d.homophones(eWord, removeFirst)&&d.homophones(eWord, removeSecond)&&d.homophones(removeFirst, removeSecond))
		{
			std::tuple<std::string, std::string, std::string> answer;
			std::get<0>(answer) = eWord;
			std::get<1>(answer) = removeFirst;
			std::get<2>(answer) = removeSecond;
			ret.push_back(answer);
		}
	}
    return ret;


}

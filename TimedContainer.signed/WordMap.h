//Author:Vagdevi Challa
//SJSU ID:012524707
//File name:WordMap.h
//Description:STL Vector and Map
//Asssignment Number:11
//Last Changed:04/19/2018

#ifndef WORDMAP_H_
#define WORDMAP_H_

/***** Modify this file as needed. *****/

#include <map>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

/**
 * A map implementation for the concordance that inherits a timer.
 */
class WordMap : public map<string, Word>, public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordMap();

    /**
     * Destructor.
     */
    virtual ~WordMap();
    int size() const;
    /**
     * Getter.
     * @return the frequency count.
     */
    int get_count(const string text) const;

    /**
     * Insert a new word into the map,
     * or increment the count of an existing word.
     * Time this operation.
     * @param text the text of the word to insert or increment.
     */
    void insert(const string text);

    /**
     * Search the map for a word entry with the given text.
     * Time this operation.
     * @param text the text of the word to find.
     * @return an iterator pointing to the word entry if found,
     *         or end() if not.
     */
    map<string, Word>::iterator search(const string text);
private:
    map<string, Word> data;
};

#endif /* WORDMAP_H_ */
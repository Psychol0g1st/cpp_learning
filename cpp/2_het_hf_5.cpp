#include <iostream>
#include <string>
using namespace std;
/*Legyen egy WordList nevű osztály, aminek a képességei az alábbiak.

    Képes tetszőleges darabszámú szó (string) tömbben való tárolására.
    A paraméter nélküli konstruktor beolvassa a szavak számát, majd a szavakat egyenként. Feltehetjük, hogy a szavak nem tartalmaznak whitespace-t.
    Van egy további konstruktor, ami paraméterben megkapja a szavak számát, és csak a szavakat olvassa be egyenként. Feltehetjük, hogy a szavak nem tartalmaznak whitespace-t.
    Van másoló konstruktor, a logikus működéssel.
    A destruktor felszabadítja a lefoglalt dinamikus memóriát.
    Van egy print() metódus, ami a jelzett formátumban kiírja egy sorba a szavak számát, majd ":", majd szókösszel elválasztva a szavakat, sortöréssel a végén.
    Van egy contains() metódus, ami paraméterben egy szót kap, és visszaadja, hogy a szó szerepel-e a tárolt szavak között.
*/
class WordList
{
    
    int wordCount;
    string* words;

public:
    WordList()
    {
        cin >> wordCount;
        words = new string[wordCount];
        for (unsigned int i = 0; i < wordCount; i++)
        {
            cin >> words[i];
        }
               
    }
    WordList(int word_count) : wordCount(word_count)

    {
        words = new string[word_count];
        for (unsigned int i = 0; i < word_count; i++)
        {
            cin >> words[i];
        }
    }
    WordList(const WordList& orig) : 
        wordCount(orig.wordCount)
    {
        words = new string[wordCount];
        for (unsigned i = 0; i < wordCount; i++)
        {
            words[i] = orig.words[i];
        }
        
    }
    ~WordList()
    {
        delete[] words;
    }
    void print() const
    {
        for (unsigned i = 0; i < wordCount; ++i){
            cout << words[i] << " ";
        }
        cout << endl;
    }
    bool contains(const string& word) const
    {
        return true;
    }
};

int main()
{
    WordList sl1;
    WordList sl3(sl1);
    sl1.words[0] = "Nem vagyok gyumolcs";
    sl1.print();
    sl3.print();

    // WordList sl1;
    // cout << "WordList #1:" << endl;
    // sl1.print();
    // int count;
    // cin >> count;
    // WordList sl2(count);
    // cout << "WordList #2:" << endl;
    // sl2.print();
    // {
    //     WordList sl3(sl1);
    //     cout << "WordList #3:" << endl;
    //     sl3.print();
    // }
    // cout << "WordList #1:" << endl;
    // sl1.print();
    // cout << "Alpha? -> " << (sl1.contains("Alpha") ? "yes" : "no") << endl;
    // cout << "Bravo? -> " << (sl1.contains("Bravo") ? "yes" : "no") << endl;
    // cout << "Charlie? -> " << (sl1.contains("Charlie") ? "yes" : "no") << endl;
    return 0;
}

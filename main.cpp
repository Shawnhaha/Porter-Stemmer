#include <iostream>
#include "readDoc.h"
#include "Querry.h"
#include "Frequency.h"
#include "stem.h"
using namespace std;

int main(){
    readDoc R;
    string fname;
    string stopname;
    Querry querry;

    cout << "Please enter the name of the collection file:";
    cin >> fname;
    cout << "Please enter the name of the stopwords file:";
    cin >> stopname;

    R.readAndStore(fname);
    R.storeStopwords(stopname);
    R.parse();
    R.output();
    R.get_words_count();

    Stem st;
    st.inout(R.documents[3]);

    Frequency fq;
    fq.set_stemmed_words_count_in_all_documents(R.words_count);
    fq.get_tf_idf(0);
    fq.print_tf_idf();

    querry.read_line();
    querry.add_stemmed_words_count_in_all_documents(R.words_count);
    querry.remove_stopwords_and_get_stem();



}

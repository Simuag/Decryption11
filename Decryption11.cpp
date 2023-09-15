// Created By Simon Yegikyan and Published on 09/14/2023

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
       


bool decrypt(const char ciphertext[], const char crib[]) {
    int split = 0;
    char crib_words[100][100]{'\0'};
    int i = 0;
    while (true) {
        if (i == 100){
            return false;
        }
        while(crib[split] != '\0' && !isalpha(crib[split])){
            split++;
        }
        if (crib[split] == '\0')
            break;
        int k = 0;
        while(crib[split] != '\0' && isalpha(crib[split])){
            if (k >= 100){
                return false;
            }
            crib_words[i][k] = tolower(crib[split]);
            k++;
            split++;
            
        }
        crib_words[i][k] = '\0';
        i++;
        
        
    }
    if(crib_words[0][0] == '\0'){
        return false;
    }
//    int z = 0;
//    int counter = 0;
//    for (z; z < 100; z++){
//        for (counter; crib_words[z][counter] != '\0'; counter++){
//
//        }
//    }
//    for (int o = 0; o < i; o++){
//        cout << crib_words[o] << endl;
//    }
    int h = 0;
    int l = 0;
    char trasharray[100][100]{'\0'};
//    char alphabet[100]{' '};
    int alphabet[26]; //set all this -1. cipher->crib Ex:a(0th index) matches c(crib so we put a 2) ---> alphabet[0] = 2
    int inversealphabet[26];
    for (int i = 0; i < 26; i++){
        alphabet[i] = -1;
        inversealphabet[i] = -1;
    }
    
    while(ciphertext[h] != '\0' && h < 100){
        int comment = 0;
        int hello = 0;
        for(; comment < 100; comment++){
            if (ciphertext[comment] != '\0'){
                hello++;
            } else {
                break;
            }
        }
        if (h >= hello){
            break;
        }

        while(ciphertext[h] != '\n' && ciphertext[h] != '\0' && l < 100){
            while(ciphertext[h] != '\n' && ciphertext[h] != '\0' && !isalpha(ciphertext[h])){
                h++;
            }
            if (ciphertext[h] == '\0')
                break;
            int j = 0;
            while(ciphertext[h] != '\n' && ciphertext[h] != '\0' && isalpha(ciphertext[h])){
                    
                if (j == 100){
                    return false;
                }
                
                if(l < 100 && j < 100){
                    trasharray[l][j] = ciphertext[h];
                }
                //might be the error
                j++;
                h++;
                
            }
            trasharray[l][j] = '\0';
            l++;
           
        }
        
        if (ciphertext[h] == '\n')
            trasharray[l++][0] = '\0';
        
        if (ciphertext[h] == '\0')
            break;
       
        // break;
         h++;
        
    }
//        int b = 0;
//       for(; b < l; b++){
//           cout << trasharray[b] << endl;
//
//        }
    //cout << tolower(ciphertext[yes]) - 'a'<< endl;
        
        int startCribWord = 0;
        int cribLetter = 0;
        // first couple loops lgo through trash array, then we check if we havent reached the end of the crib
        for(int ai = 0; ai < 100; ai++) {
            int aj = 0;
            for(; trasharray[ai][aj] != '\0'; aj++) {
                
                //crib_words[100][100]
                if(crib_words[startCribWord][cribLetter] != '\0') {
                    
                    int letter = (int)tolower(trasharray[ai][aj])-'a';
                    int cribler = crib_words[startCribWord][cribLetter]-'a';
                    
                    if(alphabet[letter] == -1 && inversealphabet[cribler] == -1) {
                        alphabet[letter] = cribler;
                        inversealphabet[cribler] = letter;
                        
                        cribLetter++;
                    } else if(alphabet[letter] == cribler && inversealphabet[cribler] == letter){
                        cribLetter++;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    //reset crib word and crib letter
                    for (int jkl = 0; jkl < 26; jkl++){
                        alphabet[jkl] = -1;
                        inversealphabet[jkl] = -1;
                    }
                    startCribWord = 0;
                    cribLetter = 0;
                    break;
                }
                //if crib words is finished: break
            }
            
             int amountcrib = 0;
            int totalwords = 0;
            for(; amountcrib < 100; amountcrib++){
                if (crib_words[amountcrib][0] == '\0'){
                    break;
                } else {
                    totalwords = totalwords + 1;
                }
            }
            
            //if trasharray[ai][aj] and crib_words ended at the same thing
            if(trasharray[ai][aj] == '\0' && crib_words[startCribWord][cribLetter] == '\0') {
                startCribWord++;
                cribLetter = 0;
                if(startCribWord >= totalwords) {
                    break;
                }
                    
            } else {
                //reset alphabet array to all -1
                for (int jkl = 0; jkl < 26; jkl++){
                    alphabet[jkl] = -1;
                }
                startCribWord = 0;
                cribLetter = 0;
            }
        }
        
//        int yes = 0;
//        for (yes; yes < 100; yes++){
//            int joesph = 0;
//            for (; trasharray[yes][joesph] != '\0'; joesph++){
//                if (alphabet[trasharray[yes][joesph] - 'a'] != -1){
//                    trasharray[yes][joesph] = 'A' + alphabet[trasharray[yes][joesph] - 'a'];
//                }
//            }
//        }
        bool result = false;
        int asd = 0;
        for(; asd < 26; asd++){
            if(alphabet[asd] != -1){
                result = true;
                break;
            }
        }
    

    
        if(result) {
            int yes = 0;
            for (; ciphertext[yes] != '\0'; yes++){
               
                if(isalpha(ciphertext[yes])) {
                    
              
                    if (alphabet[(int)tolower(ciphertext[yes]) - 'a'] != -1){
                        cout << (char)('A' + alphabet[(int)tolower(ciphertext[yes]) - 'a']);
                    } else {
                        cout << (char)(tolower(ciphertext[yes]));
                    }
                } else {
                    cout << ciphertext[yes];
                }
                
                
            }
            
             cout << endl;
        }
        
        //for b
        // dont forget to zero out alphabet
        //      for i
        //            if (!is_translatable(trasharray[], crib_WORDS[], ALPHABET)){
        // check length
        // traverse each word
        // if translation in alphabet array is not set set it and if its already set if it matches its fine if it doesnt return false from the function.
        // break out from inner loop
        // EDGES
        // crib is empty or doesnt have any alpha chracters
       

    
    
    
    // translate ciphertext using the alphabet and print it.
   
    return result;
    
}


void runtest(const char ciphertext[], const char crib[])
            {
                cout << "====== " << crib << endl;
                bool result = decrypt(ciphertext, crib);
                cout << "Return value: " << result << endl;
            }

// check length of crib and cipher text word to see if they are the same, if so then they match.
// everytime you encounter pair of letters from ciphertext and crib then you change that letter to the crib letter.
//
  


    int main()
    {
       
        

           
                cout.setf(ios::boolalpha); // output bools as "true"/"false"

               runtest("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "my secret");
               runtest("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "shadow");
        runtest("ugand ejsy ze dsaae od.\nO'z fodvtrry.", "your my buddy");
        runtest("Hirld ejsy zu drvtry od.", "chair dogs");
        runtest("slud slid slid sdjksdkl civui dkfjsdo.", "your");
        runtest("sl ud sl id sl id sdjksdkl civui dkfjsdo.", "yo8ur");
        runtest("Hirld\nejsy", "chair dogs");
         runtest("Hirld ejsy 02394rwioehf9sy-fy23. /n 28efu3rsodifosiufuw sdjf3rlskdf /n oidv /n", "chair dogs");
          runtest("aaaa", "abcd"); 
        runtest("abcd", "aaaa");



        
       runtest("Hirld ejsy zu drvtry od.", "chair dogs");
       runtest("ugand ejsy ze dsaae od.\nO'z fodvtrry.", "yo9ur my buddy");
        runtest("aaaa", "abcd");
       runtest("\nsl ud sl id sl id sdjksdkl civui dkfjsdo.", "Yo8ur");

        

        
    }

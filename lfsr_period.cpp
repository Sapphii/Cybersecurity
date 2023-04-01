
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(void)
{
    cout << "Enter in the seed in binary" << endl;

    string seedBinary;
    std::cin >> seedBinary;

    cout << "Enter in the taps in binary" << endl;

    string tapsBinary;
    std::cin >> tapsBinary;

    // int indexesToCheck[tapsBinary.length()];

    // for (int i = 0; i < tapsBinary.length(); i++)
    // {
    //     cout << tapsBinary[i] << endl;
    //     if (tapsBinary[i] == '1')
    //     {
    //         indexesToCheck[i] += 1;
    //     }
    // }

    string modifiedBinary = seedBinary;
    string currentFirstToAdd;

    for (int i = 0; i < pow(2, seedBinary.length()); i++)
    {
        
        int sum = 0;
        for (int j = 0; j < tapsBinary.length(); j++)
        {
            //cout << tapsBinary[j] <<  " | " << modifiedBinary[j] << endl;
            if (tapsBinary[j] == '1' && modifiedBinary[j] == '1')
            {
                sum ++;
                //cout << "happens" << endl;
            }
            
        }

        if(sum % 2 == 0){
            modifiedBinary = "0" + modifiedBinary.substr(0,modifiedBinary.length()-1);
            cout << i + 1 << " : " <<  sum << " : " << modifiedBinary << endl;
        }
        else{
            modifiedBinary = "1" + modifiedBinary.substr(0,modifiedBinary.length()-1);
            cout << i + 1 << " : " <<  sum << " : " << modifiedBinary << endl;
        }
        if(modifiedBinary == seedBinary){
            cout << "There is a period of " << i << endl;
            i = 512;
        }
        

    }



}
#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'scoreTosses' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING tosses1
 *  2. STRING tosses2
 *  3. STRING tosses3
 */

string scoreTosses(string tosses1, string tosses2, string tosses3) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string tosses1;
    getline(cin, tosses1);

    string tosses2;
    getline(cin, tosses2);

    string tosses3;
    getline(cin, tosses3);

    string result = scoreTosses(tosses1, tosses2, tosses3);

    fout << result << "\n";

    fout.close();

    return 0;
}

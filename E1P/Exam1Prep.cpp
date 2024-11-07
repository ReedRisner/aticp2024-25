#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * Complete the 'findModeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER num
 *  2. INTEGER base
 *  3. STRING start
 */

int baseToDecimal(const string& num, int base) {
    int value = 0;
    for (char c : num) {
        value *= base;
        if (c >= '0' && c <= '9') {
            value += c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value += c - 'A' + 10;
        }
    }
    return value;
}

string decimalToBase(int num, int base) {
    string result;
    const char digits[] = "0123456789ABCDEF";
    while (num > 0) {
        result.push_back(digits[num % base]);
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

int findModeCount(int num, int base, string start) {
    int startValue = baseToDecimal(start, base);

    
    vector<string> numbers;
    for (int i = 0; i < num; ++i) {
        numbers.push_back(decimalToBase(startValue + i, base));
    }

    
    unordered_map<char, int> frequency;
    for (const string& number : numbers) {
        for (char digit : number) {
            frequency[digit]++;
        }
    }

    
    int maxCount = 0;
    for (const auto& entry : frequency) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }


    return maxCount;
}




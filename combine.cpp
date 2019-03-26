#include<iostream>
#include<vector>

using namespace std;

void printBits(unsigned int x)
{
    unsigned i;
    int j;
    for(i = 1 << 31, j = 0; i > 0; i = i >> 1, j++)
    {
        if(j % 4 == 0 && j != 0)
                cout << "\t";
        (x & i) ? cout << "1" : cout << "0";
    }
}
int countOnes(unsigned int x)
{
    int count = 0;
    while(x)
    {
        count += x & 1;
        x = x >> 1;
    }
    return count;
}
void printVec(const vector<int>& vec)
{
    for(const int& elem: vec) cout << elem << " ";
    cout << endl;
}
vector<vector<int>> combine(int n, int r)
{
    vector<vector<int>> result = {};
    unsigned int xmax = 1 << n;
    for(unsigned int x = 0; x < xmax; x++)
    {
        if(countOnes(x) == r)
        {
            printBits(x); cout << endl;
            vector<int> sequence = {};
            int mask = 1;
            for(int r = 0; r < n; r++)
            {
                if(mask & x) sequence.push_back(r);
                mask = mask << 1;
            }
            result.push_back(sequence);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> sequences = combine(5, 2);
    for(auto elem: sequences) printVec(elem);
    return 0;
}

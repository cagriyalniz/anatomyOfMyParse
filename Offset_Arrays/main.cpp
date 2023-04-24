#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

/*
class values{
    public:
        int key;
        int value;
};
*/

class element
{
    public:
        string name;
        int size;
        map<int, int> values;

};

void printVec(vector<int> vec)
{
    vector<int>::iterator it = vec.begin();

    while(it != vec.end())
    {
        cout<<"I "<<*it<<" I ";
        it++;
    }
    cout<<endl;

}

string findElementName(string ass)
{
    int i = 0;
    string name = "";

    while(ass[i] != '[')
    {
        name.push_back(ass[i]);
        i++;
    }
    return name;
}

int findFirstKey(string ass)
{
    int i = 0;
    int first = 0;
    bool negFirstFlag = 0;

    while(ass[i] != '[')
        i++;
    i++;
    if (ass[i] == '-')
    {
        negFirstFlag = 1;
        i++;
    }
    first = int(ass[i]) - 48;
    if (negFirstFlag == 1)
        first *= -1;
    
    return first;
}

int findLastKey(string ass)
{
    int i = 0;
    int last = 0;
    bool negSecondFlag = 0;

    while(ass[i] != '[')
        i++;
    i++;
    if (ass[i] == '-')
        i++;
    i += 3;
    if (ass[i] == '-')
    {
        i++;
    }
    last = int(ass[i]) - 48;
    if (negSecondFlag == 1)
        last *= -1;
    return last;
}

int findElementSize(string ass)
{   
    return findLastKey(ass) - findFirstKey(ass) + 1; 
}

void fillKeys(vector<int> *keys, string ass)
{
    int first = findFirstKey(ass);
    int last = findLastKey(ass);
    while(first != last)
    {
        keys->push_back(first);
        first++;
    }
    keys->push_back(first);
}

vector<int> mySplit(vector<int> *values, string orj, char c)
{
    int i = 0;
    int k = 0;


    while(orj[i] != '=')
        i++;
    i++;
    vector<int> res;
    int x = 0;
    while(orj[i])
    {
        string str;
        k = 0;
        if (orj[i] != c)
        {
            while (orj[i] && orj[i] != c)
            {
                
                str.push_back(orj[i]);
                i++;
                k++;
            }
        }
        else
            i++;

         if (!str.empty() && str.find_first_not_of("0123456789") == string::npos) {
            x = stoi(str);
            values->push_back(x);
        }
        str.clear();
    }
   

    return res;
}


void fillValues(vector<int> *values, string ass)
{
    int i = 0;
    
    while(ass[i] != '=')
        i++;
    i++;
    mySplit(values, ass, ' ');
    
}

void fillMyElements(element &elem, vector<int> keys, vector<int> values)
{
    int i = 0;
    
    int len = keys.size();

    while(i < len){
        elem.values[keys[i]] = values[i];
        i++;
    }

}



int main()
{

    int n;
    cin >> n; cin.ignore();
    element *elements = new element[n];
    vector<int> keys;
    vector <int> values;
    for (int i = 0; i < n; i++) {
        string assignment;
        getline(cin, assignment);
        elements[i].size = findElementSize(assignment);
        fillKeys(&keys, assignment);
        fillValues(&values, assignment);
        fillMyElements(elements[i], keys, values);
        keys.erase(keys.begin(), keys.end());
        values.erase(values.begin(), values.end());   

    }
    string x;
    getline(cin, x);

    
}
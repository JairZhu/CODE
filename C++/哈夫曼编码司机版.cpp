 #include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <map>
using namespace std;
struct node {
    node(char _ch, int _w, node* _lch = NULL, node* _rch = NULL) :
        ch(_ch), w(_w), lch(_lch), rch(_rch) {}
    char ch;
    int w;
    node* lch;
    node* rch;
};

map<char, int> weight;
void readWeight(node* tree, int depth) {
    if(tree->ch != '\0')
        weight[tree->ch] = depth;
    else {
        readWeight(tree->lch, depth+1);
        readWeight(tree->rch, depth+1);
    }
}

void readWeight(node* tree) {
    readWeight(tree, 0);
}

int main() {
    map<int, int> words;
    string str;
    cin >> str;
    stringstream ss(str);
    char ch;
    while(ss >> ch)
        words[ch] ++;
    vector<node*> ws;
    for(auto p : words)
        ws.push_back(new node(p.first, p.second));
    if(ws.size() == 0) {
        cout << '0';
        return 0;
    }
    while(ws.size() > 1) {
        int min1 = INT_MAX, min2 = INT_MAX;
        node* pmin1 = NULL;
        node* pmin2 = NULL;
        auto tmin1 = ws.begin();
        auto itmin1 = ws.end();
        for(; tmin1 != ws.end(); ++tmin1) {
            if((*tmin1)->w < min1){
                min1 = (*tmin1)->w;
                pmin1 = (*tmin1);
                itmin1 = tmin1;
            }
        }
        ws.erase(itmin1);
        auto tmin2 = ws.begin();
        auto itmin2 = ws.end();
        for(; tmin2 != ws.end(); ++tmin2) {
            if((*tmin2)->w < min2){
                min2 = (*tmin2)->w;
                pmin2 = (*tmin2);
                itmin2 = tmin2;
            }
        }
        ws.erase(itmin2);
        node* combine = new node('\0', pmin1->w + pmin2->w, pmin1, pmin2);
        ws.push_back(combine);
    }
    readWeight(ws[0]);
    int result = 0;
    for(auto ch : str) {
//        cout << ch << ":" << weight[ch] << endl;
        result += weight[ch];
    }
    cout << result;
    return 0;
}
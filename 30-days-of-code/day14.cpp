#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    
    Difference(vector<int> _e) : elements(_e) {}
    
    void computeDifference(){
        int small = *min_element(this->elements.begin(), this->elements.end());
        int big = *max_element(this->elements.begin(), this->elements.end());
        
        this->maximumDifference = big - small;
    }

}; // End of Difference class
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution{
private:
    string p_state;
    float p_values[2];
public:
    Solution(float values[2],string state){
        p_state = state;
        p_values[0] = values[0];
        p_values[1] = values[1];
    }
    float* getValues(){return p_values;}
    string getState(){return p_state;}
};

Solution* solve(float a, float b, float c){
    float delta = pow(b,2)-4*a*c;
    float pass_array[] = {0,0};
    if(delta < 0){
        return new Solution(pass_array,"There are no real x-es where f(x)=0.");
    }
    else{
        pass_array[0] = (-b-sqrt(delta))/(2*a);
        if(delta == 0)
            return new Solution(pass_array,"There is only one real solution.");
        pass_array[1] = (-b+sqrt(delta))/(2*a);
        return new Solution(pass_array,"There are two solutions");
    }
}

int main()
{
    Solution* solveEq = solve(2,0,2);
    cout << solveEq->getState() << "    " << solveEq->getValues()[0] << "    " << solveEq->getValues()[1];
    return 0;
}

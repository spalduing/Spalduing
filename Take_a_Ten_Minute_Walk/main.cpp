#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

bool isValidWalk_5(std::vector<char> walk);
bool isValidWalk_4(std::vector<char> walk);
int movement(char current_step);

int main()
{
    std::vector<char> steps_sequence =
    {'w','e','n','s','w','e','n','s','n','e'};
    if(isValidWalk_5(steps_sequence))
    {
        std::cout << "The walk is valid!" << std::endl;
    }else{
        std::cout << "The walk is NOT valid!" << std::endl;
    }


    return 0;
}


int movement(char current_step)
{
        switch(current_step){
        case 'n':
            return 1;
            //break;
        case 's':
            return -1;
            //break;
        case 'w':
            return -1;
            //break;
        case 'e':
            return 1;
            break;
        default:
            return 0;
            break;
            }
}

bool isValidWalk_4(std::vector<char> walk)
{
    int s=walk.size();
    double dist;
    int x, y;
    std::pair<int,int> origin(0,0);
    std::pair<int,int> point(0,0);

    if(s == 10){
        for(int i=0; i<s; i++){
            point.first += movement(walk[i]);
            point.second += movement(walk[i]);
        }
    }else{
        return false;
    }
    std::cout<<" The point end up on: ("<<point.first<<","<<point.second<<")"<<std::endl;
    x = origin.first - point.first;
    y = origin.second - point.second;
    dist = sqrt(pow(x, 2) + pow(y, 2));

    return dist == 0.0;
}
bool isValidWalk_5(std::vector<char> walk)
{
    int num_n,num_s,num_e,num_w = 0;
    int s = walk.size();
    if(s == 10){
        num_n = count(walk.begin(),walk.end(),'n');
        num_s = count(walk.begin(),walk.end(),'s');
        num_e = count(walk.begin(),walk.end(),'e');
        num_w = count(walk.begin(),walk.end(),'w');
        return num_n == num_s && num_e == num_w;
    }else{
        return false;
    }
}

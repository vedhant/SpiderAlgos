/*inputs:
current Floor
capacity
initial no of people already inside
no of requests - n
following n lines contain : floor no, people getting in, people getting out
*/

/*
output:
elevator order
distance
*/

/*
sample input:
25
100
0
8
30 10 2
9 20 0
44 30 10
23 15 5
1 15 20
99 0 1
33 25 2
10 40 32
*/

/*
sample output:
25 9 1 23 30 33 44 99 10 
211
*/

#include <bits/stdc++.h>
using namespace std;

struct Floor{
    int request;
    int out;
    int in;
};
vector <Floor> floors;
int capacity,no_of_floors;
int done = 1;

bool comp(Floor i, Floor j){
    return i.request<j.request;
}
void Distance(vector <int> a, int dummy){
    int dist = 0;
    for(int i=1;i<no_of_floors;++i){
        if(a[i]-a[i-1]>0)
        dist+=a[i]-a[i-1];
        else
        dist+=a[i-1]-a[i];
    }
    cout<<dist;
}

void nextFloor(int current_floor_index, string direction, int people_inside, vector <bool> visited, vector <int> order){
    if(done)
    return;
    if(current_floor_index == 0){
        direction = "up";
    }
    if(current_floor_index == no_of_floors-1){
        direction = "down";
    }
    if(people_inside + floors[current_floor_index].in - floors[current_floor_index].out > capacity)
    return;
    if(people_inside < floors[current_floor_index].out)
    return;
    visited[current_floor_index] = true;
    order.push_back(floors[current_floor_index].request);
    
    people_inside += (floors[current_floor_index].in - floors[current_floor_index].out);
    
    if(order.size()==no_of_floors){
        done = true;
        for(int i=0;i<no_of_floors; ++i)
        cout<<order[i]<<" ";
        cout<<endl;
        Distance(order);
    }
    
    int i = current_floor_index;
    int Count = 0;
    loop:
    if(Count<4*no_of_floors && !done){
        Count++;
        if(direction == "up"){
            i++;
            if(i==no_of_floors-1)
            direction = "down";
            if(!visited[i])
            nextFloor(i, direction, people_inside, visited, order);
        }
        else{
            i--;
            if(i==0)
            direction = "up";
            if(!visited[i])
            nextFloor(i, direction, people_inside, visited, order);
        }
        goto loop;
    }
    
}

int main() {
    int current_floor, people_inside;
    int above = 0;
    int below = 0;
    cin>>current_floor;
    cin>>capacity;
    cin>>people_inside;
    cin>>no_of_floors;
    vector <bool> visited;
    int i;
    for(i=0;i<no_of_floors;++i){
        int x;
        cin>>x;
        if(x>=current_floor)
        above++;
        else
        below++;
        int request = x;
        cin>>x;
        int in = x;
        cin>>x;
        int out = x;
        floors.push_back({request,out,in});
        visited.push_back(false);
    }
    sort(floors.begin(), floors.end(), comp);
    floors.insert(floors.begin()+below,{current_floor,0,0});
    no_of_floors++;
    string direction = "up";
    vector <int> order;
    visited.push_back(false);
    nextFloor(below, direction, people_inside, visited, order);
    
	return 0;
}

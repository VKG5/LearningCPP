#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

// For the temp variable
int temp_value(int a, int b)
{
    if(a<b)
        return 0;

    return 1;
}

int assemblyLine(int time[2][8], int penalty[2][9])
{
    int temp = temp_value(time[0][0], time[1][0]);
    int tot_time = penalty[temp][0];

    for(int i=0; i<8; i++)
    {
        if(temp_value(time[0][i], time[1][i])==temp)
        {
            tot_time+=min(time[0][i], time[1][i]);
        }

        else
        {
            temp = temp_value(time[0][i], time[1][i]);
            tot_time += min(time[0][i], time[1][i]) +  penalty[temp][i+1];
        }
    }

    return tot_time;
}

int main()
{
    int time[][8] = {{3, 3, 5, 7, 9, 10, 14, 16},
                     {4, 4, 6, 5, 11, 6, 15, 22}};

    int penalty[][9] = {{2, 1, 2, 2, 3, 2, 4, 3, 1},
                        {2, 1, 3, 3, 2, 1, 3, 3, 2}};

    cout<<assemblyLine(time, penalty);

    return 0;
}

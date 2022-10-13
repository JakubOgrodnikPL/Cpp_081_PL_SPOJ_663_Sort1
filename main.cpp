#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string name[1000], buffer_name;
int x[1000],y[1000],buffer;
double distance_current, distance_next;

int main()
{
    int t,nop; // t is number of series
    cin>>t;
    while(t){

        cin>>nop;//number of points

        for(int j = 0; j<nop; j++)
        {
            cin>>name[j]>>x[j]>>y[j];
        }
        for(int j = 0; j<nop; j++)
        {
            for(int k = 0; k<nop - 1; k++)
            {
                distance_current = sqrt(x[k] * x[k] + y[k] * y[k]);
                distance_next = sqrt(x[k + 1] * x[k + 1] + y[k + 1] * y[k + 1]);
                if(distance_current > distance_next)
                {
                    buffer = x[k];
                    x[k] = x[k + 1];
                    x[k + 1] = buffer;
                    buffer = y[k];
                    y[k] = y[k + 1];
                    y[k + 1] = buffer;
                    buffer_name = name[k];
                    name[k] = name[k + 1];
                    name[k + 1] = buffer_name;
                }
            }
        }
        for(int j = 0; j<nop; j++)
            cout<<name[j]<<" "<<x[j]<<" "<<y[j]<<endl;
        t--;
    }
    return 0;
}

#include "iostream"
using namespace std;
int min(int *a, int n)
{
    int m=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}
double min(double *a, int n)
{
    double m=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}
double min(double *a, int n)
{
    double m=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}
float min(float *a, int n)
{
    float m=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}
long min(long *a, int n)
{
    long m=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
    }
    return m;
}
int main()
{
    int a[6]={1,5,2,3,6,0};
    cout<<min(a,6)<<endl;
    system("pause");
}
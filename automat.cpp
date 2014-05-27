#include<iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

float csc(float x){ return 1.00/sin(x); }
float cot(float x){ return 1.00/tan(x); }

float rad2deg(float x){return x/(2*3.14159265)*360;}

int main()
{
    float a,d,nuv;

    a = 11.80;
    d = 24.00;

    nuv = 2*atan(a/(2.00*d)); 

    string s;

    ifstream f;

    f.open("testset1/testset1");
    
    f >> s;

    float H0,OP,DH,DOP,theta;

    f >> H0 >> OP >> DH >>DOP;

//cout << H << " " << OP << endl;

    float R;
    R = 8.5;

    theta = atan(OP/H0);

    float H;
    H = H0 - R*cos(theta) - 2.5;

    int maxH = 480;

    float n;

    while (!f.eof())
    {
        f >> n;

        if (f.eof()) break;

        float phi = atan( 1.00/(  (n)/(maxH-n)*csc(nuv) + cot(nuv)  )  );

        //cout << n << " " << rad2deg(phi) << " "; 

        float eps;
 
        eps = theta - nuv/2.00 + phi;

        //cout << rad2deg(theta) << " " << rad2deg(nuv/2.00) << " " << rad2deg(phi) << " " <<
        //    rad2deg(eps) << endl;

        //cout << rad2deg(eps) << " ";

        cout << " " << H * tan(eps) + R*sin(theta) << " " << rad2deg(nuv/2.00) << endl;


    
    }


    return 0;
}

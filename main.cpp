#include <iostream>
#include <vector>
#include <cmath>
#include "gnuplot.h"
double C(double n, double k)
{
    double ans=1;
    for(;k>0;k--){
        ans*=n--;
        ans/=k;
    }
    return ans;
}
std::vector<double> legendre(int n)
{
    std::vector<double> coeffs;
    for(int k=0; k<=n; k++){
        coeffs.push_back(pow(2,n)*C(n, k)*C((n+k-1)/2.0, n));
    }
    return coeffs;
}
int main() {
    GnuplotPipe gp;
    auto a=legendre(20);//change number in legendre(number) to get Pn(x)
    std::string line="plot [-1.0:1.0] ";
    for(int i=a.size()-1;i>=0; i-- ){
        if(a[i]>=0)
            line.append("+");
        line.append(std::to_string(a[i]));
        if(i==0)
            break;
        line.append("*x**");
        line.append(std::to_string(i));
    }
    std::cout<<line.substr(18, line.size());
    gp.sendLine(line);
    return 0;
}

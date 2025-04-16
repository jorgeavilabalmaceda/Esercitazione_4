#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
	string InputFileName = "data.txt";
	double S = 0.0;
	size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
	
	if (!ImportVectors(InputFileName, S, n, w, r))
    {
        cerr << "Something goes wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successful: S= " << S << " n= " << n << endl;
		cout << " w= "<< ArrayToString(n, w) << endl;
		cout << " r= "<< ArrayToString(n, r) << endl;
		
	double TotRend;
	double TotPort; 
	
	ImportVectors(InputFileName, S, n, w, r);
	
	TotRend = TassoRendimento(n, w, r);
	
	TotPort = ValPort(TotRend, S);    
	
	cout << TotRend << endl;
	cout << TotPort << endl;
	
	ExportResult("result.txt", S, n, w, r, TotRend, TotPort);
	
	
	delete [] w;
	delete [] r;
		
    return 0;
}
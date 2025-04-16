#include <Utils.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;

bool ImportVectors(const string& inputFilePath,
				   double & S,
                   size_t& n,
                   double*& w,
                   double*& r)
{
    
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }
	
	
	string temp; 
	getline( file, temp,';');

	
	file >> S;
	file.ignore();  //so we can skip the newline character
	

	getline(file, temp,';');
	file >> n;
	file.ignore();
	getline(file, temp);	
	
	//define w and r
	w = new double[n];
	r = new double[n];
	double pos_pv;
	for(unsigned int i = 0; i < n; i++)
	{
		getline(file, temp);
		pos_pv = temp.find(';');
		w[i] = stod(temp.substr(0, pos_pv));
		r[i] = stod(temp.substr(pos_pv + 1));
	}

    file.close();

    return true;
}


double TassoRendimento(const size_t& n,
					   const double* const& w,
					   const double* const& r)
{
    double tassoRend = 0;
    for (unsigned int i = 0; i < n; i++)
        tassoRend += w[i] * r[i];

    return tassoRend;
}

//portfolio calculation
double ValPort(const double &r,
			   const double &S)
{
	double V;
	V = (1 + r) * S;
	return V;
}

bool ExportResult(const string& outputFilePath,
				  const double& S, 
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& tassoRend,
				  const double& V)
{
    // opening
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

	//writing
    file << "S = "<< fixed << setprecision(2) << S << endl;
    file << "n = " << n << endl;

	file.unsetf(ios::fixed);//tolgo la notazione forzata
	file << setprecision(4); //back to 4

    //writing vectors
	file << "w = " << ArrayToString(n, w) << endl;
	file << "r = " << ArrayToString(n, r) << endl;
	
	//for compiling purposes
	file << "Il tasso di rendimento del portafoglio è: " << tassoRend << endl;
	file << "Il valore del portafoglio è: " << fixed << setprecision(2) << V << endl;

    file.close();

    return true;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
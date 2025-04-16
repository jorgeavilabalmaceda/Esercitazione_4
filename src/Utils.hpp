#pragma once

#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
				   double& S,
                   size_t& n,
                   double*& w,
                   double*& r);
				   
bool ExportResult(const string& outputFilePath,
				  const double& S, 
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& tassoRend,
				  const double& V);

double TassoRendimento(const size_t& n,
					   const double* const& w,
					   const double* const& r);
					   
double ValPort(const double &r,
			   const double &S);

string ArrayToString(const size_t& n,
                     const double* const& v);
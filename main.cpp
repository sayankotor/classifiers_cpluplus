#include <QCoreApplication>
#include "XGBClassifierPID.h"
#include<iostream>
#include<fstream>
#include "/home/sayankotor/works/QtProjects/XGBplus/strtk/strtk.hpp"


using namespace std;

int main(int argc, char *argv[])
{
    XGBClassifierPID a;

    a.setPath("/home/sayankotor/works/QtProjects/XGBplus/sayankotor_xgb.model");


    ifstream file ("/home/sayankotor/works/QtProjects/XGBplus/test_val.csv" ); // declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
    string value;
    std::vector<std::vector<double>> test_data;
    while ( file.good() )
    {
         getline ( file, value, '\n' );
         std::vector<double> double_vector;
         strtk::parse(value,",",double_vector);
         test_data.push_back(double_vector);
    }

    std::vector<std::vector<double>> res;
    try{
        for (auto feature_vector_it = test_data.begin(); feature_vector_it < test_data.end(); feature_vector_it++){
             res.push_back(a.getClassifierValue(*feature_vector_it));
        }
    }
    catch(...){}
    std::cout<<res.size();
    ofstream out_csv;
    out_csv.open("/home/sayankotor/works/QtProjects/XGBplus/cplus_pred.csv");
    for (int i =0; i<res.size(); i++){
        strtk::write_to_text_file(out_csv, res[i], ",");
        out_csv<<"\r\n";
    }
}

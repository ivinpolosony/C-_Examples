#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib> // for exit()


using namespace std;
void display_2dvector( vector< vector<string> >);

int main (int argc, char *argv[])
{ 
      if (argc <= 1)
      {
        if (argv[0])
          cout << "Usage: " << argv[0] << " <file name>"  << endl;
        else
          cout << "Usage: <program name> <file name>"  << endl;
        exit(1);
      }
      
      ifstream filehandle(argv[1]);
      if(filehandle.fail()){
        cout << "File not found" << endl;
      }
      string str,word; 
      stringstream sstr;
      //  typedef std::pair<int , string> pr; 
      // std::vector<pr> v;
      //  v.push_back(make_pair(1,"sdudfhsdf"));
      //  std::vector<pr>::iterator it = v.begin();
      //  cout << it->first << " " << it->second;
      vector<string> v;
      vector< vector<string> > vectorofstings;  
      while (std::getline(filehandle, str))
      {    
      stringstream s(str);
        while(getline(s,word,',')) 
        {
        v.push_back(word);
        } 
      vectorofstings.push_back(v);
      v.clear();
      }
      display_2dvector(vectorofstings);      
     
     
    
    return 0;
}

void display_2dvector(const vector< vector<string> > vectorofstings)
{
    vector< vector<string> >::const_iterator row;
    vector<string>::const_iterator col;

    for (row = vectorofstings.begin(); row != vectorofstings.end(); row++) 
    {
      for (col = row->begin(); col != row->end(); col++) 
      {
          cout << *col << " ";
      }
      cout << endl;
    }
}


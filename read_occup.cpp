#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdint.h>
#include <stdlib.h>  

using namespace std;

 /*
 *   controlLoop
 *
 *   Function Description
 *
 *   @critical Major Multi-Point
 *
 *   @param
 *   @return
 *
 *   @ureq
 *   -#
 */

bool contains_letter(std::string const& str)
{
    // There are many other ways to do this, but for the sake of keeping this answer short...
    return str.find_first_of("end_of_params") != std::string::npos;
}

/*
int get_number_of_lines(std::string const& str)
    {
    string s;
    int sTotal;
    while(!str.eof()())
        {
	        getline(str, s);
	        sTotal ++;	
        }
        cout << sTotal << "\n";
    return sTotal;
    }
*/


int main( )
{  
    string gridline;
    vector <vector<int8_t> > _occGrid;
    vector<int8_t> _occGrid_msg;
    vector<string> String_occ;
    double _gridOrigin[2]; 
    double gridOriginX; 
    double gridOriginY;
    string s;
    //int sTotal;
    
   ifstream OccGridfile ("getOccGrid.txt");
   int number_of_lines ;
   int values;
   
   
   if (OccGridfile.is_open())
    {
        while(!OccGridfile.eof())
        {   
            getline(OccGridfile, gridline);
            number_of_lines++; 
            
             if (contains_letter(gridline))
            {
            printf(" Error \n ");
            }
            else
            {   
                for ( int number_of_lines = 0; number_of_lines < 200; number_of_lines++ )  //The grid size is 200 X 200 
                { 
                   // int occ_temp;
                    for (int yIndex = 0; yIndex < 200; yIndex++)
                        {  
                            while ( OccGridfile >> values)
                                {
                                // cout << OccGridfile << "\n"; 
                                //int num = atoi(gridline.at(yIndex).c_str());
                               // cout << values ;
                                //String_occ.push_back(gridline);
                                _occGrid_msg.push_back(values);
                                }
                            
                        }
                    //printf("%d",_occGrid_msg) ;   
                }
            
        _occGrid.push_back(_occGrid_msg);
        }


        }
       // cout << number_of_lines << "\n";
        

   
    OccGridfile.close();
   }
   else
   {
      cout << "Unable to open file"; 
   }
   return 0;
}




             /*

            while (number_of_lines < 2)
           {
               OccGridfile >> gridOriginX;
                cout  << gridOriginX << "\n";
                _gridOrigin[0] = gridOriginX;
                OccGridfile >> gridOriginY;
                cout  << gridOriginY << "\n";
                _gridOrigin[1] = gridOriginY;
           }
           */
/*
            for (int i = 0; i < number_of_lines; i++)
       {
           while (number_of_lines < 2)
           {
               OccGridfile >> gridOriginX;
                cout  << gridOriginX << "\n";
                _gridOrigin[0] = gridOriginX;
                OccGridfile >> gridOriginY;
                cout  << gridOriginY << "\n";
                _gridOrigin[1] = gridOriginY;
           }
           
       }
*/
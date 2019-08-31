#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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


int main( )
{
   string line;
   double straightLineDist_m;
   double angleAtStart_r;
   double angleAtGoal_r;
   double maxVel_mps;

   ifstream Paramfile ("DispParameter.txt");
   
   if (Paramfile.is_open())
   {
      while (Paramfile >> straightLineDist_m >> angleAtStart_r >> angleAtGoal_r >> maxVel_mps, ios::app)
      {  

          if (contains_letter(line))
        {
         printf(" Error \n ");
        }
        else
         {  
            int linesArr = sizeof(Paramfile);
            for (int i = 0; i < linesArr ; i++)
            {
               
               Paramfile >> straightLineDist_m;
               Paramfile >> angleAtStart_r;
               Paramfile >> angleAtGoal_r;
               Paramfile >> maxVel_mps ;

             cout  << straightLineDist_m  << angleAtStart_r  << angleAtGoal_r  << maxVel_mps  << "\n";
             // printf("%d \n", straightLineDist_m, " ");
            }
         }
      }
   }
   else
   {
      cout << "Unable to open file"; 
   }
   return 0;
}

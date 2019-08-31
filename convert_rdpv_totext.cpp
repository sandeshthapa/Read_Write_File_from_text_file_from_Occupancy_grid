#include <math.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64MultiArray.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/Bool.h>
#include <iostream>
#include <fstream>

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

void ParamsArrayCallback(const std_msgs::Float64MultiArray::ConstPtr &msg )
{    
   ofstream Paramfile;
   Paramfile.open ("/home/sthapa/DispParameter.txt", ios::app);
   // int linesArr = (msg->data).size();
   int linesArr =sizeof(msg->data);
   printf( "%d", linesArr );

   if (Paramfile.is_open())
   {
   for ( int Arrsize = 0; Arrsize < linesArr; Arrsize++ )
      {
         for (int lines = 0; lines < 4; lines++)
         {
           Paramfile << msg->data[lines] << " ";
         }
         Paramfile << "\n";  
      }
   Paramfile << "end_of_params \n";
   Paramfile.close();
   }

   else
   {
      cout << "Unable to open file"; 
   }
   }


int main( int argc, char * *argv )
{
   ros::init( argc, argv, "convert_rdpv" );
   ros::NodeHandle n;

    //Parameters to try 
    ros::Subscriber  _paramsToTrySub   = n.subscribe("/dispParametersToTry",1, ParamsArrayCallback );
   // Planned path

   while ( ros::ok() )
   {
     
      ros::spinOnce();
   }
}
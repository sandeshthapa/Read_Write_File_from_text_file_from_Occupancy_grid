#include <math.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64MultiArray.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/OccupancyGrid.h>
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/Bool.h>
#include <iostream>
#include <fstream>

using namespace std;
const vector<int8_t> *_occGrid;
double _gridOrigin[2];

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

// Get occupancy grid and write to a .txt file
void getNavPack( const nav_msgs::OccupancyGrid::ConstPtr &msg )
{   
   _occGrid       = &( msg->data );
   _gridOrigin[0] = msg->info.origin.position.x;
   _gridOrigin[1] = msg->info.origin.position.y;

   ofstream OccGridfile;
   OccGridfile.open ("/home/sthapa/getOccGrid.txt", ios::app);

   if (OccGridfile.is_open())
   { 
     // OccGridfile << _gridOrigin[0] << "\n";
      // OccGridfile << "\n";  
     // OccGridfile << _gridOrigin[1] << " \n ";
     // OccGridfile << "\n";  
      
      for ( int xIndex = 0; xIndex < 200; xIndex++ )  //The grid size is 200 X 200 
      {
         for (int yIndex = 0; yIndex < 200; yIndex++)
         {
            int occVal = _occGrid->at( yIndex * 200 + xIndex );  
            // printf("%d", occVal ); //Un comment this to test if it's printing the right info
            OccGridfile << occVal << " ";
         }
         OccGridfile << "\n";  
      }
   OccGridfile << "end_of_params \n" ;
   OccGridfile.close();
   }
   else
   {
      cout << "Unable to open file"; 
   }


   ofstream OccGridOriginfile;
   OccGridOriginfile.open ("/home/sthapa/getOccGridOrigin.txt", ios::app);

   if (OccGridOriginfile.is_open())
   { 
      OccGridOriginfile << _gridOrigin[0] << " " << _gridOrigin[1] << "\n ";
     // OccGridOriginfile << "\n";  
       OccGridOriginfile << "end_of_params \n" ;
   OccGridOriginfile.close();
   }
   else
   {
      cout << "Unable to open file"; 
   }

}

int main( int argc, char * *argv )
{
   ros::init( argc, argv, "convert_toOcc" );
   ros::NodeHandle n;

    //Subscribe to the occupancy grid nav_msgs
    ros::Subscriber _occGridSub = n.subscribe( "/global_freespace/occupancy_grid",1, getNavPack );

   while ( ros::ok() )
   {
     
      ros::spinOnce();
   }
}
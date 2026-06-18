#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
  /*
  Total angle = 360 degrees 
  
  ---- For hour hand ---- 
  Total hours = 12 
  Angle per hr = 360/12 = 30 degrees
  
  Tiny movement in hour hand cause of minute hand : 
  1 hr = 60 min = 30 degree movement 

  60 min = 30 degree
  1 min = 30/60 = 0.5 degree
  
  Total tiny movement = 0.5 * minutes

  Edge Case : 
  For 12th hr, Angle = 12 * 30 = 360 but since we restart do 12%12 * 360 = 0
  
  ---- For minute hand ---- 
  60 minutes 
  360 degrees
  Each min = 360/60 = 6 degrees / minute 
  */
  
  double minuteAngle = 6 * minutes;
  double hourAngle = (hour % 12) * 30 + (minutes * 0.5);
  double diff = abs(hourAngle - minuteAngle);
  return min(diff, 360 - diff); 
  }
};
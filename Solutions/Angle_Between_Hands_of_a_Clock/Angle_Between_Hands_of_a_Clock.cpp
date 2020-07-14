class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minRatio = minutes/60.;
        double hourAngle = 0.;
        
        if(hour >=12)
            hourAngle = (hour - 12)*30 +  (minRatio*30);
        else
            hourAngle = hour*30 + (minRatio*30);
        
        
        double minAngle = minRatio * 360;
        
        double result = minAngle - hourAngle;
        
        if(result < 0)
            result *= -1;
        
        if(result > 180)
            result = 360 - result;
        
        return result;
    }
};

/*
Fastest:
class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h=(hour*30)+minutes*0.5;
        //float h=((hourminutes%360)*0.5);
        int m=minutes*6;
        float angle=abs(h-m);
        if(angle>180)
            angle=360-angle;
        return angle;
    }
};
*/
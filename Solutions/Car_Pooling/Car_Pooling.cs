public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {
        var stops = trips
            .Select(x => new []{
                new {
                    passengers = x[0],
                    stop = x[1],
                    inOut = -1
                },
                new {
                    passengers = x[0],
                    stop = x[2],
                    inOut = 1
                }
            })
            .SelectMany(x => x)
            .OrderBy(x => x.stop)
            .ThenByDescending(x => x.inOut);
        
        foreach (var stop in stops) {
            capacity += stop.inOut * stop.passengers;
            if (capacity < 0) {
                return false;
            }
        }
        
        return true;
    }
}

//Most common
public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {        
        
        int sum =0;
        var arr =new int[1001];
        var arr1 =new int[1001];
                
        for(int i =0; i< trips.Length; i++){
            arr[trips[i][1]]+= trips[i][0];
            arr1[trips[i][2]]+= trips[i][0];            
        }
        
         
        for(int i=0; i< 1001; i++){
          
            sum+= arr[i];
            sum-= arr1[i];
            
            
            if(sum >capacity){
                return false;
            }
        }
        
        return true;
        
    }
}

//Fastest
public class Solution {
    public bool CarPooling(int[][] trips, int capacity) {        
        
        int sum =0;
        var arr =new int[1001];
        var arr1 =new int[1001];
                
        for(int i =0; i< trips.Length; i++){
            arr[trips[i][1]]+= trips[i][0];
            arr1[trips[i][2]]+= trips[i][0];            
        }
        
          Console.Write(arr[10]);
        
        for(int i=0; i< 1001; i++){
          
            sum+= arr[i];
            sum-= arr1[i];
            
            
            if(sum >capacity){
                return false;
            }
        }
        
        return true;
        
    }
}
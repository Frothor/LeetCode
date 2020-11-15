int poorPigs(int buckets, int minutesToDie, int minutesToTest) {return (int)ceil(log(buckets) / (log(minutesToTest / minutesToDie + 1)));}

//Another
int poorPigs(int buckets, int minutesToDie, int minutesToTest){
    int i =  minutesToTest/minutesToDie + 1;
    int n = 0;
    int t = 1;
    while (t < buckets) {
        t = i * t;
        n++;
    }
    return n;
}
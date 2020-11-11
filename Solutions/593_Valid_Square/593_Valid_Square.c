//Fastest
int cmp(void* a,void* b){
    if(((int**)a)[0][0]==((int**)b)[0][0]){
        return ((int**)a)[0][1]-((int**)b)[0][1];
    }
    return ((int**)a)[0][0]-((int**)b)[0][0];
}
int lenSquare(int* p,int* q){
    return (p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
}
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    if(p1[0]==p2[0]&&p1[1]==p2[1]){
        return false;
    }
    int** square=(int**)malloc(4*sizeof(int*));
    square[0]=p1;
    square[1]=p2;
    square[2]=p3;
    square[3]=p4;
    qsort(square,4,sizeof(square[0]),cmp);
    int len0=lenSquare(square[0],square[1]);
    int len1=lenSquare(square[0],square[2]);
    if(len0!=len1){
        return false;
    }
    int len2=lenSquare(square[3],square[2]);
    if(len2!=len1||len2!=lenSquare(square[3],square[1])){
        return false;
    }
    if(len0+len1!=lenSquare(square[1],square[2])){
        return false;
    }
    return true;
}

//Another
double distance(int* p, int* q) {
    int dist = ((q[0] - p[0]) * (q[0] - p[0])) + ((q[1] - p[1]) * (q[1] - p[1]));
    return dist;
}

int compare(const void* a, const void* b) {
    int** p = (int**)a;
    int** q = (int**)b;
    
    if ((*p)[0] == (*q)[0]) {
        return (int)((*p)[1] - (*q)[1]);        
    } else {
        return (int)((*p)[0] - (*q)[0]);
    }   
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int** p = malloc(4 * sizeof(int*));
    bool result = false;
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    
    qsort(p, 4, sizeof(int *), compare);
    
    if ((distance(p[0],p[1]) != 0) && (distance(p[0],p[1]) == distance(p[1],p[3])) 
        && (distance(p[1],p[3]) == distance(p[3],p[2])) && (distance(p[3],p[2]) == distance(p[2],p[0])) && 
        (distance(p[1],p[2]) == distance(p[0],p[3]))) {
        result = true;
    }
    
    free(p);
    return result;
}

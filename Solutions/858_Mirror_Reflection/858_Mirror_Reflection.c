int mirrorReflection(int p, int q){
    
    while((p%2) == 0 && (q%2) == 0)
    {
        p = p/2;
        q = q/2;
    }
    printf("%d %d\n", p, q);
    if (p%q == 0)
    {
        if (p/q%2 == 0)
            return 2;
        else
            return 1;
    }
    else
    {
        if (p%2 == 0)
            if (q%2 == 1)
                return 2;
            else
                return 0;
        else
            if (q%2 == 1)
                return 1;
            else
                return 0;
    }
    return 3;
}

int mirrorReflection(int p, int q){
    while(p % 2 == 0 && q % 2 == 0) {
        p = p / 2;
        q = q / 2;
    }
    if(p % 2 == 0) {
        if(q % 2 == 1) return 2;  
    } else {
        return (q % 2 == 1) ? 1 : 0;
    }
    return -1;
}
func champagneTower(poured int, query_row int, query_glass int) float64 {
    
    pours := [101][101] float64{}
    
    pours[0][0] = float64(poured);
    
    
    for row := 0; row <= query_row ; row++{
        for glass := 0 ; glass <= row ; glass++ {
            
            if pours[row][glass] > 1 {
                
                pours[row+1][glass] += (pours[row][glass] - 1 )/ 2.0 ;
                pours[row+1][glass+1] += (pours[row][glass] - 1 )/ 2.0 ;
                pours[row][glass] = 1.0;
         
            }
                   }
    }
    
     return pours[query_row][query_glass] ;
}
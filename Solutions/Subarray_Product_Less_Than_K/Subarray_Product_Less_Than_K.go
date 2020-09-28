func numSubarrayProductLessThanK(nums []int, k int) int {
    if k<= 1 {
        return 0
    }
    
    left := 0
    ans := 0
    prod := 1
    
    for right:=0;right<len(nums);right++ {
        prod*=nums[right]
        
        for prod >= k {
            prod/=nums[left]
            left+=1
        }
        ans+=right-left+1
    
    }
    return ans
}

//Fastest
func numSubarrayProductLessThanK(nums []int, k int) int {
    
    result:=0
    st:=0
    maxp:=0
    for i:=0;i<len(nums);i++{
        if nums[i]<k{
            p:=1
            if maxp==0 && nums[i]<k{
                maxp=nums[i]
                result++
                st=i
                //fmt.Printf("result %d st %d i %d maxp %d \n",result,st,i,maxp)
                continue
            }
            if maxp*nums[i] <k{
                maxp=maxp*nums[i]
                result+=(i-st+1)
                //fmt.Printf("result %d st %d i %d maxp %d \n",result,st,i,maxp)
                continue
            }
            for j:=i;j>=st;j--{
                p=p*nums[j]
                if p<k{
                    result++
                    maxp=p
                    //fmt.Printf("result %d st %d i %d j %d \n",result,st,i,j)
                    continue
                }
                st=j+1
                break
            }
           
           
        }else{
             maxp=0
            
        }
        
        
    }
    
    return result
    
}
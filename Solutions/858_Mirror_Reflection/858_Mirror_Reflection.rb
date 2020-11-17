def mirror_reflection(p, q)
  k = 1
  
  while k*q%p>0
    k += 1
  end
  
  k%2==0 ? 2 : (k*q/p)%2
end
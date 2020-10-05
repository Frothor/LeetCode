# LeetCode Complement of Base 10 Integer Solution
## [Python] Oneliner explained

What we actually need to find in this problem is length of our number in bits: if we have `10 = 1010`, then complementary is `5 = 101`. Note, that `5 + 10 = 15 = 2^4 - 1`. So, let us just find length of our number in bits and subtract `N-1`.

**Complexity** time complexity is `O(log N)` to find its length; space complexity is also `O(log N)` to keep binary representation of our number.

```python
class Solution:
    def bitwiseComplement(self, N):
         return (1<<(len(bin(N)) - 2)) - 1 - N
```

[Link to orignal post](https://leetcode.com/problems/complement-of-base-10-integer/discuss/880072/Python-Oneliner-explained)

## golang bitwise op with explanation [CH/EN]

```go
func bitwiseComplement(N int) int {
	if N == 0 {
		return 1
	}
	
	NP := N // a copy of N
	for offset := uint(1); N>>offset > 0; offset <<= 1 {
		N |= (N >> offset)
	}
	return NP ^ N
}
```

### 中文:

有如下逻辑关系：

数字	二进制	操作数	XOR 结果
5	101	111	010
20	10100	11111	01011
7	111	111	0
所以，找到与数字 N 的 bit 位数相同，但是每个 bit 都为 1 的数（mask），与 N 进行 XOR 运算就可以了

这里使用的位运算技巧源于一个将数字 round 到最近的 2 次方数的算法。例如数字 11，将其所有 bit 置为 1 的步骤：
```go
num:=8 // 1000
num>>1 // 0100
num=num|(num>>1) // 1100
num>>2 // 0011
num=num|(num>>2) // 1111
num>>4 // 0000, break
```
位移的偏移量按照 2 的指数递增，因为每次 OR 运算都会累积 2 的倍数长度的、为 1 的 bit

### english:

N	binary of N	operand	XOR result
5	101	111	010
20	10100	11111	01011
7	111	111	0
Calculate the bit width of N, construct a bit mask with the same width, return the XOR of N and mask

there is a trick to get the mask without using lib function
```go
// example 
num:=8 // 1000
num>>1 // 0100
num=num|(num>>1) // 1100
num>>2 // 0011
num=num|(num>>2) // 1111
num>>4 // 0000, num decreased to zero after the shift, stop the loop

num:=0x100 // 1 0000 0000
num>>1 // 0 1000 0000
num=num|(num>>1) // 1 1000 0000, 2 bits
num>>2 // 0 0110 0000
num=num|(num>>2) // 1 1110 0000, 4 bits
num>>4 // 0 0001 1110
num=num|(num>>4) // 1 1111 1110, 8 bits
...
```

[Link to original post](https://leetcode.com/problems/complement-of-base-10-integer/discuss/379906/golang-bitwise-op-with-explanation-CHEN)
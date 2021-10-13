class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
     unsigned int e=(n&(0xAAAAAAAA));
     unsigned int o=(n&(0x55555555));
      
      e=(e>>1);
      o=(o<<1);
      
     unsigned int m;
      
      m= e|o;
      
      return m;
    }
};

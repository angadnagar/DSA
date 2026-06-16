class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;

        for(int i=0;i<32;i++){
          int curr_bit_a = (a>>i)&1;
          int curr_bit_b = (b>>i)&1;

          int xor_bit = curr_bit_a ^ curr_bit_b ^ carry;

          carry = (curr_bit_a+curr_bit_b+carry) >=2 ? 1 : 0;

          if(xor_bit){
            res|=(1<<i);
          }
        }

        // if(res>0x7FFFFFFF){
        //   res=~(res ^ 0xFFFFFFFF);
        // }

        return res;
    }
};

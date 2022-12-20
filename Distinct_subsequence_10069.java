import java.io.*;
import java.math.BigInteger;


public class Distinct_subsequence_10069 {
    static String x,z;

    static BigInteger memo[][];
    static boolean V[][];

    private static BigInteger dp(int i, int j){
        if(V[i][j])
            return memo[i][j];
        if(j == z.length()){
            V[i][j]=true;
            memo[i][j] = BigInteger.valueOf(1);
            return memo[i][j];
        }
            
        if(i == x.length()){
            V[i][j]=true;
            memo[i][j]=BigInteger.valueOf(0);
            return BigInteger.valueOf(0);
        }
        

        BigInteger ans=BigInteger.valueOf(0);
        for(int k=i;k<x.length();++k) {
            if(x.charAt(k) == z.charAt(j)) {
                ans = ans.add(dp(k+1,j+1));
            }
        }
        V[i][j]=true;
        memo[i][j]=ans;
        return ans;
    }

    public static void main(String [] args){
        int cases;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            cases = Integer.parseInt(br.readLine());
            while(cases-- > 0) {
                memo = new BigInteger[10005][105];
                V = new boolean[10005][105];
                x = br.readLine();
                z = br.readLine();
                BigInteger res = dp(0,0);
                System.out.println(res.toString());
            }
        } catch (IOException ioe){}
    }
}

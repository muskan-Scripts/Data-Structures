class Main {
    public static int[] genlps(String str){
        int[] lps=new int[str.length()];
        if(lps.length<=1)return lps;
        lps[0]=0;
        int len=0;
        for(int i=1; i<lps.length; i++){
            if(str.charAt(len) == str.charAt(i)) {
                lps[i]=len+1;
            }
            else{
                lps[i]=0;
            }
            len=lps[i];
        }
        
        return lps;
    }
    
    public static void main(String[] args) {
        
    }
}

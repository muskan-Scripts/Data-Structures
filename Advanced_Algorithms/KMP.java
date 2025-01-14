class KMP {
    public static int[] genlps(String str) {
        int[] lps = new int[str.length()];
        if (lps.length <= 1) return lps;
        lps[0] = 0;
        int len = 0;
        for (int i=1; i < lps.length; i++) {
            
            if (str.charAt(len) == str.charAt(i)) {
                lps[i]=len+1;
            }
            else {
                lps[i] = 0;
            }
            
            len = lps[i];
        }
        
        return lps;
    }
    
    public static boolean ispresent(String text, String pattern) {
        int[] lps = genlps(pattern);
        int i = 0;
        int j = 0;

        while (i < text.length()) {
            if (pattern.charAt(j) == text.charAt(i)) {
                i++;
                j++;
            }
            if (j == pattern.length()) {
                return true;
            } else if (i < text.length() && pattern.charAt(j) != text.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    
    public static void main(String[] args) {
        
    }
}

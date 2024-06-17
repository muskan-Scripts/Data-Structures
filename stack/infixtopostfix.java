import java.util.*;


public class infixtopostfix{
    public static void main(String[] args) {
        Stack <Character> st = new  Stack<>();
        String str= new String("4512+-*"); //runs only if output is positive
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i)<='9' && str.charAt(i)>='0'){
                st.push(str.charAt(i));
            }
            else{
                int a= Integer.parseInt(Character.toString(st.pop()));
                int b= Integer.parseInt(Character.toString(st.pop()));
                if(str.charAt(i)=='+'){
                    int val= b+a;

                    String t = Integer.toString(val);
                    char [] cho= t.toCharArray();
                    st.push(cho[0]);
                    


                }
                if(str.charAt(i)=='-'){
                    int val= b-a;

                    String t = Integer.toString(val);
                    char [] cho= t.toCharArray();
                    st.push(cho[0]);
                }
                if(str.charAt(i)=='/'){
                    int val= b/a;

                    String t = Integer.toString(val);
                    char [] cho= t.toCharArray();
                    st.push(cho[0]);

                }
                if(str.charAt(i)=='*'){
                    int val= b*a;

                    String t = Integer.toString(val);
                    char [] cho= t.toCharArray();
                    st.push(cho[0]);
                }
            

            }
        }
        System.out.println(st);


    }
}
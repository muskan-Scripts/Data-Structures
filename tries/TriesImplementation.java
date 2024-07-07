import java.util.*;

 class Node{
    Node[] children = new Node[26];
    boolean eow;

    public Node(){
        for(int i=0; i<26; i++){
            children[i]=null;
        }
    }
}


public class TriesImplementation{
    public static void insert(Node root, String word){
        
       

        int idx=0;

        Node curr=root;
        for(int level=0; level<word.length(); level++){
            idx= word.charAt(level)-'a';
            if(curr.children[idx]==null){
                curr.children[idx] = new Node();
            }
            curr= curr.children[idx];
        }
        curr.eow=true;
        return;
    }
    public static boolean search(Node root, String word){
        Node curr= root;

        for(int i=0; i<word.length(); i++){
            int idx= word.charAt(i)-'a';
            if(curr.children[idx]==null){
                return false;
            }
            if(i==word.length()-1 && curr.children[idx].eow!=true){
                return false;
            }
            curr=curr.children[idx];
        }
        return true;
    }
    public static void main(String[] args) {
        Node root=new Node();
        String word = new String("hello");
        insert(root, word);
        System.out.println(search(root, "helt"));
    }
}

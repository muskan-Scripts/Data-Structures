import java.util.*;
public class stl {
    public static void main(String[] args) {
        HashSet<Integer> st= new HashSet<>();
        for(int i=0; i<10; i+=2){
            st.add(i);
        }
        st.add(5);
        st.add(59);
        st.add(58);
        st.add(50);
        st.add(65);
        System.out.println(st);

        TreeSet<Integer> sto= new TreeSet<>();
        sto.add(5);
        sto.add(59);
        sto.add(58);
        sto.add(50);
        sto.add(65);
        System.out.println(sto);

        LinkedHashSet<Integer> stoo= new LinkedHashSet<>();
        stoo.add(5);
        stoo.add(59);
        stoo.add(58);
        stoo.add(50);
        stoo.add(65);
        System.out.println(stoo);
        Iterator it= stoo.iterator();
        int cout=0;
        while(it.hasNext()){
            it.next();
            cout++;

        }
        System.out.println(cout);
    }

}

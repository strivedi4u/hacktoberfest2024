import java.util.*;
public class AllSubsequence {
    public static void subs(int[] arr,int idx,List<Integer> list,int n)
    {
        if(idx==n)
        {
            System.out.println(list);
            return;
        }
        list.add(arr[idx]);
        subs(arr,idx+1,list,n);
        list.remove(list.size()-1);
        subs(arr,idx+1,list,n);
    }
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);
        System.out.println("Enter the value of n: ");
        int n=vis.nextInt();
        System.out.println("Enter any "+n+" values");
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=vis.nextInt();
        }
        List<Integer> list=new ArrayList<>();
        subs(arr,0,list,n);
        vis.close();
    }
}

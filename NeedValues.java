public class NeedValues{
    public List<Integer> NeededValues(int[] a, int n)
    {
        List<Integer> values = new ArrayList<Integer>();
        if (a == null || a.Length == 0)
            return values;

        int sum = 0;
        int index = 0;
        int i = 1;

        while (i <= n)
        {
            if (index < a.Length && i == a[index])
            {
                sum += a[index];
                index++;
            }
            else if (sum < i)
            {
                sum += i;
                values.Add(i);
            }

            i++;
        }

        return values;
    }
    public static void main(String[] args){
        NeedValues sol = new NeedValues();
        int [] A= new int[]{1,2,4,5,9};
        List<Integer> res= sol.NeedValues(A,20);
        for(int i = 0; i <res.size(); i++){
            System.out.println(res.get(i));
        }
    }
}
public class Aufg1 {
    public static void main(String[] args) {
        int[] a = { 0,0,0,0 };
        int[] b = a;
        System.out.println(java.util.Arrays.toString(b));
        int sum = 0;
        for (int i = 0; i < a.length; i++)
            sum += a[i];
        System.out.println(sum);
        int k = 0;
        for (int i = 1; i <= a.length; i++)
            System.out.println(i + ": " + a[k++]);
        int[] m = new int[a.length - 2];
        for (int i = 1; i < a.length - 1; i++) {
            int val = (a[i - 1] + a[i] + a[i + 1]);
            m[i - 1] = val / 3;
        }
        int max = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] > max)
                max = a[i];
        }
        System.out.println(max);
        int i = 0;
        while (a[i] == 0 & ++i < a.length)
            ;
        System.out.println(i);
    }

}

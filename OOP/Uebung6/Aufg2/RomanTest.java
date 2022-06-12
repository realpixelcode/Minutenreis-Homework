public class RomanTest {
    public static void main(String[] args) {
        Roman r1 = new Roman("IVXC");
        Roman r2 = new Roman(4);
        Roman r3 = new Roman(44);
        Roman r4 = new Roman(50);
        Roman r5 = new Roman(99);
        Roman r6 = new Roman(100);
        Roman r7 = new Roman(500);
        Roman r8 = new Roman(1001);
        Roman[] arr = { r1, r2, r3, r4, r5, r6, r7, r8 };
        for (Roman elem : arr) {
            System.out.println(elem);
        }
        
    }
}

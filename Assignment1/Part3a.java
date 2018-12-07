import java.util.ArrayList;
import java.util.Scanner;

public class Part3a {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String alpha = "abcdefghijklmnopqrstuvwxyz";

        ArrayList alpha_array = new ArrayList();
        ArrayList key_array = new ArrayList();

        for (int i=0; i<26; i++)
        {
            char c = alpha.charAt(i);
            alpha_array.add(c);
            int d = (int)c +7;
            if  (d>122)
            {
                d=d-26;
            }
            key_array.add((char)d);
        }
        String ciphertext = sc.next() + sc.nextLine();

        String plain_text = "";

        for (int i=0; i<ciphertext.length(); i++)
        {
            char c = ciphertext.charAt(i);

            if (c>64 && c<91)
            {
                c=Character.toLowerCase(c);
                int index = key_array.indexOf(c);
                char  d = Character.toUpperCase((Character) alpha_array.get(index));
                plain_text += d;
            }
            else if ( c>96 && c<123)
            {
                int index = key_array.indexOf(c);
                plain_text += alpha_array.get(index);
            }
            else
            {
                plain_text +=  c;
            }
        }

        System.out.println(plain_text);

    }


}

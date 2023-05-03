import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        Stack stack = new Stack();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine(), " ");
            String input = st.nextToken();
            if(input.equals("push")){
                int num = Integer.parseInt(st.nextToken());
                stack.push(num);
            }
            if(input.equals("pop")){
                if(stack.empty()) System.out.println("-1");
                else{
                    System.out.println(stack.pop());
                }
            }
            if(input.equals("size")){
                System.out.println(stack.size());
            }
            if(input.equals("empty")){
                if(stack.empty()) System.out.println("1");
                else System.out.println("0");
            }
            if(input.equals("top")){
                if(stack.empty()) System.out.println("-1");
                else System.out.println(stack.peek());
            }
        }
    }
}

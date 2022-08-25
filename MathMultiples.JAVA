<InputManager>
  import java.util.Scanner;

public class InputManager {
	Scanner scan = new Scanner(System.in);

	int getInt() {
		int x;
		System.out.print("정수를 입력하시오 : ");
		x = scan.nextInt();
		return x;
	}
}
----------------------------------------------------------
<MathMultiples>
public class MathMultiples {
	int integer;
	
	MathMultiples(int in){
		integer = in;
	}
	
	int calculate(int in) {
		int i = 0;
		int cnt = 0;
		
		for(i = in; i<500; i++) {
			if(i % in == 0) {	// 배수
				System.out.print(i+" ");
				cnt ++;
			}
			if(cnt % 5 == 0) {
				System.out.println();
			}
		}
		return i;
	}
}
----------------------------------------------------------
<Operator>
public class Operator {

	public static void main(String[] args) {
		
		MathMultiples math;
		int x;
		InputManager in = new InputManager();
		x = in.getInt();
		
		math = new MathMultiples(x);
		math.calculate(x);
		System.out.println(math.calculate(x));
	}
}

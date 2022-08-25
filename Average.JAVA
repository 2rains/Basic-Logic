<InputManager>
import java.util.Scanner;

public class InputManager {
	Scanner scan = new Scanner(System.in);
	//int inteager;

	int[] getInt() {	// 메소드
		int[] x;
		x= new int[5];
		for(int i=0;i<5;i++) {
			System.out.print("정수를 입력하시오 : ");
			x[i] = scan.nextInt();
		}
		return x;
	}
}
---------------------------------------------------------
<Average>
public class Average {
	int[] integer;
	int avg;

	Average(int[] integer){
		this.integer = integer;
		
	}
	
	int average(int integer[]) {
		int sum=0;
		int avg=0;
		
		for(int i = 0; i<integer.length; i++) {
			sum += integer[i];
		}
		System.out.println("총합 : " + sum);
		avg = sum / integer.length;
		
		System.out.println("평균 : " + avg);
		return avg;
	}
}
---------------------------------------------------------
<Operator>
public class Operator {

	public static void main(String[] args) {
		Average avg;
		int[] x;
		InputManager in = new InputManager();
		x = in.getInt();
		
		avg = new Average(x);
		avg.average(x);
	}
}

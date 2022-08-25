<InputManager>
import java.util.Scanner;

public class InputManager {
	Scanner scan = new Scanner(System.in);
	
	double getDouble() {
		double x;
		System.out.print("실수를 입력하시오 : ");
		x = scan.nextDouble();
		return x;
	}
	
	int getInt() {
		int x;
		System.out.print("정수를 입력하시오 : ");
		x = scan.nextInt();
		return x;
	}
	
	String getString() {
		String x;
		System.out.print("문자열을 입력하시오 : ");
		x = scan.nextLine();
		return x;
	}
}
-------------------------------------------------------------
<Rectangle>

public class Rectangle {
	double side1;
	double side2;
	double area;
	double round;
	
	Rectangle(double s1, double s2){	// 기본생성자
		side1 = s1;
		side2 = s2;
	}
	
	Rectangle(){
	}
	
	void calculateArea() {
		area = side1 * side2;
	}
	
	void calculateRound() {
		round = (side1 + side2)*2;
	}
}
-------------------------------------------------------------
<Operator>
public class Operator {

	public static void main(String[] args) {
		
		Rectangle rec;
		double x, y;
		InputManager in = new InputManager();
		x = in.getDouble();
		y = in.getDouble();
		
		rec = new Rectangle(x,y);
		rec.calculateArea();
		System.out.println("사각형의 면적 : "+rec.area);
	}
}

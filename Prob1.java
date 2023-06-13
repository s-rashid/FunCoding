import java.util.ArrayList;
import java.util.Scanner;

// Abstract class Shape
abstract class Shape {
    // Abstract method for area
    abstract double area();
    // Abstract method for perimeter
    abstract double perimeter();
}

// Circle class extends Shape class
class Circle extends Shape {
    double radius;
    
    // Constructor
    Circle(double radius) {
        this.radius = radius;
    }
    
    // Method to calculate area
    @Override
    double area() {
        return Math.PI * Math.pow(radius, 2);
    }
    
    // Method to calculate perimeter
    @Override
    double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// Rectangle class extends Shape class
class Rectangle extends Shape {
    double length;
    double width;
    
    // Constructor
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    
    // Method to calculate area
    @Override
    double area() {
        return length * width;
    }
    
    // Method to calculate perimeter
    @Override
    double perimeter() {
        return 2 * (length + width);
    }
}

// Triangle class extends Shape class
class Triangle extends Shape {
    double sideA;
    double sideB;
    double sideC;
    
    // Constructor
    Triangle(double sideA, double sideB, double sideC) {
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
    }
    
    // Method to calculate area
    @Override
    double area() {
        double s = (sideA + sideB + sideC) / 2.0;
        return Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
    
    // Method to calculate perimeter
    @Override
    double perimeter() {
        return sideA + sideB + sideC;
    }
}

public class ShapeDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Shape> shapes = new ArrayList<Shape>();
        int choice = 0;
        while (choice != 4) {
            System.out.println("1. Add a Circle\n2. Add a Rectangle\n3. Add a Triangle\n4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter radius of circle: ");
                    double radius = scanner.nextDouble();
                    shapes.add(new Circle(radius));
                    break;
                case 2:
                    System.out.print("Enter length of rectangle: ");
                    double length = scanner.nextDouble();
                    System.out.print("Enter width of rectangle: ");
                    double width = scanner.nextDouble();
                    shapes.add(new Rectangle(length, width));
                    break;
                case 3:
                    System.out.print("Enter side A of triangle: ");
                    double sideA = scanner.nextDouble();
                    System.out.print("Enter side B of triangle: ");
                    double sideB = scanner.nextDouble();
                    System.out.print("Enter side C of triangle: ");
                    double sideC = scanner.nextDouble();
                    shapes.add(new Triangle(sideA, sideB, sideC));
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice, try again.");
                    break;
            }
        }
        scanner.close();
        System.out.println("Shapes:");
        for (Shape shape : shapes) {
            System.out.println(shape.getClass().getSimpleName() + " -

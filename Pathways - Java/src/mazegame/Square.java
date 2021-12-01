// Square class
// By Nick Verrochi
// Last Modified: 4/13/15

package mazegame;

import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

enum Status { UNTOUCHED, WARNING, PATH, PRESSED };
// this enumerated type is used
// as opposed to a set of booleans

public class Square extends Rectangle {
    private Color color;
    private Status status;
    static private int globalErrors = 0;
    static private boolean mapMode = true;
    static private int squaresMapped = 0;
    static private int squaresPressed = 0;
    
    // initializes the square to default values
    public Square() {
        super(50, 50);
        status = Status.UNTOUCHED;
        color = Color.WHITE;
        setFill(color);
        setStroke(Color.BLACK);
    }
    
    public void setColor(Color c) {
        color = c;
        setFill(color);
    }
    
    public void setStatus(Status s) {
        status = s;
    }
    
    public static void setMapMode(boolean m) {
        mapMode = m;
    }
    
    public static void setSquaresMapped(int n) {
        squaresMapped = (n < 0 ? 0 : n);
    }
    
    public static void setSquaresPressed(int n) {
        squaresPressed = (n < 0 ? 0 : n);
    }
    
    public Color getColor() {
        return color;
    }
    
    public Status getStatus() {
        return status;
    }
    
    public static int getGlobalErrors() {
        return globalErrors;
    }
    
    public static boolean isMapMode() {
        return mapMode;
    }
    
    public static int getSquaresMapped() {
        return squaresMapped;
    }
    
    public static int getSquaresPressed() {
        return squaresPressed;
    }
    
    // this function decides what to do with square
    // based on status
    public void press() {
        switch (status) {
            case UNTOUCHED:
                warn();
                status = Status.WARNING;
                break;
            case WARNING:
                error();
                break;
            case PATH:
                status = Status.PRESSED;
                color = Color.BLUE;
                setFill(color);
                ++squaresPressed;
        }
    }
    
    // this function maps the square as part of the path
    public void map() {
        if (status == Status.UNTOUCHED) {
            status = Status.PATH;
            color = Color.BLUE;
            setFill(color);
            ++squaresMapped;
        }
    }
    
    // this function produces a warning when pressed
    public void warn() {
        if (status == Status.UNTOUCHED) {
            status = Status.WARNING;
            setColor(new Color(1.0, 1.0, 0.0, 1.0));
        }
    }
    
    public void error() {
        if (status == Status.WARNING) {
            setColor(new Color(color.getRed(), (color.getGreen() - 0.2 >= 0.0 ?
                    color.getGreen() - 0.2 : 0.0), color.getBlue(), 1.0));
            ++globalErrors;
        }
    }
}
// Preset class
// Stores and retrieves presets for maze game
// By Nick Verrochi
// Last Modified: 5/14/15

package mazegame;

import java.util.ArrayList;
import javafx.scene.paint.Color;

public class Preset {
    private ArrayList<Square> squareList;
    private Square ref; 
    // reference variable to set up squares 
    // as they are added to the list
    
    public ArrayList<Square> getPreset1() {
        Square.setMapMode(true);
        squareList = new ArrayList<>();
        
        for (int i = 0; i < 60; ++i) {
            ref = new Square();
            switch(i) {
                case 0:   case 1:   case 2:   case 3:
                case 14:   case 15:
                case 20:   case 21:   case 22:   case 23:
                case 25:   case 26:
                case 33:   case 34:
                case 36:   case 37:   case 38:   case 39:
                case 46:   case 47:
                    break;
                default:
                    ref.map();
                    ref.setColor(Color.WHITE);
            }
            squareList.add(ref);
        }
        
        Square.setMapMode(false);
        return squareList;
    }
    
    public ArrayList<Square> getPreset2() {
        Square.setMapMode(true);
        squareList = new ArrayList<>();
        
        for (int i = 0; i < 60; ++i) {
            ref = new Square();
            switch(i) {
                case 6:   case 7:
                case 20:   case 21:   case 22:   case 23:   case 24:
                case 27:
                case 29:   case 30:   case 31:   case 32:
                case 34:
                case 38:   case 39:   case 40:
                case 45:
                case 52:   case 53:
                    break;
                default:
                    ref.map();
                    ref.setColor(Color.WHITE);
            }
            squareList.add(ref);
        }
        
        Square.setMapMode(false);
        return squareList;
    }
    
}

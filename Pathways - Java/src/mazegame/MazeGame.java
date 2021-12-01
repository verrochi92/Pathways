// Maze Game JavaFX version
// Main class
// By Nick Verrochi
// Last Modified: 5/14/15
// TODO: implement preset loading
// TODO: change button

package mazegame;

import java.util.ArrayList;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class MazeGame extends Application {
    private Square sqRef; // reference variable for temporary use
    private Label label = new Label("Welcome! First we must map the squares. \n"
            + "Simply click on a square to map it.");
    private GridPane squarePane = new GridPane();
    private HBox presetPane = new HBox();
    private boolean presetMode = false;
    private ArrayList<Square> squareList = new ArrayList<>();
    private Preset preset = new Preset();
    private Stage stage = new Stage();
    private Scene presetScene = new Scene(presetPane, 500, 35);
    
    @Override
    public void start(Stage primaryStage) {
        primaryStage = stage;
        // sets "stage" pointer to the primary stage
        
        Square.setMapMode(true);
        // switches to false after squares have been mapped
        
        // sets up scene for game
        BorderPane mainPane = new BorderPane();
        mainPane.setCenter(squarePane);
        mainPane.setBottom(label);
        mainPane.setAlignment(label, Pos.CENTER);
        Scene gameScene = new Scene(mainPane, 500, 600);
        
        // sets up scene for preset selection
        Label presetLabel = new Label("Please select a preset or customize "
                + "your own path: ");
        Button btPreset1 = new Button("Preset 1");
        Button btPreset2 = new Button("Preset 2");
        Button btCustomize = new Button("Customize");
        
        // preset events
        btPreset1.setOnAction(e -> {
            squareList = preset.getPreset1();
            presetMode = true;
            stage.setScene(gameScene);
            setGameScene();
        });
        btPreset2.setOnAction(e -> {
            squareList = preset.getPreset2();
            presetMode = true;
            stage.setScene(gameScene);
            setGameScene();
        });
        btCustomize.setOnAction(e -> {
            presetMode = false;
            stage.setScene(gameScene);
            setGameScene();
        });
        presetPane.getChildren().addAll(presetLabel, btPreset1, btPreset2,
                btCustomize);
        
        // initialization
        stage.setScene(presetScene);
        stage.setTitle("Maze Game");
        stage.show();
    }
    
    public void setGameScene() {
        SquareHandler handler = new SquareHandler(); 
        // event handler for squares
        
        // population of square pane
        squarePane.setAlignment(Pos.CENTER);
        int i = 0;
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 6; ++x) {
                // sets up grid of squares with x and y indexes
                if (!presetMode) {
                    sqRef = new Square();
                }
                else {
                    sqRef = squareList.get(i);
                    ++i;
                }
                squarePane.getChildren().add(sqRef);
                squarePane.setRowIndex(sqRef, y);
                squarePane.setColumnIndex(sqRef, x);
                sqRef.setOnMouseClicked(handler);
            }
        }
        Font font = new Font(15);
        label.setFont(font);
        label.setAlignment(Pos.CENTER);
        label.setTextAlignment(TextAlignment.CENTER);
        if (presetMode) {
            label.setText("Time to play! " + Square.getSquaresMapped() + 
                    " squares remain");
        }
    }
    
    public class SquareHandler implements EventHandler<MouseEvent> {
        @Override
        public void handle(MouseEvent e) {
            if (Square.isMapMode()) {
                if (Square.getSquaresMapped() < 24) {
                    // find source
                    for (int i = 0; i < squarePane.getChildren().size(); ++i) {
                        if (squarePane.getChildren().get(i) == e.getSource()) {
                            sqRef = (Square)e.getSource();
                            sqRef.map();
                            label.setText(String.format("%d squares left to map"
                            , 25 - Square.getSquaresMapped()));
                        }
                    }
                }
                else {
                    Square.setMapMode(false);
                    for (int i = 0; i < squarePane.getChildren().size(); ++i) {
                        if (squarePane.getChildren().get(i) instanceof Square) {
                            sqRef = (Square)squarePane.getChildren().get(i);
                            if (sqRef == e.getSource()) {
                                sqRef.map();
                            }
                            sqRef.setColor(Color.WHITE);
                        }
                        
                    }
                    label.setText("Time to play! 25 squares remain");
                }
            }
            
            // play mode
            else {
                if (Square.getSquaresPressed() < Square.getSquaresMapped()) {
                    for (int i = 0; i < squarePane.getChildren().size(); ++i) {
                        if (squarePane.getChildren().get(i) == e.getSource()) {
                            sqRef = (Square)e.getSource();
                            sqRef.press();
                            label.setText(String.format("%d squares remain",
                                    Square.getSquaresMapped() - 
                                            Square.getSquaresPressed()));
                        }
                    }
                }
                else {
                    for (int i = 0; i < squarePane.getChildren().size(); ++i) {
                        if (squarePane.getChildren().get(i) instanceof Square) {
                            sqRef = (Square)squarePane.getChildren().get(i);
                            if (sqRef == e.getSource()) {
                                sqRef.press();
                            }
                            sqRef.setColor(Color.WHITE);
                            sqRef.setStatus(Status.UNTOUCHED);
                        }
                    }
                    label.setText("Congratulations! You have won the"
                                    + " game. \n You made " + 
                                    Square.getGlobalErrors() + " errors. \n" +
                                    "Now going back to map mode...");
                    Square.setMapMode(true);
                    Square.setSquaresMapped(0);
                    Square.setSquaresPressed(0);
                    stage.setScene(presetScene);
                }
            }
        }
    }
}
import javafx.application.Application;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;


public class AudioPlayerDemo extends Application {

	static MediaPlayer mediaPlayer = null;
	static int itemNum = -1;	//当前歌曲索引
	static int maxItem;	//歌曲数目


	public void start(Stage primaryStage) throws Exception {
		primaryStage = EventHandlerDemo.getStage();
		primaryStage.setTitle("音乐点播平台");

        primaryStage.show();
	}

	 
	 
	            

	public static void main(String[] args) {
		launch(args);
	}

}

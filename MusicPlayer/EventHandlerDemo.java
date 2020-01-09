import java.io.File;
import java.util.List;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.paint.Color;
import javafx.stage.DirectoryChooser;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class EventHandlerDemo {

	static public Stage getStage() {
		Stage primaryStage = new Stage();

		/*********************歌曲列表处理****************/
		LayoutDemo.lv.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				//鼠标双击
				if (event.getButton() == MouseButton.PRIMARY && event.getClickCount() == 2) {
					if (AudioPlayerDemo.mediaPlayer != null)
						AudioPlayerDemo.mediaPlayer.stop();

					if (AudioPlayerDemo.itemNum != -1) {
						LayoutDemo.lv.getSelectionModel().getSelectedItem().setTextFill(Color.BLACK);
					}
					AudioPlayerDemo.itemNum = LayoutDemo.lv.getSelectionModel().getSelectedIndex();
					LayoutDemo.lv.getSelectionModel().getSelectedItem().setTextFill(Color.GRAY);

					File path = UtilDemo.listFiles.get(AudioPlayerDemo.itemNum);
					String source = path.toURI().toString();
					Media media = new Media(source);
					AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
					LayoutDemo.bindSlider();

					if (AudioPlayerDemo.itemNum < 11) {
						LayoutDemo.lv.scrollTo(0);
					} else {
						LayoutDemo.lv.scrollTo(AudioPlayerDemo.itemNum - 11);
					}

					LayoutDemo.doParse();
					AudioPlayerDemo.mediaPlayer.play();
					LayoutDemo.play.setText("暂停");
				}
			}
		});

		/*********************菜单处理****************/
		//打开歌曲文件
		LayoutDemo.openSongFiles.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				FileChooser fileChooser = new FileChooser();
				fileChooser.setTitle("添加歌曲");
				fileChooser.getExtensionFilters().addAll(new FileChooser.ExtensionFilter("MP3", "*.mp3"));
				List<File> tempLv = null;
				tempLv = fileChooser.showOpenMultipleDialog(primaryStage);

				if (tempLv != null) {
					UtilDemo.listFiles = tempLv;
					Label[] listLabel = new Label[UtilDemo.listFiles.size()];
					AudioPlayerDemo.maxItem = UtilDemo.listFiles.size();
					ObservableList<Label> obLabel = FXCollections.observableArrayList();
					int i = 0;
					for (File lf : UtilDemo.listFiles) {
						listLabel[i] = new Label(lf.getName());
						obLabel.add(listLabel[i]);
						i++;
					}
					AudioPlayerDemo.itemNum = -1;
					LayoutDemo.lv = new ListView<Label>(obLabel);
					LayoutDemo.bp.setRight(LayoutDemo.lv);
					UtilDemo.saveSongMenuFiles(UtilDemo.listFiles);

					LayoutDemo.lv.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
						
						public void handle(MouseEvent event) {
							//鼠标双击
							if (event.getButton() == MouseButton.PRIMARY && event.getClickCount() == 2) {
								if (AudioPlayerDemo.mediaPlayer != null)
									AudioPlayerDemo.mediaPlayer.stop();
								AudioPlayerDemo.itemNum = LayoutDemo.lv.getSelectionModel().getSelectedIndex();
								LayoutDemo.lv.getSelectionModel().getSelectedItem().setTextFill(Color.GREY);

								File path = UtilDemo.listFiles.get(AudioPlayerDemo.itemNum);
								String source = path.toURI().toString();
								Media media = new Media(source);
								AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
								LayoutDemo.bindSlider();
								if (AudioPlayerDemo.itemNum < 11) {
									LayoutDemo.lv.scrollTo(0);
								} else {
									LayoutDemo.lv.scrollTo(AudioPlayerDemo.itemNum - 11);
								}
								LayoutDemo.doParse();
								AudioPlayerDemo.mediaPlayer.play();
								LayoutDemo.play.setText("暂停");
							}
						}
					});

				} else {
					UtilDemo.displayAlert();
					return;
				}
			}

		});

		//打开目录
		LayoutDemo.openDirectory.setOnAction(e -> {
			DirectoryChooser directoryChooser = new DirectoryChooser();
			directoryChooser.setTitle("选择歌曲目录");
			File dirFilePath = directoryChooser.showDialog(primaryStage);
			List<File> tempLv = null;
			tempLv = UtilDemo.foundFiles(dirFilePath);
			if (tempLv != null) {
				UtilDemo.listFiles = tempLv;
				Label[] listLabel = new Label[UtilDemo.listFiles.size()];
				AudioPlayerDemo.maxItem = UtilDemo.listFiles.size();
				ObservableList<Label> obLabel = FXCollections.observableArrayList();
				int i = 0;
				for (File lf : UtilDemo.listFiles) {
					listLabel[i] = new Label(lf.getName());
					obLabel.add(listLabel[i]);
					i++;
				}
				AudioPlayerDemo.itemNum = -1;
				LayoutDemo.lv = new ListView<Label>(obLabel);
				LayoutDemo.bp.setRight(LayoutDemo.lv);
				UtilDemo.saveSongMenuFiles(UtilDemo.listFiles);
				
				LayoutDemo.lv.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
					
					public void handle(MouseEvent event) {
						//鼠标双击
						if (event.getButton() == MouseButton.PRIMARY && event.getClickCount() == 2) {
							if (AudioPlayerDemo.mediaPlayer != null)
								AudioPlayerDemo.mediaPlayer.stop();

							AudioPlayerDemo.itemNum = LayoutDemo.lv.getSelectionModel().getSelectedIndex();
							LayoutDemo.lv.getSelectionModel().getSelectedItem().setTextFill(Color.GRAY);

							File path = UtilDemo.listFiles.get(AudioPlayerDemo.itemNum);
							// System.out.println(path);
							String source = path.toURI().toString();
							Media media = new Media(source);
							AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
							LayoutDemo.bindSlider();
							if (AudioPlayerDemo.itemNum < 11) {
								LayoutDemo.lv.scrollTo(0);
							} else {
								LayoutDemo.lv.scrollTo(AudioPlayerDemo.itemNum - 11);
							}

							LayoutDemo.doParse();
							AudioPlayerDemo.mediaPlayer.play();
							LayoutDemo.play.setText("暂停");
						}
					}
				});

			} else {
				UtilDemo.displayAlert();
				return;
			}

		});

		//关闭软件
		LayoutDemo.closeSoftware.setOnAction(e -> Platform.exit());

		/* ********************按钮事件*************** */
		//播放按钮
		LayoutDemo.play.setOnAction(e -> {
			if (AudioPlayerDemo.itemNum == -1) {
				if (UtilDemo.listFiles != null) {
					File path = UtilDemo.listFiles.get(++AudioPlayerDemo.itemNum);
					String source = path.toURI().toString();
					Media media = new Media(source);
					AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
					LayoutDemo.bindSlider();
					LayoutDemo.doParse();
					AudioPlayerDemo.mediaPlayer.play();
					LayoutDemo.play.setText("暂停");
				} else {
					UtilDemo.displayAlert();
					return;
				}
			} else {
				if (LayoutDemo.play.getText().equals("播放")) {
					AudioPlayerDemo.mediaPlayer.play();
					LayoutDemo.play.setText("暂停");
				} else {
					AudioPlayerDemo.mediaPlayer.pause();
					LayoutDemo.play.setText("播放");
				}
			}

		});

		//播放上一歌曲
		LayoutDemo.last.setOnAction(e -> {
			if (AudioPlayerDemo.itemNum == -1) {
				UtilDemo.displayAlert();
				return;
			}
			if (AudioPlayerDemo.mediaPlayer != null)
				AudioPlayerDemo.mediaPlayer.stop();
			AudioPlayerDemo.itemNum--;
			if (AudioPlayerDemo.itemNum < 0) {
				AudioPlayerDemo.itemNum = AudioPlayerDemo.maxItem - 1;
			}
			File path = UtilDemo.listFiles.get(AudioPlayerDemo.itemNum % AudioPlayerDemo.maxItem);
			String source = path.toURI().toString();
			Media media = new Media(source);
			AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
			LayoutDemo.bp.setCenter(LayoutDemo.mediaView);
			LayoutDemo.bindSlider();
			LayoutDemo.lv.getItems().get(AudioPlayerDemo.itemNum).setTextFill(Color.GRAY);
			if (AudioPlayerDemo.itemNum < 11) {
				LayoutDemo.lv.scrollTo(0);
			} else {
				LayoutDemo.lv.scrollTo(AudioPlayerDemo.itemNum - 11);
			}

			LayoutDemo.doParse();
			AudioPlayerDemo.mediaPlayer.play();
			LayoutDemo.play.setText("暂停");
		});

		//播放下一歌曲
		LayoutDemo.next.setOnAction(e -> {
			if (AudioPlayerDemo.itemNum == -1) {
				UtilDemo.displayAlert();
				return;
			}
			if (AudioPlayerDemo.mediaPlayer != null)
				AudioPlayerDemo.mediaPlayer.stop();
			AudioPlayerDemo.itemNum++;
			if (AudioPlayerDemo.itemNum >= AudioPlayerDemo.maxItem) {
				AudioPlayerDemo.itemNum = 0;
			}
			File path = UtilDemo.listFiles.get(AudioPlayerDemo.itemNum % AudioPlayerDemo.maxItem);
			String source = path.toURI().toString();
			Media media = new Media(source);
			AudioPlayerDemo.mediaPlayer = new MediaPlayer(media);
			LayoutDemo.bp.setCenter(LayoutDemo.mediaView);
			LayoutDemo.bindSlider();
			LayoutDemo.doParse();

			LayoutDemo.lv.getItems().get(AudioPlayerDemo.itemNum).setTextFill(Color.GRAY);
			if (AudioPlayerDemo.itemNum < 11) {
				LayoutDemo.lv.scrollTo(0);
			} else {
				LayoutDemo.lv.scrollTo(AudioPlayerDemo.itemNum - 11);
			}
			AudioPlayerDemo.mediaPlayer.play();
			LayoutDemo.play.setText("暂停");
		});

		//循环播放
		LayoutDemo.loop.setOnAction(e -> {
			if (AudioPlayerDemo.mediaPlayer != null && "单曲循环".equals(LayoutDemo.loop.getText())) {
				AudioPlayerDemo.mediaPlayer.setCycleCount(MediaPlayer.INDEFINITE);
				LayoutDemo.loop.setText("列表循环");
			} else {
				AudioPlayerDemo.mediaPlayer.setCycleCount(1);
				LayoutDemo.loop.setText("单曲循环");
			}
		});

		//停止播放
		LayoutDemo.stop.setOnAction(e -> {
			if (AudioPlayerDemo.mediaPlayer != null) {
				AudioPlayerDemo.mediaPlayer.stop();
				LayoutDemo.play.setText("播放");
			}
		});

		primaryStage.setScene(LayoutDemo.sc);
		primaryStage.setResizable(false);
		return primaryStage;
	}
}

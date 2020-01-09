import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

public class UtilDemo {
	static Alert alert = new Alert(AlertType.INFORMATION);
	static List<File> listFiles = new ArrayList<>(); // 歌曲文件目录

	// 初始化歌单内容
	static public ListView<Label> initDate() {
		UtilDemo.listFiles = UtilDemo.readSongMenuFiles();
		if (UtilDemo.listFiles != null) {
			Label[] listLabel = new Label[UtilDemo.listFiles.size()];
			AudioPlayerDemo.maxItem = UtilDemo.listFiles.size();
			ObservableList<Label> obLabel = FXCollections.observableArrayList();
			int i = 0;
			for (File lf : UtilDemo.listFiles) {
				listLabel[i] = new Label(lf.getName());
				obLabel.add(listLabel[i]);
				i++;
			}
			LayoutDemo.lv = new ListView<Label>(obLabel);
			return LayoutDemo.lv;
		} else {
			// UtilDemo.displayAlert();
			return null;
		}
	}

	/*
	 * 把歌单存入文件
	 * 
	 * @param 参数是文件列表
	 */
	static void saveSongMenuFiles(List<File> list) {
		Path path = Paths.get("songMenu_temp.txt");
		if (!Files.exists(path)) {
			try {
				Files.createFile(path.getFileName());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try (BufferedWriter bw = Files.newBufferedWriter(path)) {
			for (File f : list) {
				bw.write(f.getPath());
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/*
	  * 读出歌单
	 * 
	 * @return 返回一个歌单文件列表
	 */
	static List<File> readSongMenuFiles() {
		Path path = Paths.get("songMenu_temp.txt");
		List<File> list = new ArrayList<>();
		List<String> lStr = new ArrayList<>();
		if (Files.exists(path)) {
			try {
				lStr = Files.readAllLines(path);
			} catch (IOException e) {
				e.printStackTrace();
			}

			for (String str : lStr) {
				list.add(new File(str));
			}
			return list;
		}
		return null;
	}

	/*
	 * 把符合格式的文件找出来（MP3）
	 * 
	 * @param 参数是歌曲根目录
	 * 
	 * @return 返回该目录所有符合条件的文件列表
	 */
	static List<File> foundFiles(File file) {
		if (file != null) {
			List<File> list = new ArrayList<>();
			File[] files = file.listFiles();
			for (File file2 : files) {
				if (file2.isFile()) {
					if (file2.getName().endsWith(".mp3")) {
						list.add(file2);
					}
				}
			}
			return list;
		} else {
			return null;
		}
	}

	/*
	 * 显示是否成功导入了歌单
	 */
	static public void displayAlert() {
		alert.setTitle("温馨提示");
		alert.setHeaderText("请注意！");
		alert.setContentText("您尚未选择歌曲！");
		alert.show();
	}
}

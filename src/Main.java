import java.io.IOException;
import java.util.Scanner;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {

    public static void main(String[] args) throws IOException {
        WorkFile run = new WorkFile();
        Scanner scanner = new Scanner (System.in);
        String nextInt;
        int choice;

        System.out.println("1) Ввод с клавиатуры\n2) Ввод из файла");
        nextInt = scanner.nextLine();
        choice = Integer.parseInt(nextInt);

        System.out.println("Введите имя файла");
        String path = scanner.nextLine();
        run.path = path;
        if (choice == 1){
            Files.createFile(Paths.get(path));
            System.out.println("Введите кол-во записей");
            nextInt = scanner.nextLine();
            run.InputStructKeyboard(Integer.parseInt(nextInt));
        } else {
            run.InputStructFile();
        }

        while (choice != 5){
            run.OutputStruct();
            System.out.println("\n1) Вывести кол-во марок\n2) Добавить запись\n3) Удалить записи по № машины");
            System.out.println("4 Изменить марку машины по ФИО владельца\n5 Выход из программы и сохранить изменения в файле");
            nextInt = scanner.nextLine();
            choice = Integer.parseInt(nextInt);
            switch (choice) {
                case (1):
                    run.NumberModel();
                    break;
                case (2):
                    run.InputStructKeyboard(1);
                    break;
                case (3):
                    nextInt = scanner.nextLine();
                    run.DeleteStruct(Integer.parseInt(nextInt));
                    break;  
                case (4):
                    System.out.println("Введите ФИО владельца, а затем марку машины");
                    run.ChangeModel(scanner.nextLine(), scanner.nextLine());
                    break;
                default:
                    break;
            }
        }
        run.SaveFile();
        scanner.close();
    }
}
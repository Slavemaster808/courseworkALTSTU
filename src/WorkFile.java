import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.File;
import java.io.PrintWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class WorkFile {
    List<StructCar> structList = new ArrayList<>();
    String path;

    public void InputStructKeyboard (int size){
        String nextInt;
        int number;
        int property;
        String model;
        String owner;
        Scanner scanner = new Scanner (System.in);
        for (int i=0; i<size; i++){
            System.out.print("\nНомер машины: ");
            nextInt = scanner.nextLine();
            number = Integer.parseInt(nextInt);
            System.out.print("Характеристика машины: ");
            nextInt = scanner.nextLine();
            property = Integer.parseInt(nextInt);
            System.out.print("Марка мишины: ");
            model = scanner.nextLine();
            System.out.print("ФИО владельца: ");
            owner = scanner.nextLine();
            structList.add(new StructCar(number, property, model, owner));
        }
    }

    public void InputStructFile (){
        Scanner scanner = new Scanner (System.in);
        File file = new File(path);
        String line;
        int number;
        int property;
        String model;
        String owner;
        try (Scanner sc = new Scanner(file, StandardCharsets.UTF_8))
        {
            while (sc.hasNextLine()) {
                line = sc.nextLine();
                Scanner text = new Scanner (line);
                number = text.nextInt();
                property = text.nextInt();
                model = text.next();
                owner = text.next();
                while(text.hasNext()){
                    owner += text.next();
                }
                structList.add(new StructCar(number, property, model, owner));
                text.close();
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void NumberModel (){
        List<StructCar> structListCopy = new ArrayList<>();
        structListCopy.addAll(structList);
        int size = structListCopy.size();
        int number;
        int output = 0;
        for (int i = 0; i < size-1; i++){
            number = 1;
            for (int j = i + 1; j < size; j++){
                if (structListCopy.get(j).model.equals(structListCopy.get(i).model)){
                    structListCopy.remove(j);
                    j--;
                    size--;
                    number++;
                }
            }
            System.out.printf("%s: %d\n", structListCopy.get(i).model, number);
            output++;
        }
        if (output != size){
            System.out.printf("%s: %d\n", structListCopy.get(output).model, 1);
        }
    }

    public void DeleteStruct (int number){
        int size = structList.size();
        for (int i=0; i < size; i++){
            if (structList.get(i).number == number){
                structList.remove(i);
                i--;
                size--;
            }
        }
    }

    public void ChangeModel (String owner, String model){
        for (int i=0; i < structList.size(); i++){
            if (structList.get(i).owner.equals(owner)){
                structList.get(i).model = model;
            }
        }
    }

    public void OutputStruct (){
        for (int i=0; i < structList.size(); i++){
            structList.get(i).OutputStructCar();
        }
    }

    public void SaveFile (){
        File file = new File(path);
        try {
            Files.delete(Paths.get(path));
        } catch (IOException e) {
            e.printStackTrace();
        }
        try (PrintWriter out = new PrintWriter(file, StandardCharsets.UTF_8))
        {
            for (int i = 0; i < structList.size(); i++){
                out.println(structList.get(i).OutputStructCar());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}

public class StructCar {
    int number;
    int property;
    String model;
    String owner;

    public StructCar (int number, int property, String model, String owner) {
        this.number = number;
        this.property = property;
        this.model = model;
        this.owner = owner;
    }

    public String OutputStructCar (){
        System.out.printf("%d %d %s %s\n", number, property, model, owner);
        String output = number + " " + property + " " + model + " " + owner ;
        return output;
    }

}
package L1600;

public class LeetCode1603 {}

class ParkingSystem {

    private int[] cars;

    public ParkingSystem(int big, int medium, int small) {
        cars = new int[3];
        cars[0] = big;
        cars[1] = medium;
        cars[2] = small;
    }
    
    public boolean addCar(int carType) {
        if (cars[carType - 1] > 0) {
            cars[carType - 1] -= 1;
            return true;
        } else {
            return false;
        }
    }
}

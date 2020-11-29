package L1100;

public class LeetCode1114 {
}

class Foo {
    private volatile boolean one = false;
    private volatile boolean two = false;

    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        one = true;
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!one) {
            Thread.sleep(0);
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        two = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!(one && two)) {
            Thread.sleep(0);
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
package L1100;

public class LeetCode1115 {
}

class FooBar {
    private int n;
    private volatile boolean flag;

    public FooBar(int n) {
        this.n = n;
        flag = true;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (!flag) {
                Thread.yield();
            }
        	// printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            flag = false;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (flag) {
                Thread.yield();
            }
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            flag = true;
        }
    }
}
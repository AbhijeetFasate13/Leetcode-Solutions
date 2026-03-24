class Foo {
    public boolean firstDone;
    public boolean secondDone;

    public Foo() {

    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        firstDone = true;
        notifyAll();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while (!firstDone) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        secondDone = true;
        notifyAll();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while (!secondDone) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}
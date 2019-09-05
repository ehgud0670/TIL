# Singleton Pattern 

## Singleton - step 1 

Database.java
```java
public class Database {
    private static Database singleton;
    private String name;

    private Database(String name) throws InterruptedException {
        Thread.sleep(100);
        this.name = name;
    }


    public static Database getInstance(String name) throws InterruptedException {
        if (singleton == null) {
            singleton = new Database(name);
        }
        return singleton;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

## Singleton - step 2

Database.java
```java
public class Database {
    private static Database singleton;
    private String name;

    private Database(String name) throws InterruptedException {
        Thread.sleep(100);
        this.name = name;
    }

    public synchronized static Database getInstance(String name) throws InterruptedException {
        if (singleton == null) {
            singleton = new Database(name);
        }
        return singleton;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

## Singleton - step 3

Database.java
```java
public class Database {
    private static Database singleton = new Database("products");
    private String name;

    private Database(String name) {
        try {
            Thread.sleep(100);
            this.name = name;
        } catch(InterruptedException e ){
            e.printStackTrace();
        }
    }

    public static Database getInstance(String name) {
        return singleton;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

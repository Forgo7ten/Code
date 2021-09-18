package android.homework.homeworkone.domain;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Bill {
    private int id;
    private Boolean isIncome;
    private String usage;
    private double amount;
    private String date;
    private String describe;
    public Bill() {
        this.id = -1;
        this.isIncome = null;
        usage = "";
        amount = 0;
        date = "";
        describe = "";
    }

    public Bill(int id, Boolean isIncome, String usage, double amount, String date, String describe) {
        this.id = id;
        this.isIncome = isIncome;
        this.usage = usage;
        this.amount = amount;
        this.date = date;
        this.describe = describe;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Boolean getIncome() {
        return isIncome;
    }

    public void setIncome(Boolean income) {
        isIncome = income;
    }

    public String getUsage() {
        return usage;
    }

    public void setUsage(String usage) {
        this.usage = usage;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getDescribe() {
        return describe;
    }

    public void setDescribe(String describe) {
        this.describe = describe;
    }
}
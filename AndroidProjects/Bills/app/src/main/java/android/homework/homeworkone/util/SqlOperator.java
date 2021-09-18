package android.homework.homeworkone.util;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.homework.homeworkone.domain.Bill;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;

public class SqlOperator {
    private static SQLiteDatabase database = null;
    private static final String tableName = "bills";

    public static SQLiteDatabase getDatabase() {
        return database;
    }

    public static void setDatabase(SQLiteDatabase database) {
        SqlOperator.database = database;
    }

    public static Boolean insertBill(Bill bill){
        ContentValues contentValues = new ContentValues();
        contentValues.put("isIncome",bill.getIncome());
        contentValues.put("usage",bill.getUsage());
        contentValues.put("amount",bill.getAmount());
        contentValues.put("date",bill.getDate());
        contentValues.put("describe",bill.getDescribe());
        long rows = database.insert(tableName, null, contentValues);
        Boolean result = rows>0;
        Log.d("HomeWork-insert","插入结果："+result);
        return result;
    }
    public static List<Bill> queryAll(){
        List<Bill> bills = new ArrayList<>();
        Cursor cursor = database.query(tableName, null, null, null, null, null, "date DESC");
        while (cursor.moveToNext()){
            int id = cursor.getInt(cursor.getColumnIndex("id"));
            Boolean isIncome = cursor.getInt(cursor.getColumnIndex("isIncome"))>0;
            String usage = cursor.getString(cursor.getColumnIndex("usage"));
            double amount = cursor.getDouble(cursor.getColumnIndex("amount"));
            String date = cursor.getString(cursor.getColumnIndex("date"));
            String describe = cursor.getString(cursor.getColumnIndex("describe"));
            Bill bill = new Bill(id, isIncome, usage, amount, date, describe);
            bills.add(bill);
        }
        Log.d("HomeWork-queryAll","查询到"+bills.size()+"条数据");
        return bills;
    }
    public static Bill queryBillById(int id){
        Bill bill = null;
        if(id>0){
            Cursor cursor = database.query(tableName, null, "id = ?", new String[]{String.valueOf(id)}, null, null, null);
            while (cursor.moveToNext()){
                Boolean isIncome = cursor.getInt(cursor.getColumnIndex("isIncome"))>0;
                String usage = cursor.getString(cursor.getColumnIndex("usage"));
                double amount = cursor.getDouble(cursor.getColumnIndex("amount"));
                String date = cursor.getString(cursor.getColumnIndex("date"));
                String describe = cursor.getString(cursor.getColumnIndex("describe"));
                bill = new Bill(id, isIncome, usage, amount, date, describe);
            }
        }
        Log.d("HomeWork-queryBillById","查询结果："+(null!=bill));
        return bill;
    }
    public static Boolean deleteBillById(int id){
        if(id>0){
            int rows = database.delete(tableName, "id = ?", new String[]{String.valueOf(id)});
            Log.d("HomeWork-deleteBillById","删除结果："+(rows>0));
            return rows>0;
        }
        return false;
    }
    public static Boolean updateBill(Bill newBill){
        int id = newBill.getId();
        if(id>0){
            ContentValues contentValues = new ContentValues();
            contentValues.put("isIncome",newBill.getIncome());
            contentValues.put("usage",newBill.getUsage());
            contentValues.put("amount",newBill.getAmount());
            contentValues.put("date",newBill.getDate());
            contentValues.put("describe",newBill.getDescribe());
            int rows = database.update(tableName, contentValues, "id=?", new String[]{String.valueOf(id)});
            Log.d("HomeWork-updateBillById","更新结果："+(rows>0));
            return rows>0;
        }
        return true;
    }
    public static List<String> queryDataByName(String name){
        List<String> data = new ArrayList<>();
        Cursor cursor = database.query(true, tableName, new String[]{name}, null, null, null, null, "id DESC", "5");
        while (cursor.moveToNext()){
            data.add(cursor.getString(cursor.getColumnIndex(name)));
        }
        Log.d("HomeWork-queryData","查询结果："+data.toString());
        return data;
    }
}

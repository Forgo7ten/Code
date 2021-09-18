package android.homework.homeworkone.dao;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.homework.homeworkone.R;

import androidx.annotation.Nullable;

public class MySqlHelper extends SQLiteOpenHelper {
    private static final String createBillTableSql = "create table bills(id Integer Primary key autoincrement,isIncome BOOLEAN,usage varchar(20),amount DOUBLE,date varchar(20),describe varchar(100));";
    public MySqlHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(createBillTableSql);
        insertTestData(db);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
    private void insertTestData(SQLiteDatabase db){
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (1, '0', '吃饭', '9.9', '2021-09-01 00:00', '吃饭吃饭吃饭');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (2, '0', '喝水', '4.0', '2021-09-01 12:00', '喝水喝水喝水');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (3, '1', '偷电瓶', '299', '2021-09-01 14:00', '偷电瓶偷电瓶');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (4, '0', '买衣服', '99.9', '2021-09-02 00:00', '买衣服买衣服买衣服');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (5, '0', '买鞋子', '199', '2021-09-02 12:00', '买鞋买鞋买鞋');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (6, '1', '捡瓶子', '888', '2021-09-02 14:00', '捡瓶子捡瓶子');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (7, '0', '上网', '20', '2021-09-03 12:00', '上网上网上网');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (8, '0', '摇摇车', '20', '2021-09-03 16:00', '摇摇车摇摇车');");
        db.execSQL("INSERT INTO bills(id, isIncome, usage, amount, date, describe) VALUES (9, '1', '捡破烂儿', '888', '2021-09-03 17:00', '捡破烂捡破烂捡破烂捡破烂捡破烂捡破烂捡破烂');");
    }
}

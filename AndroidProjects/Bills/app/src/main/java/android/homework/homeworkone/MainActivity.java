package android.homework.homeworkone;

import android.homework.homeworkone.dao.MySqlHelper;
import android.homework.homeworkone.util.SqlOperator;
import android.homework.homeworkone.fragment.AddBillFragment;
import android.homework.homeworkone.fragment.ShowBillsFragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TabHost;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTabHost;


public class MainActivity extends AppCompatActivity {
    private FragmentTabHost fragmentTabHost;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        MySqlHelper billSql = new MySqlHelper(getApplicationContext(), "Bills.db", null, 1);
        SqlOperator.setDatabase(billSql.getWritableDatabase());
        initFragment();
    }
    private void initFragment() {
        // 获取FragmentTabHost对象
        fragmentTabHost = findViewById(android.R.id.tabhost);
        // 对FragmentTabHost对象进行初始化
        fragmentTabHost.setup(this, getSupportFragmentManager(), android.R.id.tabhost);

        // 创建选项卡
        View indexView = LayoutInflater.from(this).inflate(R.layout.view_update_bill, null);
        TabHost.TabSpec indexTab = fragmentTabHost.newTabSpec("AddBill").setIndicator("添加账单");
        fragmentTabHost.addTab(indexTab, AddBillFragment.class, null);

        TabHost.TabSpec storeTab = fragmentTabHost.newTabSpec("BillsList").setIndicator("账单列表");
        fragmentTabHost.addTab(storeTab, ShowBillsFragment.class, null);

        // 设置默认显示页面
        fragmentTabHost.setCurrentTab(0);


    }

}
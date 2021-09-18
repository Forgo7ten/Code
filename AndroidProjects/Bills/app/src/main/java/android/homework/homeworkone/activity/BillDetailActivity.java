package android.homework.homeworkone.activity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.homework.homeworkone.R;
import android.homework.homeworkone.util.SqlOperator;
import android.homework.homeworkone.domain.Bill;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

public class BillDetailActivity extends AppCompatActivity {
    private RadioGroup radioGroup;
    private TextView usageTv;
    private TextView amountTv;
    private TextView desTv;
    private TextView showDateTv;
    private Button updateBut;
    private Button delBut;
    private Button finishBut;
    private Bill bill;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bill_detail);
        initSource();
        initViews();
        registerListener();
    }

    @Override
    protected void onStart() {
        super.onStart();
        initSource();
        initViews();
    }

    private void registerListener() {
        MyOnClickListener listener = new MyOnClickListener();
        updateBut.setOnClickListener(listener);
        delBut.setOnClickListener(listener);
        finishBut.setOnClickListener(listener);
    }
    class MyOnClickListener implements View.OnClickListener{
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.update_but:
                    Intent intent = new Intent();
                    intent.setClass(getApplicationContext(),UpdateBillActivity.class);
                    intent.putExtra("billId",bill.getId());
                    startActivity(intent);
                    break;
                case R.id.del_but:
                    Boolean delResult = SqlOperator.deleteBillById(bill.getId());
                    Log.d("HomeWork-deleteBillBut",delResult?"删除账单成功":"删除账单失败");
                    if(delResult){
                        Toast.makeText(getApplicationContext(),"删除账单成功！",Toast.LENGTH_SHORT).show();
                        finish();
                    }else{
                        Toast.makeText(getApplicationContext(),"删除账单失败！",Toast.LENGTH_SHORT).show();
                    }
                    break;
                case R.id.finish_but:
                    finish();
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + v.getId());
            }
        }
    }
    private void initSource() {
        int billId = getIntent().getIntExtra("billId",-1);
        bill = billId!=-1? SqlOperator.queryBillById(billId):null;
    }

    private void initViews() {
        radioGroup = findViewById(R.id.radio_group);
        usageTv = findViewById(R.id.usage_tv);
        amountTv = findViewById(R.id.amount_tv);
        desTv = findViewById(R.id.des_tv);
        showDateTv = findViewById(R.id.date_show);
        updateBut = findViewById(R.id.update_but);
        delBut = findViewById(R.id.del_but);
        finishBut = findViewById(R.id.finish_but);

        if(bill.getIncome()){
            radioGroup.check(R.id.is_income);
        }else{
            radioGroup.check(R.id.not_income);
        }
        findViewById(R.id.is_income).setClickable(false);
        findViewById(R.id.not_income).setClickable(false);
        // 显示用途
        usageTv.setText(bill.getUsage());
        // 显示金额
        amountTv.setText(String.valueOf(bill.getAmount()));
        // 显示详细描述
        desTv.setText(bill.getDescribe());
        // 显示日期
        showDateTv.setText(bill.getDate());
    }
    class MyButListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.submit_but:

                    break;
                case R.id.finish_but:
                    finish();
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + v.getId());
            }
        }
    }
}
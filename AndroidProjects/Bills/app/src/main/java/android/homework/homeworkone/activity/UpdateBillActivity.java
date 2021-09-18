package android.homework.homeworkone.activity;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.homework.homeworkone.MainActivity;
import android.homework.homeworkone.R;
import android.homework.homeworkone.domain.Bill;
import android.homework.homeworkone.fragment.ShowBillsFragment;
import android.homework.homeworkone.util.SqlOperator;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListPopupWindow;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class UpdateBillActivity extends Activity {
    private RadioGroup radioGroup;
    private EditText usageEdt;
    private ImageView usageBut;
    private EditText amountEdt;
    private ImageView amountBut;
    private EditText desEdt;
    private TextView dateEdt;
    private Button selectDateBut;
    private Button submitBut;
    private Button finishBut;
    private Bill bill;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_update_bill);
        initSource();
        initViews();
        registerListener();
    }

    private void registerListener() {
        MyOnClickListener listener = new MyOnClickListener();
        selectDateBut.setOnClickListener(listener);
        submitBut.setOnClickListener(listener);
        finishBut.setOnClickListener(listener);
        usageBut.setOnClickListener(listener);
        amountBut.setOnClickListener(listener);
    }

    private void initSource() {
        int billId = getIntent().getIntExtra("billId",-1);
        bill = billId!=-1? SqlOperator.queryBillById(billId):null;
    }

    private void initViews() {
        TextView titleTv = findViewById(R.id.title_tv);
        titleTv.setText("修改账单");
        radioGroup = findViewById(R.id.radio_group);
        usageEdt = findViewById(R.id.usage_edt);
        usageBut = findViewById(R.id.usage_but);
        amountEdt = findViewById(R.id.amount_edt);
        amountBut = findViewById(R.id.amount_but);
        desEdt = findViewById(R.id.des_edt);
        dateEdt = findViewById(R.id.date_edt);
        selectDateBut = findViewById(R.id.select_date_but);
        submitBut = findViewById(R.id.submit_but);
        finishBut = findViewById(R.id.finish_but);

        if(bill.getIncome()){
            radioGroup.check(R.id.is_income);
        }else{
            radioGroup.check(R.id.not_income);
        }
        // 显示用途
        usageEdt.setText(bill.getUsage());
        // 显示金额
        amountEdt.setText(String.valueOf(bill.getAmount()));
        // 显示详细描述
        desEdt.setText(bill.getDescribe());
        // 显示日期
        dateEdt.setText(bill.getDate());
    }
    class MyOnClickListener implements View.OnClickListener{
        @Override
        public void onClick(View v) {
            switch (v.getId()){
                case R.id.select_date_but:
                    selectDate();
                    break;
                case R.id.submit_but:
                    submitBill();
                    break;
                case R.id.finish_but:
                    finish();
                    break;
                case R.id.usage_but:
                    showListPopupWindow(R.id.usage_but);
                    break;
                case R.id.amount_but:
                    showListPopupWindow(R.id.amount_but);
                    break;
                default:
                    throw new IllegalStateException("Unexpected value: " + v.getId());
            }
        }
    }
    private void submitBill() {
        bill.setIncome(radioGroup.getCheckedRadioButtonId()==R.id.is_income?true:false);
        bill.setUsage(usageEdt.getText().toString());
        bill.setAmount(Double.parseDouble(amountEdt.getText().toString()));
        bill.setDescribe(desEdt.getText().toString());
        bill.setDate(dateEdt.getText().toString());
        if(!"".equals(bill.getUsage())){
            if(!"".equals(bill.getAmount())){
                if(!"".equals(bill.getDate())){
                    Boolean updateBillResult = SqlOperator.updateBill(bill);
                    if(updateBillResult){
                        Toast.makeText(getApplicationContext(),"修改成功！",Toast.LENGTH_SHORT).show();
                        finish();
                    }else{
                        Toast.makeText(getApplicationContext(),"修改失败！",Toast.LENGTH_SHORT).show();
                    }
                }else {
                    Toast.makeText(getApplicationContext(),"日期不能为空！",Toast.LENGTH_SHORT).show();
                }
            }else {
                Toast.makeText(getApplicationContext(),"金额不能为空！",Toast.LENGTH_SHORT).show();
            }
        }else{
            Toast.makeText(getApplicationContext(),"用途不能为空！",Toast.LENGTH_SHORT).show();
        }
    }

    private void selectDate() {
        View dialogView = getLayoutInflater().inflate(R.layout.view_date_dialog, null, false);
        initDialogView(dialogView);
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("选择日期")
                .setView(dialogView)
                .setCancelable(false)
                .setPositiveButton("确定", (dialog, which) -> {
                    DatePicker datePicker  = dialogView.findViewById(R.id.date_picker);
                    TimePicker timePicker  = dialogView.findViewById(R.id.time_picker);
                    Calendar calendarSelected = Calendar.getInstance();
                    String dateStr;
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                        calendarSelected.set(datePicker.getYear(),datePicker.getMonth(),datePicker.getDayOfMonth(),
                                timePicker.getHour(),timePicker.getMinute());
                        dateStr = new SimpleDateFormat("yyyy-MM-dd HH:mm").format(calendarSelected.getTime());
                    }else{
                        calendarSelected.set(datePicker.getYear(),datePicker.getMonth(),datePicker.getDayOfMonth());
                        dateStr = new SimpleDateFormat("yyyy-MM-dd").format(calendarSelected.getTime());
                    }
                    dateEdt.setText(dateStr);
                })
                .setNegativeButton("取消", (dialog, which) -> dialog.dismiss());
        AlertDialog dateDialog = builder.create();
        dateDialog.show();
    }
    private void initDialogView(View dialogView) {

        DatePicker datePicker = dialogView.findViewById(R.id.date_picker);
        TimePicker timePicker = dialogView.findViewById(R.id.time_picker);
        Calendar calendar = Calendar.getInstance();
        calendar.add(Calendar.YEAR,-100);
        datePicker.setMinDate(calendar.getTimeInMillis());
        calendar = Calendar.getInstance();
        calendar.add(Calendar.YEAR,100);
        datePicker.setMaxDate(calendar.getTimeInMillis());
        calendar = Calendar.getInstance();
        datePicker.init(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH), null);
        timePicker.setIs24HourView(true);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            timePicker.setHour(calendar.get(Calendar.HOUR_OF_DAY)+8);
            timePicker.setMinute(calendar.get(Calendar.MINUTE));
        }else{
            timePicker.setVisibility(View.GONE);
        }
    }
    private void showListPopupWindow(int viewId) {
        List<String> candidateList = new ArrayList<>();
        ListPopupWindow listPopupWindow = new ListPopupWindow(getApplicationContext());
        listPopupWindow.setModal(true);
        switch (viewId){
            case R.id.usage_but:
                candidateList = SqlOperator.queryDataByName("usage");
                listPopupWindow.setAdapter(new ArrayAdapter<String>(getApplicationContext(), android.R.layout.simple_list_item_1,candidateList));
                listPopupWindow.setAnchorView(usageEdt);
                List<String> finalCandidateList = candidateList;
                listPopupWindow.setOnItemClickListener((parent, view, position, id) -> {
                    usageEdt.setText(finalCandidateList.get(position));
                    listPopupWindow.dismiss();
                });
                listPopupWindow.show();
                break;
            case R.id.amount_but:
                listPopupWindow.setAnchorView(amountEdt);
                candidateList = SqlOperator.queryDataByName("amount");
                listPopupWindow.setAdapter(new ArrayAdapter<String>(getApplicationContext(), android.R.layout.simple_list_item_1,candidateList));
                List<String> afinalCandidateList = candidateList;
                listPopupWindow.setOnItemClickListener((parent, view, position, id) ->{
                    amountEdt.setText(afinalCandidateList.get(position));
                    listPopupWindow.dismiss();
                } );
                listPopupWindow.show();
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + viewId);
        }
    }
}
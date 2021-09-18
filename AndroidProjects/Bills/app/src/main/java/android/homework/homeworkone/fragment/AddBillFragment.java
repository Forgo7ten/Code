package android.homework.homeworkone.fragment;
import android.homework.homeworkone.R;
import android.homework.homeworkone.domain.Bill;
import android.homework.homeworkone.util.SqlOperator;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.ListPopupWindow;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.Fragment;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class AddBillFragment extends Fragment {
    private RadioGroup radioGroup;
    private EditText usageEdt;
    private ImageView usageBut;
    private EditText amountEdt;
    private ImageView amountBut;
    private EditText desEdt;
    private TextView dateEdt;
    private Button selectDateBut;
    private Button submitBut;
    private Bill bill;


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.view_update_bill,null);
        bill = new Bill();
        initViews(view);
        registListener();
        return view;
    }


    private void registListener() {
        MyOnClickListener listener = new MyOnClickListener();
        selectDateBut.setOnClickListener(listener);
        submitBut.setOnClickListener(listener);
        usageBut.setOnClickListener(listener);
        amountBut.setOnClickListener(listener);
    }

    private void initViews(View view) {
        radioGroup = view.findViewById(R.id.radio_group);
        radioGroup.check(R.id.is_income);
        usageEdt = view.findViewById(R.id.usage_edt);
        usageBut = view.findViewById(R.id.usage_but);
        amountEdt = view.findViewById(R.id.amount_edt);
        amountBut = view.findViewById(R.id.amount_but);
        desEdt = view.findViewById(R.id.des_edt);
        dateEdt = view.findViewById(R.id.date_edt);
        selectDateBut = view.findViewById(R.id.select_date_but);
        submitBut = view.findViewById(R.id.submit_but);
        view.findViewById(R.id.finish_but).setVisibility(View.GONE);
    }

    private void selectDate() {
        View dialogView = getLayoutInflater().inflate(R.layout.view_date_dialog, null, false);
        initDialogView(dialogView);
        AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
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

    class MyOnClickListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.select_date_but:
                    selectDate();
                    break;
                case R.id.submit_but:
                    submitBill();
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

    private void showListPopupWindow(int viewId) {
        List<String> candidateList = new ArrayList<>();
        ListPopupWindow listPopupWindow = new ListPopupWindow(getContext());
        listPopupWindow.setModal(true);
        switch (viewId){
            case R.id.usage_but:
                candidateList = SqlOperator.queryDataByName("usage");
                listPopupWindow.setAdapter(new ArrayAdapter<String>(getContext(), android.R.layout.simple_list_item_1,candidateList));
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
                listPopupWindow.setAdapter(new ArrayAdapter<String>(getContext(), android.R.layout.simple_list_item_1,candidateList));
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

    private void submitBill() {
        bill.setIncome(radioGroup.getCheckedRadioButtonId()==R.id.is_income?true:false);
        bill.setUsage(usageEdt.getText().toString());
        bill.setAmount(Double.parseDouble(amountEdt.getText().toString()));
        bill.setDescribe(desEdt.getText().toString());
            bill.setDate(dateEdt.getText().toString());
        if(!"".equals(bill.getUsage())){
            if(!"".equals(bill.getAmount())){
                if(!"".equals(bill.getDate())){
                    Boolean insertBillResult = SqlOperator.insertBill(bill);
                    if(insertBillResult){
                        Toast.makeText(getContext(),"添加成功！",Toast.LENGTH_SHORT).show();
                    }else{
                        Toast.makeText(getContext(),"添加失败！",Toast.LENGTH_SHORT).show();
                    }
                }else {
                    Toast.makeText(getContext(),"日期不能为空！",Toast.LENGTH_SHORT).show();
                }
            }else {
                Toast.makeText(getContext(),"金额不能为空！",Toast.LENGTH_SHORT).show();
            }
        }else{
            Toast.makeText(getContext(),"用途不能为空！",Toast.LENGTH_SHORT).show();
        }
    }
}

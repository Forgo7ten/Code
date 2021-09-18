package android.homework.homeworkone.fragment;

import android.content.Intent;
import android.homework.homeworkone.R;
import android.homework.homeworkone.activity.BillDetailActivity;
import android.homework.homeworkone.adapter.BillsAdapter;
import android.homework.homeworkone.domain.Bill;
import android.homework.homeworkone.util.SqlOperator;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import java.util.ArrayList;
import java.util.List;

public class ShowBillsFragment extends Fragment {
    private ListView billsList;
    private List<Bill> bills = new ArrayList<>();
    private BillsAdapter billsAdapter;


    @Override
    public void onResume() {
        super.onResume();
        initSource();
        billsAdapter.notifyDataSetChanged();
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_show_bills,null);
        billsList = view.findViewById(R.id.bills_lv);
        initSource();
         billsAdapter = new BillsAdapter(R.layout.view_bills_item, bills, getContext());
        billsList.setAdapter(billsAdapter);
        billsList.setOnItemClickListener((parent, v, position, id) -> {
            Intent intent = new Intent();
            intent.setClass(getContext(), BillDetailActivity.class);
            intent.putExtra("billId",bills.get(position).getId());
            startActivity(intent);
        });
        return view;
    }

    private void initSource() {
        bills.clear();
        bills.addAll(SqlOperator.queryAll());
    }
}

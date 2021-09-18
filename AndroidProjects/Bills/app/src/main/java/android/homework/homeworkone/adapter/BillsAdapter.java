package android.homework.homeworkone.adapter;

import android.content.Context;
import android.homework.homeworkone.R;
import android.homework.homeworkone.domain.Bill;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.List;
import java.util.Properties;


public class BillsAdapter extends BaseAdapter {
    private final int itemLayoutId;
    private final List<Bill> bills;
    private final Context mContext;

    public BillsAdapter(int itemLayoutId, List<Bill> bills, Context mContext) {
        this.itemLayoutId = itemLayoutId;
        this.bills = bills;
        this.mContext = mContext;
    }

    @Override
    public int getCount() {
        if (bills != null) {
            return bills.size();
        }
        return 0;
    }

    @Override
    public Object getItem(int position) {
        if (bills != null) {
            return bills.get(position);
        }
        return null;
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;
        if (null == convertView) {
            convertView = LayoutInflater.from(mContext).inflate(itemLayoutId, null);
            viewHolder = new ViewHolder();
            viewHolder.accountTypeTv = convertView.findViewById(R.id.account_type_tv);
            viewHolder.usageTv = convertView.findViewById(R.id.usage_tv);
            viewHolder.amountTv = convertView.findViewById(R.id.amount_tv);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder) convertView.getTag();
        }
        Bill bill = bills.get(position);
        viewHolder.accountTypeTv.setText(bill.getIncome()?"收入":"支出");
        viewHolder.usageTv.setText(bill.getUsage());
        viewHolder.amountTv.setText(String.valueOf(bill.getAmount()));
        return convertView;
    }

    final static class ViewHolder {
        TextView accountTypeTv;
        TextView usageTv;
        TextView amountTv;
    }
}

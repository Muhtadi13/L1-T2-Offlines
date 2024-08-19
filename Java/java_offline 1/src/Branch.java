import java.util.Random;

public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private int accountCount;
	// add your code here
	// you are allowed to add variables here
    static Branch b1[]=new Branch[20];
    static int br_count=0;

    // there can be at most 20 branches  

    // you are not allowed to write any other constructor

    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        int it;

        for(it=0;it<10;it++)
            accounts[it]=new Account(0," ",0.0);

        accountCount=0;

        b1[br_count]=this;
        br_count++;

    }

    // add your code here

    public static void transferBalance(Account account, Account account1, int i) {
        account.setBalance(account.getBalance()-i);
        account1.setBalance(account1.getBalance()+i);
    }

    public static void printAllBranchesInfo() {

        int i,j;
        for(i=0;i<br_count;i++) {


            System.out.print("Branch Id :" + b1[i].id + ",\t");
            System.out.println("Branch Name :" + b1[i].name);

            for (j=0;j<b1[i].accountCount;j++)
            {
                System.out.print("Account Number :" + b1[i].accounts[j].getNumber() + ",\t");

                System.out.print("Customer Name :" + b1[i].accounts[j].getCustomer() + ",\t");

                System.out.println("Balance :" + b1[i].accounts[j].getBalance());
            }
        }


    }

    // you are not allowed to modify this method
    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }

    public double getBranchBalance() {

        double sum=0;
        int it;

        for(it=0;it<accountCount;it++)
        {
            sum+=accounts[it].getBalance();

        }
        return sum;

    }

    public Account getMinBalanceAccount() {

        double mn=200005.0;
        Account ac_temp=new Account(0,"",0.0);

        int it;
        for(it=0;it<accountCount;it++)
        {
            if(accounts[it].getBalance()<mn)
            {
                ac_temp=accounts[it];
                mn=accounts[it].getBalance();
            }

        }
        return ac_temp;
    }


}

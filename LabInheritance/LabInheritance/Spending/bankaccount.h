#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
public:
    BankAccount(double balance);
    inline void setBalance(double balance)
    {
        m_Balance = balance;
    }
    inline double getBalance() const
    {
        return m_Balance;
    }

private:
    double m_Balance;
};

#endif // BANKACCOUNT_H

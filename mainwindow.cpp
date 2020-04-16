#include "mainwindow.h"
#include "ui_mainwindow.h"
#define int unsigned long long int
#define maxn 9223372036854775807

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime::currentTime().msec());
    this->resize(900,450);
    this->setFixedSize(900,450);
    ui->label_18->setStyleSheet("color: rgb(133, 24, 102)");
    ui->label_19->setStyleSheet("color: rgb(133, 24, 102)");
    ui->pushButton->setStyleSheet("color: rgb(237, 222, 12);"
                                  "background-color: rgb(69, 5, 87);"
                                  "selection-color: rgb(50, 0, 200);"
                                  "selection-background-color: rgb(200,200,200);");

}
MainWindow::~MainWindow()
{
    delete ui;
}
bool f;
bool prost(int x)
{
    int q = trunc(sqrt(x));
    for (int i = 2;i<=q;i++)
        if (x%i==0) return false;

    return true;
}
int mypow(int x,int st)
{
    int ans = 1;
    for (int i = 0;i<st;i++)
    {
        if (ans>maxn/x) return 0;
        ans*=x;
    }

 return ans;
}
void MainWindow::algo()
{
    int p = qrand()%1000000,q = 0,g = 0,y = 0, w = 0,r = 0,x = 0,e = 0, s = 0,z = 0;

    if (prost(p))
    {
        for (int i = p/2;i>0;i--)
          if ((p-1)%i==0 && prost(i))
            {
                q = i;
                break;
            }
        if (q==0) return;


        for (int i = p;i>1;i--)
        {
            int x = mypow (i,q);
            if (x!=0 && (x-1)%p==0)
            {
                g = i;
                break;
            }
        }
        if (g==0) return;


       for (int i = q;i>0;i--)
       {
            int xx = rand()%q,x = mypow(g,xx);

            if (x!=0)
            {
            for (int j = p;j>0;j--)
                if (j<=maxn/x && (j*x-1)%p==0)
                    {
                        y = j;
                        w = xx;
                        break;
                    }
            if (y!=0) break;
            }
       }
       if (y==0 || w==0) return;


    for (int i = 0;i<q;i++)
    {
        int x1 = rand()%q,x2 = mypow(g,x1);
        if (x2!=0)
        {
            r = x1;
            x = x2%p;
            break;
        }
    }
    if (r==0 || x==0) return;


    for (int i = q-1;i>0;i--)
    {

        int x1 = rand()%q+1;

        if (w>(maxn-r)/x1) continue;
        int x2 = (r+w*x1)%q;
        int xx1 = mypow(g,x2);
        int xx2 = mypow(y,x1);
        if (xx1!=0 && xx2!=0)
        {
            z = (xx1%p*xx2%p)%p;
            e = x1;
            s = x2;
            break;
        }

    }
    if (z==0) return;

    if (z!=x) return;

    f=false;
    ui->label_p->setText(QString::number(p));
    ui->label_q->setText(QString::number(q));
    ui->label_g->setText(QString::number(g));
    ui->label_y->setText(QString::number(y));
    ui->label_w->setText(QString::number(w));
    ui->label_w_2->setText(QString::number(w));
    ui->label_r->setText(QString::number(r));
    ui->label_x->setText(QString::number(x));
    ui->label_e->setText(QString::number(e));
    ui->label_s->setText(QString::number(s));
    ui->label_z->setText(QString::number(z));
    ui->biglabel->setText('('+QString::number(p)+','+QString::number(q)+','+QString::number(g)+','+QString::number(y)+')');

    }
}
void MainWindow::on_pushButton_clicked()
{
   f = true;
   while (f)
       algo();

}

#include "dialogvote.h"
#include "ui_dialogvote.h"
using namespace std;
DialogVote::DialogVote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogVote)
{
    vote = new Vote();
    ui->setupUi(this);
}

DialogVote::DialogVote(QWidget *parent, QVector<QString> &list) : DialogVote(parent)
{
    create_person_list(list);
    layout();
}

DialogVote::~DialogVote()
{
    delete ui;
    delete vote;
    for (int i = 0; i < label_list.size(); i++)
    {
        delete label_list[i];
        delete lineEdit_list[i];
    }
}

void DialogVote::create_person_list(QVector<QString> &list)
{
    for (QString &s : list)
    {
        vote->add_person(s);
    }
}

void DialogVote::layout()
{
    auto &l = vote->get_list();
    for (auto &iter : l)
    {
        label_list.append(new QLabel(iter->get_name(), this));
        lineEdit_list.append(new QLineEdit(this));
    }
    for (int i = 0; i < label_list.size(); i++)
    {
        ui->gridLayout->addWidget(label_list[i], i+2, 0);
        ui->gridLayout->addWidget(lineEdit_list[i], i+2, 1);
    }
}

void DialogVote::on_pushButton_clicked()
{
    QVector<Person*> v = vote->get_list();
    int max = 0;
    int ind = -1;
    for (int i = 0; i < label_list.size(); i++)
    {
        if (vote->vote_to(label_list[i]->text(), lineEdit_list[i]->text().toInt()) == true)
        {

            for (int i = 0; i < v.length(); i++)
            {
                if (max < v[i]->get_vote())
                {
                    max = v[i]->get_vote();
                    ind = i;
                }
            }


        }
        else
        {

        }
    }
    dr = new DialogResult(v[ind]->get_name(), this);
    dr->setModal(true);
    dr->show();
}

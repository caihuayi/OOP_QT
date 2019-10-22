#ifndef DIALOGVOTE_H
#define DIALOGVOTE_H

#include <QDialog>
#include <QVector>
#include <QString>
#include "vote.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "dialogresult.h"

namespace Ui {
class DialogVote;
}

class DialogVote : public QDialog
{
    Q_OBJECT

public:
    DialogVote(QWidget *parent, QVector<QString> &list);
    ~DialogVote();

private slots:
    void on_pushButton_clicked();

private:
    explicit DialogVote(QWidget *parent = nullptr);
    Ui::DialogVote *ui;
    Vote *vote;
    void layout();
    QVector<QLabel*> label_list;
    QVector<QLineEdit*> lineEdit_list;
    DialogResult *dr;

    void create_person_list(QVector<QString> &list);
};

#endif // DIALOGVOTE_H

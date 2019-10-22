#ifndef DIALOGRESULT_H
#define DIALOGRESULT_H

#include <QDialog>
#include <QString>
#include <algorithm>

namespace Ui {
class DialogResult;
}

class DialogResult : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResult(QWidget *parent = nullptr);
    DialogResult(QString name, QWidget *parent);
    ~DialogResult();

private:
    Ui::DialogResult *ui;
};

#endif // DIALOGRESULT_H

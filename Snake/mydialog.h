#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>




class MyDialog : public QDialog
{
    Q_OBJECT
private:



    QLabel *text;
    QLabel * score;
    int score_num = 0;
    QPushButton *retry;
    QPushButton *leave;
    QWidget* parent;
    QGridLayout *lay;
    QFont letter_size;

public:
    MyDialog(QWidget * parent);
    void ScoreCahange(int a);


public slots:

    void RestartClicked();

    void Score();

    void ChangeLabel(int a);

    void LeaveClicked();

signals:

    void Change(int a);


};

#endif // MYDIALOG_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_actionAdd_variable_definition_triggered();

    void on_actionAdd_definition_group_triggered();

    void on_actionReload_environment_triggered();

    void on_actionAdd_variable_to_context_2_triggered();

    void on_actionAdd_variable_to_context_3_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

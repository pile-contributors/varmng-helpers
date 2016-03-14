#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

namespace Ui {
class MainWindow;
}

class ModelTest;
class VarMng;
class VarDefModel;
class VarCtxModel;
class VarEvalModel;

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

    void on_actionRemove_variable_definition_triggered();

    void on_actionCheck_definitions_model_triggered();

private:
    Ui::MainWindow *ui;

    VarMng * manager_;

    VarDefModel * def_model_;
    VarCtxModel * env_model_;
    VarCtxModel * ctx2_model_;
    VarCtxModel * ctx3_model_;
    VarEvalModel * spl_model_;
    VarEvalModel * enh_model_;

    ModelTest * def_test_model_;
    ModelTest * env_test_model_;
    ModelTest * ctx2_test_model_;
    ModelTest * ctx3_test_model_;
    ModelTest * spl_test_model_;
    ModelTest * enh_test_model_;

};

#endif // MAINWINDOW_H

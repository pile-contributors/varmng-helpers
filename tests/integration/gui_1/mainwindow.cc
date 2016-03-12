#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->definitionsTreeView->addAction (ui->actionAdd_variable_definition);
    ui->definitionsTreeView->addAction (ui->actionAdd_definition_group);

    ui->environmentTreeView->addAction (ui->actionReload_environment);

    ui->ctx2TreeView->addAction (ui->actionAdd_variable_to_context_2);
    ui->ctx3TreeView->addAction (ui->actionAdd_variable_to_context_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionAdd_variable_definition_triggered()
{
    ui->definitionsTreeView->model()->insertRow (-1);
}

void MainWindow::on_actionAdd_definition_group_triggered()
{
    ui->definitionsTreeView->model()->insertRow (-1);
}

void MainWindow::on_actionReload_environment_triggered()
{

}

void MainWindow::on_actionAdd_variable_to_context_2_triggered()
{

}

void MainWindow::on_actionAdd_variable_to_context_3_triggered()
{

}

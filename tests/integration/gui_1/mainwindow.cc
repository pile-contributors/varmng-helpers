#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../../motest/modeltest.h"
#include <varmng/varctx_model.h>
#include <varmng/vardef_model.h>
#include <varmng/vareval_model.h>
#include <varmng/varmng.h>

#include <QItemSelectionModel>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    manager_(new VarMng ()),
    def_model_ (new VarDefModel (manager_, this)),
    env_model_ (new VarCtxModel (this)),
    ctx2_model_ (new VarCtxModel (this)),
    ctx3_model_ (new VarCtxModel (this)),
    spl_model_ (new VarEvalModel (this)),
    enh_model_ (new VarEvalModel (this)),

    def_test_model_ (new ModelTest (def_model_, this)),
    env_test_model_ (new ModelTest (env_model_, this)),
    ctx2_test_model_ (new ModelTest (ctx2_model_, this)),
    ctx3_test_model_ (new ModelTest (ctx3_model_, this)),
    spl_test_model_ (new ModelTest (spl_model_, this)),
    enh_test_model_ (new ModelTest (enh_model_, this))
{
    ui->setupUi (this);

    ui->definitionsTreeView->addAction (ui->actionAdd_variable_definition);
    ui->definitionsTreeView->addAction (ui->actionAdd_definition_group);
    ui->definitionsTreeView->addAction (ui->actionRemove_variable_definition);
    ui->definitionsTreeView->addAction (ui->actionCheck_definitions_model);

    ui->environmentTreeView->addAction (ui->actionReload_environment);

    ui->ctx2TreeView->addAction (ui->actionAdd_variable_to_context_2);
    ui->ctx3TreeView->addAction (ui->actionAdd_variable_to_context_3);



    // Create the models and install them in views.
    ui->definitionsTreeView->setModel (
               def_model_);

    ui->environmentTreeView->setModel (
               env_model_);
    ui->ctx2TreeView->setModel (
               ctx2_model_);
    ui->ctx3TreeView->setModel (
               ctx3_model_);

    ui->valuesTreeView->setModel (
               spl_model_);
    ui->explicitValuesTreeView->setModel (
               enh_model_);


/*
    ui->definitionsTreeView->setModel (
                (new ModelTest (
                    def_model_,
                    this))->testedModel ());

    ui->environmentTreeView->setModel (
                (new ModelTest (
                    env_model_,
                    this))->testedModel ());
    ui->ctx2TreeView->setModel (
                (new ModelTest (
                    ctx2_model_,
                    this))->testedModel ());
    ui->ctx3TreeView->setModel (
                (new ModelTest (
                    ctx3_model_,
                    this))->testedModel ());

    ui->valuesTreeView->setModel (
                (new ModelTest (
                    spl_model_,
                    this))->testedModel ());
    ui->explicitValuesTreeView->setModel (
                (new ModelTest (
                    enh_model_,
                    this))->testedModel ());
                    */
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

void MainWindow::on_actionAdd_variable_definition_triggered ()
{
    // whan first item is added to a treeview it appears it becomes
    // current without any user visible sign
    // thus we avoid using it as parent by checking that there
    // is also a selection
    QItemSelectionModel * sm = ui->definitionsTreeView->selectionModel ();
    QModelIndex mi;
    if (sm->selectedIndexes ().count() > 0)
        mi = sm->currentIndex ();
    def_model_->insertRow (-1, mi);
    if (mi.isValid())
        ui->definitionsTreeView->expand (sm->currentIndex ());
}

void MainWindow::on_actionAdd_definition_group_triggered ()
{
    QItemSelectionModel * sm = ui->definitionsTreeView->selectionModel ();
    QModelIndex mi;
    if (sm->selectedIndexes ().count() > 0)
        mi = sm->currentIndex ();
    IVarDef * idf = def_model_->insertVarDef (
                QLatin1String ("NewGroup"),
                tr ("NewGroup"),
                QString(),
                -1,
                mi);
    if (idf) {
        ui->definitionsTreeView->scrollTo (def_model_->toIndex (idf));
    }
}

void MainWindow::on_actionRemove_variable_definition_triggered()
{
    QItemSelectionModel * sm = ui->definitionsTreeView->selectionModel ();
    QModelIndex mi;
    if (sm->selectedIndexes ().count() > 0)
        mi = sm->currentIndex ();
    else
        return;
    def_model_->removeRow (mi.row(), mi.parent ());
}

static void debugPrintDefGroup (
        VarDefModel * m, IVarDef * item, const QString & indent)
{
    QModelIndex mi;
    QModelIndex mip;
    IVarDef * item_parent = NULL;
    if (!indent.isEmpty()) {
        mi = m->toIndex (item);
        mip = mi.parent ();
        item_parent = m->fromIndex (mip);
    }

    qDebug ().noquote() << indent << item << " r:" << mi.row() << " parent:" << item_parent << item->varName();

    foreach(IVarDef *  iter, item->varKids()) {
        debugPrintDefGroup (m, iter, indent + "  ");
    }
}

void MainWindow::on_actionCheck_definitions_model_triggered ()
{
    def_test_model_->runAllTests ();
    debugPrintDefGroup (def_model_, def_model_->manager ()->rootVarDef(), "");
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



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QInputDialog"
#include "hash_table.h"
static HashTable<string> CurrentTable;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->max_mistakes->setVisible(false);
    ui->min_mistakes->setVisible(false);
    ui->edit->setVisible(false);
    ui->add_key->setVisible(false);
    ui->delete_key->setVisible(false);
    ui->delete_all->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_import_button_clicked()
{
    CurrentTable.delete_all();

    QString file_name = "";
    file_name = QFileDialog::getOpenFileName(this, tr("Open File"),
    "/C",
    tr("TXT (*.txt *)"));
    CurrentTable.read_file(file_name.toStdString());

    ui->table_widget->setColumnCount(2);
    ui->table_widget->setRowCount(CurrentTable.get_keys_number());
    ui->table_widget->setHorizontalHeaderLabels(QStringList() << "key" << "value");

    string previous_key = "";
    for(int i = 0; i < CurrentTable.get_keys_number(); i++)
    {
        string current_k = CurrentTable.next_key(previous_key);
        previous_key = current_k;
        QString qstr = QString::fromStdString(current_k);
        QTableWidgetItem *current_key = new QTableWidgetItem(qstr);
        ui->table_widget->setItem(i, 0, current_key);
        int current_v = CurrentTable.get_value(current_k);
        QTableWidgetItem *current_value = new QTableWidgetItem(tr("%1").arg(current_v));
        ui->table_widget->setItem(i, 1, current_value);
    }

    if(CurrentTable.get_keys_number() != 0)
    {
        ui->max_mistakes->setVisible(true);
        ui->min_mistakes->setVisible(true);
        ui->edit->setVisible(true);
    }

    ui->statusbar->showMessage("table has been imported");
}

void MainWindow::on_save_button_clicked()
{
    QString file_name = "";
    file_name = QFileDialog::getOpenFileName(this, tr("Open File"),
    "/C",
    tr("TXT (*.txt *)"));
    CurrentTable.save_file(file_name.toStdString());
    ui->statusbar->showMessage("table has been saved");
}

void MainWindow::on_max_mistakes_clicked() const
{
    string max;
    max = "MAX mistakes has: " + CurrentTable.max_value_key();
    QString qstr = QString::fromStdString(max);
    (new QErrorMessage())->showMessage(qstr);
}

void MainWindow::on_min_mistakes_clicked() const
{
    string min;
    min = "MIN mistakes has: " + CurrentTable.min_value_key();
    QString qstr = QString::fromStdString(min);
    (new QErrorMessage())->showMessage(qstr);
}

void MainWindow::on_edit_clicked() const
{
    if(ui->add_key->isVisible() == false)
    {
        ui->add_key->setVisible(true);
        ui->delete_key->setVisible(true);
        ui->delete_all->setVisible(true);
    }
    else
    {
        ui->add_key->setVisible(false);
        ui->delete_key->setVisible(false);
        ui->delete_all->setVisible(false);
    }
    if(CurrentTable.get_keys_number() == 0)
    {
        ui->delete_all->setVisible(false);
        ui->delete_key->setVisible(false);
    }
}

void MainWindow::on_add_key_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Adding a key"), tr("Enter a key:"), QLineEdit::Normal, "key", &ok);
    if (ok && text.isEmpty())
        (new QErrorMessage())->showMessage("Key is empty");
    else if(ok && !text.isEmpty())
    {
        string key = text.toStdString();
        CurrentTable<<key;
        ui->max_mistakes->setVisible(true);
        ui->min_mistakes->setVisible(true);
    }

    ui->table_widget->setColumnCount(2);
    ui->table_widget->setRowCount(CurrentTable.get_keys_number());
    ui->table_widget->setHorizontalHeaderLabels(QStringList() << "key" << "value");

    string previous_key = "";
    for(int i = 0; i < CurrentTable.get_keys_number(); i++)
    {
        string current_k = CurrentTable.next_key(previous_key);
        previous_key = current_k;
        QString qstr = QString::fromStdString(current_k);
        QTableWidgetItem *current_key = new QTableWidgetItem(qstr);
        ui->table_widget->setItem(i, 0, current_key);
        int current_v = CurrentTable.get_value(current_k);
        QTableWidgetItem *current_value = new QTableWidgetItem(tr("%1").arg(current_v));
        ui->table_widget->setItem(i, 1, current_value);
    }
    if(CurrentTable.get_keys_number() != 0)
    {
        ui->delete_all->setVisible(true);
        ui->delete_key->setVisible(true);
    }
    ui->statusbar->showMessage("key has been added");
}

void MainWindow::on_delete_key_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Removing a key"), tr("Enter a key:"), QLineEdit::Normal, "key", &ok);
    if (ok && text.isEmpty())
        (new QErrorMessage())->showMessage("Key is empty");
    else if(ok && !text.isEmpty())
    {
        string key = text.toStdString();
        CurrentTable.delete_key(key);
    }

    ui->table_widget->setColumnCount(2);
    ui->table_widget->setRowCount(CurrentTable.get_keys_number());
    ui->table_widget->setHorizontalHeaderLabels(QStringList() << "key" << "value");

    string previous_key = "";
    for(int i = 0; i < CurrentTable.get_keys_number(); i++)
    {
        string current_k = CurrentTable.next_key(previous_key);
        previous_key = current_k;
        QString qstr = QString::fromStdString(current_k);
        QTableWidgetItem *current_key = new QTableWidgetItem(qstr);
        ui->table_widget->setItem(i, 0, current_key);
        int current_v = CurrentTable.get_value(current_k);
        QTableWidgetItem *current_value = new QTableWidgetItem(tr("%1").arg(current_v));
        ui->table_widget->setItem(i, 1, current_value);
    }

    if(CurrentTable.get_keys_number() != 0)
    {
        ui->max_mistakes->setVisible(true);
        ui->min_mistakes->setVisible(true);
        ui->edit->setVisible(true);
    }
    else
    {
        ui->max_mistakes->setVisible(false);
        ui->min_mistakes->setVisible(false);
        ui->delete_all->setVisible(false);
    }
    if(CurrentTable.get_keys_number() == 0)
        ui->delete_key->setVisible(false);
    ui->statusbar->showMessage("key has been deleted");
}

void MainWindow::on_delete_all_clicked()
{
    CurrentTable.delete_all();
    ui->table_widget->setColumnCount(2);
    ui->table_widget->setRowCount(CurrentTable.get_keys_number());
    ui->table_widget->setHorizontalHeaderLabels(QStringList() << "key" << "value");

    string previous_key = "";
    for(int i = 0; i < CurrentTable.get_keys_number(); i++)
    {
        string current_k = CurrentTable.next_key(previous_key);
        previous_key = current_k;
        QString qstr = QString::fromStdString(current_k);
        QTableWidgetItem *current_key = new QTableWidgetItem(qstr);
        ui->table_widget->setItem(i, 0, current_key);
        int current_v = CurrentTable.get_value(current_k);
        QTableWidgetItem *current_value = new QTableWidgetItem(tr("%1").arg(current_v));
        ui->table_widget->setItem(i, 1, current_value);
    }

    if(CurrentTable.get_keys_number() != 0)
    {
        ui->max_mistakes->setVisible(true);
        ui->min_mistakes->setVisible(true);
        ui->edit->setVisible(true);
    }
    else
    {
        ui->max_mistakes->setVisible(false);
        ui->min_mistakes->setVisible(false);
    }
    if(CurrentTable.get_keys_number() == 0)
    {
        ui->delete_key->setVisible(false);
        ui->delete_all->setVisible(false);
    }
    ui->statusbar->showMessage("all keys have been deleted");

}

void MainWindow::on_new_table_clicked()
{
    this->on_delete_all_clicked();
    ui->max_mistakes->setVisible(true);
    ui->min_mistakes->setVisible(true);
    ui->edit->setVisible(true);
    ui->max_mistakes->setVisible(false);
    ui->min_mistakes->setVisible(false);
}

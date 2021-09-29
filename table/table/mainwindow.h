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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_import_button_clicked();
    void on_save_button_clicked();
    void on_max_mistakes_clicked() const;
    void on_min_mistakes_clicked() const;
    void on_edit_clicked() const;
    void on_add_key_clicked();
    void on_delete_key_clicked();
    void on_delete_all_clicked();
    void on_new_table_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef Database_H
#define Database_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidgetItem>
#include <details.h>
#include <tools.h>
#include <map>
#include <utility.h>
#include <filter.h>
#include <advancedFilters.h>
#include <set>

class Details;

namespace Ui {
class Database;
}

class Database : public QMainWindow
{
    Q_OBJECT

public:
    explicit Database(Utility* _utility, QWidget* _parent = nullptr);
    ~Database();

signals:
    void changeEditModeDb();

private slots:
    void on_filterByName_textChanged(const QString& _text);
    void on_filterById_textChanged(const QString& _text);
    void on_saveButton_clicked();
    void on_characterList_itemClicked(QListWidgetItem* _item);
    void changeDetails(int _characterId);
    void redraw();

    void on_ownedMode_clicked();
    void on_showOwned_clicked();

    void on_editMode_stateChanged(int _state);

    void on_idOperator_currentIndexChanged(int index);

    void on_advancedFilters_clicked();

    void advancedFilters_set(Filter _filter);
    void advancedFilters_reset();

    void change_advancedFilters_color(bool _active);

private:

    void openCloseDetails(short _id);
    void setIdCondition(QString _text);

    Ui::Database *ui;
    std::vector<QPushButton*> buttons;
    Utility* utility;
    std::vector<Character*> characters;
    std::map<int, std::vector<MyCharacter*>>* myCharacters;

    std::set<int> allIds;

    Filter* filter;
    Details* detailMenu = nullptr;
    AdvancedFilters* advancedFilters = nullptr;
    bool open = false;
    int openId = 0;
};

#endif // Database_H

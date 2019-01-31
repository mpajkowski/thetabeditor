#ifndef DIALOGS_GOTOREHEARSALSIGNDIALOG_H
#define DIALOGS_GOTOREHEARSALSIGNDIALOG_H

#include <QDialog>

namespace Ui {
class GoToRehearsalSignDialog;
}

class Score;
class ScoreLocation;

class GoToRehearsalSignDialog : public QDialog
{
  Q_OBJECT

public:
  explicit GoToRehearsalSignDialog(QWidget* parent, Score const& score);
  ~GoToRehearsalSignDialog();

  /// Returns the location of the selected rehearsal sign.
  ScoreLocation getLocation() const;

public slots:
  virtual void accept() override;

private:
  Ui::GoToRehearsalSignDialog* ui;
  Score const& myScore;
};

#endif

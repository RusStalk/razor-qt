#ifndef NOTIFICATIONHANDLER_H
#define NOTIFICATIONHANDLER_H

#include <QObject>
#include <QPointer>
#include <QSharedPointer>

#include "notification.h"

class NotificationView ;
class NotificationHandlerPrivate ;

class NotificationHandler : public QObject
{
    Q_OBJECT

public:
    //! basic ctor
    explicit NotificationHandler(QObject *parent = 0);

    //! basic dctor
    ~NotificationHandler();

    /**
      * adds notification to handling. pN must not be NULL
      * @param pointer to Notification class
      * @note if notification with the same id exists, pN is free'd
      */
    void addNotification(const Notification &pN);

    /**
      * finds notification by id
      * @param id id of notifications
      * @return pointer to found notification, NULL if not found
      */
    Notification* findNotification( int id ) const;

    /**
     * @brief removes notification.
     * @param id
     */
    void removeNotification( int id ) ;

    /**
     * @brief show notification window
     *
     */
    void showWindow() ;

    /**
     * @brief hides notification window
     *
     */
    void hideWindow();


signals:
    //! emmited when notification is added
    void notificationAdded() ;
protected:
    Q_DECLARE_PRIVATE(NotificationHandler)
    NotificationHandlerPrivate* const d_ptr ;

private slots:
    void removeNotificationSlot();
};

#endif // NOTIFICATIONHANDLER_H

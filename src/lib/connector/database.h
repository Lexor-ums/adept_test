/*
 * database.h
 *
 *  Created on: 02.12.2010
 *		$Revision: 6 $
 *		$Author: pavlov_sg $
 *		$Date: 2010-12-02 11:18:32 +0300 (Чт, 02 дек 2010) $
 *
 */

#ifndef DATABASE_H_
#define DATABASE_H_

/*!
 * \enum Database::DatabaseEvents это перечисление описывает сыбытия базы
 * данных.
 */
namespace Database {
enum DatabaseEvents {
	Delete = 0, //!< удаление записи
	Insert = 1, //!< вставка записи
	Update = 2 //!< обновление записи
};
}

#endif /* DATABASE_H_ */

/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2021 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 #include <config.h>
 #include "private.h"
 #include <udjat/tools/configuration.h>
 #include <iostream>

#ifdef HAVE_DBUS
	#include <udjat/tools/dbus.h>
#endif // HAVE_DBUS

 using namespace std;

 namespace Udjat {

	void User::Controller::deinit(std::shared_ptr<Session> session) {

#ifdef HAVE_DBUS
		if(session->bus) {
			session->info() << "Disconnecting from user's bus" << endl;
			((DBus::Connection *) session->bus)->unsubscribe(this);
			delete ((DBus::Connection *) session->bus);
			session->bus = nullptr;
		}
#endif // HAVE_DBUS

	}

 }

/**
 * Shadow Daemon -- High-Interaction Web Honeypot
 *
 *   Copyright (C) 2014 Hendrik Buchwald <hb@zecure.org>
 *
 * This file is part of Shadow Daemon. Shadow Daemon is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WHITELIST_H
#define WHITELIST_H

#include <vector>

#include "request.h"
#include "whitelist_filter.h"
#include "whitelist_rule.h"

namespace swd {
	/**
	 * @brief Handles the whitelist examination of a request.
	 */
	class whitelist {
		public:
			/**
			 * @brief Construct the whitelist.
			 *
			 * @param request The pointer to the request object
			 */
			whitelist(swd::request_ptr request);

			/**
			 * @brief Initialize the whitelist rules once to cache them for the life
			 *  time of this request.
			 */
			void init();

			/**
			 * @brief Scan all parameters in the request and add connections to broken
			 *  rules.
			 */
			void scan();

		private:
			swd::request_ptr request_;
			swd::whitelist_rules rules_;
	};
}

#endif /* WHITELIST_H */
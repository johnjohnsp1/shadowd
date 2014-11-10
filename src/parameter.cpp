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

#include "parameter.h"

swd::parameter::parameter(std::string value) :
 value_(value),
 threat_(false),
 critical_impact_(false),
 rules_counter_(0) {
}

std::string swd::parameter::get_value() {
	return value_;
}

void swd::parameter::add_blacklist_filter(swd::blacklist_filter_ptr filter) {
	filters_.push_back(filter);
}

const swd::blacklist_filters& swd::parameter::get_blacklist_filters() {
	return filters_;
}

void swd::parameter::add_whitelist_rule(swd::whitelist_rule_ptr rule) {
	rules_.push_back(rule);
}

const swd::whitelist_rules& swd::parameter::get_whitelist_rules() {
	return rules_;
}

int swd::parameter::get_impact() {
	int impact = 0;

	for (swd::blacklist_filters::iterator it_filter = filters_.begin();
	 it_filter != filters_.end(); it_filter++) {
		impact += (*it_filter)->get_impact();
	}

	return impact;
}

void swd::parameter::is_threat(bool threat) {
	threat_ = threat;
}

bool swd::parameter::is_threat() {
	return threat_;
}

void swd::parameter::has_critical_impact(bool critical) {
	critical_impact_ = critical;
}

bool swd::parameter::has_critical_impact() {
	return critical_impact_;
}

void swd::parameter::increment_rules_counter() {
	rules_counter_++;
}

int swd::parameter::get_total_rules() {
	return rules_counter_;
}
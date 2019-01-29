/*
 * Copyright (C) 2013 Cameron White
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FORMATS_POWERTABIMPORTER_H
#define FORMATS_POWERTABIMPORTER_H

#include <formats/fileformatmanager.h>

class PowerTabImporter : public FileFormatImporter
{
public:
    PowerTabImporter();

    virtual void load(const boost::filesystem::path &filename,
                      Score &score) override;
};

#endif

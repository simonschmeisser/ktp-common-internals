/***************************************************************************
 *   Copyright (C) 2014 by Marcin Ziemiński <zieminn@gmail.com>            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2.1 of the License, or   *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef KTP_PROXY_OTR_CONSTANTS_HEADER
#define KTP_PROXY_OTR_CONSTANTS_HEADER

namespace OTR
{
    enum class TrustLevel : unsigned int
    {
        NOT_PRIVATE = 0,
        UNVERIFIED  = 1,
        VERIFIED    = 2,
        FINISHED    = 3
    };

    enum class MessageDirection : unsigned int
    {
        TO_PEER,
        FROM_PEER,
        INTERNAL
    };

    enum class CryptResult : unsigned int
    {
        UNCHANGED,
        CHANGED,
        INGORE,
        ERROR
    };

    template <typename T> unsigned int toUInt(T &&t)
    {
        return static_cast<unsigned int>(t);
    }
}

#endif
